interface NodeChange_kiwi {}

enum NodeType {
  NONE,
  DOCUMENT,
  CANVAS,
  GROUP,
  FRAME,
  BOOLEAN_OPERATION,
  VECTOR,
  STAR,
  LINE,
  ELLIPSE,
  RECTANGLE,
}

interface BaseNodeMixin extends NodeChange_kiwi {
  id: GUID;
  parent: GUID;
  name: string;
  type: NodeType;
  isDocument_function: "virtual bool isDocument() { return false; };"
  isPage_function: "virtual bool isPage() { return false; };"
  isFrame_function: "virtual bool isFrame() { return false; };;"
  isRect_function: "virtual bool isRect() { return false; };;"
}

interface BaseNodeMixin_pointer {}

interface ChildrenMixin_CppOnly {
  children: Array<BaseNodeMixin_pointer>;
  appendChild_function: "void appendChild(BaseNodeMixin* node);"
}

interface SceneNodeMixin {
  visible: bool | true;
  locked: bool | false;
}

interface IndividualStrokesMixin {
  strokeTopWeight: float | 0;
  strokeBottomWeight: float | 0;
  strokeLeftWeight: float | 0;
  strokeRightWeight: float | 0;
}

interface GeometryMixin extends MinimalStrokesMixin, MinimalFillsMixin {
  strokeCap: StrokeCap
  strokeMiterLimit: float | 0;
  fillGeometry: Array<KiwiPath>;
}

interface CornerMixin {
  cornerRadius: float | 0;
  cornerSmoothing: float | 0;
}

interface RectangleCornerMixin {
  topLeftRadius: float | 0;
  topRightRadius: float | 0;
  bottomLeftRadius: float | 0;
  bottomRightRadius: float | 0;
}

interface DefaultShapeMixin extends
    BaseNodeMixin,
    SceneNodeMixin,
    GeometryMixin,
    LayoutMixin
    {}

interface EffectMixin {
  effects: ReadonlyArray<Effect>
  effectStyleId: string
}

enum LayoutMode {
  NONE,
  HORIZONTAL,
  VERTICAL
}
enum AxisSizingMode {
  FIXED,
  AUTO
}
enum PrimaryAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  SPACE_BETWEEN
}
enum CounterAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  BASELINE
}
interface BaseFrameMixin extends BaseNodeMixin,
    SceneNodeMixin,
    GeometryMixin,
    ChildrenMixin_CppOnly,
    CornerMixin,
    RectangleCornerMixin,
    EffectMixin,
    ConstraintMixin,
    LayoutMixin,
    IndividualStrokesMixin {
  layoutMode: LayoutMode
  primaryAxisSizingMode: AxisSizingMode
  counterAxisSizingMode: AxisSizingMode
  primaryAxisAlignItems: PrimaryAxisAlignItems
  counterAxisAlignItems: CounterAxisAlignItems
  paddingLeft: float | 0;
  paddingRight: float | 0;
  paddingTop: float | 0;
  paddingBottom: float | 0;
  itemSpacing: float | 0;
  itemReverseZIndex: bool | false;
  strokesIncludedInLayout: bool | false;
  horizontalPadding: float | 0;
  verticalPadding: float | 0;
  clipsContent: bool | true;
}

interface DefaultFrameMixin extends BaseFrameMixin {}
