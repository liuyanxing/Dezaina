interface GeometryMixin extends MinimalStrokesMixin, MinimalFillsMixin {
  strokeCap: StrokeCap
  strokeMiterLimit: float | 0;
  fillGeometry: Array<Path>;
}

interface LayoutMixin extends DimensionAndPositionMixin {
  rotation: float | 0;
  layoutGrow: uint
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
  gridStyleId: string
  clipsContent: bool | true;
}

interface DefaultFrameMixin extends BaseFrameMixin {
}
