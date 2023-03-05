interface RectangleNode
  extends DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
  readonly type: 'RECTANGLE'
  clone(): RectangleNode
}

interface FrameNode extends DefaultFrameMixin {
  readonly type: 'DOCUMENT'
}

interface PageNode extends BaseNodeMixin {
  readonly type: 'PAGE'
  backgrounds: ReadonlyArray<Paint>
}

interface DocumentNode extends BaseNodeMixin {
  readonly children: ReadonlyArray<PageNode>
}
