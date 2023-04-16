interface RectangleNodeBase extends
    DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
  isRect_function: "virtual bool isRect() { return true; };;"
}

interface FrameNodeBase extends DefaultFrameMixin {
  isFrame_function: "virtual bool isFrame() { return true; };;"
}

interface PageNodeBase extends BaseNodeMixin, ChildrenMixin_CppOnly {
  backgrounds: ReadonlyArray<Paint>
  isPage_function: "bool isPage() { return true; };"
}

interface DocumentNodeBase extends BaseNodeMixin, ChildrenMixin_CppOnly {
  isDocument_function: "bool isDocument() { return true; };"
}
