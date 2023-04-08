import Mustache from "mustache";
import {
  DDeclaraction,
  DeclaractionType,
  DEnum,
  DInterface,
  Member,
} from "./types";
import { Graph } from "../utils/graph";
import fs from "fs";
import path from "path";
import { outDir, schemaFileName } from "../const";

function groupByExtends(interfaces: DInterface[]) {
  const graph = new Graph();
  for (const interf of interfaces) {
    const from = interf.name;
    if (interf.mixins.length === 0) {
      graph.addEdge(from, "");
      continue;
    }
    for (const mixin of interf.mixins) {
      graph.addEdge(mixin, from);
    }
  }
  return graph.groupByConnection();
}

function uniqueMembers(members: Member[]) {
  const map = new Map();
  for (const member of members) {
    map.set(member.name, member);
  }
  return Array.from(map.values());
}

function removeKiwiMark(name: string) {
  return name.replace(/(_kiwi|_KiwiOnly)$/, "");
}

function removeMembersTypeMark(members: Member[]) {
  return members.map((member) => {
    if (!member.type) {
      return member;
    }
    return {
      ...member,
      type: removeKiwiMark(member.type),
    };
  });
}

function mixinInterfacByGroup(group: string[][], interfaces: DInterface[]) {
  const interfaceMap: Map<string, DInterface> = new Map();
  for (const interf of interfaces) {
    interfaceMap.set(interf.name, interf);
  }
  group.reverse();
  const groupedInterface: DInterface[] = [];
  for (const i of group) {
    const isStruct = i.some((name) => interfaceMap.get(name)?.isStruct);
    const kiwiName = i.find((name) => name.endsWith("_kiwi"));
    const name = kiwiName ? kiwiName.split("_kiwi")[0] : i[0];
    const item: DInterface = {
      name,
      type: DeclaractionType.Interface,
      members: [],
      mixins: [...i],
      depends: [],
      isStruct,
    };
    for (const name of i) {
      const interf = interfaceMap.get(name);
      if (interf === undefined) {
        continue;
      }
      const members = interf.members as Member[];
      item.members.push(...members);
    }
    
    item.members = uniqueMembers(item.members);
    item.members = removeMembersTypeMark(item.members);
    item.members = item.members.map((member, index) => ({
      ...member,
      index: index + 1,
    })) as Member[];
    groupedInterface.push(item);
  }
  return groupedInterface;
}

function getSchemaData(interfaces: DInterface[], enums: DEnum[]) {
  const kiwiInterfaces = interfaces.map((item) => {
    const members = item.members.map((member) => {
      let type = member.type;
      if (member.isArray) {
        type = type + "[]";
      }
      return { ...member, type };
    });

    return {
      name: removeKiwiMark(item.name),
      members,
      isStruct: item.isStruct,
    };
  });
  const schemaData = {
    enums,
    structs: kiwiInterfaces.filter((item) => item.isStruct),
    messages: kiwiInterfaces.filter((item) => !item.isStruct),
  };
  return schemaData;
}

export function genKiwiSchema(declars: DDeclaraction[], template: string) {
  const interfaces = declars.filter(
    (dInterface) => dInterface.type === DeclaractionType.Interface
  ) as DInterface[];
  const enums = declars.filter(
    (dInterface) => dInterface.type === DeclaractionType.Enum
  ) as DEnum[];
  const grouped = groupByExtends(interfaces);
  const mixined = mixinInterfacByGroup(grouped, interfaces);
  const schemaData = getSchemaData(mixined, enums);
  const reslut = Mustache.render(template, schemaData);
  fs.writeFileSync(path.join(outDir, schemaFileName), reslut);
  const res = declars.filter(declar => !declar.name.endsWith("_kiwi"))
  res.forEach(declar => {
    if (declar.type === DeclaractionType.Interface) {
      declar.mixins = declar.mixins.filter(mixin => !mixin.endsWith("_kiwi"));
    }
  });
  return [res, mixined];
}
