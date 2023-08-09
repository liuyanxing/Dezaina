type byte = number 
type bool = boolean 
type int  = number 
type uint = number 
type float = number 

interface GUID {
	sessionID: uint | 0;
	localID: uint | 0;
}

interface Vector {
  x: float | 0;
  y: float  | 0;
}

interface Matrix {
  m00: float | 1;
  m01: float | 0;
  m02: float | 0;
  m10: float | 0;
  m11: float | 1;
  m12: float | 0;
}

enum NumberUnits {
  RAW,
  PIXELS,
  PERCENT,
}
interface Number {
  value: float | 0;
  units: NumberUnits;
}

interface Color {
  r: float | 0;
  g: float | 0;
  b: float | 0;
  a: float | 1;
}

enum BlendMode {
 PASS_THROUGH,
 NORMAL,
 DARKEN,
 MULTIPLY,
 LINEAR_BURN,
 COLOR_BURN,
 LIGHTEN,
 SCREEN,
 LINEAR_DODGE,
 COLOR_DODGE,
 OVERLAY,
 SOFT_LIGHT,
 HARD_LIGHT,
 DIFFERENCE,
 EXCLUSION,
 HUE,
 SATURATION,
 COLOR,
 LUMINOSITY,
}

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
  readonly color: Color
  readonly offset: Vector
  readonly radius: float | 0;
  readonly spread?: float | 0;
  readonly visible: bool | true
  readonly blendMode: BlendMode
  readonly showShadowBehindNode?: bool | false;
}

interface InnerShadowEffect extends Effect {
  readonly color: Color
  readonly offset: Vector
  readonly radius: float | 10
  readonly spread: float | 0;
  readonly visible: bool | true;
  readonly blendMode: BlendMode
}

interface BlurEffect extends Effect {
  readonly radius: float | 10
  readonly visible: bool | true
}

enum PaintType {
  SOLID,
  GRADIENT_LINEAR,
  GRADIENT_RADIAL,
  GRADIENT_ANGULAR,
  GRADIENT_DIAMOND,
  IMAGE,
}

enum ImageScaleMode{
  STRETCH,
  FIT,
  FILL,
  TILE,
}

interface ColorStop {
  position: float | 0;
  color: Color
}

interface Paint {
	type: PaintType
  visible: bool | true;
  opacity: float | 1;
  blendMode: BlendMode
}

interface SolidPaint extends Paint {
  color: Color
}

interface GradientPaint extends Paint{
  transform: Matrix
  stops: ReadonlyArray<ColorStop>
}

interface ImagePaint extends Paint {
  imageScaleMode: ImageScaleMode
  transform: Matrix
}

enum ConstraintType {
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
}

enum LayoutAlignType{
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
  INHERIT
}

enum StackMode {
  NONE,
  HORIZONTAL,
  VERTICAL
}

enum StackWrap {
  NO_WRAP,
  WRAP
}

enum AxisSizingMode {
  FIXED,
  AUTO
}

enum PrimaryAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  SPACE_BETWEEN,
}

enum CounterAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  BASELINE,
}

enum CounterAxisAlignContent {
  AUTO,
  SPACE_BETWEEN,
}

enum NodeType {
  NONE,
  DOCUMENT,
  CANVAS,
  GROUP,
  FRAME,
  BOOLEAN_OPERATION,
  VECTOR,
  STAR,
  LINE,
  ELLIPSE,
  RECTANGLE,
}

enum MessageType {
  JOIN_START,
  NODE_CHANGES,
  USER_CHANGES,
  JOIN_END,
  SIGNAL,
  STYLE,
  STYLE_SET,
  JOIN_START_SKIP_RELOAD,
  NOTIFY_SHOULD_UPGRADE,
  UPGRADE_DONE,
  UPGRADE_REFRESH,
  SCENE_GRAPH_QUERY,
  SCENE_GRAPH_REPLY,
  DIFF,
  CLIENT_BROADCAST,
  JOIN_START_JOURNALED,
}

enum StrokeCap {
  NONE,
  ROUND,
  SQUARE,
  ARROW_LINES,
  ARROW_EQUILATERAL
}

enum StrokeJoin {
  MITER,
  BEVEL,
  ROUND
}

enum StrokeAlign {
  CENTER,
  INSIDE,
  OUTSIDE
}

enum WindingRule {
  NONZERO,
  EVENODD,
  NONE,
}

interface Path {
  windingRule: WindingRule
  commandsBlob: uint
}

interface ParentIndex {
  guid: GUID 
  position: string
}

interface AssetRef {
  key: string
  version: string
}

interface StyleId {
  guid: GUID
  assetRef: AssetRef 
}


