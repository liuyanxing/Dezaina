type DefalutValue = number | string | boolean;

export interface Member {
  name: string;
  type?: string;
  isArray?: boolean;
  defaultValue?: DefalutValue;
  index?: number;
}

export enum DeclaractionType {
  Interface,
  Enum,
}

export interface DInterface {
  name: string;
  type: DeclaractionType.Interface;
  members: Member[];
  mixins: string[];
  isStruct: boolean;
}

export interface DEnum {
  type: DeclaractionType.Enum;
  name: string;
  members: Array<{ name: string; index: number }>;
}

export type DDeclaraction = DInterface | DEnum;
