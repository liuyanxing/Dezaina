import { promisify } from "util";
import { exec } from "child_process";
import path from "path";

export const execSync = promisify(exec);

export function getPathFromRelative(p: string) {
  return path.join(__dirname, p);
}
