interface NodeChange_kiwi {}

interface NodeBase extends NodeChange_kiwi {
  encode_function: "virtual void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) {};";
  applyChange_function: "virtual void applyChange(const Desaina_Kiwi::NodeChange& change) {};";
  isDocument_function: "virtual bool isDocument() { return false; };"
  isPage_function: "virtual bool isPage() { return false; };"
  isFrame_function: "virtual bool isFrame() { return false; };;"
  isRect_function: "virtual bool isRect() { return false; };;"
}

interface BaseNodeMixin extends NodeBase {
  guid: GUID;
  parentIndex: ParentIndex;
  name: string;
  type: NodeType;
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
  strokePaints: ReadonlyArray<PaintUnion>
  styleIdForStrokeFill: StyleId
  strokeWeight: float | 0
  strokeJoin: StrokeJoin
  strokeAlign: StrokeAlign
  dashPattern: ReadonlyArray<float>
  strokeGeometry: ReadonlyArray<Path>
}

interface MinimalFillsMixin {
  fillPaints: ReadonlyArray<PaintUnion>
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

