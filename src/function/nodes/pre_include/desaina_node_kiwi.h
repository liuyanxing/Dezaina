#include "kiwi.h"

namespace Desaina_Kiwi {

#ifndef INCLUDE_DESAINA_KIWI_H
#define INCLUDE_DESAINA_KIWI_H

class BinarySchema {
public:
  bool parse(kiwi::ByteBuffer &bb);
  const kiwi::BinarySchema &underlyingSchema() const { return _schema; }
  bool skipVectorPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorSegmentField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipVectorVertexField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipKiwiPathField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipConstraintsField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipNodeChangeField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const;
  bool skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const;

private:
  kiwi::BinarySchema _schema;
  uint32_t _indexVectorPath = 0;
  uint32_t _indexVectorSegment = 0;
  uint32_t _indexVectorVertex = 0;
  uint32_t _indexKiwiPath = 0;
  uint32_t _indexConstraints = 0;
  uint32_t _indexNodeChange = 0;
  uint32_t _indexPaint = 0;
  uint32_t _indexEffect = 0;
};

enum class NumberUnits : uint32_t {
  RAW = 0,
  PIXELS = 1,
  PERCENT = 2,
};

enum class BlendMode : uint32_t {
  PASS_THROUGH = 0,
  NORMAL = 1,
  DARKEN = 2,
  MULTIPLY = 3,
  LINEAR_BURN = 4,
  COLOR_BURN = 5,
  LIGHTEN = 6,
  SCREEN = 7,
  LINEAR_DODGE = 8,
  COLOR_DODGE = 9,
  OVERLAY = 10,
  SOFT_LIGHT = 11,
  HARD_LIGHT = 12,
  DIFFERENCE = 13,
  EXCLUSION = 14,
  HUE = 15,
  SATURATION = 16,
  COLOR = 17,
  LUMINOSITY = 18,
};

enum class EffectType : uint32_t {
  DROP_SHADOW = 0,
  INNER_SHADOW = 1,
  LAYER_BLUR = 2,
  BACKGROUND_BLUR = 3,
};

enum class ConstraintType : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  STRETCH = 3,
  SCALE = 4,
};

enum class LayoutAlignType : uint32_t {
  MIN = 0,
  CENTER = 1,
  MAX = 2,
  STRETCH = 3,
  SCALE = 4,
  INHERIT = 5,
};

enum class LayoutMode : uint32_t {
  NONE = 0,
  HORIZONTAL = 1,
  VERTICAL = 2,
};

enum class AxisSizingMode : uint32_t {
  FIXED = 0,
  AUTO = 1,
};

enum class PrimaryAxisAlignItems : uint32_t {
  MIN = 0,
  MAX = 1,
  CENTER = 2,
  SPACE_BETWEEN = 3,
};

enum class CounterAxisAlignItems : uint32_t {
  MIN = 0,
  MAX = 1,
  CENTER = 2,
  BASELINE = 3,
};

enum class PaintType : uint32_t {
  SOLID = 0,
  GRADIENT_LINEAR = 1,
  GRADIENT_RADIAL = 2,
  GRADIENT_ANGULAR = 3,
  GRADIENT_DIAMOND = 4,
  IMAGE = 5,
};

enum class ScaleMode : uint32_t {
  FILL = 0,
  FIT = 1,
  CROP = 2,
  TILE = 3,
};

enum class StrokeCap : uint32_t {
  NONE = 0,
  ROUND = 1,
  SQUARE = 2,
  ARROW_LINES = 3,
  ARROW_EQUILATERAL = 4,
};

enum class StrokeJoin : uint32_t {
  MITER = 0,
  BEVEL = 1,
  ROUND = 2,
};

enum class Align : uint32_t {
  CENTER = 0,
  INSIDE = 1,
  OUTSIDE = 2,
};

enum class WindingRule : uint32_t {
  NONZERO = 0,
  EVENODD = 1,
};

class ColorStop;
class RGBA;
class RGB;
class GUID;
class KiwiNumber;
class Matrix;
class Vector;
class VectorPath;
class VectorSegment;
class VectorVertex;
class KiwiPath;
class Constraints;
class NodeChange;
class Paint;
class Effect;

class ColorStop {
public:
  ColorStop() { (void)_flags; }

  float *position();
  const float *position() const;
  void set_position(const float &value);

  RGBA *color();
  const RGBA *color() const;
  void set_color(RGBA *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  RGBA *_data_color = {};
  float _data_position = {};
};

class RGBA {
public:
  RGBA() { (void)_flags; }

  float *r();
  const float *r() const;
  void set_r(const float &value);

  float *g();
  const float *g() const;
  void set_g(const float &value);

  float *b();
  const float *b() const;
  void set_b(const float &value);

  float *a();
  const float *a() const;
  void set_a(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_r = {};
  float _data_g = {};
  float _data_b = {};
  float _data_a = {};
};

class RGB {
public:
  RGB() { (void)_flags; }

  float *r();
  const float *r() const;
  void set_r(const float &value);

  float *g();
  const float *g() const;
  void set_g(const float &value);

  float *b();
  const float *b() const;
  void set_b(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_r = {};
  float _data_g = {};
  float _data_b = {};
};

class GUID {
public:
  GUID() { (void)_flags; }

  uint32_t *sessionId();
  const uint32_t *sessionId() const;
  void set_sessionId(const uint32_t &value);

  uint32_t *localId();
  const uint32_t *localId() const;
  void set_localId(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  uint32_t _data_sessionId = {};
  uint32_t _data_localId = {};
};

class KiwiNumber {
public:
  KiwiNumber() { (void)_flags; }

  float *value();
  const float *value() const;
  void set_value(const float &value);

  NumberUnits *units();
  const NumberUnits *units() const;
  void set_units(const NumberUnits &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  NumberUnits _data_units = {};
  float _data_value = {};
};

class Matrix {
public:
  Matrix() { (void)_flags; }

  float *m00();
  const float *m00() const;
  void set_m00(const float &value);

  float *m01();
  const float *m01() const;
  void set_m01(const float &value);

  float *m02();
  const float *m02() const;
  void set_m02(const float &value);

  float *m10();
  const float *m10() const;
  void set_m10(const float &value);

  float *m11();
  const float *m11() const;
  void set_m11(const float &value);

  float *m12();
  const float *m12() const;
  void set_m12(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_m00 = {};
  float _data_m01 = {};
  float _data_m02 = {};
  float _data_m10 = {};
  float _data_m11 = {};
  float _data_m12 = {};
};

class Vector {
public:
  Vector() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  float _data_x = {};
  float _data_y = {};
};

class VectorPath {
public:
  VectorPath() { (void)_flags; }

  WindingRule *windingRule();
  const WindingRule *windingRule() const;
  void set_windingRule(const WindingRule &value);

  kiwi::String *data();
  const kiwi::String *data() const;
  void set_data(const kiwi::String &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  WindingRule _data_windingRule = {};
  kiwi::String _data_data = {};
};

class VectorSegment {
public:
  VectorSegment() { (void)_flags; }

  float *start();
  const float *start() const;
  void set_start(const float &value);

  float *end();
  const float *end() const;
  void set_end(const float &value);

  Vector *tangentStart();
  const Vector *tangentStart() const;
  void set_tangentStart(Vector *value);

  Vector *tangentEnd();
  const Vector *tangentEnd() const;
  void set_tangentEnd(Vector *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  Vector *_data_tangentStart = {};
  Vector *_data_tangentEnd = {};
  float _data_start = {};
  float _data_end = {};
};

class VectorVertex {
public:
  VectorVertex() { (void)_flags; }

  float *x();
  const float *x() const;
  void set_x(const float &value);

  float *y();
  const float *y() const;
  void set_y(const float &value);

  StrokeCap *strokeCap();
  const StrokeCap *strokeCap() const;
  void set_strokeCap(const StrokeCap &value);

  StrokeJoin *strokeJoin();
  const StrokeJoin *strokeJoin() const;
  void set_strokeJoin(const StrokeJoin &value);

  float *cornerRadius();
  const float *cornerRadius() const;
  void set_cornerRadius(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  StrokeCap _data_strokeCap = {};
  StrokeJoin _data_strokeJoin = {};
  float _data_x = {};
  float _data_y = {};
  float _data_cornerRadius = {};
};

class KiwiPath {
public:
  KiwiPath() { (void)_flags; }

  WindingRule *windingRule();
  const WindingRule *windingRule() const;
  void set_windingRule(const WindingRule &value);

  uint32_t *commandsBlob();
  const uint32_t *commandsBlob() const;
  void set_commandsBlob(const uint32_t &value);

  uint32_t *styleID();
  const uint32_t *styleID() const;
  void set_styleID(const uint32_t &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  WindingRule _data_windingRule = {};
  uint32_t _data_commandsBlob = {};
  uint32_t _data_styleID = {};
};

class Constraints {
public:
  Constraints() { (void)_flags; }

  ConstraintType *horizontal();
  const ConstraintType *horizontal() const;
  void set_horizontal(const ConstraintType &value);

  ConstraintType *vertical();
  const ConstraintType *vertical() const;
  void set_vertical(const ConstraintType &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  ConstraintType _data_horizontal = {};
  ConstraintType _data_vertical = {};
};

class NodeChange {
public:
  NodeChange() { (void)_flags; }

  kiwi::Array<Paint> *fills();
  const kiwi::Array<Paint> *fills() const;
  kiwi::Array<Paint> &set_fills(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *fillStyleId();
  const kiwi::String *fillStyleId() const;
  void set_fillStyleId(const kiwi::String &value);

  StrokeCap *strokeCap();
  const StrokeCap *strokeCap() const;
  void set_strokeCap(const StrokeCap &value);

  float *strokeMiterLimit();
  const float *strokeMiterLimit() const;
  void set_strokeMiterLimit(const float &value);

  kiwi::Array<KiwiPath> *fillGeometry();
  const kiwi::Array<KiwiPath> *fillGeometry() const;
  kiwi::Array<KiwiPath> &set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<Paint> *strokes();
  const kiwi::Array<Paint> *strokes() const;
  kiwi::Array<Paint> &set_strokes(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *strokeStyleId();
  const kiwi::String *strokeStyleId() const;
  void set_strokeStyleId(const kiwi::String &value);

  float *strokeWeight();
  const float *strokeWeight() const;
  void set_strokeWeight(const float &value);

  StrokeJoin *strokeJoin();
  const StrokeJoin *strokeJoin() const;
  void set_strokeJoin(const StrokeJoin &value);

  Align *strokeAlign();
  const Align *strokeAlign() const;
  void set_strokeAlign(const Align &value);

  kiwi::Array<float> *dashPattern();
  const kiwi::Array<float> *dashPattern() const;
  kiwi::Array<float> &set_dashPattern(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::Array<KiwiPath> *strokeGeometry();
  const kiwi::Array<KiwiPath> *strokeGeometry() const;
  kiwi::Array<KiwiPath> &set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *id();
  const kiwi::String *id() const;
  void set_id(const kiwi::String &value);

  GUID *parent();
  const GUID *parent() const;
  void set_parent(GUID *value);

  kiwi::String *name();
  const kiwi::String *name() const;
  void set_name(const kiwi::String &value);

  kiwi::Array<Paint> *backgrounds();
  const kiwi::Array<Paint> *backgrounds() const;
  kiwi::Array<Paint> &set_backgrounds(kiwi::MemoryPool &pool, uint32_t count);

  LayoutMode *layoutMode();
  const LayoutMode *layoutMode() const;
  void set_layoutMode(const LayoutMode &value);

  AxisSizingMode *primaryAxisSizingMode();
  const AxisSizingMode *primaryAxisSizingMode() const;
  void set_primaryAxisSizingMode(const AxisSizingMode &value);

  AxisSizingMode *counterAxisSizingMode();
  const AxisSizingMode *counterAxisSizingMode() const;
  void set_counterAxisSizingMode(const AxisSizingMode &value);

  PrimaryAxisAlignItems *primaryAxisAlignItems();
  const PrimaryAxisAlignItems *primaryAxisAlignItems() const;
  void set_primaryAxisAlignItems(const PrimaryAxisAlignItems &value);

  CounterAxisAlignItems *counterAxisAlignItems();
  const CounterAxisAlignItems *counterAxisAlignItems() const;
  void set_counterAxisAlignItems(const CounterAxisAlignItems &value);

  float *paddingLeft();
  const float *paddingLeft() const;
  void set_paddingLeft(const float &value);

  float *paddingRight();
  const float *paddingRight() const;
  void set_paddingRight(const float &value);

  float *paddingTop();
  const float *paddingTop() const;
  void set_paddingTop(const float &value);

  float *paddingBottom();
  const float *paddingBottom() const;
  void set_paddingBottom(const float &value);

  float *itemSpacing();
  const float *itemSpacing() const;
  void set_itemSpacing(const float &value);

  bool *itemReverseZIndex();
  const bool *itemReverseZIndex() const;
  void set_itemReverseZIndex(const bool &value);

  bool *strokesIncludedInLayout();
  const bool *strokesIncludedInLayout() const;
  void set_strokesIncludedInLayout(const bool &value);

  float *horizontalPadding();
  const float *horizontalPadding() const;
  void set_horizontalPadding(const float &value);

  float *verticalPadding();
  const float *verticalPadding() const;
  void set_verticalPadding(const float &value);

  bool *clipsContent();
  const bool *clipsContent() const;
  void set_clipsContent(const bool &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  bool *locked();
  const bool *locked() const;
  void set_locked(const bool &value);

  float *cornerRadius();
  const float *cornerRadius() const;
  void set_cornerRadius(const float &value);

  float *cornerSmoothing();
  const float *cornerSmoothing() const;
  void set_cornerSmoothing(const float &value);

  Constraints *constraints();
  const Constraints *constraints() const;
  void set_constraints(Constraints *value);

  float *topLeftRadius();
  const float *topLeftRadius() const;
  void set_topLeftRadius(const float &value);

  float *topRightRadius();
  const float *topRightRadius() const;
  void set_topRightRadius(const float &value);

  float *bottomLeftRadius();
  const float *bottomLeftRadius() const;
  void set_bottomLeftRadius(const float &value);

  float *bottomRightRadius();
  const float *bottomRightRadius() const;
  void set_bottomRightRadius(const float &value);

  float *strokeTopWeight();
  const float *strokeTopWeight() const;
  void set_strokeTopWeight(const float &value);

  float *strokeBottomWeight();
  const float *strokeBottomWeight() const;
  void set_strokeBottomWeight(const float &value);

  float *strokeLeftWeight();
  const float *strokeLeftWeight() const;
  void set_strokeLeftWeight(const float &value);

  float *strokeRightWeight();
  const float *strokeRightWeight() const;
  void set_strokeRightWeight(const float &value);

  kiwi::Array<Effect> *effects();
  const kiwi::Array<Effect> *effects() const;
  kiwi::Array<Effect> &set_effects(kiwi::MemoryPool &pool, uint32_t count);

  kiwi::String *effectStyleId();
  const kiwi::String *effectStyleId() const;
  void set_effectStyleId(const kiwi::String &value);

  float *rotation();
  const float *rotation() const;
  void set_rotation(const float &value);

  LayoutAlignType *layoutAlign();
  const LayoutAlignType *layoutAlign() const;
  void set_layoutAlign(const LayoutAlignType &value);

  uint32_t *layoutGrow();
  const uint32_t *layoutGrow() const;
  void set_layoutGrow(const uint32_t &value);

  float *width();
  const float *width() const;
  void set_width(const float &value);

  float *height();
  const float *height() const;
  void set_height(const float &value);

  Matrix *transform();
  const Matrix *transform() const;
  void set_transform(Matrix *value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[2] = {};
  kiwi::Array<Paint> _data_fills = {};
  kiwi::String _data_fillStyleId = {};
  StrokeCap _data_strokeCap = {};
  kiwi::Array<KiwiPath> _data_fillGeometry = {};
  kiwi::Array<Paint> _data_strokes = {};
  kiwi::String _data_strokeStyleId = {};
  StrokeJoin _data_strokeJoin = {};
  Align _data_strokeAlign = {};
  kiwi::Array<float> _data_dashPattern = {};
  kiwi::Array<KiwiPath> _data_strokeGeometry = {};
  kiwi::String _data_id = {};
  GUID *_data_parent = {};
  kiwi::String _data_name = {};
  kiwi::Array<Paint> _data_backgrounds = {};
  LayoutMode _data_layoutMode = {};
  AxisSizingMode _data_primaryAxisSizingMode = {};
  AxisSizingMode _data_counterAxisSizingMode = {};
  PrimaryAxisAlignItems _data_primaryAxisAlignItems = {};
  CounterAxisAlignItems _data_counterAxisAlignItems = {};
  Constraints *_data_constraints = {};
  kiwi::Array<Effect> _data_effects = {};
  kiwi::String _data_effectStyleId = {};
  LayoutAlignType _data_layoutAlign = {};
  Matrix *_data_transform = {};
  float _data_strokeMiterLimit = {};
  float _data_strokeWeight = {};
  float _data_paddingLeft = {};
  float _data_paddingRight = {};
  float _data_paddingTop = {};
  float _data_paddingBottom = {};
  float _data_itemSpacing = {};
  float _data_horizontalPadding = {};
  float _data_verticalPadding = {};
  float _data_cornerRadius = {};
  float _data_cornerSmoothing = {};
  float _data_topLeftRadius = {};
  float _data_topRightRadius = {};
  float _data_bottomLeftRadius = {};
  float _data_bottomRightRadius = {};
  float _data_strokeTopWeight = {};
  float _data_strokeBottomWeight = {};
  float _data_strokeLeftWeight = {};
  float _data_strokeRightWeight = {};
  float _data_rotation = {};
  uint32_t _data_layoutGrow = {};
  float _data_width = {};
  float _data_height = {};
  bool _data_itemReverseZIndex = {};
  bool _data_strokesIncludedInLayout = {};
  bool _data_clipsContent = {};
  bool _data_visible = {};
  bool _data_locked = {};
};

class Paint {
public:
  Paint() { (void)_flags; }

  PaintType *type();
  const PaintType *type() const;
  void set_type(const PaintType &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  float *opacity();
  const float *opacity() const;
  void set_opacity(const float &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  RGB *color();
  const RGB *color() const;
  void set_color(RGB *value);

  Matrix *gradientTransform();
  const Matrix *gradientTransform() const;
  void set_gradientTransform(Matrix *value);

  kiwi::Array<ColorStop> *gradientStops();
  const kiwi::Array<ColorStop> *gradientStops() const;
  kiwi::Array<ColorStop> &set_gradientStops(kiwi::MemoryPool &pool, uint32_t count);

  ScaleMode *scaleMode();
  const ScaleMode *scaleMode() const;
  void set_scaleMode(const ScaleMode &value);

  kiwi::String *imageHash();
  const kiwi::String *imageHash() const;
  void set_imageHash(const kiwi::String &value);

  Matrix *imageTransform();
  const Matrix *imageTransform() const;
  void set_imageTransform(Matrix *value);

  float *scalingFactor();
  const float *scalingFactor() const;
  void set_scalingFactor(const float &value);

  float *rotation();
  const float *rotation() const;
  void set_rotation(const float &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  PaintType _data_type = {};
  BlendMode _data_blendMode = {};
  RGB *_data_color = {};
  Matrix *_data_gradientTransform = {};
  kiwi::Array<ColorStop> _data_gradientStops = {};
  ScaleMode _data_scaleMode = {};
  kiwi::String _data_imageHash = {};
  Matrix *_data_imageTransform = {};
  float _data_opacity = {};
  float _data_scalingFactor = {};
  float _data_rotation = {};
  bool _data_visible = {};
};

class Effect {
public:
  Effect() { (void)_flags; }

  EffectType *type();
  const EffectType *type() const;
  void set_type(const EffectType &value);

  RGBA *color();
  const RGBA *color() const;
  void set_color(RGBA *value);

  Vector *offset();
  const Vector *offset() const;
  void set_offset(Vector *value);

  float *radius();
  const float *radius() const;
  void set_radius(const float &value);

  float *spread();
  const float *spread() const;
  void set_spread(const float &value);

  bool *visible();
  const bool *visible() const;
  void set_visible(const bool &value);

  BlendMode *blendMode();
  const BlendMode *blendMode() const;
  void set_blendMode(const BlendMode &value);

  bool *showShadowBehindNode();
  const bool *showShadowBehindNode() const;
  void set_showShadowBehindNode(const bool &value);

  bool encode(kiwi::ByteBuffer &bb);
  bool decode(kiwi::ByteBuffer &bb, kiwi::MemoryPool &pool, const BinarySchema *schema = nullptr);

private:
  uint32_t _flags[1] = {};
  EffectType _data_type = {};
  RGBA *_data_color = {};
  Vector *_data_offset = {};
  BlendMode _data_blendMode = {};
  float _data_radius = {};
  float _data_spread = {};
  bool _data_visible = {};
  bool _data_showShadowBehindNode = {};
};

#endif
#ifdef IMPLEMENT_SCHEMA_H

bool BinarySchema::parse(kiwi::ByteBuffer &bb) {
  if (!_schema.parse(bb)) return false;
  _schema.findDefinition("VectorPath", _indexVectorPath);
  _schema.findDefinition("VectorSegment", _indexVectorSegment);
  _schema.findDefinition("VectorVertex", _indexVectorVertex);
  _schema.findDefinition("KiwiPath", _indexKiwiPath);
  _schema.findDefinition("Constraints", _indexConstraints);
  _schema.findDefinition("NodeChange", _indexNodeChange);
  _schema.findDefinition("Paint", _indexPaint);
  _schema.findDefinition("Effect", _indexEffect);
  return true;
}

bool BinarySchema::skipVectorPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorPath, id);
}

bool BinarySchema::skipVectorSegmentField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorSegment, id);
}

bool BinarySchema::skipVectorVertexField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexVectorVertex, id);
}

bool BinarySchema::skipKiwiPathField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexKiwiPath, id);
}

bool BinarySchema::skipConstraintsField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexConstraints, id);
}

bool BinarySchema::skipNodeChangeField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexNodeChange, id);
}

bool BinarySchema::skipPaintField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexPaint, id);
}

bool BinarySchema::skipEffectField(kiwi::ByteBuffer &bb, uint32_t id) const {
  return _schema.skipField(bb, _indexEffect, id);
}

float *ColorStop::position() {
  return _flags[0] & 1 ? &_data_position : nullptr;
}

const float *ColorStop::position() const {
  return _flags[0] & 1 ? &_data_position : nullptr;
}

void ColorStop::set_position(const float &value) {
  _flags[0] |= 1; _data_position = value;
}

RGBA *ColorStop::color() {
  return _data_color;
}

const RGBA *ColorStop::color() const {
  return _data_color;
}

void ColorStop::set_color(RGBA *value) {
  _data_color = value;
}

bool ColorStop::encode(kiwi::ByteBuffer &_bb) {
  if (position() == nullptr) return false;
  _bb.writeVarFloat(_data_position);
  if (color() == nullptr) return false;
  if (!_data_color->encode(_bb)) return false;
  return true;
}

bool ColorStop::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_position)) return false;
  set_position(_data_position);
  _data_color = _pool.allocate<RGBA>();
  if (!_data_color->decode(_bb, _pool, _schema)) return false;
  return true;
}

float *RGBA::r() {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

const float *RGBA::r() const {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

void RGBA::set_r(const float &value) {
  _flags[0] |= 1; _data_r = value;
}

float *RGBA::g() {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

const float *RGBA::g() const {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

void RGBA::set_g(const float &value) {
  _flags[0] |= 2; _data_g = value;
}

float *RGBA::b() {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

const float *RGBA::b() const {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

void RGBA::set_b(const float &value) {
  _flags[0] |= 4; _data_b = value;
}

float *RGBA::a() {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

const float *RGBA::a() const {
  return _flags[0] & 8 ? &_data_a : nullptr;
}

void RGBA::set_a(const float &value) {
  _flags[0] |= 8; _data_a = value;
}

bool RGBA::encode(kiwi::ByteBuffer &_bb) {
  if (r() == nullptr) return false;
  _bb.writeVarFloat(_data_r);
  if (g() == nullptr) return false;
  _bb.writeVarFloat(_data_g);
  if (b() == nullptr) return false;
  _bb.writeVarFloat(_data_b);
  if (a() == nullptr) return false;
  _bb.writeVarFloat(_data_a);
  return true;
}

bool RGBA::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_r)) return false;
  set_r(_data_r);
  if (!_bb.readVarFloat(_data_g)) return false;
  set_g(_data_g);
  if (!_bb.readVarFloat(_data_b)) return false;
  set_b(_data_b);
  if (!_bb.readVarFloat(_data_a)) return false;
  set_a(_data_a);
  return true;
}

float *RGB::r() {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

const float *RGB::r() const {
  return _flags[0] & 1 ? &_data_r : nullptr;
}

void RGB::set_r(const float &value) {
  _flags[0] |= 1; _data_r = value;
}

float *RGB::g() {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

const float *RGB::g() const {
  return _flags[0] & 2 ? &_data_g : nullptr;
}

void RGB::set_g(const float &value) {
  _flags[0] |= 2; _data_g = value;
}

float *RGB::b() {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

const float *RGB::b() const {
  return _flags[0] & 4 ? &_data_b : nullptr;
}

void RGB::set_b(const float &value) {
  _flags[0] |= 4; _data_b = value;
}

bool RGB::encode(kiwi::ByteBuffer &_bb) {
  if (r() == nullptr) return false;
  _bb.writeVarFloat(_data_r);
  if (g() == nullptr) return false;
  _bb.writeVarFloat(_data_g);
  if (b() == nullptr) return false;
  _bb.writeVarFloat(_data_b);
  return true;
}

bool RGB::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_r)) return false;
  set_r(_data_r);
  if (!_bb.readVarFloat(_data_g)) return false;
  set_g(_data_g);
  if (!_bb.readVarFloat(_data_b)) return false;
  set_b(_data_b);
  return true;
}

uint32_t *GUID::sessionId() {
  return _flags[0] & 1 ? &_data_sessionId : nullptr;
}

const uint32_t *GUID::sessionId() const {
  return _flags[0] & 1 ? &_data_sessionId : nullptr;
}

void GUID::set_sessionId(const uint32_t &value) {
  _flags[0] |= 1; _data_sessionId = value;
}

uint32_t *GUID::localId() {
  return _flags[0] & 2 ? &_data_localId : nullptr;
}

const uint32_t *GUID::localId() const {
  return _flags[0] & 2 ? &_data_localId : nullptr;
}

void GUID::set_localId(const uint32_t &value) {
  _flags[0] |= 2; _data_localId = value;
}

bool GUID::encode(kiwi::ByteBuffer &_bb) {
  if (sessionId() == nullptr) return false;
  _bb.writeVarUint(_data_sessionId);
  if (localId() == nullptr) return false;
  _bb.writeVarUint(_data_localId);
  return true;
}

bool GUID::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarUint(_data_sessionId)) return false;
  set_sessionId(_data_sessionId);
  if (!_bb.readVarUint(_data_localId)) return false;
  set_localId(_data_localId);
  return true;
}

float *KiwiNumber::value() {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

const float *KiwiNumber::value() const {
  return _flags[0] & 1 ? &_data_value : nullptr;
}

void KiwiNumber::set_value(const float &value) {
  _flags[0] |= 1; _data_value = value;
}

NumberUnits *KiwiNumber::units() {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

const NumberUnits *KiwiNumber::units() const {
  return _flags[0] & 2 ? &_data_units : nullptr;
}

void KiwiNumber::set_units(const NumberUnits &value) {
  _flags[0] |= 2; _data_units = value;
}

bool KiwiNumber::encode(kiwi::ByteBuffer &_bb) {
  if (value() == nullptr) return false;
  _bb.writeVarFloat(_data_value);
  if (units() == nullptr) return false;
  _bb.writeVarUint(static_cast<uint32_t>(_data_units));
  return true;
}

bool KiwiNumber::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_value)) return false;
  set_value(_data_value);
  if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_units))) return false;
  set_units(_data_units);
  return true;
}

float *Matrix::m00() {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

const float *Matrix::m00() const {
  return _flags[0] & 1 ? &_data_m00 : nullptr;
}

void Matrix::set_m00(const float &value) {
  _flags[0] |= 1; _data_m00 = value;
}

float *Matrix::m01() {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

const float *Matrix::m01() const {
  return _flags[0] & 2 ? &_data_m01 : nullptr;
}

void Matrix::set_m01(const float &value) {
  _flags[0] |= 2; _data_m01 = value;
}

float *Matrix::m02() {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

const float *Matrix::m02() const {
  return _flags[0] & 4 ? &_data_m02 : nullptr;
}

void Matrix::set_m02(const float &value) {
  _flags[0] |= 4; _data_m02 = value;
}

float *Matrix::m10() {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

const float *Matrix::m10() const {
  return _flags[0] & 8 ? &_data_m10 : nullptr;
}

void Matrix::set_m10(const float &value) {
  _flags[0] |= 8; _data_m10 = value;
}

float *Matrix::m11() {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

const float *Matrix::m11() const {
  return _flags[0] & 16 ? &_data_m11 : nullptr;
}

void Matrix::set_m11(const float &value) {
  _flags[0] |= 16; _data_m11 = value;
}

float *Matrix::m12() {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

const float *Matrix::m12() const {
  return _flags[0] & 32 ? &_data_m12 : nullptr;
}

void Matrix::set_m12(const float &value) {
  _flags[0] |= 32; _data_m12 = value;
}

bool Matrix::encode(kiwi::ByteBuffer &_bb) {
  if (m00() == nullptr) return false;
  _bb.writeVarFloat(_data_m00);
  if (m01() == nullptr) return false;
  _bb.writeVarFloat(_data_m01);
  if (m02() == nullptr) return false;
  _bb.writeVarFloat(_data_m02);
  if (m10() == nullptr) return false;
  _bb.writeVarFloat(_data_m10);
  if (m11() == nullptr) return false;
  _bb.writeVarFloat(_data_m11);
  if (m12() == nullptr) return false;
  _bb.writeVarFloat(_data_m12);
  return true;
}

bool Matrix::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_m00)) return false;
  set_m00(_data_m00);
  if (!_bb.readVarFloat(_data_m01)) return false;
  set_m01(_data_m01);
  if (!_bb.readVarFloat(_data_m02)) return false;
  set_m02(_data_m02);
  if (!_bb.readVarFloat(_data_m10)) return false;
  set_m10(_data_m10);
  if (!_bb.readVarFloat(_data_m11)) return false;
  set_m11(_data_m11);
  if (!_bb.readVarFloat(_data_m12)) return false;
  set_m12(_data_m12);
  return true;
}

float *Vector::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *Vector::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void Vector::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *Vector::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *Vector::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void Vector::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

bool Vector::encode(kiwi::ByteBuffer &_bb) {
  if (x() == nullptr) return false;
  _bb.writeVarFloat(_data_x);
  if (y() == nullptr) return false;
  _bb.writeVarFloat(_data_y);
  return true;
}

bool Vector::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  if (!_bb.readVarFloat(_data_x)) return false;
  set_x(_data_x);
  if (!_bb.readVarFloat(_data_y)) return false;
  set_y(_data_y);
  return true;
}

WindingRule *VectorPath::windingRule() {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

const WindingRule *VectorPath::windingRule() const {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

void VectorPath::set_windingRule(const WindingRule &value) {
  _flags[0] |= 1; _data_windingRule = value;
}

kiwi::String *VectorPath::data() {
  return _flags[0] & 2 ? &_data_data : nullptr;
}

const kiwi::String *VectorPath::data() const {
  return _flags[0] & 2 ? &_data_data : nullptr;
}

void VectorPath::set_data(const kiwi::String &value) {
  _flags[0] |= 2; _data_data = value;
}

bool VectorPath::encode(kiwi::ByteBuffer &_bb) {
  if (windingRule() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_windingRule));
  }
  if (data() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_data.c_str());
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorPath::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_windingRule))) return false;
        set_windingRule(_data_windingRule);
        break;
      }
      case 2: {
        if (!_bb.readString(_data_data, _pool)) return false;
        set_data(_data_data);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *VectorSegment::start() {
  return _flags[0] & 1 ? &_data_start : nullptr;
}

const float *VectorSegment::start() const {
  return _flags[0] & 1 ? &_data_start : nullptr;
}

void VectorSegment::set_start(const float &value) {
  _flags[0] |= 1; _data_start = value;
}

float *VectorSegment::end() {
  return _flags[0] & 2 ? &_data_end : nullptr;
}

const float *VectorSegment::end() const {
  return _flags[0] & 2 ? &_data_end : nullptr;
}

void VectorSegment::set_end(const float &value) {
  _flags[0] |= 2; _data_end = value;
}

Vector *VectorSegment::tangentStart() {
  return _data_tangentStart;
}

const Vector *VectorSegment::tangentStart() const {
  return _data_tangentStart;
}

void VectorSegment::set_tangentStart(Vector *value) {
  _data_tangentStart = value;
}

Vector *VectorSegment::tangentEnd() {
  return _data_tangentEnd;
}

const Vector *VectorSegment::tangentEnd() const {
  return _data_tangentEnd;
}

void VectorSegment::set_tangentEnd(Vector *value) {
  _data_tangentEnd = value;
}

bool VectorSegment::encode(kiwi::ByteBuffer &_bb) {
  if (start() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_start);
  }
  if (end() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_end);
  }
  if (tangentStart() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_tangentStart->encode(_bb)) return false;
  }
  if (tangentEnd() != nullptr) {
    _bb.writeVarUint(4);
    if (!_data_tangentEnd->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorSegment::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_start)) return false;
        set_start(_data_start);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_end)) return false;
        set_end(_data_end);
        break;
      }
      case 3: {
        _data_tangentStart = _pool.allocate<Vector>();
        if (!_data_tangentStart->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        _data_tangentEnd = _pool.allocate<Vector>();
        if (!_data_tangentEnd->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorSegmentField(_bb, _type)) return false;
        break;
      }
    }
  }
}

float *VectorVertex::x() {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

const float *VectorVertex::x() const {
  return _flags[0] & 1 ? &_data_x : nullptr;
}

void VectorVertex::set_x(const float &value) {
  _flags[0] |= 1; _data_x = value;
}

float *VectorVertex::y() {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

const float *VectorVertex::y() const {
  return _flags[0] & 2 ? &_data_y : nullptr;
}

void VectorVertex::set_y(const float &value) {
  _flags[0] |= 2; _data_y = value;
}

StrokeCap *VectorVertex::strokeCap() {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

const StrokeCap *VectorVertex::strokeCap() const {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

void VectorVertex::set_strokeCap(const StrokeCap &value) {
  _flags[0] |= 4; _data_strokeCap = value;
}

StrokeJoin *VectorVertex::strokeJoin() {
  return _flags[0] & 8 ? &_data_strokeJoin : nullptr;
}

const StrokeJoin *VectorVertex::strokeJoin() const {
  return _flags[0] & 8 ? &_data_strokeJoin : nullptr;
}

void VectorVertex::set_strokeJoin(const StrokeJoin &value) {
  _flags[0] |= 8; _data_strokeJoin = value;
}

float *VectorVertex::cornerRadius() {
  return _flags[0] & 16 ? &_data_cornerRadius : nullptr;
}

const float *VectorVertex::cornerRadius() const {
  return _flags[0] & 16 ? &_data_cornerRadius : nullptr;
}

void VectorVertex::set_cornerRadius(const float &value) {
  _flags[0] |= 16; _data_cornerRadius = value;
}

bool VectorVertex::encode(kiwi::ByteBuffer &_bb) {
  if (x() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarFloat(_data_x);
  }
  if (y() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarFloat(_data_y);
  }
  if (strokeCap() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeCap));
  }
  if (strokeJoin() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeJoin));
  }
  if (cornerRadius() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_cornerRadius);
  }
  _bb.writeVarUint(0);
  return true;
}

bool VectorVertex::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarFloat(_data_x)) return false;
        set_x(_data_x);
        break;
      }
      case 2: {
        if (!_bb.readVarFloat(_data_y)) return false;
        set_y(_data_y);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeCap))) return false;
        set_strokeCap(_data_strokeCap);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeJoin))) return false;
        set_strokeJoin(_data_strokeJoin);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_cornerRadius)) return false;
        set_cornerRadius(_data_cornerRadius);
        break;
      }
      default: {
        if (!_schema || !_schema->skipVectorVertexField(_bb, _type)) return false;
        break;
      }
    }
  }
}

WindingRule *KiwiPath::windingRule() {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

const WindingRule *KiwiPath::windingRule() const {
  return _flags[0] & 1 ? &_data_windingRule : nullptr;
}

void KiwiPath::set_windingRule(const WindingRule &value) {
  _flags[0] |= 1; _data_windingRule = value;
}

uint32_t *KiwiPath::commandsBlob() {
  return _flags[0] & 2 ? &_data_commandsBlob : nullptr;
}

const uint32_t *KiwiPath::commandsBlob() const {
  return _flags[0] & 2 ? &_data_commandsBlob : nullptr;
}

void KiwiPath::set_commandsBlob(const uint32_t &value) {
  _flags[0] |= 2; _data_commandsBlob = value;
}

uint32_t *KiwiPath::styleID() {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

const uint32_t *KiwiPath::styleID() const {
  return _flags[0] & 4 ? &_data_styleID : nullptr;
}

void KiwiPath::set_styleID(const uint32_t &value) {
  _flags[0] |= 4; _data_styleID = value;
}

bool KiwiPath::encode(kiwi::ByteBuffer &_bb) {
  if (windingRule() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_windingRule));
  }
  if (commandsBlob() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(_data_commandsBlob);
  }
  if (styleID() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(_data_styleID);
  }
  _bb.writeVarUint(0);
  return true;
}

bool KiwiPath::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_windingRule))) return false;
        set_windingRule(_data_windingRule);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(_data_commandsBlob)) return false;
        set_commandsBlob(_data_commandsBlob);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(_data_styleID)) return false;
        set_styleID(_data_styleID);
        break;
      }
      default: {
        if (!_schema || !_schema->skipKiwiPathField(_bb, _type)) return false;
        break;
      }
    }
  }
}

ConstraintType *Constraints::horizontal() {
  return _flags[0] & 1 ? &_data_horizontal : nullptr;
}

const ConstraintType *Constraints::horizontal() const {
  return _flags[0] & 1 ? &_data_horizontal : nullptr;
}

void Constraints::set_horizontal(const ConstraintType &value) {
  _flags[0] |= 1; _data_horizontal = value;
}

ConstraintType *Constraints::vertical() {
  return _flags[0] & 2 ? &_data_vertical : nullptr;
}

const ConstraintType *Constraints::vertical() const {
  return _flags[0] & 2 ? &_data_vertical : nullptr;
}

void Constraints::set_vertical(const ConstraintType &value) {
  _flags[0] |= 2; _data_vertical = value;
}

bool Constraints::encode(kiwi::ByteBuffer &_bb) {
  if (horizontal() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_horizontal));
  }
  if (vertical() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeVarUint(static_cast<uint32_t>(_data_vertical));
  }
  _bb.writeVarUint(0);
  return true;
}

bool Constraints::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_horizontal))) return false;
        set_horizontal(_data_horizontal);
        break;
      }
      case 2: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_vertical))) return false;
        set_vertical(_data_vertical);
        break;
      }
      default: {
        if (!_schema || !_schema->skipConstraintsField(_bb, _type)) return false;
        break;
      }
    }
  }
}

kiwi::Array<Paint> *NodeChange::fills() {
  return _flags[0] & 1 ? &_data_fills : nullptr;
}

const kiwi::Array<Paint> *NodeChange::fills() const {
  return _flags[0] & 1 ? &_data_fills : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_fills(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1; return _data_fills = pool.array<Paint>(count);
}

kiwi::String *NodeChange::fillStyleId() {
  return _flags[0] & 2 ? &_data_fillStyleId : nullptr;
}

const kiwi::String *NodeChange::fillStyleId() const {
  return _flags[0] & 2 ? &_data_fillStyleId : nullptr;
}

void NodeChange::set_fillStyleId(const kiwi::String &value) {
  _flags[0] |= 2; _data_fillStyleId = value;
}

StrokeCap *NodeChange::strokeCap() {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

const StrokeCap *NodeChange::strokeCap() const {
  return _flags[0] & 4 ? &_data_strokeCap : nullptr;
}

void NodeChange::set_strokeCap(const StrokeCap &value) {
  _flags[0] |= 4; _data_strokeCap = value;
}

float *NodeChange::strokeMiterLimit() {
  return _flags[0] & 8 ? &_data_strokeMiterLimit : nullptr;
}

const float *NodeChange::strokeMiterLimit() const {
  return _flags[0] & 8 ? &_data_strokeMiterLimit : nullptr;
}

void NodeChange::set_strokeMiterLimit(const float &value) {
  _flags[0] |= 8; _data_strokeMiterLimit = value;
}

kiwi::Array<KiwiPath> *NodeChange::fillGeometry() {
  return _flags[0] & 16 ? &_data_fillGeometry : nullptr;
}

const kiwi::Array<KiwiPath> *NodeChange::fillGeometry() const {
  return _flags[0] & 16 ? &_data_fillGeometry : nullptr;
}

kiwi::Array<KiwiPath> &NodeChange::set_fillGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 16; return _data_fillGeometry = pool.array<KiwiPath>(count);
}

kiwi::Array<Paint> *NodeChange::strokes() {
  return _flags[0] & 32 ? &_data_strokes : nullptr;
}

const kiwi::Array<Paint> *NodeChange::strokes() const {
  return _flags[0] & 32 ? &_data_strokes : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_strokes(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32; return _data_strokes = pool.array<Paint>(count);
}

kiwi::String *NodeChange::strokeStyleId() {
  return _flags[0] & 64 ? &_data_strokeStyleId : nullptr;
}

const kiwi::String *NodeChange::strokeStyleId() const {
  return _flags[0] & 64 ? &_data_strokeStyleId : nullptr;
}

void NodeChange::set_strokeStyleId(const kiwi::String &value) {
  _flags[0] |= 64; _data_strokeStyleId = value;
}

float *NodeChange::strokeWeight() {
  return _flags[0] & 128 ? &_data_strokeWeight : nullptr;
}

const float *NodeChange::strokeWeight() const {
  return _flags[0] & 128 ? &_data_strokeWeight : nullptr;
}

void NodeChange::set_strokeWeight(const float &value) {
  _flags[0] |= 128; _data_strokeWeight = value;
}

StrokeJoin *NodeChange::strokeJoin() {
  return _flags[0] & 256 ? &_data_strokeJoin : nullptr;
}

const StrokeJoin *NodeChange::strokeJoin() const {
  return _flags[0] & 256 ? &_data_strokeJoin : nullptr;
}

void NodeChange::set_strokeJoin(const StrokeJoin &value) {
  _flags[0] |= 256; _data_strokeJoin = value;
}

Align *NodeChange::strokeAlign() {
  return _flags[0] & 512 ? &_data_strokeAlign : nullptr;
}

const Align *NodeChange::strokeAlign() const {
  return _flags[0] & 512 ? &_data_strokeAlign : nullptr;
}

void NodeChange::set_strokeAlign(const Align &value) {
  _flags[0] |= 512; _data_strokeAlign = value;
}

kiwi::Array<float> *NodeChange::dashPattern() {
  return _flags[0] & 1024 ? &_data_dashPattern : nullptr;
}

const kiwi::Array<float> *NodeChange::dashPattern() const {
  return _flags[0] & 1024 ? &_data_dashPattern : nullptr;
}

kiwi::Array<float> &NodeChange::set_dashPattern(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 1024; return _data_dashPattern = pool.array<float>(count);
}

kiwi::Array<KiwiPath> *NodeChange::strokeGeometry() {
  return _flags[0] & 2048 ? &_data_strokeGeometry : nullptr;
}

const kiwi::Array<KiwiPath> *NodeChange::strokeGeometry() const {
  return _flags[0] & 2048 ? &_data_strokeGeometry : nullptr;
}

kiwi::Array<KiwiPath> &NodeChange::set_strokeGeometry(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 2048; return _data_strokeGeometry = pool.array<KiwiPath>(count);
}

kiwi::String *NodeChange::id() {
  return _flags[0] & 4096 ? &_data_id : nullptr;
}

const kiwi::String *NodeChange::id() const {
  return _flags[0] & 4096 ? &_data_id : nullptr;
}

void NodeChange::set_id(const kiwi::String &value) {
  _flags[0] |= 4096; _data_id = value;
}

GUID *NodeChange::parent() {
  return _data_parent;
}

const GUID *NodeChange::parent() const {
  return _data_parent;
}

void NodeChange::set_parent(GUID *value) {
  _data_parent = value;
}

kiwi::String *NodeChange::name() {
  return _flags[0] & 16384 ? &_data_name : nullptr;
}

const kiwi::String *NodeChange::name() const {
  return _flags[0] & 16384 ? &_data_name : nullptr;
}

void NodeChange::set_name(const kiwi::String &value) {
  _flags[0] |= 16384; _data_name = value;
}

kiwi::Array<Paint> *NodeChange::backgrounds() {
  return _flags[0] & 32768 ? &_data_backgrounds : nullptr;
}

const kiwi::Array<Paint> *NodeChange::backgrounds() const {
  return _flags[0] & 32768 ? &_data_backgrounds : nullptr;
}

kiwi::Array<Paint> &NodeChange::set_backgrounds(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 32768; return _data_backgrounds = pool.array<Paint>(count);
}

LayoutMode *NodeChange::layoutMode() {
  return _flags[0] & 65536 ? &_data_layoutMode : nullptr;
}

const LayoutMode *NodeChange::layoutMode() const {
  return _flags[0] & 65536 ? &_data_layoutMode : nullptr;
}

void NodeChange::set_layoutMode(const LayoutMode &value) {
  _flags[0] |= 65536; _data_layoutMode = value;
}

AxisSizingMode *NodeChange::primaryAxisSizingMode() {
  return _flags[0] & 131072 ? &_data_primaryAxisSizingMode : nullptr;
}

const AxisSizingMode *NodeChange::primaryAxisSizingMode() const {
  return _flags[0] & 131072 ? &_data_primaryAxisSizingMode : nullptr;
}

void NodeChange::set_primaryAxisSizingMode(const AxisSizingMode &value) {
  _flags[0] |= 131072; _data_primaryAxisSizingMode = value;
}

AxisSizingMode *NodeChange::counterAxisSizingMode() {
  return _flags[0] & 262144 ? &_data_counterAxisSizingMode : nullptr;
}

const AxisSizingMode *NodeChange::counterAxisSizingMode() const {
  return _flags[0] & 262144 ? &_data_counterAxisSizingMode : nullptr;
}

void NodeChange::set_counterAxisSizingMode(const AxisSizingMode &value) {
  _flags[0] |= 262144; _data_counterAxisSizingMode = value;
}

PrimaryAxisAlignItems *NodeChange::primaryAxisAlignItems() {
  return _flags[0] & 524288 ? &_data_primaryAxisAlignItems : nullptr;
}

const PrimaryAxisAlignItems *NodeChange::primaryAxisAlignItems() const {
  return _flags[0] & 524288 ? &_data_primaryAxisAlignItems : nullptr;
}

void NodeChange::set_primaryAxisAlignItems(const PrimaryAxisAlignItems &value) {
  _flags[0] |= 524288; _data_primaryAxisAlignItems = value;
}

CounterAxisAlignItems *NodeChange::counterAxisAlignItems() {
  return _flags[0] & 1048576 ? &_data_counterAxisAlignItems : nullptr;
}

const CounterAxisAlignItems *NodeChange::counterAxisAlignItems() const {
  return _flags[0] & 1048576 ? &_data_counterAxisAlignItems : nullptr;
}

void NodeChange::set_counterAxisAlignItems(const CounterAxisAlignItems &value) {
  _flags[0] |= 1048576; _data_counterAxisAlignItems = value;
}

float *NodeChange::paddingLeft() {
  return _flags[0] & 2097152 ? &_data_paddingLeft : nullptr;
}

const float *NodeChange::paddingLeft() const {
  return _flags[0] & 2097152 ? &_data_paddingLeft : nullptr;
}

void NodeChange::set_paddingLeft(const float &value) {
  _flags[0] |= 2097152; _data_paddingLeft = value;
}

float *NodeChange::paddingRight() {
  return _flags[0] & 4194304 ? &_data_paddingRight : nullptr;
}

const float *NodeChange::paddingRight() const {
  return _flags[0] & 4194304 ? &_data_paddingRight : nullptr;
}

void NodeChange::set_paddingRight(const float &value) {
  _flags[0] |= 4194304; _data_paddingRight = value;
}

float *NodeChange::paddingTop() {
  return _flags[0] & 8388608 ? &_data_paddingTop : nullptr;
}

const float *NodeChange::paddingTop() const {
  return _flags[0] & 8388608 ? &_data_paddingTop : nullptr;
}

void NodeChange::set_paddingTop(const float &value) {
  _flags[0] |= 8388608; _data_paddingTop = value;
}

float *NodeChange::paddingBottom() {
  return _flags[0] & 16777216 ? &_data_paddingBottom : nullptr;
}

const float *NodeChange::paddingBottom() const {
  return _flags[0] & 16777216 ? &_data_paddingBottom : nullptr;
}

void NodeChange::set_paddingBottom(const float &value) {
  _flags[0] |= 16777216; _data_paddingBottom = value;
}

float *NodeChange::itemSpacing() {
  return _flags[0] & 33554432 ? &_data_itemSpacing : nullptr;
}

const float *NodeChange::itemSpacing() const {
  return _flags[0] & 33554432 ? &_data_itemSpacing : nullptr;
}

void NodeChange::set_itemSpacing(const float &value) {
  _flags[0] |= 33554432; _data_itemSpacing = value;
}

bool *NodeChange::itemReverseZIndex() {
  return _flags[0] & 67108864 ? &_data_itemReverseZIndex : nullptr;
}

const bool *NodeChange::itemReverseZIndex() const {
  return _flags[0] & 67108864 ? &_data_itemReverseZIndex : nullptr;
}

void NodeChange::set_itemReverseZIndex(const bool &value) {
  _flags[0] |= 67108864; _data_itemReverseZIndex = value;
}

bool *NodeChange::strokesIncludedInLayout() {
  return _flags[0] & 134217728 ? &_data_strokesIncludedInLayout : nullptr;
}

const bool *NodeChange::strokesIncludedInLayout() const {
  return _flags[0] & 134217728 ? &_data_strokesIncludedInLayout : nullptr;
}

void NodeChange::set_strokesIncludedInLayout(const bool &value) {
  _flags[0] |= 134217728; _data_strokesIncludedInLayout = value;
}

float *NodeChange::horizontalPadding() {
  return _flags[0] & 268435456 ? &_data_horizontalPadding : nullptr;
}

const float *NodeChange::horizontalPadding() const {
  return _flags[0] & 268435456 ? &_data_horizontalPadding : nullptr;
}

void NodeChange::set_horizontalPadding(const float &value) {
  _flags[0] |= 268435456; _data_horizontalPadding = value;
}

float *NodeChange::verticalPadding() {
  return _flags[0] & 536870912 ? &_data_verticalPadding : nullptr;
}

const float *NodeChange::verticalPadding() const {
  return _flags[0] & 536870912 ? &_data_verticalPadding : nullptr;
}

void NodeChange::set_verticalPadding(const float &value) {
  _flags[0] |= 536870912; _data_verticalPadding = value;
}

bool *NodeChange::clipsContent() {
  return _flags[0] & 1073741824 ? &_data_clipsContent : nullptr;
}

const bool *NodeChange::clipsContent() const {
  return _flags[0] & 1073741824 ? &_data_clipsContent : nullptr;
}

void NodeChange::set_clipsContent(const bool &value) {
  _flags[0] |= 1073741824; _data_clipsContent = value;
}

bool *NodeChange::visible() {
  return _flags[0] & 2147483648 ? &_data_visible : nullptr;
}

const bool *NodeChange::visible() const {
  return _flags[0] & 2147483648 ? &_data_visible : nullptr;
}

void NodeChange::set_visible(const bool &value) {
  _flags[0] |= 2147483648; _data_visible = value;
}

bool *NodeChange::locked() {
  return _flags[1] & 1 ? &_data_locked : nullptr;
}

const bool *NodeChange::locked() const {
  return _flags[1] & 1 ? &_data_locked : nullptr;
}

void NodeChange::set_locked(const bool &value) {
  _flags[1] |= 1; _data_locked = value;
}

float *NodeChange::cornerRadius() {
  return _flags[1] & 2 ? &_data_cornerRadius : nullptr;
}

const float *NodeChange::cornerRadius() const {
  return _flags[1] & 2 ? &_data_cornerRadius : nullptr;
}

void NodeChange::set_cornerRadius(const float &value) {
  _flags[1] |= 2; _data_cornerRadius = value;
}

float *NodeChange::cornerSmoothing() {
  return _flags[1] & 4 ? &_data_cornerSmoothing : nullptr;
}

const float *NodeChange::cornerSmoothing() const {
  return _flags[1] & 4 ? &_data_cornerSmoothing : nullptr;
}

void NodeChange::set_cornerSmoothing(const float &value) {
  _flags[1] |= 4; _data_cornerSmoothing = value;
}

Constraints *NodeChange::constraints() {
  return _data_constraints;
}

const Constraints *NodeChange::constraints() const {
  return _data_constraints;
}

void NodeChange::set_constraints(Constraints *value) {
  _data_constraints = value;
}

float *NodeChange::topLeftRadius() {
  return _flags[1] & 16 ? &_data_topLeftRadius : nullptr;
}

const float *NodeChange::topLeftRadius() const {
  return _flags[1] & 16 ? &_data_topLeftRadius : nullptr;
}

void NodeChange::set_topLeftRadius(const float &value) {
  _flags[1] |= 16; _data_topLeftRadius = value;
}

float *NodeChange::topRightRadius() {
  return _flags[1] & 32 ? &_data_topRightRadius : nullptr;
}

const float *NodeChange::topRightRadius() const {
  return _flags[1] & 32 ? &_data_topRightRadius : nullptr;
}

void NodeChange::set_topRightRadius(const float &value) {
  _flags[1] |= 32; _data_topRightRadius = value;
}

float *NodeChange::bottomLeftRadius() {
  return _flags[1] & 64 ? &_data_bottomLeftRadius : nullptr;
}

const float *NodeChange::bottomLeftRadius() const {
  return _flags[1] & 64 ? &_data_bottomLeftRadius : nullptr;
}

void NodeChange::set_bottomLeftRadius(const float &value) {
  _flags[1] |= 64; _data_bottomLeftRadius = value;
}

float *NodeChange::bottomRightRadius() {
  return _flags[1] & 128 ? &_data_bottomRightRadius : nullptr;
}

const float *NodeChange::bottomRightRadius() const {
  return _flags[1] & 128 ? &_data_bottomRightRadius : nullptr;
}

void NodeChange::set_bottomRightRadius(const float &value) {
  _flags[1] |= 128; _data_bottomRightRadius = value;
}

float *NodeChange::strokeTopWeight() {
  return _flags[1] & 256 ? &_data_strokeTopWeight : nullptr;
}

const float *NodeChange::strokeTopWeight() const {
  return _flags[1] & 256 ? &_data_strokeTopWeight : nullptr;
}

void NodeChange::set_strokeTopWeight(const float &value) {
  _flags[1] |= 256; _data_strokeTopWeight = value;
}

float *NodeChange::strokeBottomWeight() {
  return _flags[1] & 512 ? &_data_strokeBottomWeight : nullptr;
}

const float *NodeChange::strokeBottomWeight() const {
  return _flags[1] & 512 ? &_data_strokeBottomWeight : nullptr;
}

void NodeChange::set_strokeBottomWeight(const float &value) {
  _flags[1] |= 512; _data_strokeBottomWeight = value;
}

float *NodeChange::strokeLeftWeight() {
  return _flags[1] & 1024 ? &_data_strokeLeftWeight : nullptr;
}

const float *NodeChange::strokeLeftWeight() const {
  return _flags[1] & 1024 ? &_data_strokeLeftWeight : nullptr;
}

void NodeChange::set_strokeLeftWeight(const float &value) {
  _flags[1] |= 1024; _data_strokeLeftWeight = value;
}

float *NodeChange::strokeRightWeight() {
  return _flags[1] & 2048 ? &_data_strokeRightWeight : nullptr;
}

const float *NodeChange::strokeRightWeight() const {
  return _flags[1] & 2048 ? &_data_strokeRightWeight : nullptr;
}

void NodeChange::set_strokeRightWeight(const float &value) {
  _flags[1] |= 2048; _data_strokeRightWeight = value;
}

kiwi::Array<Effect> *NodeChange::effects() {
  return _flags[1] & 4096 ? &_data_effects : nullptr;
}

const kiwi::Array<Effect> *NodeChange::effects() const {
  return _flags[1] & 4096 ? &_data_effects : nullptr;
}

kiwi::Array<Effect> &NodeChange::set_effects(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[1] |= 4096; return _data_effects = pool.array<Effect>(count);
}

kiwi::String *NodeChange::effectStyleId() {
  return _flags[1] & 8192 ? &_data_effectStyleId : nullptr;
}

const kiwi::String *NodeChange::effectStyleId() const {
  return _flags[1] & 8192 ? &_data_effectStyleId : nullptr;
}

void NodeChange::set_effectStyleId(const kiwi::String &value) {
  _flags[1] |= 8192; _data_effectStyleId = value;
}

float *NodeChange::rotation() {
  return _flags[1] & 16384 ? &_data_rotation : nullptr;
}

const float *NodeChange::rotation() const {
  return _flags[1] & 16384 ? &_data_rotation : nullptr;
}

void NodeChange::set_rotation(const float &value) {
  _flags[1] |= 16384; _data_rotation = value;
}

LayoutAlignType *NodeChange::layoutAlign() {
  return _flags[1] & 32768 ? &_data_layoutAlign : nullptr;
}

const LayoutAlignType *NodeChange::layoutAlign() const {
  return _flags[1] & 32768 ? &_data_layoutAlign : nullptr;
}

void NodeChange::set_layoutAlign(const LayoutAlignType &value) {
  _flags[1] |= 32768; _data_layoutAlign = value;
}

uint32_t *NodeChange::layoutGrow() {
  return _flags[1] & 65536 ? &_data_layoutGrow : nullptr;
}

const uint32_t *NodeChange::layoutGrow() const {
  return _flags[1] & 65536 ? &_data_layoutGrow : nullptr;
}

void NodeChange::set_layoutGrow(const uint32_t &value) {
  _flags[1] |= 65536; _data_layoutGrow = value;
}

float *NodeChange::width() {
  return _flags[1] & 131072 ? &_data_width : nullptr;
}

const float *NodeChange::width() const {
  return _flags[1] & 131072 ? &_data_width : nullptr;
}

void NodeChange::set_width(const float &value) {
  _flags[1] |= 131072; _data_width = value;
}

float *NodeChange::height() {
  return _flags[1] & 262144 ? &_data_height : nullptr;
}

const float *NodeChange::height() const {
  return _flags[1] & 262144 ? &_data_height : nullptr;
}

void NodeChange::set_height(const float &value) {
  _flags[1] |= 262144; _data_height = value;
}

Matrix *NodeChange::transform() {
  return _data_transform;
}

const Matrix *NodeChange::transform() const {
  return _data_transform;
}

void NodeChange::set_transform(Matrix *value) {
  _data_transform = value;
}

bool NodeChange::encode(kiwi::ByteBuffer &_bb) {
  if (fills() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(_data_fills.size());
    for (Paint &_it : _data_fills) if (!_it.encode(_bb)) return false;
  }
  if (fillStyleId() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeString(_data_fillStyleId.c_str());
  }
  if (strokeCap() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeCap));
  }
  if (strokeMiterLimit() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_strokeMiterLimit);
  }
  if (fillGeometry() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarUint(_data_fillGeometry.size());
    for (KiwiPath &_it : _data_fillGeometry) if (!_it.encode(_bb)) return false;
  }
  if (strokes() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeVarUint(_data_strokes.size());
    for (Paint &_it : _data_strokes) if (!_it.encode(_bb)) return false;
  }
  if (strokeStyleId() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeString(_data_strokeStyleId.c_str());
  }
  if (strokeWeight() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarFloat(_data_strokeWeight);
  }
  if (strokeJoin() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeJoin));
  }
  if (strokeAlign() != nullptr) {
    _bb.writeVarUint(10);
    _bb.writeVarUint(static_cast<uint32_t>(_data_strokeAlign));
  }
  if (dashPattern() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarUint(_data_dashPattern.size());
    for (float &_it : _data_dashPattern) _bb.writeVarFloat(_it);
  }
  if (strokeGeometry() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarUint(_data_strokeGeometry.size());
    for (KiwiPath &_it : _data_strokeGeometry) if (!_it.encode(_bb)) return false;
  }
  if (id() != nullptr) {
    _bb.writeVarUint(13);
    _bb.writeString(_data_id.c_str());
  }
  if (parent() != nullptr) {
    _bb.writeVarUint(14);
    if (!_data_parent->encode(_bb)) return false;
  }
  if (name() != nullptr) {
    _bb.writeVarUint(15);
    _bb.writeString(_data_name.c_str());
  }
  if (backgrounds() != nullptr) {
    _bb.writeVarUint(16);
    _bb.writeVarUint(_data_backgrounds.size());
    for (Paint &_it : _data_backgrounds) if (!_it.encode(_bb)) return false;
  }
  if (layoutMode() != nullptr) {
    _bb.writeVarUint(17);
    _bb.writeVarUint(static_cast<uint32_t>(_data_layoutMode));
  }
  if (primaryAxisSizingMode() != nullptr) {
    _bb.writeVarUint(18);
    _bb.writeVarUint(static_cast<uint32_t>(_data_primaryAxisSizingMode));
  }
  if (counterAxisSizingMode() != nullptr) {
    _bb.writeVarUint(19);
    _bb.writeVarUint(static_cast<uint32_t>(_data_counterAxisSizingMode));
  }
  if (primaryAxisAlignItems() != nullptr) {
    _bb.writeVarUint(20);
    _bb.writeVarUint(static_cast<uint32_t>(_data_primaryAxisAlignItems));
  }
  if (counterAxisAlignItems() != nullptr) {
    _bb.writeVarUint(21);
    _bb.writeVarUint(static_cast<uint32_t>(_data_counterAxisAlignItems));
  }
  if (paddingLeft() != nullptr) {
    _bb.writeVarUint(22);
    _bb.writeVarFloat(_data_paddingLeft);
  }
  if (paddingRight() != nullptr) {
    _bb.writeVarUint(23);
    _bb.writeVarFloat(_data_paddingRight);
  }
  if (paddingTop() != nullptr) {
    _bb.writeVarUint(24);
    _bb.writeVarFloat(_data_paddingTop);
  }
  if (paddingBottom() != nullptr) {
    _bb.writeVarUint(25);
    _bb.writeVarFloat(_data_paddingBottom);
  }
  if (itemSpacing() != nullptr) {
    _bb.writeVarUint(26);
    _bb.writeVarFloat(_data_itemSpacing);
  }
  if (itemReverseZIndex() != nullptr) {
    _bb.writeVarUint(27);
    _bb.writeByte(_data_itemReverseZIndex);
  }
  if (strokesIncludedInLayout() != nullptr) {
    _bb.writeVarUint(28);
    _bb.writeByte(_data_strokesIncludedInLayout);
  }
  if (horizontalPadding() != nullptr) {
    _bb.writeVarUint(29);
    _bb.writeVarFloat(_data_horizontalPadding);
  }
  if (verticalPadding() != nullptr) {
    _bb.writeVarUint(30);
    _bb.writeVarFloat(_data_verticalPadding);
  }
  if (clipsContent() != nullptr) {
    _bb.writeVarUint(31);
    _bb.writeByte(_data_clipsContent);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(32);
    _bb.writeByte(_data_visible);
  }
  if (locked() != nullptr) {
    _bb.writeVarUint(33);
    _bb.writeByte(_data_locked);
  }
  if (cornerRadius() != nullptr) {
    _bb.writeVarUint(34);
    _bb.writeVarFloat(_data_cornerRadius);
  }
  if (cornerSmoothing() != nullptr) {
    _bb.writeVarUint(35);
    _bb.writeVarFloat(_data_cornerSmoothing);
  }
  if (constraints() != nullptr) {
    _bb.writeVarUint(36);
    if (!_data_constraints->encode(_bb)) return false;
  }
  if (topLeftRadius() != nullptr) {
    _bb.writeVarUint(37);
    _bb.writeVarFloat(_data_topLeftRadius);
  }
  if (topRightRadius() != nullptr) {
    _bb.writeVarUint(38);
    _bb.writeVarFloat(_data_topRightRadius);
  }
  if (bottomLeftRadius() != nullptr) {
    _bb.writeVarUint(39);
    _bb.writeVarFloat(_data_bottomLeftRadius);
  }
  if (bottomRightRadius() != nullptr) {
    _bb.writeVarUint(40);
    _bb.writeVarFloat(_data_bottomRightRadius);
  }
  if (strokeTopWeight() != nullptr) {
    _bb.writeVarUint(41);
    _bb.writeVarFloat(_data_strokeTopWeight);
  }
  if (strokeBottomWeight() != nullptr) {
    _bb.writeVarUint(42);
    _bb.writeVarFloat(_data_strokeBottomWeight);
  }
  if (strokeLeftWeight() != nullptr) {
    _bb.writeVarUint(43);
    _bb.writeVarFloat(_data_strokeLeftWeight);
  }
  if (strokeRightWeight() != nullptr) {
    _bb.writeVarUint(44);
    _bb.writeVarFloat(_data_strokeRightWeight);
  }
  if (effects() != nullptr) {
    _bb.writeVarUint(45);
    _bb.writeVarUint(_data_effects.size());
    for (Effect &_it : _data_effects) if (!_it.encode(_bb)) return false;
  }
  if (effectStyleId() != nullptr) {
    _bb.writeVarUint(46);
    _bb.writeString(_data_effectStyleId.c_str());
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(47);
    _bb.writeVarFloat(_data_rotation);
  }
  if (layoutAlign() != nullptr) {
    _bb.writeVarUint(48);
    _bb.writeVarUint(static_cast<uint32_t>(_data_layoutAlign));
  }
  if (layoutGrow() != nullptr) {
    _bb.writeVarUint(49);
    _bb.writeVarUint(_data_layoutGrow);
  }
  if (width() != nullptr) {
    _bb.writeVarUint(50);
    _bb.writeVarFloat(_data_width);
  }
  if (height() != nullptr) {
    _bb.writeVarUint(51);
    _bb.writeVarFloat(_data_height);
  }
  if (transform() != nullptr) {
    _bb.writeVarUint(52);
    if (!_data_transform->encode(_bb)) return false;
  }
  _bb.writeVarUint(0);
  return true;
}

bool NodeChange::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_fills(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 2: {
        if (!_bb.readString(_data_fillStyleId, _pool)) return false;
        set_fillStyleId(_data_fillStyleId);
        break;
      }
      case 3: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeCap))) return false;
        set_strokeCap(_data_strokeCap);
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_strokeMiterLimit)) return false;
        set_strokeMiterLimit(_data_strokeMiterLimit);
        break;
      }
      case 5: {
        if (!_bb.readVarUint(_count)) return false;
        for (KiwiPath &_it : set_fillGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_strokes(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readString(_data_strokeStyleId, _pool)) return false;
        set_strokeStyleId(_data_strokeStyleId);
        break;
      }
      case 8: {
        if (!_bb.readVarFloat(_data_strokeWeight)) return false;
        set_strokeWeight(_data_strokeWeight);
        break;
      }
      case 9: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeJoin))) return false;
        set_strokeJoin(_data_strokeJoin);
        break;
      }
      case 10: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_strokeAlign))) return false;
        set_strokeAlign(_data_strokeAlign);
        break;
      }
      case 11: {
        if (!_bb.readVarUint(_count)) return false;
        for (float &_it : set_dashPattern(_pool, _count)) if (!_bb.readVarFloat(_it)) return false;
        break;
      }
      case 12: {
        if (!_bb.readVarUint(_count)) return false;
        for (KiwiPath &_it : set_strokeGeometry(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 13: {
        if (!_bb.readString(_data_id, _pool)) return false;
        set_id(_data_id);
        break;
      }
      case 14: {
        _data_parent = _pool.allocate<GUID>();
        if (!_data_parent->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 15: {
        if (!_bb.readString(_data_name, _pool)) return false;
        set_name(_data_name);
        break;
      }
      case 16: {
        if (!_bb.readVarUint(_count)) return false;
        for (Paint &_it : set_backgrounds(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 17: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_layoutMode))) return false;
        set_layoutMode(_data_layoutMode);
        break;
      }
      case 18: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_primaryAxisSizingMode))) return false;
        set_primaryAxisSizingMode(_data_primaryAxisSizingMode);
        break;
      }
      case 19: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_counterAxisSizingMode))) return false;
        set_counterAxisSizingMode(_data_counterAxisSizingMode);
        break;
      }
      case 20: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_primaryAxisAlignItems))) return false;
        set_primaryAxisAlignItems(_data_primaryAxisAlignItems);
        break;
      }
      case 21: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_counterAxisAlignItems))) return false;
        set_counterAxisAlignItems(_data_counterAxisAlignItems);
        break;
      }
      case 22: {
        if (!_bb.readVarFloat(_data_paddingLeft)) return false;
        set_paddingLeft(_data_paddingLeft);
        break;
      }
      case 23: {
        if (!_bb.readVarFloat(_data_paddingRight)) return false;
        set_paddingRight(_data_paddingRight);
        break;
      }
      case 24: {
        if (!_bb.readVarFloat(_data_paddingTop)) return false;
        set_paddingTop(_data_paddingTop);
        break;
      }
      case 25: {
        if (!_bb.readVarFloat(_data_paddingBottom)) return false;
        set_paddingBottom(_data_paddingBottom);
        break;
      }
      case 26: {
        if (!_bb.readVarFloat(_data_itemSpacing)) return false;
        set_itemSpacing(_data_itemSpacing);
        break;
      }
      case 27: {
        if (!_bb.readByte(_data_itemReverseZIndex)) return false;
        set_itemReverseZIndex(_data_itemReverseZIndex);
        break;
      }
      case 28: {
        if (!_bb.readByte(_data_strokesIncludedInLayout)) return false;
        set_strokesIncludedInLayout(_data_strokesIncludedInLayout);
        break;
      }
      case 29: {
        if (!_bb.readVarFloat(_data_horizontalPadding)) return false;
        set_horizontalPadding(_data_horizontalPadding);
        break;
      }
      case 30: {
        if (!_bb.readVarFloat(_data_verticalPadding)) return false;
        set_verticalPadding(_data_verticalPadding);
        break;
      }
      case 31: {
        if (!_bb.readByte(_data_clipsContent)) return false;
        set_clipsContent(_data_clipsContent);
        break;
      }
      case 32: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 33: {
        if (!_bb.readByte(_data_locked)) return false;
        set_locked(_data_locked);
        break;
      }
      case 34: {
        if (!_bb.readVarFloat(_data_cornerRadius)) return false;
        set_cornerRadius(_data_cornerRadius);
        break;
      }
      case 35: {
        if (!_bb.readVarFloat(_data_cornerSmoothing)) return false;
        set_cornerSmoothing(_data_cornerSmoothing);
        break;
      }
      case 36: {
        _data_constraints = _pool.allocate<Constraints>();
        if (!_data_constraints->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 37: {
        if (!_bb.readVarFloat(_data_topLeftRadius)) return false;
        set_topLeftRadius(_data_topLeftRadius);
        break;
      }
      case 38: {
        if (!_bb.readVarFloat(_data_topRightRadius)) return false;
        set_topRightRadius(_data_topRightRadius);
        break;
      }
      case 39: {
        if (!_bb.readVarFloat(_data_bottomLeftRadius)) return false;
        set_bottomLeftRadius(_data_bottomLeftRadius);
        break;
      }
      case 40: {
        if (!_bb.readVarFloat(_data_bottomRightRadius)) return false;
        set_bottomRightRadius(_data_bottomRightRadius);
        break;
      }
      case 41: {
        if (!_bb.readVarFloat(_data_strokeTopWeight)) return false;
        set_strokeTopWeight(_data_strokeTopWeight);
        break;
      }
      case 42: {
        if (!_bb.readVarFloat(_data_strokeBottomWeight)) return false;
        set_strokeBottomWeight(_data_strokeBottomWeight);
        break;
      }
      case 43: {
        if (!_bb.readVarFloat(_data_strokeLeftWeight)) return false;
        set_strokeLeftWeight(_data_strokeLeftWeight);
        break;
      }
      case 44: {
        if (!_bb.readVarFloat(_data_strokeRightWeight)) return false;
        set_strokeRightWeight(_data_strokeRightWeight);
        break;
      }
      case 45: {
        if (!_bb.readVarUint(_count)) return false;
        for (Effect &_it : set_effects(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 46: {
        if (!_bb.readString(_data_effectStyleId, _pool)) return false;
        set_effectStyleId(_data_effectStyleId);
        break;
      }
      case 47: {
        if (!_bb.readVarFloat(_data_rotation)) return false;
        set_rotation(_data_rotation);
        break;
      }
      case 48: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_layoutAlign))) return false;
        set_layoutAlign(_data_layoutAlign);
        break;
      }
      case 49: {
        if (!_bb.readVarUint(_data_layoutGrow)) return false;
        set_layoutGrow(_data_layoutGrow);
        break;
      }
      case 50: {
        if (!_bb.readVarFloat(_data_width)) return false;
        set_width(_data_width);
        break;
      }
      case 51: {
        if (!_bb.readVarFloat(_data_height)) return false;
        set_height(_data_height);
        break;
      }
      case 52: {
        _data_transform = _pool.allocate<Matrix>();
        if (!_data_transform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      default: {
        if (!_schema || !_schema->skipNodeChangeField(_bb, _type)) return false;
        break;
      }
    }
  }
}

PaintType *Paint::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const PaintType *Paint::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Paint::set_type(const PaintType &value) {
  _flags[0] |= 1; _data_type = value;
}

bool *Paint::visible() {
  return _flags[0] & 2 ? &_data_visible : nullptr;
}

const bool *Paint::visible() const {
  return _flags[0] & 2 ? &_data_visible : nullptr;
}

void Paint::set_visible(const bool &value) {
  _flags[0] |= 2; _data_visible = value;
}

float *Paint::opacity() {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

const float *Paint::opacity() const {
  return _flags[0] & 4 ? &_data_opacity : nullptr;
}

void Paint::set_opacity(const float &value) {
  _flags[0] |= 4; _data_opacity = value;
}

BlendMode *Paint::blendMode() {
  return _flags[0] & 8 ? &_data_blendMode : nullptr;
}

const BlendMode *Paint::blendMode() const {
  return _flags[0] & 8 ? &_data_blendMode : nullptr;
}

void Paint::set_blendMode(const BlendMode &value) {
  _flags[0] |= 8; _data_blendMode = value;
}

RGB *Paint::color() {
  return _data_color;
}

const RGB *Paint::color() const {
  return _data_color;
}

void Paint::set_color(RGB *value) {
  _data_color = value;
}

Matrix *Paint::gradientTransform() {
  return _data_gradientTransform;
}

const Matrix *Paint::gradientTransform() const {
  return _data_gradientTransform;
}

void Paint::set_gradientTransform(Matrix *value) {
  _data_gradientTransform = value;
}

kiwi::Array<ColorStop> *Paint::gradientStops() {
  return _flags[0] & 64 ? &_data_gradientStops : nullptr;
}

const kiwi::Array<ColorStop> *Paint::gradientStops() const {
  return _flags[0] & 64 ? &_data_gradientStops : nullptr;
}

kiwi::Array<ColorStop> &Paint::set_gradientStops(kiwi::MemoryPool &pool, uint32_t count) {
  _flags[0] |= 64; return _data_gradientStops = pool.array<ColorStop>(count);
}

ScaleMode *Paint::scaleMode() {
  return _flags[0] & 128 ? &_data_scaleMode : nullptr;
}

const ScaleMode *Paint::scaleMode() const {
  return _flags[0] & 128 ? &_data_scaleMode : nullptr;
}

void Paint::set_scaleMode(const ScaleMode &value) {
  _flags[0] |= 128; _data_scaleMode = value;
}

kiwi::String *Paint::imageHash() {
  return _flags[0] & 256 ? &_data_imageHash : nullptr;
}

const kiwi::String *Paint::imageHash() const {
  return _flags[0] & 256 ? &_data_imageHash : nullptr;
}

void Paint::set_imageHash(const kiwi::String &value) {
  _flags[0] |= 256; _data_imageHash = value;
}

Matrix *Paint::imageTransform() {
  return _data_imageTransform;
}

const Matrix *Paint::imageTransform() const {
  return _data_imageTransform;
}

void Paint::set_imageTransform(Matrix *value) {
  _data_imageTransform = value;
}

float *Paint::scalingFactor() {
  return _flags[0] & 1024 ? &_data_scalingFactor : nullptr;
}

const float *Paint::scalingFactor() const {
  return _flags[0] & 1024 ? &_data_scalingFactor : nullptr;
}

void Paint::set_scalingFactor(const float &value) {
  _flags[0] |= 1024; _data_scalingFactor = value;
}

float *Paint::rotation() {
  return _flags[0] & 2048 ? &_data_rotation : nullptr;
}

const float *Paint::rotation() const {
  return _flags[0] & 2048 ? &_data_rotation : nullptr;
}

void Paint::set_rotation(const float &value) {
  _flags[0] |= 2048; _data_rotation = value;
}

bool Paint::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(2);
    _bb.writeByte(_data_visible);
  }
  if (opacity() != nullptr) {
    _bb.writeVarUint(3);
    _bb.writeVarFloat(_data_opacity);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(5);
    if (!_data_color->encode(_bb)) return false;
  }
  if (gradientTransform() != nullptr) {
    _bb.writeVarUint(6);
    if (!_data_gradientTransform->encode(_bb)) return false;
  }
  if (gradientStops() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(_data_gradientStops.size());
    for (ColorStop &_it : _data_gradientStops) if (!_it.encode(_bb)) return false;
  }
  if (scaleMode() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeVarUint(static_cast<uint32_t>(_data_scaleMode));
  }
  if (imageHash() != nullptr) {
    _bb.writeVarUint(9);
    _bb.writeString(_data_imageHash.c_str());
  }
  if (imageTransform() != nullptr) {
    _bb.writeVarUint(10);
    if (!_data_imageTransform->encode(_bb)) return false;
  }
  if (scalingFactor() != nullptr) {
    _bb.writeVarUint(11);
    _bb.writeVarFloat(_data_scalingFactor);
  }
  if (rotation() != nullptr) {
    _bb.writeVarUint(12);
    _bb.writeVarFloat(_data_rotation);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Paint::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  uint32_t _count;
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 3: {
        if (!_bb.readVarFloat(_data_opacity)) return false;
        set_opacity(_data_opacity);
        break;
      }
      case 4: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 5: {
        _data_color = _pool.allocate<RGB>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 6: {
        _data_gradientTransform = _pool.allocate<Matrix>();
        if (!_data_gradientTransform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 7: {
        if (!_bb.readVarUint(_count)) return false;
        for (ColorStop &_it : set_gradientStops(_pool, _count)) if (!_it.decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 8: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_scaleMode))) return false;
        set_scaleMode(_data_scaleMode);
        break;
      }
      case 9: {
        if (!_bb.readString(_data_imageHash, _pool)) return false;
        set_imageHash(_data_imageHash);
        break;
      }
      case 10: {
        _data_imageTransform = _pool.allocate<Matrix>();
        if (!_data_imageTransform->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 11: {
        if (!_bb.readVarFloat(_data_scalingFactor)) return false;
        set_scalingFactor(_data_scalingFactor);
        break;
      }
      case 12: {
        if (!_bb.readVarFloat(_data_rotation)) return false;
        set_rotation(_data_rotation);
        break;
      }
      default: {
        if (!_schema || !_schema->skipPaintField(_bb, _type)) return false;
        break;
      }
    }
  }
}

EffectType *Effect::type() {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

const EffectType *Effect::type() const {
  return _flags[0] & 1 ? &_data_type : nullptr;
}

void Effect::set_type(const EffectType &value) {
  _flags[0] |= 1; _data_type = value;
}

RGBA *Effect::color() {
  return _data_color;
}

const RGBA *Effect::color() const {
  return _data_color;
}

void Effect::set_color(RGBA *value) {
  _data_color = value;
}

Vector *Effect::offset() {
  return _data_offset;
}

const Vector *Effect::offset() const {
  return _data_offset;
}

void Effect::set_offset(Vector *value) {
  _data_offset = value;
}

float *Effect::radius() {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

const float *Effect::radius() const {
  return _flags[0] & 8 ? &_data_radius : nullptr;
}

void Effect::set_radius(const float &value) {
  _flags[0] |= 8; _data_radius = value;
}

float *Effect::spread() {
  return _flags[0] & 16 ? &_data_spread : nullptr;
}

const float *Effect::spread() const {
  return _flags[0] & 16 ? &_data_spread : nullptr;
}

void Effect::set_spread(const float &value) {
  _flags[0] |= 16; _data_spread = value;
}

bool *Effect::visible() {
  return _flags[0] & 32 ? &_data_visible : nullptr;
}

const bool *Effect::visible() const {
  return _flags[0] & 32 ? &_data_visible : nullptr;
}

void Effect::set_visible(const bool &value) {
  _flags[0] |= 32; _data_visible = value;
}

BlendMode *Effect::blendMode() {
  return _flags[0] & 64 ? &_data_blendMode : nullptr;
}

const BlendMode *Effect::blendMode() const {
  return _flags[0] & 64 ? &_data_blendMode : nullptr;
}

void Effect::set_blendMode(const BlendMode &value) {
  _flags[0] |= 64; _data_blendMode = value;
}

bool *Effect::showShadowBehindNode() {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

const bool *Effect::showShadowBehindNode() const {
  return _flags[0] & 128 ? &_data_showShadowBehindNode : nullptr;
}

void Effect::set_showShadowBehindNode(const bool &value) {
  _flags[0] |= 128; _data_showShadowBehindNode = value;
}

bool Effect::encode(kiwi::ByteBuffer &_bb) {
  if (type() != nullptr) {
    _bb.writeVarUint(1);
    _bb.writeVarUint(static_cast<uint32_t>(_data_type));
  }
  if (color() != nullptr) {
    _bb.writeVarUint(2);
    if (!_data_color->encode(_bb)) return false;
  }
  if (offset() != nullptr) {
    _bb.writeVarUint(3);
    if (!_data_offset->encode(_bb)) return false;
  }
  if (radius() != nullptr) {
    _bb.writeVarUint(4);
    _bb.writeVarFloat(_data_radius);
  }
  if (spread() != nullptr) {
    _bb.writeVarUint(5);
    _bb.writeVarFloat(_data_spread);
  }
  if (visible() != nullptr) {
    _bb.writeVarUint(6);
    _bb.writeByte(_data_visible);
  }
  if (blendMode() != nullptr) {
    _bb.writeVarUint(7);
    _bb.writeVarUint(static_cast<uint32_t>(_data_blendMode));
  }
  if (showShadowBehindNode() != nullptr) {
    _bb.writeVarUint(8);
    _bb.writeByte(_data_showShadowBehindNode);
  }
  _bb.writeVarUint(0);
  return true;
}

bool Effect::decode(kiwi::ByteBuffer &_bb, kiwi::MemoryPool &_pool, const BinarySchema *_schema) {
  while (true) {
    uint32_t _type;
    if (!_bb.readVarUint(_type)) return false;
    switch (_type) {
      case 0:
        return true;
      case 1: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_type))) return false;
        set_type(_data_type);
        break;
      }
      case 2: {
        _data_color = _pool.allocate<RGBA>();
        if (!_data_color->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 3: {
        _data_offset = _pool.allocate<Vector>();
        if (!_data_offset->decode(_bb, _pool, _schema)) return false;
        break;
      }
      case 4: {
        if (!_bb.readVarFloat(_data_radius)) return false;
        set_radius(_data_radius);
        break;
      }
      case 5: {
        if (!_bb.readVarFloat(_data_spread)) return false;
        set_spread(_data_spread);
        break;
      }
      case 6: {
        if (!_bb.readByte(_data_visible)) return false;
        set_visible(_data_visible);
        break;
      }
      case 7: {
        if (!_bb.readVarUint(reinterpret_cast<uint32_t &>(_data_blendMode))) return false;
        set_blendMode(_data_blendMode);
        break;
      }
      case 8: {
        if (!_bb.readByte(_data_showShadowBehindNode)) return false;
        set_showShadowBehindNode(_data_showShadowBehindNode);
        break;
      }
      default: {
        if (!_schema || !_schema->skipEffectField(_bb, _type)) return false;
        break;
      }
    }
  }
}

#endif

}
