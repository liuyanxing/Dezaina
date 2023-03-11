enum PaintType {
  SOLID,
  GRADIENT_LINEAR,
  GRADIENT_RADIAL,
  GRADIENT_ANGULAR,
  GRADIENT_DIAMOND,
  IMAGE,
}

class ColorStop extends Struct {
  position: float = 0;
  color: RGBA
}

class Paint {
	type: PaintType
}

class SolidPaint extends Paint {
  color: RGB
  visible: bool = true;
  opacity: float = 1;
  blendMode: BlendMode
}

class GradientPaint extends Paint{
  gradientTransform: Matrix
  gradientStops: ReadonlyArray<ColorStop>
  visible: bool
  opacity: float = 1;
  blendMode: BlendMode
}

enum ScaleMode{
  FILL,
  FIT,
  CROP,
  TILE,
}

class ImagePaint extends Paint {
  scaleMode: ScaleMode
  imageHash: string
  imageTransform: Matrix
  scalingFactor: float
  rotation: float
  visible: bool
  opacity: float
  blendMode: BlendMode
}