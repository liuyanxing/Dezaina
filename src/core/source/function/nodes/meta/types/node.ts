interface RectangleNodeBase extends
    DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
}

interface FrameNodeBase extends DefaultFrameMixin {
}

interface PageNodeBase extends BaseNodeMixin {
  backgrounds: ReadonlyArray<Paint>
}

interface DocumentNodeBase extends BaseNodeMixin {
}
