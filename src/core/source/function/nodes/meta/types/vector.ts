enum WindingRule {
  NONZERO,
  EVENODD,
}

interface VectorVertex {
  readonly x: float | 0
  readonly y: float | 0
  readonly strokeCap?: StrokeCap
  readonly strokeJoin?: StrokeJoin
  readonly cornerRadius?: float | 0
}

interface VectorSegment {
  readonly start: float | 0
  readonly end: float | 0
  readonly tangentStart?: Vector
  readonly tangentEnd?: Vector
}

interface VectorPath {
  readonly windingRule: WindingRule
  readonly data: string
}

interface KiwiPath {
  windingRule: WindingRule
  commandsBlob: uint | 0
  styleID: uint | 0
}
