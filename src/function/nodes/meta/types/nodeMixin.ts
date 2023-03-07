interface BaseNodeMixin {
  id: string
  parent: GUID
  name: string
}

interface SceneNodeMixin {
  visible: boolean
  locked: boolean
}

interface IndividualStrokesMixin {
  strokeTopWeight: number
  strokeBottomWeight: number
  strokeLeftWeight: number
  strokeRightWeight: number
}

interface GeometryMixin extends MinimalStrokesMixin, MinimalFillsMixin {
  strokeCap: StrokeCap
  strokeMiterLimit: number
  fillGeometry: VectorPaths
}

interface CornerMixin {
  cornerRadius: number
  cornerSmoothing: number
}

interface RectangleCornerMixin {
  topLeftRadius: number
  topRightRadius: number
  bottomLeftRadius: number
  bottomRightRadius: number
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
  paddingLeft: number
  paddingRight: number
  paddingTop: number
  paddingBottom: number
  itemSpacing: number
  itemReverseZIndex: boolean
  strokesIncludedInLayout: boolean
  horizontalPadding: number
  verticalPadding: number
  clipsContent: boolean
}

interface DefaultFrameMixin extends BaseFrameMixin {}
