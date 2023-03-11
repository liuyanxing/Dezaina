interface Struct {}
interface Message {}

type byte = number 
type bool  = number 
type int  = number 
type uint = number 
type float = number 

declare type Transform = [[number, number, number], [number, number, number]]
declare type BlendMode =
  | 'PASS_THROUGH'
  | 'NORMAL'
  | 'DARKEN'
  | 'MULTIPLY'
  | 'LINEAR_BURN'
  | 'COLOR_BURN'
  | 'LIGHTEN'
  | 'SCREEN'
  | 'LINEAR_DODGE'
  | 'COLOR_DODGE'
  | 'OVERLAY'
  | 'SOFT_LIGHT'
  | 'HARD_LIGHT'
  | 'DIFFERENCE'
  | 'EXCLUSION'
  | 'HUE'
  | 'SATURATION'
  | 'COLOR'
  | 'LUMINOSITY'
interface MinimalBlendMixin {
  opacity: float
  blendMode: BlendMode
}