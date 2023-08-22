interface RectangleNodeBase extends
    DefaultShapeNode,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
}

interface FrameNodeBase extends DefaultFrameMixin {
}

interface PageNodeBase extends BaseNodeMixin {
  backgroundColor: Color
  backgroundOpacity: float
  backgroundEnabled: bool
}

interface DocumentNodeBase extends BaseNodeMixin {
}
