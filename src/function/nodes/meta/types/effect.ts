type EffectType = 'DROP_SHADOW'
	| 'DROP_SHADOW'
	| 'INNER_SHADOW'
	| 'LAYER_BLUR'
	| 'BACKGROUND_BLUR'

interface Effect_kiwi {}

interface Effect extends Effect_kiwi {
  type: EffectType
}

interface DropShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float
  readonly spread?: float
  readonly visible: bool
  readonly blendMode: BlendMode
  readonly showShadowBehindNode?: bool
}
interface InnerShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float
  readonly spread?: float
  readonly visible: bool
  readonly blendMode: BlendMode
}
interface BlurEffect extends Effect {
  readonly radius: float
  readonly visible: bool
}
