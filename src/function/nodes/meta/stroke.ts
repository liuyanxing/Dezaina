type StrokeCap = 'NONE' | 'ROUND' | 'SQUARE' | 'ARROW_LINES' | 'ARROW_EQUILATERAL'
type StrokeJoin = 'MITER' | 'BEVEL' | 'ROUND'

interface MinimalStrokesMixin {
  strokes: ReadonlyArray<Paint>
  strokeStyleId: string
  strokeWeight: number
  strokeJoin: StrokeJoin
  strokeAlign: 'CENTER' | 'INSIDE' | 'OUTSIDE'
  dashPattern: ReadonlyArray<number>
  strokeGeometry: VectorPaths
}