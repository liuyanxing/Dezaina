type PaintType = 'SOLID'
		| 'GRADIENT_LINEAR'
		| 'GRADIENT_RADIAL'
		| 'GRADIENT_ANGULAR'
		| 'GRADIENT_DIAMOND'
		| 'IMAGE'

interface ColorStop extends Struct {
  position: number
  color: RGBA
}

interface Paint {
	type: PaintType
}

interface SolidPaint extends Paint {
  color: RGB
  visible: boolean
  opacity: number
  blendMode: BlendMode
}

interface GradientPaint extends Paint{
  gradientTransform: Transform
  gradientStops: ReadonlyArray<ColorStop>
  visible: boolean
  opacity: number
  blendMode: BlendMode
}

interface ImageFilters {
  exposure: number
  contrast: number
  saturation: number
  temperature: number
  tint: number
  highlights: number
  shadows: number
}

type ScaleMode = 'FILL' | 'FIT' | 'CROP' | 'TILE'
interface ImagePaint extends Paint {
  scaleMode: ScaleMode
  imageHash: string
  imageTransform: Transform
  scalingFactor: number
  rotation: number
  filters: ImageFilters
  visible: boolean
  opacity: number
  blendMode: BlendMode
}