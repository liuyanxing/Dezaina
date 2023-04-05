interface DimensionAndPositionMixin {
  readonly width: float | 100;
  readonly height: float | 100;
  transform: Matrix
}

enum ConstraintType {
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
}

interface Constraints {
  readonly horizontal: ConstraintType
  readonly vertical: ConstraintType
}

enum LayoutAlignType{
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
  INHERIT
}
interface ConstraintMixin {
  constraints: Constraints
}

interface LayoutMixin extends DimensionAndPositionMixin {
  rotation: float | 0;
  layoutAlign: LayoutAlignType
  layoutGrow: uint
}