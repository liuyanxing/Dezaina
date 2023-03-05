interface DimensionAndPositionMixin {
  readonly width: number
  readonly height: number
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
  rotation: number
  layoutAlign: LayoutAlignType
  layoutGrow: number
  layoutPositioning: 'AUTO' | 'ABSOLUTE'
}