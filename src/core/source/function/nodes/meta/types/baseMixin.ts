interface NodeChange_kiwi {}

interface BaseNodeMixin extends NodeChange_kiwi {
  guid: GUID;
  parentIndex: ParentIndex;
  name: string;
  type: NodeType;
  encode_function: "virtual void encode(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) { toChange(change, pool); };";
  isDocument_function: "virtual bool isDocument() { return false; };"
  isPage_function: "virtual bool isPage() { return false; };"
  isFrame_function: "virtual bool isFrame() { return false; };;"
  isRect_function: "virtual bool isRect() { return false; };;"
}

interface SceneNodeMixin {
  visible: bool | true;
  locked: bool | false;
}

interface CornerMixin {
  cornerRadius: float | 0;
  cornerSmoothing: float | 0;
}

interface RectangleCornerMixin {
  rectangleTopLeftCornerRadius: float | 0;
  rectangleTopRightCornerRadius: float | 0;
  rectangleBottomLeftCornerRadius: float | 0;
  rectangleBottomRightCornerRadius: float | 0;
}

interface IndividualStrokesMixin {
  borderTopWeight: float | 0;
  borderBottomWeight: float | 0;
  borderLeftWeight: float | 0;
  borderRightWeight: float | 0;
}

interface MinimalStrokesMixin {
  strokePaints: ReadonlyArray<Paint>
  styleIdForStrokeFill: StyleId
  strokeWeight: float | 0
  strokeJoin: StrokeJoin
  strokeAlign: Align
  dashPattern: ReadonlyArray<float>
  strokeGeometry: ReadonlyArray<Path>
}

interface MinimalFillsMixin {
  fills: ReadonlyArray<Paint>
  styleIdForStrokeFill: StyleId
}

interface DimensionAndPositionMixin {
  size: Vector
  transform: Matrix
}

interface ConstraintMixin {
  horizontalConstraint: ConstraintType
  verticalConstraint: ConstraintType
}

interface EffectMixin {
  effects: ReadonlyArray<Effect>
  styleIdForEffect: StyleId
}

interface ExportMixin {

}

interface BlendMixin {

}

interface AutoLayoutMixin extends NodeChange_kiwi {
  stackMode: StackMode
  stackWrap: StackWrap
  stackPaddingRight: float | 0
  stackPaddingBottom: float | 0
  stackHorizontalPadding: float | 0
  stackVerticalPadding: float | 0
}

