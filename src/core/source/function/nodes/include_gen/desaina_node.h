#pragma once

#include <string>
#include <vector>
#include <variant>

using  uint = uint32_t;
using string = std::string;

class NodePool;

#include "buffer.h"
#include "change/change_type.h"

class NodeBase;
class BaseNodeMixin;
class SceneNodeMixin;
class CornerMixin;
class RectangleCornerMixin;
class IndividualStrokesMixin;
class DimensionAndPositionMixin;
class ConstraintMixin;
class ExportMixin;
class BlendMixin;
class AutoLayoutMixin;
class PageNodeBase;
class DocumentNodeBase;
class LayoutMixin;
class SymbolData;
class DropShadowEffect;
class InnerShadowEffect;
class BlurEffect;
class SolidPaint;
class GradientPaint;
class ImagePaint;
class MinimalStrokesMixin;
class MinimalFillsMixin;
class GeometryMixin;
class DefaultShapeNode;
class RectangleNodeBase;
class LineNodeBase;
class EllipseNodeBase;
class PolygonNodeBase;
class StarNodeBase;
class VectorNodeBase;
class SubTextMixin;
class TextNodeMixin;
class EffectMixin;
class BaseFrameMixin;
class DefaultFrameMixin;
class FrameNodeBase;
class SymbolNodeBase;
class InstanceNodeBase;
class Decoration;
class TextData;
class TextNodeBase;

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
enum class PaintType {
	SOLID,
	GRADIENT_LINEAR,
	GRADIENT_RADIAL,
	GRADIENT_ANGULAR,
	GRADIENT_DIAMOND,
	IMAGE,
};
enum class ImageScaleMode {
	STRETCH,
	FIT,
	FILL,
	TILE,
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
enum class StackMode {
	NONE,
	HORIZONTAL,
	VERTICAL,
};
enum class StackWrap {
	NO_WRAP,
	WRAP,
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
enum class CounterAxisAlignContent {
	AUTO,
	SPACE_BETWEEN,
};
enum class NodeType {
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
	REGULAR_POLYGON,
	ROUNDED_RECTANGLE,
	TEXT,
	SLICE,
	SYMBOL,
	INSTANCE,
	STICKY,
	SHAPE_WITH_TEXT,
	CONNECTOR,
	CODE_BLOCK,
	WIDGET,
	STAMP,
	MEDIA,
	HIGHLIGHT,
	SECTION,
	SECTION_OVERLAY,
	WASHI_TAPE,
	VARIABLE,
	TABLE,
	TABLE_CELL,
	VARIABLE_SET,
	SLIDE,
};
enum class MessageType {
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
enum class StrokeAlign {
	CENTER,
	INSIDE,
	OUTSIDE,
};
enum class WindingRule {
	NONZERO,
	EVENODD,
	NONE,
};

struct GUID {
	uint sessionID = 0;
	uint localID = 0;
void applyChange(const Desaina_Kiwi::GUID& change) {
	if (change.sessionID() != nullptr) {
    applyChangeImpl(sessionID, *change.sessionID());
	}
	if (change.localID() != nullptr) {
    applyChangeImpl(localID, *change.localID());
	}
}

void toChange(Desaina_Kiwi::GUID& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::GUID::set_sessionID, sessionID, pool);
  toChangeImpl(&change, &Desaina_Kiwi::GUID::set_localID, localID, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::GUID>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct ParentIndex {
	GUID guid;
	string position;
void applyChange(const Desaina_Kiwi::ParentIndex& change) {
	if (change.guid() != nullptr) {
    applyChangeImpl(guid, *change.guid());
	}
	if (change.position() != nullptr) {
    applyChangeImpl(position, *change.position());
	}
}

void toChange(Desaina_Kiwi::ParentIndex& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::ParentIndex::set_guid, guid, pool);
  toChangeImpl(&change, &Desaina_Kiwi::ParentIndex::set_position, position, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::ParentIndex>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Path {
	WindingRule windingRule;
	uint commandsBlob;
void applyChange(const Desaina_Kiwi::Path& change) {
	if (change.windingRule() != nullptr) {
    applyChangeImpl(windingRule, *change.windingRule());
	}
	if (change.commandsBlob() != nullptr) {
    applyChangeImpl(commandsBlob, *change.commandsBlob());
	}
}

void toChange(Desaina_Kiwi::Path& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Path::set_windingRule, windingRule, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Path::set_commandsBlob, commandsBlob, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Path>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Vector {
	float x = 0;
	float y = 0;
void applyChange(const Desaina_Kiwi::Vector& change) {
	if (change.x() != nullptr) {
    applyChangeImpl(x, *change.x());
	}
	if (change.y() != nullptr) {
    applyChangeImpl(y, *change.y());
	}
}

void toChange(Desaina_Kiwi::Vector& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Vector::set_x, x, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Vector::set_y, y, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Vector>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Matrix {
	float m00 = 1;
	float m01 = 0;
	float m02 = 0;
	float m10 = 0;
	float m11 = 1;
	float m12 = 0;
void applyChange(const Desaina_Kiwi::Matrix& change) {
	if (change.m00() != nullptr) {
    applyChangeImpl(m00, *change.m00());
	}
	if (change.m01() != nullptr) {
    applyChangeImpl(m01, *change.m01());
	}
	if (change.m02() != nullptr) {
    applyChangeImpl(m02, *change.m02());
	}
	if (change.m10() != nullptr) {
    applyChangeImpl(m10, *change.m10());
	}
	if (change.m11() != nullptr) {
    applyChangeImpl(m11, *change.m11());
	}
	if (change.m12() != nullptr) {
    applyChangeImpl(m12, *change.m12());
	}
}

void toChange(Desaina_Kiwi::Matrix& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m00, m00, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m01, m01, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m02, m02, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m10, m10, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m11, m11, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Matrix::set_m12, m12, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Matrix>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Effect {
	EffectType type;
void applyChange(const Desaina_Kiwi::Effect& change) {
	if (change.type() != nullptr) {
    applyChangeImpl(type, *change.type());
	}
}

void toChange(Desaina_Kiwi::Effect& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_type, type, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Effect>();
  toChange(*change, pool);
  return change;
}

};
struct ArcData {
	float startingAngle = 0;
	float endingAngle = 6.2831854820251465;
	float innerRadius = 0;
void applyChange(const Desaina_Kiwi::ArcData& change) {
	if (change.startingAngle() != nullptr) {
    applyChangeImpl(startingAngle, *change.startingAngle());
	}
	if (change.endingAngle() != nullptr) {
    applyChangeImpl(endingAngle, *change.endingAngle());
	}
	if (change.innerRadius() != nullptr) {
    applyChangeImpl(innerRadius, *change.innerRadius());
	}
}

void toChange(Desaina_Kiwi::ArcData& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::ArcData::set_startingAngle, startingAngle, pool);
  toChangeImpl(&change, &Desaina_Kiwi::ArcData::set_endingAngle, endingAngle, pool);
  toChangeImpl(&change, &Desaina_Kiwi::ArcData::set_innerRadius, innerRadius, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::ArcData>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct VectorData {
	uint vectorNetworkBlob;
void applyChange(const Desaina_Kiwi::VectorData& change) {
	if (change.vectorNetworkBlob() != nullptr) {
    applyChangeImpl(vectorNetworkBlob, *change.vectorNetworkBlob());
	}
}

void toChange(Desaina_Kiwi::VectorData& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::VectorData::set_vectorNetworkBlob, vectorNetworkBlob, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::VectorData>();
  toChange(*change, pool);
  return change;
}

};
struct Color {
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;
void applyChange(const Desaina_Kiwi::Color& change) {
	if (change.r() != nullptr) {
    applyChangeImpl(r, *change.r());
	}
	if (change.g() != nullptr) {
    applyChangeImpl(g, *change.g());
	}
	if (change.b() != nullptr) {
    applyChangeImpl(b, *change.b());
	}
	if (change.a() != nullptr) {
    applyChangeImpl(a, *change.a());
	}
}

void toChange(Desaina_Kiwi::Color& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Color::set_r, r, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Color::set_g, g, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Color::set_b, b, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Color::set_a, a, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Color>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Number {
	float value = 0;
	NumberUnits units;
void applyChange(const Desaina_Kiwi::Number& change) {
	if (change.value() != nullptr) {
    applyChangeImpl(value, *change.value());
	}
	if (change.units() != nullptr) {
    applyChangeImpl(units, *change.units());
	}
}

void toChange(Desaina_Kiwi::Number& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Number::set_value, value, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Number::set_units, units, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Number>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Rect {
	float x;
	float y;
	float w;
	float h;
void applyChange(const Desaina_Kiwi::Rect& change) {
	if (change.x() != nullptr) {
    applyChangeImpl(x, *change.x());
	}
	if (change.y() != nullptr) {
    applyChangeImpl(y, *change.y());
	}
	if (change.w() != nullptr) {
    applyChangeImpl(w, *change.w());
	}
	if (change.h() != nullptr) {
    applyChangeImpl(h, *change.h());
	}
}

void toChange(Desaina_Kiwi::Rect& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Rect::set_x, x, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Rect::set_y, y, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Rect::set_w, w, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Rect::set_h, h, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Rect>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct ColorStop {
	float position = 0;
	Color color;
void applyChange(const Desaina_Kiwi::ColorStop& change) {
	if (change.position() != nullptr) {
    applyChangeImpl(position, *change.position());
	}
	if (change.color() != nullptr) {
    applyChangeImpl(color, *change.color());
	}
}

void toChange(Desaina_Kiwi::ColorStop& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::ColorStop::set_position, position, pool);
  toChangeImpl(&change, &Desaina_Kiwi::ColorStop::set_color, color, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::ColorStop>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Paint {
	PaintType type;
	bool visible = true;
	float opacity = 1;
	BlendMode blendMode;
void applyChange(const Desaina_Kiwi::Paint& change) {
	if (change.type() != nullptr) {
    applyChangeImpl(type, *change.type());
	}
	if (change.visible() != nullptr) {
    applyChangeImpl(visible, *change.visible());
	}
	if (change.opacity() != nullptr) {
    applyChangeImpl(opacity, *change.opacity());
	}
	if (change.blendMode() != nullptr) {
    applyChangeImpl(blendMode, *change.blendMode());
	}
}

void toChange(Desaina_Kiwi::Paint& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_type, type, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_visible, visible, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_opacity, opacity, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_blendMode, blendMode, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Paint>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct AssetRef {
	string key;
	string version;
void applyChange(const Desaina_Kiwi::AssetRef& change) {
	if (change.key() != nullptr) {
    applyChangeImpl(key, *change.key());
	}
	if (change.version() != nullptr) {
    applyChangeImpl(version, *change.version());
	}
}

void toChange(Desaina_Kiwi::AssetRef& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::AssetRef::set_key, key, pool);
  toChangeImpl(&change, &Desaina_Kiwi::AssetRef::set_version, version, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::AssetRef>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct StyleId {
	GUID guid;
	AssetRef assetRef;
void applyChange(const Desaina_Kiwi::StyleId& change) {
	if (change.guid() != nullptr) {
    applyChangeImpl(guid, *change.guid());
	}
	if (change.assetRef() != nullptr) {
    applyChangeImpl(assetRef, *change.assetRef());
	}
}

void toChange(Desaina_Kiwi::StyleId& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::StyleId::set_guid, guid, pool);
  toChangeImpl(&change, &Desaina_Kiwi::StyleId::set_assetRef, assetRef, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::StyleId>();
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Glyph {
	uint styleID;
	uint commandsBlob;
	Vector position;
	float fontSize;
	float advance;
void applyChange(const Desaina_Kiwi::Glyph& change) {
	if (change.styleID() != nullptr) {
    applyChangeImpl(styleID, *change.styleID());
	}
	if (change.commandsBlob() != nullptr) {
    applyChangeImpl(commandsBlob, *change.commandsBlob());
	}
	if (change.position() != nullptr) {
    applyChangeImpl(position, *change.position());
	}
	if (change.fontSize() != nullptr) {
    applyChangeImpl(fontSize, *change.fontSize());
	}
	if (change.advance() != nullptr) {
    applyChangeImpl(advance, *change.advance());
	}
}

void toChange(Desaina_Kiwi::Glyph& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Glyph::set_styleID, styleID, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Glyph::set_commandsBlob, commandsBlob, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Glyph::set_position, position, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Glyph::set_fontSize, fontSize, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Glyph::set_advance, advance, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Glyph>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};
struct Baseline {
	Vector position;
	float width;
	float lineY;
	float lineHeight;
	float lineAscent;
	uint firstCharacter;
	uint endCharacter;
void applyChange(const Desaina_Kiwi::Baseline& change) {
	if (change.position() != nullptr) {
    applyChangeImpl(position, *change.position());
	}
	if (change.width() != nullptr) {
    applyChangeImpl(width, *change.width());
	}
	if (change.lineY() != nullptr) {
    applyChangeImpl(lineY, *change.lineY());
	}
	if (change.lineHeight() != nullptr) {
    applyChangeImpl(lineHeight, *change.lineHeight());
	}
	if (change.lineAscent() != nullptr) {
    applyChangeImpl(lineAscent, *change.lineAscent());
	}
	if (change.firstCharacter() != nullptr) {
    applyChangeImpl(firstCharacter, *change.firstCharacter());
	}
	if (change.endCharacter() != nullptr) {
    applyChangeImpl(endCharacter, *change.endCharacter());
	}
}

void toChange(Desaina_Kiwi::Baseline& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_position, position, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_width, width, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_lineY, lineY, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_lineHeight, lineHeight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_lineAscent, lineAscent, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_firstCharacter, firstCharacter, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Baseline::set_endCharacter, endCharacter, pool);
}

auto* toChange(kiwi::MemoryPool& pool) const {
  auto* change = pool.allocate<Desaina_Kiwi::Baseline>();
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  toChange(*change, pool);
  return change;
}

};


using  PaintUnion = std::variant<SolidPaint, GradientPaint, ImagePaint>;

class NodeBase  {
private:

public:
	virtual void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) {};
	virtual void applyChange(const Desaina_Kiwi::NodeChange& change) {};
	virtual NodeBase* clone(NodeBase* src, NodePool& pool) const { return nullptr; };
	virtual bool isDocument() { return false; };
	virtual bool isPage() { return false; };
	virtual bool isFrame() { return false; };;
	virtual bool isRect() { return false; };;

};
class BaseNodeMixin : public NodeBase {
private:
	GUID guid;
	ParentIndex parentIndex;
	string name;
	NodeType type;

public:
	const GUID& get_guid() const {
		return guid;
	};
	void set_guid (const GUID& val) {
		guid = val;
	};
	const ParentIndex& get_parentIndex() const {
		return parentIndex;
	};
	void set_parentIndex (const ParentIndex& val) {
		parentIndex = val;
	};
	const string& get_name() const {
		return name;
	};
	void set_name (const string& val) {
		name = val;
	};
	const NodeType& get_type() const {
		return type;
	};
	void set_type (const NodeType& val) {
		type = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.guid() != nullptr) {
    applyChangeImpl(guid, *change.guid());
  }
	if (change.parentIndex() != nullptr) {
    applyChangeImpl(parentIndex, *change.parentIndex());
  }
	if (change.name() != nullptr) {
    applyChangeImpl(name, *change.name());
  }
	if (change.type() != nullptr) {
    applyChangeImpl(type, *change.type());
  }
	NodeBase::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_guid, guid, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_parentIndex, parentIndex, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_name, name, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_type, type, pool);
}

};
class SceneNodeMixin  {
private:
	bool visible = true;
	bool locked;

public:
	const bool& get_visible() const {
		return visible;
	};
	void set_visible (const bool& val) {
		visible = val;
	};
	const bool& get_locked() const {
		return locked;
	};
	void set_locked (const bool& val) {
		locked = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.visible() != nullptr) {
    applyChangeImpl(visible, *change.visible());
  }
	if (change.locked() != nullptr) {
    applyChangeImpl(locked, *change.locked());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_visible, visible, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_locked, locked, pool);
}

};
class CornerMixin  {
private:
	float cornerRadius = 0;
	float cornerSmoothing = 0;

public:
	const float& get_cornerRadius() const {
		return cornerRadius;
	};
	void set_cornerRadius (const float& val) {
		cornerRadius = val;
	};
	const float& get_cornerSmoothing() const {
		return cornerSmoothing;
	};
	void set_cornerSmoothing (const float& val) {
		cornerSmoothing = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.cornerRadius() != nullptr) {
    applyChangeImpl(cornerRadius, *change.cornerRadius());
  }
	if (change.cornerSmoothing() != nullptr) {
    applyChangeImpl(cornerSmoothing, *change.cornerSmoothing());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_cornerRadius, cornerRadius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_cornerSmoothing, cornerSmoothing, pool);
}

};
class RectangleCornerMixin  {
private:
	float rectangleTopLeftCornerRadius = 0;
	float rectangleTopRightCornerRadius = 0;
	float rectangleBottomLeftCornerRadius = 0;
	float rectangleBottomRightCornerRadius = 0;

public:
	const float& get_rectangleTopLeftCornerRadius() const {
		return rectangleTopLeftCornerRadius;
	};
	void set_rectangleTopLeftCornerRadius (const float& val) {
		rectangleTopLeftCornerRadius = val;
	};
	const float& get_rectangleTopRightCornerRadius() const {
		return rectangleTopRightCornerRadius;
	};
	void set_rectangleTopRightCornerRadius (const float& val) {
		rectangleTopRightCornerRadius = val;
	};
	const float& get_rectangleBottomLeftCornerRadius() const {
		return rectangleBottomLeftCornerRadius;
	};
	void set_rectangleBottomLeftCornerRadius (const float& val) {
		rectangleBottomLeftCornerRadius = val;
	};
	const float& get_rectangleBottomRightCornerRadius() const {
		return rectangleBottomRightCornerRadius;
	};
	void set_rectangleBottomRightCornerRadius (const float& val) {
		rectangleBottomRightCornerRadius = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.rectangleTopLeftCornerRadius() != nullptr) {
    applyChangeImpl(rectangleTopLeftCornerRadius, *change.rectangleTopLeftCornerRadius());
  }
	if (change.rectangleTopRightCornerRadius() != nullptr) {
    applyChangeImpl(rectangleTopRightCornerRadius, *change.rectangleTopRightCornerRadius());
  }
	if (change.rectangleBottomLeftCornerRadius() != nullptr) {
    applyChangeImpl(rectangleBottomLeftCornerRadius, *change.rectangleBottomLeftCornerRadius());
  }
	if (change.rectangleBottomRightCornerRadius() != nullptr) {
    applyChangeImpl(rectangleBottomRightCornerRadius, *change.rectangleBottomRightCornerRadius());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_rectangleTopLeftCornerRadius, rectangleTopLeftCornerRadius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_rectangleTopRightCornerRadius, rectangleTopRightCornerRadius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_rectangleBottomLeftCornerRadius, rectangleBottomLeftCornerRadius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_rectangleBottomRightCornerRadius, rectangleBottomRightCornerRadius, pool);
}

};
class IndividualStrokesMixin  {
private:
	float borderTopWeight = 0;
	float borderBottomWeight = 0;
	float borderLeftWeight = 0;
	float borderRightWeight = 0;

public:
	const float& get_borderTopWeight() const {
		return borderTopWeight;
	};
	void set_borderTopWeight (const float& val) {
		borderTopWeight = val;
	};
	const float& get_borderBottomWeight() const {
		return borderBottomWeight;
	};
	void set_borderBottomWeight (const float& val) {
		borderBottomWeight = val;
	};
	const float& get_borderLeftWeight() const {
		return borderLeftWeight;
	};
	void set_borderLeftWeight (const float& val) {
		borderLeftWeight = val;
	};
	const float& get_borderRightWeight() const {
		return borderRightWeight;
	};
	void set_borderRightWeight (const float& val) {
		borderRightWeight = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.borderTopWeight() != nullptr) {
    applyChangeImpl(borderTopWeight, *change.borderTopWeight());
  }
	if (change.borderBottomWeight() != nullptr) {
    applyChangeImpl(borderBottomWeight, *change.borderBottomWeight());
  }
	if (change.borderLeftWeight() != nullptr) {
    applyChangeImpl(borderLeftWeight, *change.borderLeftWeight());
  }
	if (change.borderRightWeight() != nullptr) {
    applyChangeImpl(borderRightWeight, *change.borderRightWeight());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_borderTopWeight, borderTopWeight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_borderBottomWeight, borderBottomWeight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_borderLeftWeight, borderLeftWeight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_borderRightWeight, borderRightWeight, pool);
}

};
class DimensionAndPositionMixin  {
private:
	Vector size;
	Matrix transform;

public:
	const Vector& get_size() const {
		return size;
	};
	void set_size (const Vector& val) {
		size = val;
	};
	const Matrix& get_transform() const {
		return transform;
	};
	void set_transform (const Matrix& val) {
		transform = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.size() != nullptr) {
    applyChangeImpl(size, *change.size());
  }
	if (change.transform() != nullptr) {
    applyChangeImpl(transform, *change.transform());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_size, size, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_transform, transform, pool);
}

};
class ConstraintMixin  {
private:
	ConstraintType horizontalConstraint;
	ConstraintType verticalConstraint;

public:
	const ConstraintType& get_horizontalConstraint() const {
		return horizontalConstraint;
	};
	void set_horizontalConstraint (const ConstraintType& val) {
		horizontalConstraint = val;
	};
	const ConstraintType& get_verticalConstraint() const {
		return verticalConstraint;
	};
	void set_verticalConstraint (const ConstraintType& val) {
		verticalConstraint = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.horizontalConstraint() != nullptr) {
    applyChangeImpl(horizontalConstraint, *change.horizontalConstraint());
  }
	if (change.verticalConstraint() != nullptr) {
    applyChangeImpl(verticalConstraint, *change.verticalConstraint());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_horizontalConstraint, horizontalConstraint, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_verticalConstraint, verticalConstraint, pool);
}

};
class ExportMixin  {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class BlendMixin  {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class AutoLayoutMixin  {
private:
	StackMode stackMode;
	StackWrap stackWrap;
	float stackPaddingRight = 0;
	float stackPaddingBottom = 0;
	float stackHorizontalPadding = 0;
	float stackVerticalPadding = 0;

public:
	const StackMode& get_stackMode() const {
		return stackMode;
	};
	void set_stackMode (const StackMode& val) {
		stackMode = val;
	};
	const StackWrap& get_stackWrap() const {
		return stackWrap;
	};
	void set_stackWrap (const StackWrap& val) {
		stackWrap = val;
	};
	const float& get_stackPaddingRight() const {
		return stackPaddingRight;
	};
	void set_stackPaddingRight (const float& val) {
		stackPaddingRight = val;
	};
	const float& get_stackPaddingBottom() const {
		return stackPaddingBottom;
	};
	void set_stackPaddingBottom (const float& val) {
		stackPaddingBottom = val;
	};
	const float& get_stackHorizontalPadding() const {
		return stackHorizontalPadding;
	};
	void set_stackHorizontalPadding (const float& val) {
		stackHorizontalPadding = val;
	};
	const float& get_stackVerticalPadding() const {
		return stackVerticalPadding;
	};
	void set_stackVerticalPadding (const float& val) {
		stackVerticalPadding = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.stackMode() != nullptr) {
    applyChangeImpl(stackMode, *change.stackMode());
  }
	if (change.stackWrap() != nullptr) {
    applyChangeImpl(stackWrap, *change.stackWrap());
  }
	if (change.stackPaddingRight() != nullptr) {
    applyChangeImpl(stackPaddingRight, *change.stackPaddingRight());
  }
	if (change.stackPaddingBottom() != nullptr) {
    applyChangeImpl(stackPaddingBottom, *change.stackPaddingBottom());
  }
	if (change.stackHorizontalPadding() != nullptr) {
    applyChangeImpl(stackHorizontalPadding, *change.stackHorizontalPadding());
  }
	if (change.stackVerticalPadding() != nullptr) {
    applyChangeImpl(stackVerticalPadding, *change.stackVerticalPadding());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackMode, stackMode, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackWrap, stackWrap, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackPaddingRight, stackPaddingRight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackPaddingBottom, stackPaddingBottom, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackHorizontalPadding, stackHorizontalPadding, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_stackVerticalPadding, stackVerticalPadding, pool);
}

};
class PageNodeBase : public BaseNodeMixin {
private:
	Color backgroundColor;
	float backgroundOpacity;
	bool backgroundEnabled;

public:
	const Color& get_backgroundColor() const {
		return backgroundColor;
	};
	void set_backgroundColor (const Color& val) {
		backgroundColor = val;
	};
	const float& get_backgroundOpacity() const {
		return backgroundOpacity;
	};
	void set_backgroundOpacity (const float& val) {
		backgroundOpacity = val;
	};
	const bool& get_backgroundEnabled() const {
		return backgroundEnabled;
	};
	void set_backgroundEnabled (const bool& val) {
		backgroundEnabled = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.backgroundColor() != nullptr) {
    applyChangeImpl(backgroundColor, *change.backgroundColor());
  }
	if (change.backgroundOpacity() != nullptr) {
    applyChangeImpl(backgroundOpacity, *change.backgroundOpacity());
  }
	if (change.backgroundEnabled() != nullptr) {
    applyChangeImpl(backgroundEnabled, *change.backgroundEnabled());
  }
	BaseNodeMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_backgroundColor, backgroundColor, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_backgroundOpacity, backgroundOpacity, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_backgroundEnabled, backgroundEnabled, pool);
}

};
class DocumentNodeBase : public BaseNodeMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	BaseNodeMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class LayoutMixin : public DimensionAndPositionMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DimensionAndPositionMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) {
}

};


template <>
inline void applyChangeImpl<Buffer, kiwi::Array<Desaina_Kiwi::NodeChange>>(Buffer& value, const kiwi::Array<Desaina_Kiwi::NodeChange>& change) {
  kiwi::ByteBuffer _bb;
  _bb.writeVarUint(change.size());
  for (auto &_it : change) {
    const_cast<Desaina_Kiwi::NodeChange&>(_it).encode(_bb);
  }
  value.set(_bb.data(), _bb.size());
}

class SymbolData  {
private:
	GUID symbolID;
	Buffer symbolOverrides;
	float uniformScaleFactor;

public:
	const GUID& get_symbolID() const {
		return symbolID;
	};
	void set_symbolID (const GUID& val) {
		symbolID = val;
	};
	const Buffer& get_symbolOverrides() const {
		return symbolOverrides;
	};
	void set_symbolOverrides (const Buffer& val) {
		symbolOverrides = val;
	};
	const float& get_uniformScaleFactor() const {
		return uniformScaleFactor;
	};
	void set_uniformScaleFactor (const float& val) {
		uniformScaleFactor = val;
	};

void applyChange(const Desaina_Kiwi::SymbolData& change) {
	if (change.symbolID() != nullptr) {
    applyChangeImpl(symbolID, *change.symbolID());
  }
	if (change.symbolOverrides() != nullptr) {
    applyChangeImpl(symbolOverrides, *change.symbolOverrides());
  }
	if (change.uniformScaleFactor() != nullptr) {
    applyChangeImpl(uniformScaleFactor, *change.uniformScaleFactor());
  }
}

void toChange(Desaina_Kiwi::SymbolData& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::SymbolData::set_symbolID, symbolID, pool);
  toChangeImpl(&change, &Desaina_Kiwi::SymbolData::set_symbolOverrides, symbolOverrides, pool);
  toChangeImpl(&change, &Desaina_Kiwi::SymbolData::set_uniformScaleFactor, uniformScaleFactor, pool);
}

};
class DropShadowEffect : public Effect {
private:
	Color color;
	Vector offset;
	float radius = 0;
	float spread = 0;
	bool visible = true;
	BlendMode blendMode;
	bool showShadowBehindNode;

public:
	const Color& get_color() const {
		return color;
	};
	void set_color (const Color& val) {
		color = val;
	};
	const Vector& get_offset() const {
		return offset;
	};
	void set_offset (const Vector& val) {
		offset = val;
	};
	const float& get_radius() const {
		return radius;
	};
	void set_radius (const float& val) {
		radius = val;
	};
	const float& get_spread() const {
		return spread;
	};
	void set_spread (const float& val) {
		spread = val;
	};
	const bool& get_visible() const {
		return visible;
	};
	void set_visible (const bool& val) {
		visible = val;
	};
	const BlendMode& get_blendMode() const {
		return blendMode;
	};
	void set_blendMode (const BlendMode& val) {
		blendMode = val;
	};
	const bool& get_showShadowBehindNode() const {
		return showShadowBehindNode;
	};
	void set_showShadowBehindNode (const bool& val) {
		showShadowBehindNode = val;
	};

void applyChange(const Desaina_Kiwi::Effect& change) {
	if (change.color() != nullptr) {
    applyChangeImpl(color, *change.color());
  }
	if (change.offset() != nullptr) {
    applyChangeImpl(offset, *change.offset());
  }
	if (change.radius() != nullptr) {
    applyChangeImpl(radius, *change.radius());
  }
	if (change.spread() != nullptr) {
    applyChangeImpl(spread, *change.spread());
  }
	if (change.visible() != nullptr) {
    applyChangeImpl(visible, *change.visible());
  }
	if (change.blendMode() != nullptr) {
    applyChangeImpl(blendMode, *change.blendMode());
  }
	if (change.showShadowBehindNode() != nullptr) {
    applyChangeImpl(showShadowBehindNode, *change.showShadowBehindNode());
  }
	Effect::applyChange(change);
}

void toChange(Desaina_Kiwi::Effect& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_color, color, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_offset, offset, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_radius, radius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_spread, spread, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_visible, visible, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_blendMode, blendMode, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_showShadowBehindNode, showShadowBehindNode, pool);
}

};
class InnerShadowEffect : public Effect {
private:
	Color color;
	Vector offset;
	float radius = 10;
	float spread = 0;
	bool visible = true;
	BlendMode blendMode;

public:
	const Color& get_color() const {
		return color;
	};
	void set_color (const Color& val) {
		color = val;
	};
	const Vector& get_offset() const {
		return offset;
	};
	void set_offset (const Vector& val) {
		offset = val;
	};
	const float& get_radius() const {
		return radius;
	};
	void set_radius (const float& val) {
		radius = val;
	};
	const float& get_spread() const {
		return spread;
	};
	void set_spread (const float& val) {
		spread = val;
	};
	const bool& get_visible() const {
		return visible;
	};
	void set_visible (const bool& val) {
		visible = val;
	};
	const BlendMode& get_blendMode() const {
		return blendMode;
	};
	void set_blendMode (const BlendMode& val) {
		blendMode = val;
	};

void applyChange(const Desaina_Kiwi::Effect& change) {
	if (change.color() != nullptr) {
    applyChangeImpl(color, *change.color());
  }
	if (change.offset() != nullptr) {
    applyChangeImpl(offset, *change.offset());
  }
	if (change.radius() != nullptr) {
    applyChangeImpl(radius, *change.radius());
  }
	if (change.spread() != nullptr) {
    applyChangeImpl(spread, *change.spread());
  }
	if (change.visible() != nullptr) {
    applyChangeImpl(visible, *change.visible());
  }
	if (change.blendMode() != nullptr) {
    applyChangeImpl(blendMode, *change.blendMode());
  }
	Effect::applyChange(change);
}

void toChange(Desaina_Kiwi::Effect& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_color, color, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_offset, offset, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_radius, radius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_spread, spread, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_visible, visible, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_blendMode, blendMode, pool);
}

};
class BlurEffect : public Effect {
private:
	float radius = 10;
	bool visible = true;

public:
	const float& get_radius() const {
		return radius;
	};
	void set_radius (const float& val) {
		radius = val;
	};
	const bool& get_visible() const {
		return visible;
	};
	void set_visible (const bool& val) {
		visible = val;
	};

void applyChange(const Desaina_Kiwi::Effect& change) {
	if (change.radius() != nullptr) {
    applyChangeImpl(radius, *change.radius());
  }
	if (change.visible() != nullptr) {
    applyChangeImpl(visible, *change.visible());
  }
	Effect::applyChange(change);
}

void toChange(Desaina_Kiwi::Effect& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_radius, radius, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Effect::set_visible, visible, pool);
}

};
class SolidPaint : public Paint {
private:
	Color color;

public:
	const Color& get_color() const {
		return color;
	};
	void set_color (const Color& val) {
		color = val;
	};

void applyChange(const Desaina_Kiwi::Paint& change) {
	if (change.color() != nullptr) {
    applyChangeImpl(color, *change.color());
  }
	Paint::applyChange(change);
}

void toChange(Desaina_Kiwi::Paint& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_color, color, pool);
}

};
class GradientPaint : public Paint {
private:
	Matrix transform;
	IVector<ColorStop> stops;

public:
	const Matrix& get_transform() const {
		return transform;
	};
	void set_transform (const Matrix& val) {
		transform = val;
	};
	const IVector<ColorStop>& get_stops() const {
		return stops;
	};
	void set_stops (const IVector<ColorStop>& val) {
		stops = val;
	};

void applyChange(const Desaina_Kiwi::Paint& change) {
	if (change.transform() != nullptr) {
    applyChangeImpl(transform, *change.transform());
  }
	if (change.stops() != nullptr) {
    applyChangeImpl(stops, *change.stops());
  }
	Paint::applyChange(change);
}

void toChange(Desaina_Kiwi::Paint& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_transform, transform, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_stops, stops, pool);
}

};
class ImagePaint : public Paint {
private:
	ImageScaleMode imageScaleMode;
	Matrix transform;

public:
	const ImageScaleMode& get_imageScaleMode() const {
		return imageScaleMode;
	};
	void set_imageScaleMode (const ImageScaleMode& val) {
		imageScaleMode = val;
	};
	const Matrix& get_transform() const {
		return transform;
	};
	void set_transform (const Matrix& val) {
		transform = val;
	};

void applyChange(const Desaina_Kiwi::Paint& change) {
	if (change.imageScaleMode() != nullptr) {
    applyChangeImpl(imageScaleMode, *change.imageScaleMode());
  }
	if (change.transform() != nullptr) {
    applyChangeImpl(transform, *change.transform());
  }
	Paint::applyChange(change);
}

void toChange(Desaina_Kiwi::Paint& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_imageScaleMode, imageScaleMode, pool);
  toChangeImpl(&change, &Desaina_Kiwi::Paint::set_transform, transform, pool);
}

};
class MinimalStrokesMixin  {
private:
	IVector<PaintUnion> strokePaints;
	StyleId styleIdForStrokeFill;
	float strokeWeight = 0;
	StrokeJoin strokeJoin;
	StrokeAlign strokeAlign;
	IVector<float> dashPattern;
	IVector<Path> strokeGeometry;

public:
	const IVector<PaintUnion>& get_strokePaints() const {
		return strokePaints;
	};
	void set_strokePaints (const IVector<PaintUnion>& val) {
		strokePaints = val;
	};
	const StyleId& get_styleIdForStrokeFill() const {
		return styleIdForStrokeFill;
	};
	void set_styleIdForStrokeFill (const StyleId& val) {
		styleIdForStrokeFill = val;
	};
	const float& get_strokeWeight() const {
		return strokeWeight;
	};
	void set_strokeWeight (const float& val) {
		strokeWeight = val;
	};
	const StrokeJoin& get_strokeJoin() const {
		return strokeJoin;
	};
	void set_strokeJoin (const StrokeJoin& val) {
		strokeJoin = val;
	};
	const StrokeAlign& get_strokeAlign() const {
		return strokeAlign;
	};
	void set_strokeAlign (const StrokeAlign& val) {
		strokeAlign = val;
	};
	const IVector<float>& get_dashPattern() const {
		return dashPattern;
	};
	void set_dashPattern (const IVector<float>& val) {
		dashPattern = val;
	};
	const IVector<Path>& get_strokeGeometry() const {
		return strokeGeometry;
	};
	void set_strokeGeometry (const IVector<Path>& val) {
		strokeGeometry = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.strokePaints() != nullptr) {
    applyChangeImpl(strokePaints, *change.strokePaints());
  }
	if (change.styleIdForStrokeFill() != nullptr) {
    applyChangeImpl(styleIdForStrokeFill, *change.styleIdForStrokeFill());
  }
	if (change.strokeWeight() != nullptr) {
    applyChangeImpl(strokeWeight, *change.strokeWeight());
  }
	if (change.strokeJoin() != nullptr) {
    applyChangeImpl(strokeJoin, *change.strokeJoin());
  }
	if (change.strokeAlign() != nullptr) {
    applyChangeImpl(strokeAlign, *change.strokeAlign());
  }
	if (change.dashPattern() != nullptr) {
    applyChangeImpl(dashPattern, *change.dashPattern());
  }
	if (change.strokeGeometry() != nullptr) {
    applyChangeImpl(strokeGeometry, *change.strokeGeometry());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokePaints, strokePaints, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokeWeight, strokeWeight, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokeJoin, strokeJoin, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokeAlign, strokeAlign, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_dashPattern, dashPattern, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokeGeometry, strokeGeometry, pool);
}

};
class MinimalFillsMixin  {
private:
	IVector<PaintUnion> fillPaints;
	StyleId styleIdForStrokeFill;

public:
	const IVector<PaintUnion>& get_fillPaints() const {
		return fillPaints;
	};
	void set_fillPaints (const IVector<PaintUnion>& val) {
		fillPaints = val;
	};
	const StyleId& get_styleIdForStrokeFill() const {
		return styleIdForStrokeFill;
	};
	void set_styleIdForStrokeFill (const StyleId& val) {
		styleIdForStrokeFill = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.fillPaints() != nullptr) {
    applyChangeImpl(fillPaints, *change.fillPaints());
  }
	if (change.styleIdForStrokeFill() != nullptr) {
    applyChangeImpl(styleIdForStrokeFill, *change.styleIdForStrokeFill());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_fillPaints, fillPaints, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill, pool);
}

};
class GeometryMixin : public MinimalStrokesMixin, public MinimalFillsMixin {
private:
	StrokeCap strokeCap;
	float miterLimit = 0;
	IVector<Path> fillGeometry;

public:
	const StrokeCap& get_strokeCap() const {
		return strokeCap;
	};
	void set_strokeCap (const StrokeCap& val) {
		strokeCap = val;
	};
	const float& get_miterLimit() const {
		return miterLimit;
	};
	void set_miterLimit (const float& val) {
		miterLimit = val;
	};
	const IVector<Path>& get_fillGeometry() const {
		return fillGeometry;
	};
	void set_fillGeometry (const IVector<Path>& val) {
		fillGeometry = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.strokeCap() != nullptr) {
    applyChangeImpl(strokeCap, *change.strokeCap());
  }
	if (change.miterLimit() != nullptr) {
    applyChangeImpl(miterLimit, *change.miterLimit());
  }
	if (change.fillGeometry() != nullptr) {
    applyChangeImpl(fillGeometry, *change.fillGeometry());
  }
	MinimalStrokesMixin::applyChange(change);
	MinimalFillsMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_strokeCap, strokeCap, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_miterLimit, miterLimit, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_fillGeometry, fillGeometry, pool);
}

};
class DefaultShapeNode : public BaseNodeMixin, public SceneNodeMixin, public ExportMixin, public BlendMixin, public GeometryMixin, public LayoutMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	BaseNodeMixin::applyChange(change);
	SceneNodeMixin::applyChange(change);
	ExportMixin::applyChange(change);
	BlendMixin::applyChange(change);
	GeometryMixin::applyChange(change);
	LayoutMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class RectangleNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin, public RectangleCornerMixin, public IndividualStrokesMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
	CornerMixin::applyChange(change);
	RectangleCornerMixin::applyChange(change);
	IndividualStrokesMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class LineNodeBase : public DefaultShapeNode, public ConstraintMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class EllipseNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	ArcData arcData;

public:
	const ArcData& get_arcData() const {
		return arcData;
	};
	void set_arcData (const ArcData& val) {
		arcData = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.arcData() != nullptr) {
    applyChangeImpl(arcData, *change.arcData());
  }
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
	CornerMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_arcData, arcData, pool);
}

};
class PolygonNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	uint count = 3;

public:
	const uint& get_count() const {
		return count;
	};
	void set_count (const uint& val) {
		count = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.count() != nullptr) {
    applyChangeImpl(count, *change.count());
  }
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
	CornerMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_count, count, pool);
}

};
class StarNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	uint count = 5;

public:
	const uint& get_count() const {
		return count;
	};
	void set_count (const uint& val) {
		count = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.count() != nullptr) {
    applyChangeImpl(count, *change.count());
  }
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
	CornerMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_count, count, pool);
}

};
class VectorNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	VectorData vectorData;

public:
	const VectorData& get_vectorData() const {
		return vectorData;
	};
	void set_vectorData (const VectorData& val) {
		vectorData = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.vectorData() != nullptr) {
    applyChangeImpl(vectorData, *change.vectorData());
  }
	DefaultShapeNode::applyChange(change);
	ConstraintMixin::applyChange(change);
	CornerMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_vectorData, vectorData, pool);
}

};
class SubTextMixin : public DefaultShapeNode {
private:
	uint styleID;
	Number letterSpacing;
	Number lineHeight;

public:
	const uint& get_styleID() const {
		return styleID;
	};
	void set_styleID (const uint& val) {
		styleID = val;
	};
	const Number& get_letterSpacing() const {
		return letterSpacing;
	};
	void set_letterSpacing (const Number& val) {
		letterSpacing = val;
	};
	const Number& get_lineHeight() const {
		return lineHeight;
	};
	void set_lineHeight (const Number& val) {
		lineHeight = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.styleID() != nullptr) {
    applyChangeImpl(styleID, *change.styleID());
  }
	if (change.letterSpacing() != nullptr) {
    applyChangeImpl(letterSpacing, *change.letterSpacing());
  }
	if (change.lineHeight() != nullptr) {
    applyChangeImpl(lineHeight, *change.lineHeight());
  }
	DefaultShapeNode::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_styleID, styleID, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_letterSpacing, letterSpacing, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_lineHeight, lineHeight, pool);
}

};
class TextNodeMixin : public DefaultShapeNode {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultShapeNode::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class EffectMixin  {
private:
	IVector<Effect> effects;
	StyleId styleIdForEffect;

public:
	const IVector<Effect>& get_effects() const {
		return effects;
	};
	void set_effects (const IVector<Effect>& val) {
		effects = val;
	};
	const StyleId& get_styleIdForEffect() const {
		return styleIdForEffect;
	};
	void set_styleIdForEffect (const StyleId& val) {
		styleIdForEffect = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.effects() != nullptr) {
    applyChangeImpl(effects, *change.effects());
  }
	if (change.styleIdForEffect() != nullptr) {
    applyChangeImpl(styleIdForEffect, *change.styleIdForEffect());
  }
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_effects, effects, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_styleIdForEffect, styleIdForEffect, pool);
}

};
class BaseFrameMixin : public DefaultShapeNode, public CornerMixin, public RectangleCornerMixin, public EffectMixin, public ConstraintMixin, public IndividualStrokesMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultShapeNode::applyChange(change);
	CornerMixin::applyChange(change);
	RectangleCornerMixin::applyChange(change);
	EffectMixin::applyChange(change);
	ConstraintMixin::applyChange(change);
	IndividualStrokesMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class DefaultFrameMixin : public BaseFrameMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	BaseFrameMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class FrameNodeBase : public DefaultFrameMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultFrameMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class SymbolNodeBase : public DefaultFrameMixin {
private:

public:

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	DefaultFrameMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
}

};
class InstanceNodeBase : public DefaultFrameMixin {
private:
	SymbolData symbolData;
	Buffer derivedSymbolData;

public:
	const SymbolData& get_symbolData() const {
		return symbolData;
	};
	void set_symbolData (const SymbolData& val) {
		symbolData = val;
	};
	const Buffer& get_derivedSymbolData() const {
		return derivedSymbolData;
	};
	void set_derivedSymbolData (const Buffer& val) {
		derivedSymbolData = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.symbolData() != nullptr) {
    applyChangeImpl(symbolData, *change.symbolData());
  }
	if (change.derivedSymbolData() != nullptr) {
    applyChangeImpl(derivedSymbolData, *change.derivedSymbolData());
  }
	DefaultFrameMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_symbolData, symbolData, pool);
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_derivedSymbolData, derivedSymbolData, pool);
}

};
class Decoration  {
private:
	IVector<Rect> rects;

public:
	const IVector<Rect>& get_rects() const {
		return rects;
	};
	void set_rects (const IVector<Rect>& val) {
		rects = val;
	};

void applyChange(const Desaina_Kiwi::Decoration& change) {
	if (change.rects() != nullptr) {
    applyChangeImpl(rects, *change.rects());
  }
}

void toChange(Desaina_Kiwi::Decoration& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::Decoration::set_rects, rects, pool);
}

};
class TextData  {
private:
	string characters;
	Buffer styleOverrideTable;
	Vector layoutSize;
	IVector<Baseline> baselines;
	IVector<Glyph> glyphs;
	IVector<Decoration> decorations;

public:
	const string& get_characters() const {
		return characters;
	};
	void set_characters (const string& val) {
		characters = val;
	};
	const Buffer& get_styleOverrideTable() const {
		return styleOverrideTable;
	};
	void set_styleOverrideTable (const Buffer& val) {
		styleOverrideTable = val;
	};
	const Vector& get_layoutSize() const {
		return layoutSize;
	};
	void set_layoutSize (const Vector& val) {
		layoutSize = val;
	};
	const IVector<Baseline>& get_baselines() const {
		return baselines;
	};
	void set_baselines (const IVector<Baseline>& val) {
		baselines = val;
	};
	const IVector<Glyph>& get_glyphs() const {
		return glyphs;
	};
	void set_glyphs (const IVector<Glyph>& val) {
		glyphs = val;
	};
	const IVector<Decoration>& get_decorations() const {
		return decorations;
	};
	void set_decorations (const IVector<Decoration>& val) {
		decorations = val;
	};

void applyChange(const Desaina_Kiwi::TextData& change) {
	if (change.characters() != nullptr) {
    applyChangeImpl(characters, *change.characters());
  }
	if (change.styleOverrideTable() != nullptr) {
    applyChangeImpl(styleOverrideTable, *change.styleOverrideTable());
  }
	if (change.layoutSize() != nullptr) {
    applyChangeImpl(layoutSize, *change.layoutSize());
  }
	if (change.baselines() != nullptr) {
    applyChangeImpl(baselines, *change.baselines());
  }
	if (change.glyphs() != nullptr) {
    applyChangeImpl(glyphs, *change.glyphs());
  }
	if (change.decorations() != nullptr) {
    applyChangeImpl(decorations, *change.decorations());
  }
}

void toChange(Desaina_Kiwi::TextData& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_characters, characters, pool);
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_styleOverrideTable, styleOverrideTable, pool);
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_layoutSize, layoutSize, pool);
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_baselines, baselines, pool);
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_glyphs, glyphs, pool);
  toChangeImpl(&change, &Desaina_Kiwi::TextData::set_decorations, decorations, pool);
}

};
class TextNodeBase : public TextNodeMixin {
private:
	TextData textData;

public:
	const TextData& get_textData() const {
		return textData;
	};
	void set_textData (const TextData& val) {
		textData = val;
	};

void applyChange(const Desaina_Kiwi::NodeChange& change) {
	if (change.textData() != nullptr) {
    applyChangeImpl(textData, *change.textData());
  }
	TextNodeMixin::applyChange(change);
}

void toChange(Desaina_Kiwi::NodeChange& change, kiwi::MemoryPool& pool) const {
  toChangeImpl(&change, &Desaina_Kiwi::NodeChange::set_textData, textData, pool);
}

};

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
  


