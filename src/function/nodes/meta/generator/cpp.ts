import Mustache from "mustache";
import { readFileSync, writeFileSync } from "fs";
import { getPathFromRelative } from "../utils/system";
import { DDeclaraction, DeclaractionType, DEnum, DInterface } from "./types";
import { execSync } from "child_process";
import { desainaHppFileName, outDir, schemaFileName, schemaHppFileName } from "../const";
import path from "path";

export function genCpp(declars: DDeclaraction[], template: string) {
  const schemaPath = path.join(outDir, schemaFileName);
  const schemaHppPath = path.join(outDir, schemaHppFileName);
  execSync(`kiwic --schema ${schemaPath} --cpp ${schemaHppPath}`, {
    cwd: __dirname,
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
      return { ...member, type };
    });
    return {
      name: item.name,
      members,
      mixins: item.mixins.length ? item.mixins.join(",") : null,
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
  const reslut = Mustache.render(
    template,
    data
  );

  writeFileSync(path.join(outDir, desainaHppFileName), reslut);
}
