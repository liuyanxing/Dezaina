interface GeometryMixin extends MinimalStrokesMixin, MinimalFillsMixin {
  strokeCap: StrokeCap
  miterLimit: float | 0;
  fillGeometry: IArray<Path>;
}

interface LayoutMixin extends DimensionAndPositionMixin {
}

interface DefaultShapeNode extends
    BaseNodeMixin,
    SceneNodeMixin,
    ExportMixin,
    BlendMixin,
    GeometryMixin,
    LayoutMixin
    {}

interface BaseFrameMixin extends
    DefaultShapeNode,
    CornerMixin,
    RectangleCornerMixin,
    EffectMixin,
    ConstraintMixin,
    IndividualStrokesMixin {
}

interface DefaultFrameMixin extends BaseFrameMixin {
}

interface TextNodeMixin extends
  DefaultShapeNode {
    letterSpacing: Number
    lineHeight: Number
  }
