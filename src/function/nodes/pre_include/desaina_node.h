#include <string>
#include <vector>

#define IMPLEMENT_KIWI_H
#define IMPLEMENT_SCHEMA_H

#include "desaina_node_kiwi.h"

using uint = uint32_t;
using string = std::string;

class Effect;
class DropShadowEffect;
class InnerShadowEffect;
class BlurEffect;
class Paint;
class MinimalFillsMixin;
class DimensionAndPositionMixin;
class Constraints;
class ConstraintMixin;
class LayoutMixin;
class CornerMixin;
class RectangleCornerMixin;
class IndividualStrokesMixin;
class BaseNodeMixin;
class PageNode;
class SceneNodeMixin;
class KiwiPath;
class MinimalStrokesMixin;
class GeometryMixin;
class EffectMixin;
class DefaultShapeMixin;
class RectangleNode;
class BaseFrameMixin;
class DefaultFrameMixin;
class FrameNode;
class SolidPaint;
class GradientPaint;
class ImagePaint;
class VectorVertex;
class VectorSegment;
class VectorPath;

enum class NumberUnits {
  RAW,
  PIXELS,
  PERCENT,
};
enum class BlendMode {
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
};
enum class EffectType {
  DROP_SHADOW,
  INNER_SHADOW,
  LAYER_BLUR,
  BACKGROUND_BLUR,
};
enum class ConstraintType {
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
};
enum class LayoutAlignType {
  MIN,
  CENTER,
  MAX,
  STRETCH,
  SCALE,
  INHERIT,
};
enum class LayoutMode {
  NONE,
  HORIZONTAL,
  VERTICAL,
};
enum class AxisSizingMode {
  FIXED,
  AUTO,
};
enum class PrimaryAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  SPACE_BETWEEN,
};
enum class CounterAxisAlignItems {
  MIN,
  MAX,
  CENTER,
  BASELINE,
};
enum class PaintType {
  SOLID,
  GRADIENT_LINEAR,
  GRADIENT_RADIAL,
  GRADIENT_ANGULAR,
  GRADIENT_DIAMOND,
  IMAGE,
};
enum class ScaleMode {
  FILL,
  FIT,
  CROP,
  TILE,
};
enum class StrokeCap {
  NONE,
  ROUND,
  SQUARE,
  ARROW_LINES,
  ARROW_EQUILATERAL,
};
enum class StrokeJoin {
  MITER,
  BEVEL,
  ROUND,
};
enum class Align {
  CENTER,
  INSIDE,
  OUTSIDE,
};
enum class WindingRule {
  NONZERO,
  EVENODD,
};

struct Vector {
  float x = 0;
  float y = 0;
  void setWithKiwiData(const Desaina_Kiwi::Vector &kiwi_data) {
    if (kiwi_data.x() != nullptr) {
      x = *kiwi_data.x();
    }
    if (kiwi_data.y() != nullptr) {
      y = *kiwi_data.y();
    }
  }
};
struct Matrix {
  float m00 = 1;
  float m01 = 0;
  float m02 = 0;
  float m10 = 0;
  float m11 = 1;
  float m12 = 0;
  void setWithKiwiData(const Desaina_Kiwi::Matrix &kiwi_data) {
    if (kiwi_data.m00() != nullptr) {
      m00 = *kiwi_data.m00();
    }
    if (kiwi_data.m01() != nullptr) {
      m01 = *kiwi_data.m01();
    }
    if (kiwi_data.m02() != nullptr) {
      m02 = *kiwi_data.m02();
    }
    if (kiwi_data.m10() != nullptr) {
      m10 = *kiwi_data.m10();
    }
    if (kiwi_data.m11() != nullptr) {
      m11 = *kiwi_data.m11();
    }
    if (kiwi_data.m12() != nullptr) {
      m12 = *kiwi_data.m12();
    }
  }
};
struct KiwiNumber {
  float value = 0;
  NumberUnits units;
  void setWithKiwiData(const Desaina_Kiwi::KiwiNumber &kiwi_data) {
    if (kiwi_data.value() != nullptr) {
      value = *kiwi_data.value();
    }
    if (kiwi_data.units() != nullptr) {
      units = static_cast<NumberUnits>(*kiwi_data.units());
    }
  }
};
struct GUID {
  uint sessionId = 0;
  uint localId = 0;
  void setWithKiwiData(const Desaina_Kiwi::GUID &kiwi_data) {
    if (kiwi_data.sessionId() != nullptr) {
    }
    if (kiwi_data.localId() != nullptr) {
    }
  }
};
struct RGB {
  float r = 0;
  float g = 0;
  float b = 0;
  void setWithKiwiData(const Desaina_Kiwi::RGB &kiwi_data) {
    if (kiwi_data.r() != nullptr) {
      r = *kiwi_data.r();
    }
    if (kiwi_data.g() != nullptr) {
      g = *kiwi_data.g();
    }
    if (kiwi_data.b() != nullptr) {
      b = *kiwi_data.b();
    }
  }
};
struct RGBA {
  float r = 0;
  float g = 0;
  float b = 0;
  float a = 1;
  void setWithKiwiData(const Desaina_Kiwi::RGBA &kiwi_data) {
    if (kiwi_data.r() != nullptr) {
      r = *kiwi_data.r();
    }
    if (kiwi_data.g() != nullptr) {
      g = *kiwi_data.g();
    }
    if (kiwi_data.b() != nullptr) {
      b = *kiwi_data.b();
    }
    if (kiwi_data.a() != nullptr) {
      a = *kiwi_data.a();
    }
  }
};
struct ColorStop {
  float position = 0;
  RGBA color;
  void setWithKiwiData(const Desaina_Kiwi::ColorStop &kiwi_data) {
    if (kiwi_data.position() != nullptr) {
      position = *kiwi_data.position();
    }
    if (kiwi_data.color() != nullptr) {
      color.setWithKiwiData(*kiwi_data.color());
    }
  }
};

class Effect {
private:
  EffectType type;

public:
  EffectType get_type() { return type; };
  void set_type(const EffectType &value) { type = value; };
  void setWithKiwiData(const Desaina_Kiwi::Effect &kiwi_data) {
    if (kiwi_data.type() != nullptr) {
      type = static_cast<EffectType>(*kiwi_data.type());
    }
  }
};
class DropShadowEffect : public Effect {
private:
  RGBA color;
  Vector offset;
  float radius = 0;
  float spread = 0;
  bool visible = true;
  BlendMode blendMode;
  bool showShadowBehindNode;

public:
  RGBA get_color() { return color; };
  void set_color(const RGBA &value) { color = value; };
  Vector get_offset() { return offset; };
  void set_offset(const Vector &value) { offset = value; };
  float get_radius() { return radius; };
  void set_radius(const float &value) { radius = value; };
  float get_spread() { return spread; };
  void set_spread(const float &value) { spread = value; };
  bool get_visible() { return visible; };
  void set_visible(const bool &value) { visible = value; };
  BlendMode get_blendMode() { return blendMode; };
  void set_blendMode(const BlendMode &value) { blendMode = value; };
  bool get_showShadowBehindNode() { return showShadowBehindNode; };
  void set_showShadowBehindNode(const bool &value) {
    showShadowBehindNode = value;
  };
  void setWithKiwiData(const Desaina_Kiwi::Effect &kiwi_data) {
    if (kiwi_data.color() != nullptr) {
      color.setWithKiwiData(*kiwi_data.color());
    }
    if (kiwi_data.offset() != nullptr) {
      offset.setWithKiwiData(*kiwi_data.offset());
    }
    if (kiwi_data.radius() != nullptr) {
      radius = *kiwi_data.radius();
    }
    if (kiwi_data.spread() != nullptr) {
      spread = *kiwi_data.spread();
    }
    if (kiwi_data.visible() != nullptr) {
    }
    if (kiwi_data.blendMode() != nullptr) {
      blendMode = static_cast<BlendMode>(*kiwi_data.blendMode());
    }
    if (kiwi_data.showShadowBehindNode() != nullptr) {
    }
  }
};
class InnerShadowEffect : public Effect {
private:
  RGBA color;
  Vector offset;
  float radius = 10;
  float spread = 0;
  bool visible = true;
  BlendMode blendMode;

public:
  RGBA get_color() { return color; };
  void set_color(const RGBA &value) { color = value; };
  Vector get_offset() { return offset; };
  void set_offset(const Vector &value) { offset = value; };
  float get_radius() { return radius; };
  void set_radius(const float &value) { radius = value; };
  float get_spread() { return spread; };
  void set_spread(const float &value) { spread = value; };
  bool get_visible() { return visible; };
  void set_visible(const bool &value) { visible = value; };
  BlendMode get_blendMode() { return blendMode; };
  void set_blendMode(const BlendMode &value) { blendMode = value; };
  void setWithKiwiData(const Desaina_Kiwi::Effect &kiwi_data) {
    if (kiwi_data.color() != nullptr) {
      color.setWithKiwiData(*kiwi_data.color());
    }
    if (kiwi_data.offset() != nullptr) {
      offset.setWithKiwiData(*kiwi_data.offset());
    }
    if (kiwi_data.radius() != nullptr) {
      radius = *kiwi_data.radius();
    }
    if (kiwi_data.spread() != nullptr) {
      spread = *kiwi_data.spread();
    }
    if (kiwi_data.visible() != nullptr) {
    }
    if (kiwi_data.blendMode() != nullptr) {
      blendMode = static_cast<BlendMode>(*kiwi_data.blendMode());
    }
  }
};
class BlurEffect : public Effect {
private:
  float radius = 10;
  bool visible = true;

public:
  float get_radius() { return radius; };
  void set_radius(const float &value) { radius = value; };
  bool get_visible() { return visible; };
  void set_visible(const bool &value) { visible = value; };
  void setWithKiwiData(const Desaina_Kiwi::Effect &kiwi_data) {
    if (kiwi_data.radius() != nullptr) {
      radius = *kiwi_data.radius();
    }
    if (kiwi_data.visible() != nullptr) {
    }
  }
};
class Paint {
private:
  PaintType type;
  bool visible = true;
  float opacity = 1;
  BlendMode blendMode;

public:
  PaintType get_type() { return type; };
  void set_type(const PaintType &value) { type = value; };
  bool get_visible() { return visible; };
  void set_visible(const bool &value) { visible = value; };
  float get_opacity() { return opacity; };
  void set_opacity(const float &value) { opacity = value; };
  BlendMode get_blendMode() { return blendMode; };
  void set_blendMode(const BlendMode &value) { blendMode = value; };
  void setWithKiwiData(const Desaina_Kiwi::Paint &kiwi_data) {
    if (kiwi_data.type() != nullptr) {
      type = static_cast<PaintType>(*kiwi_data.type());
    }
    if (kiwi_data.visible() != nullptr) {
    }
    if (kiwi_data.opacity() != nullptr) {
      opacity = *kiwi_data.opacity();
    }
    if (kiwi_data.blendMode() != nullptr) {
      blendMode = static_cast<BlendMode>(*kiwi_data.blendMode());
    }
  }
};
class MinimalFillsMixin {
private:
  std::vector<Paint> fills;
  string fillStyleId;

public:
  std::vector<Paint> get_fills() { return fills; };
  void set_fills(const std::vector<Paint> &value) { fills = value; };
  string get_fillStyleId() { return fillStyleId; };
  void set_fillStyleId(const string &value) { fillStyleId = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.fills() != nullptr) {
      fills.clear();
      for (auto &item : *kiwi_data.fills()) {
        fills.push_back(Paint());
        fills.back().setWithKiwiData(item);
      }
    }
    if (kiwi_data.fillStyleId() != nullptr) {
      fillStyleId = *kiwi_data.fillStyleId()->c_str();
    }
  }
};
class DimensionAndPositionMixin {
private:
  float width = 100;
  float height = 100;
  Matrix transform;

public:
  float get_width() { return width; };
  void set_width(const float &value) { width = value; };
  float get_height() { return height; };
  void set_height(const float &value) { height = value; };
  Matrix get_transform() { return transform; };
  void set_transform(const Matrix &value) { transform = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.width() != nullptr) {
      width = *kiwi_data.width();
    }
    if (kiwi_data.height() != nullptr) {
      height = *kiwi_data.height();
    }
    if (kiwi_data.transform() != nullptr) {
      transform.setWithKiwiData(*kiwi_data.transform());
    }
  }
};
class Constraints {
private:
  ConstraintType horizontal;
  ConstraintType vertical;

public:
  ConstraintType get_horizontal() { return horizontal; };
  void set_horizontal(const ConstraintType &value) { horizontal = value; };
  ConstraintType get_vertical() { return vertical; };
  void set_vertical(const ConstraintType &value) { vertical = value; };
  void setWithKiwiData(const Desaina_Kiwi::Constraints &kiwi_data) {
    if (kiwi_data.horizontal() != nullptr) {
      horizontal = static_cast<ConstraintType>(*kiwi_data.horizontal());
    }
    if (kiwi_data.vertical() != nullptr) {
      vertical = static_cast<ConstraintType>(*kiwi_data.vertical());
    }
  }
};
class ConstraintMixin {
private:
  Constraints constraints;

public:
  Constraints get_constraints() { return constraints; };
  void set_constraints(const Constraints &value) { constraints = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.constraints() != nullptr) {
      constraints.setWithKiwiData(*kiwi_data.constraints());
    }
  }
};
class LayoutMixin : public DimensionAndPositionMixin {
private:
  float rotation = 0;
  LayoutAlignType layoutAlign;
  uint layoutGrow;

public:
  float get_rotation() { return rotation; };
  void set_rotation(const float &value) { rotation = value; };
  LayoutAlignType get_layoutAlign() { return layoutAlign; };
  void set_layoutAlign(const LayoutAlignType &value) { layoutAlign = value; };
  uint get_layoutGrow() { return layoutGrow; };
  void set_layoutGrow(const uint &value) { layoutGrow = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.rotation() != nullptr) {
      rotation = *kiwi_data.rotation();
    }
    if (kiwi_data.layoutAlign() != nullptr) {
      layoutAlign = static_cast<LayoutAlignType>(*kiwi_data.layoutAlign());
    }
    if (kiwi_data.layoutGrow() != nullptr) {
    }
  }
};
class CornerMixin {
private:
  float cornerRadius = 0;
  float cornerSmoothing = 0;

public:
  float get_cornerRadius() { return cornerRadius; };
  void set_cornerRadius(const float &value) { cornerRadius = value; };
  float get_cornerSmoothing() { return cornerSmoothing; };
  void set_cornerSmoothing(const float &value) { cornerSmoothing = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.cornerRadius() != nullptr) {
      cornerRadius = *kiwi_data.cornerRadius();
    }
    if (kiwi_data.cornerSmoothing() != nullptr) {
      cornerSmoothing = *kiwi_data.cornerSmoothing();
    }
  }
};
class RectangleCornerMixin {
private:
  float topLeftRadius = 0;
  float topRightRadius = 0;
  float bottomLeftRadius = 0;
  float bottomRightRadius = 0;

public:
  float get_topLeftRadius() { return topLeftRadius; };
  void set_topLeftRadius(const float &value) { topLeftRadius = value; };
  float get_topRightRadius() { return topRightRadius; };
  void set_topRightRadius(const float &value) { topRightRadius = value; };
  float get_bottomLeftRadius() { return bottomLeftRadius; };
  void set_bottomLeftRadius(const float &value) { bottomLeftRadius = value; };
  float get_bottomRightRadius() { return bottomRightRadius; };
  void set_bottomRightRadius(const float &value) { bottomRightRadius = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.topLeftRadius() != nullptr) {
      topLeftRadius = *kiwi_data.topLeftRadius();
    }
    if (kiwi_data.topRightRadius() != nullptr) {
      topRightRadius = *kiwi_data.topRightRadius();
    }
    if (kiwi_data.bottomLeftRadius() != nullptr) {
      bottomLeftRadius = *kiwi_data.bottomLeftRadius();
    }
    if (kiwi_data.bottomRightRadius() != nullptr) {
      bottomRightRadius = *kiwi_data.bottomRightRadius();
    }
  }
};
class IndividualStrokesMixin {
private:
  float strokeTopWeight = 0;
  float strokeBottomWeight = 0;
  float strokeLeftWeight = 0;
  float strokeRightWeight = 0;

public:
  float get_strokeTopWeight() { return strokeTopWeight; };
  void set_strokeTopWeight(const float &value) { strokeTopWeight = value; };
  float get_strokeBottomWeight() { return strokeBottomWeight; };
  void set_strokeBottomWeight(const float &value) {
    strokeBottomWeight = value;
  };
  float get_strokeLeftWeight() { return strokeLeftWeight; };
  void set_strokeLeftWeight(const float &value) { strokeLeftWeight = value; };
  float get_strokeRightWeight() { return strokeRightWeight; };
  void set_strokeRightWeight(const float &value) { strokeRightWeight = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.strokeTopWeight() != nullptr) {
      strokeTopWeight = *kiwi_data.strokeTopWeight();
    }
    if (kiwi_data.strokeBottomWeight() != nullptr) {
      strokeBottomWeight = *kiwi_data.strokeBottomWeight();
    }
    if (kiwi_data.strokeLeftWeight() != nullptr) {
      strokeLeftWeight = *kiwi_data.strokeLeftWeight();
    }
    if (kiwi_data.strokeRightWeight() != nullptr) {
      strokeRightWeight = *kiwi_data.strokeRightWeight();
    }
  }
};
class BaseNodeMixin {
private:
  string id;
  GUID parent;
  string name;

public:
  string get_id() { return id; };
  void set_id(const string &value) { id = value; };
  GUID get_parent() { return parent; };
  void set_parent(const GUID &value) { parent = value; };
  string get_name() { return name; };
  void set_name(const string &value) { name = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.id() != nullptr) {
      id = *kiwi_data.id()->c_str();
    }
    if (kiwi_data.parent() != nullptr) {
      parent.setWithKiwiData(*kiwi_data.parent());
    }
    if (kiwi_data.name() != nullptr) {
      name = *kiwi_data.name()->c_str();
    }
  }
};
class PageNode : public BaseNodeMixin {
private:
  std::vector<Paint> backgrounds;

public:
  std::vector<Paint> get_backgrounds() { return backgrounds; };
  void set_backgrounds(const std::vector<Paint> &value) {
    backgrounds = value;
  };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.backgrounds() != nullptr) {
      backgrounds.clear();
      for (auto &item : *kiwi_data.backgrounds()) {
        backgrounds.push_back(Paint());
        backgrounds.back().setWithKiwiData(item);
      }
    }
  }
};
class SceneNodeMixin {
private:
  bool visible = true;
  bool locked;

public:
  bool get_visible() { return visible; };
  void set_visible(const bool &value) { visible = value; };
  bool get_locked() { return locked; };
  void set_locked(const bool &value) { locked = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.visible() != nullptr) {
    }
    if (kiwi_data.locked() != nullptr) {
    }
  }
};
class KiwiPath {
private:
  WindingRule windingRule;
  uint commandsBlob = 0;
  uint styleID = 0;

public:
  WindingRule get_windingRule() { return windingRule; };
  void set_windingRule(const WindingRule &value) { windingRule = value; };
  uint get_commandsBlob() { return commandsBlob; };
  void set_commandsBlob(const uint &value) { commandsBlob = value; };
  uint get_styleID() { return styleID; };
  void set_styleID(const uint &value) { styleID = value; };
  void setWithKiwiData(const Desaina_Kiwi::KiwiPath &kiwi_data) {
    if (kiwi_data.windingRule() != nullptr) {
      windingRule = static_cast<WindingRule>(*kiwi_data.windingRule());
    }
    if (kiwi_data.commandsBlob() != nullptr) {
    }
    if (kiwi_data.styleID() != nullptr) {
    }
  }
};
class MinimalStrokesMixin {
private:
  std::vector<Paint> strokes;
  string strokeStyleId;
  float strokeWeight;
  StrokeJoin strokeJoin;
  Align strokeAlign;
  std::vector<float> dashPattern;
  std::vector<KiwiPath> strokeGeometry;

public:
  std::vector<Paint> get_strokes() { return strokes; };
  void set_strokes(const std::vector<Paint> &value) { strokes = value; };
  string get_strokeStyleId() { return strokeStyleId; };
  void set_strokeStyleId(const string &value) { strokeStyleId = value; };
  float get_strokeWeight() { return strokeWeight; };
  void set_strokeWeight(const float &value) { strokeWeight = value; };
  StrokeJoin get_strokeJoin() { return strokeJoin; };
  void set_strokeJoin(const StrokeJoin &value) { strokeJoin = value; };
  Align get_strokeAlign() { return strokeAlign; };
  void set_strokeAlign(const Align &value) { strokeAlign = value; };
  std::vector<float> get_dashPattern() { return dashPattern; };
  void set_dashPattern(const std::vector<float> &value) {
    dashPattern = value;
  };
  std::vector<KiwiPath> get_strokeGeometry() { return strokeGeometry; };
  void set_strokeGeometry(const std::vector<KiwiPath> &value) {
    strokeGeometry = value;
  };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.strokes() != nullptr) {
      strokes.clear();
      for (auto &item : *kiwi_data.strokes()) {
        strokes.push_back(Paint());
        strokes.back().setWithKiwiData(item);
      }
    }
    if (kiwi_data.strokeStyleId() != nullptr) {
      strokeStyleId = *kiwi_data.strokeStyleId()->c_str();
    }
    if (kiwi_data.strokeWeight() != nullptr) {
      strokeWeight = *kiwi_data.strokeWeight();
    }
    if (kiwi_data.strokeJoin() != nullptr) {
      strokeJoin = static_cast<StrokeJoin>(*kiwi_data.strokeJoin());
    }
    if (kiwi_data.strokeAlign() != nullptr) {
      strokeAlign = static_cast<Align>(*kiwi_data.strokeAlign());
    }
    if (kiwi_data.dashPattern() != nullptr) {
      dashPattern.clear();
      for (auto &item : *kiwi_data.dashPattern()) {
        dashPattern.push_back(item);
      }
    }
    if (kiwi_data.strokeGeometry() != nullptr) {
      strokeGeometry.clear();
      for (auto &item : *kiwi_data.strokeGeometry()) {
        strokeGeometry.push_back(KiwiPath());
        strokeGeometry.back().setWithKiwiData(item);
      }
    }
  }
};
class GeometryMixin : public MinimalStrokesMixin, MinimalFillsMixin {
private:
  StrokeCap strokeCap;
  float strokeMiterLimit = 0;
  std::vector<KiwiPath> fillGeometry;

public:
  StrokeCap get_strokeCap() { return strokeCap; };
  void set_strokeCap(const StrokeCap &value) { strokeCap = value; };
  float get_strokeMiterLimit() { return strokeMiterLimit; };
  void set_strokeMiterLimit(const float &value) { strokeMiterLimit = value; };
  std::vector<KiwiPath> get_fillGeometry() { return fillGeometry; };
  void set_fillGeometry(const std::vector<KiwiPath> &value) {
    fillGeometry = value;
  };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.strokeCap() != nullptr) {
      strokeCap = static_cast<StrokeCap>(*kiwi_data.strokeCap());
    }
    if (kiwi_data.strokeMiterLimit() != nullptr) {
      strokeMiterLimit = *kiwi_data.strokeMiterLimit();
    }
    if (kiwi_data.fillGeometry() != nullptr) {
      fillGeometry.clear();
      for (auto &item : *kiwi_data.fillGeometry()) {
        fillGeometry.push_back(KiwiPath());
        fillGeometry.back().setWithKiwiData(item);
      }
    }
  }
};
class EffectMixin {
private:
  std::vector<Effect> effects;
  string effectStyleId;

public:
  std::vector<Effect> get_effects() { return effects; };
  void set_effects(const std::vector<Effect> &value) { effects = value; };
  string get_effectStyleId() { return effectStyleId; };
  void set_effectStyleId(const string &value) { effectStyleId = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.effects() != nullptr) {
      effects.clear();
      for (auto &item : *kiwi_data.effects()) {
        effects.push_back(Effect());
        effects.back().setWithKiwiData(item);
      }
    }
    if (kiwi_data.effectStyleId() != nullptr) {
      effectStyleId = *kiwi_data.effectStyleId()->c_str();
    }
  }
};
class DefaultShapeMixin : public BaseNodeMixin,
                          SceneNodeMixin,
                          LayoutMixin,
                          EffectMixin,
                          GeometryMixin {
private:
public:
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {}
};
class RectangleNode : public DefaultShapeMixin,
                      ConstraintMixin,
                      CornerMixin,
                      RectangleCornerMixin,
                      IndividualStrokesMixin {
private:
public:
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {}
};
class BaseFrameMixin : public BaseNodeMixin,
                       SceneNodeMixin,
                       GeometryMixin,
                       CornerMixin,
                       RectangleCornerMixin,
                       EffectMixin,
                       ConstraintMixin,
                       LayoutMixin,
                       IndividualStrokesMixin {
private:
  LayoutMode layoutMode;
  AxisSizingMode primaryAxisSizingMode;
  AxisSizingMode counterAxisSizingMode;
  PrimaryAxisAlignItems primaryAxisAlignItems;
  CounterAxisAlignItems counterAxisAlignItems;
  float paddingLeft = 0;
  float paddingRight = 0;
  float paddingTop = 0;
  float paddingBottom = 0;
  float itemSpacing = 0;
  bool itemReverseZIndex;
  bool strokesIncludedInLayout;
  float horizontalPadding = 0;
  float verticalPadding = 0;
  bool clipsContent = true;

public:
  LayoutMode get_layoutMode() { return layoutMode; };
  void set_layoutMode(const LayoutMode &value) { layoutMode = value; };
  AxisSizingMode get_primaryAxisSizingMode() { return primaryAxisSizingMode; };
  void set_primaryAxisSizingMode(const AxisSizingMode &value) {
    primaryAxisSizingMode = value;
  };
  AxisSizingMode get_counterAxisSizingMode() { return counterAxisSizingMode; };
  void set_counterAxisSizingMode(const AxisSizingMode &value) {
    counterAxisSizingMode = value;
  };
  PrimaryAxisAlignItems get_primaryAxisAlignItems() {
    return primaryAxisAlignItems;
  };
  void set_primaryAxisAlignItems(const PrimaryAxisAlignItems &value) {
    primaryAxisAlignItems = value;
  };
  CounterAxisAlignItems get_counterAxisAlignItems() {
    return counterAxisAlignItems;
  };
  void set_counterAxisAlignItems(const CounterAxisAlignItems &value) {
    counterAxisAlignItems = value;
  };
  float get_paddingLeft() { return paddingLeft; };
  void set_paddingLeft(const float &value) { paddingLeft = value; };
  float get_paddingRight() { return paddingRight; };
  void set_paddingRight(const float &value) { paddingRight = value; };
  float get_paddingTop() { return paddingTop; };
  void set_paddingTop(const float &value) { paddingTop = value; };
  float get_paddingBottom() { return paddingBottom; };
  void set_paddingBottom(const float &value) { paddingBottom = value; };
  float get_itemSpacing() { return itemSpacing; };
  void set_itemSpacing(const float &value) { itemSpacing = value; };
  bool get_itemReverseZIndex() { return itemReverseZIndex; };
  void set_itemReverseZIndex(const bool &value) { itemReverseZIndex = value; };
  bool get_strokesIncludedInLayout() { return strokesIncludedInLayout; };
  void set_strokesIncludedInLayout(const bool &value) {
    strokesIncludedInLayout = value;
  };
  float get_horizontalPadding() { return horizontalPadding; };
  void set_horizontalPadding(const float &value) { horizontalPadding = value; };
  float get_verticalPadding() { return verticalPadding; };
  void set_verticalPadding(const float &value) { verticalPadding = value; };
  bool get_clipsContent() { return clipsContent; };
  void set_clipsContent(const bool &value) { clipsContent = value; };
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {
    if (kiwi_data.layoutMode() != nullptr) {
      layoutMode = static_cast<LayoutMode>(*kiwi_data.layoutMode());
    }
    if (kiwi_data.primaryAxisSizingMode() != nullptr) {
      primaryAxisSizingMode =
          static_cast<AxisSizingMode>(*kiwi_data.primaryAxisSizingMode());
    }
    if (kiwi_data.counterAxisSizingMode() != nullptr) {
      counterAxisSizingMode =
          static_cast<AxisSizingMode>(*kiwi_data.counterAxisSizingMode());
    }
    if (kiwi_data.primaryAxisAlignItems() != nullptr) {
      primaryAxisAlignItems = static_cast<PrimaryAxisAlignItems>(
          *kiwi_data.primaryAxisAlignItems());
    }
    if (kiwi_data.counterAxisAlignItems() != nullptr) {
      counterAxisAlignItems = static_cast<CounterAxisAlignItems>(
          *kiwi_data.counterAxisAlignItems());
    }
    if (kiwi_data.paddingLeft() != nullptr) {
      paddingLeft = *kiwi_data.paddingLeft();
    }
    if (kiwi_data.paddingRight() != nullptr) {
      paddingRight = *kiwi_data.paddingRight();
    }
    if (kiwi_data.paddingTop() != nullptr) {
      paddingTop = *kiwi_data.paddingTop();
    }
    if (kiwi_data.paddingBottom() != nullptr) {
      paddingBottom = *kiwi_data.paddingBottom();
    }
    if (kiwi_data.itemSpacing() != nullptr) {
      itemSpacing = *kiwi_data.itemSpacing();
    }
    if (kiwi_data.itemReverseZIndex() != nullptr) {
    }
    if (kiwi_data.strokesIncludedInLayout() != nullptr) {
    }
    if (kiwi_data.horizontalPadding() != nullptr) {
      horizontalPadding = *kiwi_data.horizontalPadding();
    }
    if (kiwi_data.verticalPadding() != nullptr) {
      verticalPadding = *kiwi_data.verticalPadding();
    }
    if (kiwi_data.clipsContent() != nullptr) {
    }
  }
};
class DefaultFrameMixin : public BaseFrameMixin {
private:
public:
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {}
};
class FrameNode : public DefaultFrameMixin {
private:
public:
  void setWithKiwiData(const Desaina_Kiwi::NodeChange &kiwi_data) {}
};
class SolidPaint : public Paint {
private:
  RGB color;

public:
  RGB get_color() { return color; };
  void set_color(const RGB &value) { color = value; };
  void setWithKiwiData(const Desaina_Kiwi::Paint &kiwi_data) {
    if (kiwi_data.color() != nullptr) {
      color.setWithKiwiData(*kiwi_data.color());
    }
  }
};
class GradientPaint : public Paint {
private:
  Matrix gradientTransform;
  std::vector<ColorStop> gradientStops;

public:
  Matrix get_gradientTransform() { return gradientTransform; };
  void set_gradientTransform(const Matrix &value) {
    gradientTransform = value;
  };
  std::vector<ColorStop> get_gradientStops() { return gradientStops; };
  void set_gradientStops(const std::vector<ColorStop> &value) {
    gradientStops = value;
  };
  void setWithKiwiData(const Desaina_Kiwi::Paint &kiwi_data) {
    if (kiwi_data.gradientTransform() != nullptr) {
      gradientTransform.setWithKiwiData(*kiwi_data.gradientTransform());
    }
    if (kiwi_data.gradientStops() != nullptr) {
      gradientStops.clear();
      for (auto &item : *kiwi_data.gradientStops()) {
        gradientStops.push_back(ColorStop());
        gradientStops.back().setWithKiwiData(item);
      }
    }
  }
};
class ImagePaint : public Paint {
private:
  ScaleMode scaleMode;
  string imageHash;
  Matrix imageTransform;
  float scalingFactor;
  float rotation;

public:
  ScaleMode get_scaleMode() { return scaleMode; };
  void set_scaleMode(const ScaleMode &value) { scaleMode = value; };
  string get_imageHash() { return imageHash; };
  void set_imageHash(const string &value) { imageHash = value; };
  Matrix get_imageTransform() { return imageTransform; };
  void set_imageTransform(const Matrix &value) { imageTransform = value; };
  float get_scalingFactor() { return scalingFactor; };
  void set_scalingFactor(const float &value) { scalingFactor = value; };
  float get_rotation() { return rotation; };
  void set_rotation(const float &value) { rotation = value; };
  void setWithKiwiData(const Desaina_Kiwi::Paint &kiwi_data) {
    if (kiwi_data.scaleMode() != nullptr) {
      scaleMode = static_cast<ScaleMode>(*kiwi_data.scaleMode());
    }
    if (kiwi_data.imageHash() != nullptr) {
      imageHash = *kiwi_data.imageHash()->c_str();
    }
    if (kiwi_data.imageTransform() != nullptr) {
      imageTransform.setWithKiwiData(*kiwi_data.imageTransform());
    }
    if (kiwi_data.scalingFactor() != nullptr) {
      scalingFactor = *kiwi_data.scalingFactor();
    }
    if (kiwi_data.rotation() != nullptr) {
      rotation = *kiwi_data.rotation();
    }
  }
};
class VectorVertex {
private:
  float x = 0;
  float y = 0;
  StrokeCap strokeCap;
  StrokeJoin strokeJoin;
  float cornerRadius = 0;

public:
  float get_x() { return x; };
  void set_x(const float &value) { x = value; };
  float get_y() { return y; };
  void set_y(const float &value) { y = value; };
  StrokeCap get_strokeCap() { return strokeCap; };
  void set_strokeCap(const StrokeCap &value) { strokeCap = value; };
  StrokeJoin get_strokeJoin() { return strokeJoin; };
  void set_strokeJoin(const StrokeJoin &value) { strokeJoin = value; };
  float get_cornerRadius() { return cornerRadius; };
  void set_cornerRadius(const float &value) { cornerRadius = value; };
  void setWithKiwiData(const Desaina_Kiwi::VectorVertex &kiwi_data) {
    if (kiwi_data.x() != nullptr) {
      x = *kiwi_data.x();
    }
    if (kiwi_data.y() != nullptr) {
      y = *kiwi_data.y();
    }
    if (kiwi_data.strokeCap() != nullptr) {
      strokeCap = static_cast<StrokeCap>(*kiwi_data.strokeCap());
    }
    if (kiwi_data.strokeJoin() != nullptr) {
      strokeJoin = static_cast<StrokeJoin>(*kiwi_data.strokeJoin());
    }
    if (kiwi_data.cornerRadius() != nullptr) {
      cornerRadius = *kiwi_data.cornerRadius();
    }
  }
};
class VectorSegment {
private:
  float start = 0;
  float end = 0;
  Vector tangentStart;
  Vector tangentEnd;

public:
  float get_start() { return start; };
  void set_start(const float &value) { start = value; };
  float get_end() { return end; };
  void set_end(const float &value) { end = value; };
  Vector get_tangentStart() { return tangentStart; };
  void set_tangentStart(const Vector &value) { tangentStart = value; };
  Vector get_tangentEnd() { return tangentEnd; };
  void set_tangentEnd(const Vector &value) { tangentEnd = value; };
  void setWithKiwiData(const Desaina_Kiwi::VectorSegment &kiwi_data) {
    if (kiwi_data.start() != nullptr) {
      start = *kiwi_data.start();
    }
    if (kiwi_data.end() != nullptr) {
      end = *kiwi_data.end();
    }
    if (kiwi_data.tangentStart() != nullptr) {
      tangentStart.setWithKiwiData(*kiwi_data.tangentStart());
    }
    if (kiwi_data.tangentEnd() != nullptr) {
      tangentEnd.setWithKiwiData(*kiwi_data.tangentEnd());
    }
  }
};
class VectorPath {
private:
  WindingRule windingRule;
  string data;

public:
  WindingRule get_windingRule() { return windingRule; };
  void set_windingRule(const WindingRule &value) { windingRule = value; };
  string get_data() { return data; };
  void set_data(const string &value) { data = value; };
  void setWithKiwiData(const Desaina_Kiwi::VectorPath &kiwi_data) {
    if (kiwi_data.windingRule() != nullptr) {
      windingRule = static_cast<WindingRule>(*kiwi_data.windingRule());
    }
    if (kiwi_data.data() != nullptr) {
      data = *kiwi_data.data()->c_str();
    }
  }
};
