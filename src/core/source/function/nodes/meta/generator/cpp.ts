import Mustache from "mustache";
import { writeFileSync } from "fs";
import { DDeclaraction, DeclaractionType, DEnum, DInterface } from "./types";
import { execSync } from "child_process";
import { desainaHppFileName, desainaSourceFileName, outDir, schemaFilePath, schemaHppFileName } from "../const";
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

function isCustomType(interf: DInterface) {
  return interf.name.includes("CustomType") || interf.mixins.includes("CustomType");
}

export function genCppHeader(declars: DDeclaraction[], mixinedInterfaces: DDeclaraction[], template: string) {
  // const schemaHppPath = path.join(outDir, schemaHppFileName);
  // execSync(`kiwic --schema ${schemaFilePath} --cpp ${schemaHppPath}`, {
  //   cwd: __dirname,
  // });
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

  const findCustomType = (name: string) => {
    return declars.find((item) => {
      if (item.type === DeclaractionType.Interface) {
        if (item.name === name && isCustomType(item as DInterface)) {
          return true;
        }
      }
      return false;
    });
  };

  const interfaces = declars.filter(
    (dInterface) => {
      return dInterface.type === DeclaractionType.Interface
        && !isKiwiOnlyInterface(dInterface as DInterface)
        && !isPointer(dInterface as DInterface)
        && !isCustomType(dInterface as DInterface);
    }
  ) as DInterface[];

  const customTypes: Set<string> = new Set();
  const cppInterfaces = interfaces.map((item) => {
    const members = item.members.map((member) => {
      let type = member.type;
      const customType = findCustomType(type as string);
      if (member.isPointer) {
        type = type + "*";
      }
      if (member.isArray) {
        type = "std::vector<" + type + ">";
      }
      
      let applyChange = "";
      let toChange: null | string = null;
      if (customType) {
        customTypes.add((customType.members[0] as any).defaultValue as string);
        applyChange = (customType.members[1] as any).defaultValue as string;
        toChange = (customType.members[2] as any).defaultValue as string;
      }
      return { ...member, type, typeInArray: member.type, applyChange, toChange };
    });
    const propsMembers = item.members.filter((member) => !member.isFunction);
    const name = remvoeMark(item.name); 
    return {
      name,
      kiwiChangeType: propsMembers.length ? kiwiChangeMap[name] : null,
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
    customTypes: [...customTypes]
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