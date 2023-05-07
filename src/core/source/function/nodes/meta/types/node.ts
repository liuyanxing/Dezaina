interface RectangleNodeBase extends
    DefaultShapeMixin,
    ConstraintMixin,
    CornerMixin,
    RectangleCornerMixin,
    IndividualStrokesMixin {
  isRect_function: "virtual bool isRect() const { return true; };";
  encode_function: "void encode(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) { toChange(change, pool); }";
}

interface FrameNodeBase extends DefaultFrameMixin {
  isFrame_function: "virtual bool isFrame() const { return true; };";
  encode_function: "void encode(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) { toChange(change, pool); }";
}

interface PageNodeBase extends BaseNodeMixin, ChildrenMixin_CppOnly {
  backgrounds: ReadonlyArray<Paint>
  isPage_function: "bool isPage() const { return true; };";
  encode_function: "void encode(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) { toChange(change, pool); }";
}

interface DocumentNodeBase extends BaseNodeMixin, ChildrenMixin_CppOnly {
  isDocument_function: "bool isDocument() const { return true; };"
  encode_function: "void encode(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) { toChange(change, pool); }";
}
