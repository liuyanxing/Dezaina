type EffectType = 'DROP_SHADOW'
	| 'DROP_SHADOW'
	| 'INNER_SHADOW'
	| 'LAYER_BLUR'
	| 'BACKGROUND_BLUR'

interface Effect {
  type: EffectType
}

interface DropShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: number
  readonly spread?: number
  readonly visible: boolean
  readonly blendMode: BlendMode
  readonly showShadowBehindNode?: boolean
}
interface InnerShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: number
  readonly spread?: number
  readonly visible: boolean
  readonly blendMode: BlendMode
}
interface BlurEffect extends Effect {
  readonly radius: number
  readonly visible: boolean
}
