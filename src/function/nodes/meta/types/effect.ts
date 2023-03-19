enum EffectType {
	DROP_SHADOW,
	INNER_SHADOW,
	LAYER_BLUR,
	BACKGROUND_BLUR,
}

interface Effect {
  type: EffectType
}

interface DropShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float | 0;
  readonly spread?: float | 0;
  readonly visible: bool | true
  readonly blendMode: BlendMode
  readonly showShadowBehindNode?: bool | false;
}
interface InnerShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float | 10
  readonly spread?: float | 0;
  readonly visible: bool | true;
  readonly blendMode: BlendMode
}
interface BlurEffect extends Effect {
  readonly radius: float | 10
  readonly visible: bool | true
}
