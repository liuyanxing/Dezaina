enum PaintType {
  SOLID,
  GRADIENT_LINEAR,
  GRADIENT_RADIAL,
  GRADIENT_ANGULAR,
  GRADIENT_DIAMOND,
  IMAGE,
}

enum ScaleMode{
  FILL,
  FIT,
  CROP,
  TILE,
}

interface ColorStop extends Struct {
  position: float | 0;
  color: RGBA
}

interface Paint {
	type: PaintType
  visible: bool | true;
  opacity: float | 1;
  blendMode: BlendMode
}

interface SolidPaint extends Paint {
  color: RGB
}

interface GradientPaint extends Paint{
  gradientTransform: Matrix
  gradientStops: ReadonlyArray<ColorStop>
}

interface ImagePaint extends Paint {
  scaleMode: ScaleMode
  imageHash: string
  imageTransform: Matrix
  scalingFactor: float
  rotation: float
}