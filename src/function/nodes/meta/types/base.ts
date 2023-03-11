class Struct {}
class Message {}

type byte = number 
type bool  = boolean 
type int  = number 
type uint = number 
type float = number 

class Vector {
  x: float = 0;
  y: float  = 0;
}

class Matrix extends Struct {
  m00: float = 1;
  m01: float = 0;
  m02: float = 0;
  m10: float = 0;
  m11: float = 1;
  m12: float = 0;
}

enum NumberUnits {
  RAW,
  PIXELS,
  PERCENT,
}
class KiwiNumber extends Struct {
  value: float  = 0;
  units: NumberUnits;
}

