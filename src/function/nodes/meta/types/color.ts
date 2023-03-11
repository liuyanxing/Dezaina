interface GUID extends Struct {
	sessionId: uint | 0;
	localId: uint | 0;
}

interface RGB extends Struct {
  r: float | 0;
  g: float | 0;
  b: float | 0;
}

interface RGBA extends Struct {
  r: float | 0;
  g: float | 0;
  b: float | 0;
  a: float | 1;
}
