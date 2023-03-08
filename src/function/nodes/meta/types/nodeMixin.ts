interface Node_Change_kiwi {}
interface BaseNodeMixin extends Node_Change_kiwi {
  id: string
  parent: GUID
  name: string
}

interface SceneNodeMixin {
  visible: bool
  locked: bool
}

interface IndividualStrokesMixin {
  strokeTopWeight: float
  strokeBottomWeight: float
  strokeLeftWeight: float
  strokeRightWeight: float
}

interface GeometryMixin extends MinimalStrokesMixin, MinimalFillsMixin {
  strokeCap: StrokeCap
  strokeMiterLimit: float
  fillGeometry: VectorPaths
}

interface CornerMixin {
  cornerRadius: float
  cornerSmoothing: float
}

interface RectangleCornerMixin {
  topLeftRadius: float
  topRightRadius: float
  bottomLeftRadius: float
  bottomRightRadius: float
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

type LayoutMode = 'NONE' | 'HORIZONTAL' | 'VERTICAL'
type AxisSizingMode = 'FIXED' | 'AUTO'
type PrimaryAxisAlignItems = 'MIN' | 'MAX' | 'CENTER' | 'SPACE_BETWEEN'
type CounterAxisAlignItems = 'MIN' | 'MAX' | 'CENTER' | 'BASELINE'

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
  paddingLeft: float
  paddingRight: float
  paddingTop: float
  paddingBottom: float
  itemSpacing: float
  itemReverseZIndex: bool
  strokesIncludedInLayout: bool
  horizontalPadding: float
  verticalPadding: float
  clipsContent: bool
}

interface DefaultFrameMixin extends BaseFrameMixin {}
