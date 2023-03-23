enum StrokeCap {
  NONE,
  ROUND,
  SQUARE,
  ARROW_LINES,
  ARROW_EQUILATERAL
}
enum StrokeJoin {
  MITER,
  BEVEL,
  ROUND
}

enum Align {
  CENTER,
  INSIDE,
  OUTSIDE
}

interface MinimalStrokesMixin {
  strokes: ReadonlyArray<Paint>
  strokeStyleId: string
  strokeWeight: float
  strokeJoin: StrokeJoin
  strokeAlign: Align
  dashPattern: ReadonlyArray<float>
  strokeGeometry: ReadonlyArray<KiwiPath>
}