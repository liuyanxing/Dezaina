type StrokeCap = 'NONE' | 'ROUND' | 'SQUARE' | 'ARROW_LINES' | 'ARROW_EQUILATERAL'
type StrokeJoin = 'MITER' | 'BEVEL' | 'ROUND'

type Align = 'CENTER' | 'INSIDE' | 'OUTSIDE'
interface MinimalStrokesMixin {
  strokes: ReadonlyArray<Paint>
  strokeStyleId: string
  strokeWeight: float
  strokeJoin: StrokeJoin
  strokeAlign: Align
  dashPattern: ReadonlyArray<float>
  strokeGeometry: VectorPaths
}