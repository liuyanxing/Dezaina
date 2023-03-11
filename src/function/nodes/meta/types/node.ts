interface RectangleNode extends
    DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
}

interface FrameNode extends DefaultFrameMixin {
}

interface PageNode extends BaseNodeMixin {
  backgrounds: ReadonlyArray<Paint>
}
