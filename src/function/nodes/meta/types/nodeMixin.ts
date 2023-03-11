interface Node_Change_kiwi {}
interface BaseNodeMixin extends Node_Change_kiwi {
  id: string
  parent: GUID
  name: string
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

interface DefaultShapeMixin
	extends BaseNodeMixin,
		SceneNodeMixin,
		LayoutMixin,
		EffectMixin,
		GeometryMixin {}

interface EffectMixin extends MinimalBlendMixin {
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
