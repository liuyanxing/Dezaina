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
  backgroundPaints: ReadonlyArray<Paint>
}

interface DocumentNodeBase extends BaseNodeMixin {
}
