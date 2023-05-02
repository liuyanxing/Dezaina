import Mustache from "mustache";
import { writeFileSync } from "fs";
import { DDeclaraction, DeclaractionType, DEnum, DInterface } from "./types";
import { execSync } from "child_process";
import { desainaHppFileName, desainaSourceFileName, outDir, schemaFileName, schemaHppFileName } from "../const";
import { remvoeMark } from "./util";
import path from "path";

export function sortInterfaceByExtends(interfaces: DInterface[]) {
  const result: DInterface[] = [];
  const map: { [key: string]: DInterface } = {};
  interfaces.forEach((item) => {
    map[item.name] = item;
  });
  interfaces.forEach((item) => {
    if (item.mixins.length) {
      const mixin = map[item.mixins[0]];
      if (mixin) {
        mixin.members = mixin.members.concat(item.members);
        mixin.mixins = mixin.mixins.concat(item.mixins.slice(1));
      } else {
        result.push(item);
      }
    } else {
      result.push(item);
    }
  });
  return result;
}

function isKiwiOnlyInterface(interf: DInterface) {
  return interf.name.endsWith("_KiwiOnly") || interf.mixins.some((mixin) => mixin.endsWith("_KiwiOnly"));
}

function isPointer(interf: DInterface) {
  return interf.name.includes("_pointer");
}

export function genCppHeader(declars: DDeclaraction[], mixinedInterfaces: DDeclaraction[], template: string) {
  const schemaPath = path.join(outDir, schemaFileName);
  const schemaHppPath = path.join(outDir, schemaHppFileName);
  execSync(`kiwic --schema ${schemaPath} --cpp ${schemaHppPath}`, {
    cwd: __dirname,
  });
  const kiwiChangeMap: { [key: string]: string } = {};
  mixinedInterfaces.forEach((item) => {
    if (item.type === DeclaractionType.Interface) {
      if (item.mixins.length) {
        item.mixins.forEach((mixin) => {
          kiwiChangeMap[mixin] = item.name;
        });
      }
    }
  });

  const interfaces = declars.filter(
    (dInterface) => {
      return dInterface.type === DeclaractionType.Interface
        && !isKiwiOnlyInterface(dInterface as DInterface)
        && !isPointer(dInterface as DInterface);
    }
  ) as DInterface[];
  const cppInterfaces = interfaces.map((item) => {
    const members = item.members.map((member) => {
      let type = member.type;
      if (member.isPointer) {
        type = type + "*";
      }
      if (member.isArray) {
        type = "std::vector<" + type + ">";
      }
      return { ...member, type, typeInArray: member.type };
    });
    const name = remvoeMark(item.name); 
    return {
      name,
      kiwiChangeType: kiwiChangeMap[name],
      members,
      extends: item.mixins.length ? item.mixins.map(mixin => "public " + remvoeMark(mixin)).join(", ") : null,
      isStruct: item.isStruct,
      kiwiMixins: item.mixins.filter((item) => !!kiwiChangeMap[item]),
    };
  });

  const structs = cppInterfaces.filter((item) => item.isStruct);
  const classes = cppInterfaces.filter((item) => !item.isStruct);
  const enums = declars.filter(
    (dInterface) => dInterface.type === DeclaractionType.Enum
  ) as DEnum[];

  const data = {
    classes,
    structs,
    enums,
  };
  const reslut = Mustache.render(template, data);

  writeFileSync(path.join(outDir, desainaHppFileName), reslut);
}

interface CppSourceItem {
  className: string;
  memberName: string;
  memberType: string;
  memberDefaultValue: string | number;
}

export function genCppSource(declars: DDeclaraction[], template: string) {
  const interfaceWithDefaultMember = declars.filter(declar => {
    return declar.type === DeclaractionType.Interface
      && declar.members.some(member => member.defaultValue !== undefined)
      && !declar.isStruct;
  }) as DInterface[];
  const cppSourceData = interfaceWithDefaultMember.map(declar => {
    return declar.members.map(member => {
      return {
        className: declar.name,
        memberName: member.name,
        memberType: member.type,
        memberDefaultValue: member.defaultValue
      } as CppSourceItem;
    });
  }).flat();

  const reslut = Mustache.render(template, { data: cppSourceData });
  writeFileSync(path.join(outDir, desainaSourceFileName), reslut);
}