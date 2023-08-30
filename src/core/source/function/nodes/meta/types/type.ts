type byte = number 
type bool = boolean 
type int  = number 
type uint = number 
type float = number

interface CustomType {}
interface Struct {}

interface IArray<T> extends CustomType {
  type: byte | ""
}

interface GUID extends Struct {
	sessionID: uint | 0;
	localID: uint | 0;
}

interface Vector extends Struct {
  x: float | 0;
  y: float  | 0;
}

interface Rect extends Struct {
  x: float
  y: float
  w: float
  h: float
}

interface Matrix extends Struct {
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
interface Number extends Struct {
  value: float | 0;
  units: NumberUnits;
}

interface Color extends Struct {
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

interface Effect extends Struct {
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

enum ImageScaleMode {
  STRETCH,
  FIT,
  FILL,
  TILE,
}

interface ColorStop extends Struct {
  position: float | 0;
  color: Color
}

interface Paint extends Struct {
	type: PaintType
  visible: bool | true;
  opacity: float | 1;
  blendMode: BlendMode
}

interface SolidPaint extends Paint {
  color: Color
}

interface GradientPaint extends Paint {
  transform: Matrix
  stops: IArray<ColorStop>
}

interface ImagePaint extends Paint {
  imageScaleMode: ImageScaleMode
  transform: Matrix
}

interface PaintUnion extends CustomType {
  type: byte | "using  PaintUnion = std::variant<SolidPaint, GradientPaint, ImagePaint>;"
  applyChange: byte | `
template <>
inline void applyChangeImpl<PaintUnion, Desaina_Kiwi::Paint>(PaintUnion& value, const Desaina_Kiwi::Paint& change) {
  auto type = static_cast<PaintType>(*change.type());
  switch (type) {
    case PaintType::SOLID:
      {
        value.emplace<SolidPaint>();
        std::get<SolidPaint>(value).applyChange(change);
        break;
      }
    case PaintType::GRADIENT_LINEAR:
    case PaintType::GRADIENT_RADIAL:
    case PaintType::GRADIENT_ANGULAR:
    case PaintType::GRADIENT_DIAMOND:
      {
        value.emplace<GradientPaint>();
          std::get<SolidPaint>(value).applyChange(change);
        break;
      }
    case PaintType::IMAGE:
      {
        value.emplace<ImagePaint>();
        std::get<SolidPaint>(value).applyChange(change);
        break;
      }
    default:
      break;
  };
}
  `
  toChange: byte | ``
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
  RECTANGLE ,
  REGULAR_POLYGON ,
  ROUNDED_RECTANGLE ,
  TEXT ,
  SLICE ,
  SYMBOL ,
  INSTANCE ,
  STICKY ,
  SHAPE_WITH_TEXT ,
  CONNECTOR ,
  CODE_BLOCK ,
  WIDGET ,
  STAMP ,
  MEDIA ,
  HIGHLIGHT ,
  SECTION ,
  SECTION_OVERLAY ,
  WASHI_TAPE ,
  VARIABLE ,
  TABLE ,
  TABLE_CELL ,
  VARIABLE_SET ,
  SLIDE ,
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

interface Path extends Struct {
  windingRule: WindingRule
  commandsBlob: uint
}

interface ParentIndex extends Struct {
  guid: GUID 
  position: string
}

interface AssetRef extends Struct {
  key: string
  version: string
}

interface StyleId extends Struct {
  guid: GUID
  assetRef: AssetRef 
}

interface ArcData extends Struct {
  startingAngle: float | 0
  endingAngle: float | 6.2831854820251465
  innerRadius: float | 0
}

interface VectorData extends Struct {
  vectorNetworkBlob: uint
}

interface Glyph extends Struct {
  styleID: uint
  commandsBlob: uint
  position: Vector
  fontSize: float
  advance: float
}

interface Decoration {
  rects: IArray<Rect>
}

interface Buffer extends CustomType {
  type: byte | ''
  applyChange: byte | `
template <>
inline void applyChangeImpl<Buffer, kiwi::Array<Desaina_Kiwi::NodeChange>>(Buffer& value, const kiwi::Array<Desaina_Kiwi::NodeChange>& change) {
  kiwi::ByteBuffer _bb;
  _bb.writeVarUint(change.size());
  for (auto &_it : change) {
    const_cast<Desaina_Kiwi::NodeChange&>(_it).encode(_bb);
  }
  value.set(_bb.data(), _bb.size());
}
  `
}

interface Baseline extends Struct {
  position: Vector,
  width: float,
  lineY: float,
  lineHeight: float,
  lineAscent: float,
  firstCharacter: uint,
  endCharacter: uint,
}

interface TextData {
  characters: string
  styleOverrideTable: Buffer 
  layoutSize: Vector
  baselines: IArray<Baseline>
  glyphs: IArray<Glyph>
  decorations: IArray<Decoration>
}

