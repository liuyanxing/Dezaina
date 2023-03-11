class DimensionAndPositionMixin {
  readonly width: float = 100;
  readonly height: float = 100;
  transform: Matrix
}

enum ConstraintType {
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
}

class Constraints {
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
class ConstraintMixin {
  constraints: Constraints
}

class LayoutMixin extends DimensionAndPositionMixin {
  rotation: float = 0;
  layoutAlign: LayoutAlignType
  layoutGrow: uint
}