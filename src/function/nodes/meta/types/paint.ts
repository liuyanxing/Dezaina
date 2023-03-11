enum PaintType {
  SOLID,
  GRADIENT_LINEAR,
  GRADIENT_RADIAL,
  GRADIENT_ANGULAR,
  GRADIENT_DIAMOND,
  IMAGE,
}

interface ColorStop extends Struct {
  position: float | 0;
  color: RGBA
}

interface Paint {
	type: PaintType
}

interface SolidPaint extends Paint {
  color: RGB
  visible: bool | true;
  opacity: float | 1;
  blendMode: BlendMode
}

interface GradientPaint extends Paint{
  gradientTransform: Matrix
  gradientStops: ReadonlyArray<ColorStop>
  visible: bool
  opacity: float | 1;
  blendMode: BlendMode
}

enum ScaleMode{
  FILL,
  FIT,
  CROP,
  TILE,
}

interface ImagePaint extends Paint {
  scaleMode: ScaleMode
  imageHash: string
  imageTransform: Matrix
  scalingFactor: float
  rotation: float
  visible: bool
  opacity: float
  blendMode: BlendMode
}