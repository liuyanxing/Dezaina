enum WindingRule {
  NONZERO,
  EVENODD,
}

class VectorVertex {
  readonly x: float = 0
  readonly y: float = 0
  readonly strokeCap?: StrokeCap
  readonly strokeJoin?: StrokeJoin
  readonly cornerRadius?: float = 0
}

class VectorSegment {
  readonly start: float = 0
  readonly end: float = 0
  readonly tangentStart?: Vector
  readonly tangentEnd?: Vector
}

class VectorPath {
  readonly windingRule: WindingRule
  readonly data: string
}

class KiwiPath {
  windingRule: WindingRule
  commandsBlob: uint = 0
  styleID: uint = 0
}
