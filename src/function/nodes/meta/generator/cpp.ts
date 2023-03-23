import Mustache from "mustache";
import { writeFileSync } from "fs";
import { DDeclaraction, DeclaractionType, DEnum, DInterface } from "./types";
import { execSync } from "child_process";
import { desainaHppFileName, desainaSourceFileName, outDir, schemaFileName, schemaHppFileName } from "../const";
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
    (dInterface) => dInterface.type === DeclaractionType.Interface
  ) as DInterface[];
  const cppInterfaces = interfaces.map((item) => {
    const members = item.members.map((member) => {
      let type = member.type;
      if (member.isArray) {
        type = "std::vector<" + type + ">";
      }
      return { ...member, type, typeInArray: member.type };
    });
    return {
      name: item.name,
      kiwiChangeType: kiwiChangeMap[item.name],
      members,
      mixins: item.mixins.length ? item.mixins.join(", ") : null,
      isStruct: item.isStruct,
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