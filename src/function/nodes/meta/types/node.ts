interface RectangleNode
  extends DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
  clone(): RectangleNode
}

interface FrameNode extends DefaultFrameMixin {
}

interface PageNode extends BaseNodeMixin {
  backgrounds: ReadonlyArray<Paint>
}

interface DocumentNode extends BaseNodeMixin {
  readonly children: ReadonlyArray<PageNode>
}
