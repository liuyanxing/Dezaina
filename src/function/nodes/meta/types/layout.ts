interface DimensionAndPositionMixin {
  readonly width: float
  readonly height: float
  transform: Transform
}

declare type ConstraintType = 'MIN' | 'CENTER' | 'MAX' | 'STRETCH' | 'SCALE'

interface Constraints {
  readonly horizontal: ConstraintType
  readonly vertical: ConstraintType
}

type LayoutAlignType = 'MIN' | 'CENTER' | 'MAX' | 'STRETCH' | 'INHERIT'

interface ConstraintMixin {
  constraints: Constraints
}

interface LayoutMixin extends DimensionAndPositionMixin {
  rotation: float
  layoutAlign: LayoutAlignType
  layoutGrow: uint
}