class RectangleNode extends
    DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
}

class FrameNode extends DefaultFrameMixin {
}

class PageNode extends BaseNodeMixin {
  backgrounds: ReadonlyArray<Paint>
}

class DocumentNode extends BaseNodeMixin {
  readonly children: ReadonlyArray<PageNode>
}
