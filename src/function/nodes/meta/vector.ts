interface Vector {
  readonly x: number
  readonly y: number
}
declare type WindingRule = 'NONZERO' | 'EVENODD'
interface VectorVertex {
  readonly x: number
  readonly y: number
  readonly strokeCap?: StrokeCap
  readonly strokeJoin?: StrokeJoin
  readonly cornerRadius?: number
}
interface VectorSegment {
  readonly start: number
  readonly end: number
  readonly tangentStart?: Vector
  readonly tangentEnd?: Vector
}
interface VectorRegion {
  readonly windingRule: WindingRule
  readonly loops: ReadonlyArray<ReadonlyArray<number>>
  readonly fills?: ReadonlyArray<Paint>
  readonly fillStyleId?: string
}
interface VectorNetwork {
  readonly vertices: ReadonlyArray<VectorVertex>
  readonly segments: ReadonlyArray<VectorSegment>
  readonly regions?: ReadonlyArray<VectorRegion>
}
interface VectorPath {
  readonly windingRule: WindingRule | 'NONE'
  readonly data: string
}
declare type VectorPaths = ReadonlyArray<VectorPath>
interface LetterSpacing {
  readonly value: number
  readonly unit: 'PIXELS' | 'PERCENT'
}