interface Struct {}
interface Message {}

type byte = number 
type bool = boolean 
type int  = number 
type uint = number 
type float = number 

interface Vector extends Struct {
  x: float | 0;
  y: float  | 0;
}

interface Matrix extends Struct {
  m00: float | 1;
  m01: float | 0;
  m02: float | 0;
  m10: float | 0;
  m11: float | 1;
  m12: float | 0;
}

enum NumberUnits {
  RAW,
  PIXELS,
  PERCENT,
}
interface KiwiNumber extends Struct {
  value: float | 0;
  units: NumberUnits;
}
