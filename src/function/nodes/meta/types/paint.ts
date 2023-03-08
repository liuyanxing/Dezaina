type PaintType = 'SOLID'
		| 'GRADIENT_LINEAR'
		| 'GRADIENT_RADIAL'
		| 'GRADIENT_ANGULAR'
		| 'GRADIENT_DIAMOND'
		| 'IMAGE'

interface ColorStop extends Struct {
  position: float
  color: RGBA
}

interface Paint {
	type: PaintType
}

interface SolidPaint extends Paint {
  color: RGB
  visible: bool
  opacity: float
  blendMode: BlendMode
}

interface GradientPaint extends Paint{
  gradientTransform: Transform
  gradientStops: ReadonlyArray<ColorStop>
  visible: bool
  opacity: float
  blendMode: BlendMode
}

interface ImageFilters {
  exposure: float
  contrast: float
  saturation: float
  temperature: float
  tint: float
  highlights: float
  shadows: float
}

type ScaleMode = 'FILL' | 'FIT' | 'CROP' | 'TILE'
interface ImagePaint extends Paint {
  scaleMode: ScaleMode
  imageHash: string
  imageTransform: Transform
  scalingFactor: float
  rotation: float
  filters: ImageFilters
  visible: bool
  opacity: float
  blendMode: BlendMode
}