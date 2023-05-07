interface DimensionAndPositionMixin {
  width: float | 100;
  height: float | 100;
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
  horizontal: ConstraintType
  vertical: ConstraintType
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
}