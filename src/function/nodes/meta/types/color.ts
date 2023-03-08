interface GUID extends Struct {
	sessionId: uint
	localId: uint
}

interface RGB extends Struct {
  r: byte
  g: byte
  b: byte
}

interface RGBA extends Struct {
  r: byte
  g: byte
  b: byte
  a: byte
}
