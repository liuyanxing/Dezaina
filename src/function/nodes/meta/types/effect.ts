enum EffectType {
	DROP_SHADOW,
	INNER_SHADOW,
	LAYER_BLUR,
	BACKGROUND_BLUR,
}

class Effect_kiwi {}

class Effect extends Effect_kiwi {
  type: EffectType
}

class DropShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float = 0;
  readonly spread?: float = 0;
  readonly visible: bool = true
  readonly blendMode: BlendMode
  readonly showShadowBehindNode?: bool = false;
}
class InnerShadowEffect extends Effect {
  readonly color: RGBA
  readonly offset: Vector
  readonly radius: float = 10
  readonly spread?: float = 0;
  readonly visible: bool = true;
  readonly blendMode: BlendMode
}
class BlurEffect extends Effect {
  readonly radius: float = 10
  readonly visible: bool = true
}
