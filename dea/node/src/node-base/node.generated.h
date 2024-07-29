#pragma once

#include <string>
#include <variant>

#include "common/buffer.h"
#include "schema/message.h"
#include "type.h"

namespace dea::node
{

using  uint = uint32_t;
using string = std::string;
using Buffer = base::Buffer;
using boolean = bool;

class BaseNodeMixin;
class SceneNodeMixin;
class CornerMixin;
class RectangleCornerMixin;
class IndividualStrokesMixin;
class MinimalStrokesMixin;
class MinimalFillsMixin;
class DimensionAndPositionMixin;
class ConstraintMixin;
class EffectMixin;
class ExportMixin;
class BlendMixin;
class AutoLayoutMixin;
class GeometryMixin;
class LayoutMixin;
class DefaultShapeNode;
class BaseFrameMixin;
class DefaultFrameMixin;
class SubTextMixin;
class TextNodeMixin;
class RectangleNodeBase;
class LineNodeBase;
class EllipseNodeBase;
class PolygonNodeBase;
class StarNodeBase;
class VectorNodeBase;
class FrameNodeBase;
class SymbolNodeBase;
class InstanceNodeBase;
class TextNodeBase;
class PageNodeBase;
class DocumentNodeBase;

struct GUID;
struct Vector;
struct Rect;
struct Matrix;
struct Number;
struct Color;
struct Effect;
struct DropShadowEffect;
struct InnerShadowEffect;
struct BlurEffect;
struct ColorStop;
struct Paint;
struct SolidPaint;
struct GradientPaint;
struct ImagePaint;
struct Path;
struct ParentIndex;
struct AssetRef;
struct StyleId;
struct ArcData;
struct VectorData;
struct Glyph;
struct Decoration;
struct Baseline;
struct TextData;
struct SymbolData;

using PaintUnion = std::variant<SolidPaint, GradientPaint, ImagePaint>;
using BaseNodeMixinPointer = BaseNodeMixin*;

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


struct GUID  {
	uint sessionID;
	uint localID;

	void applyChange(const message::GUID& change) {
		if (change.sessionID() != nullptr) {
			applyChangeImpl(sessionID, *change.sessionID());
		}
		if (change.localID() != nullptr) {
			applyChangeImpl(localID, *change.localID());
		}
	}

	void toChange(message::GUID& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::GUID::set_sessionID, sessionID, pool);
		toChangeImpl(&change, &message::GUID::set_localID, localID, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::GUID>();
		toChange(*change, pool);
		return change;
	}

};

struct Vector  {
	float x;
	float y;

	void applyChange(const message::Vector& change) {
		if (change.x() != nullptr) {
			applyChangeImpl(x, *change.x());
		}
		if (change.y() != nullptr) {
			applyChangeImpl(y, *change.y());
		}
	}

	void toChange(message::Vector& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Vector::set_x, x, pool);
		toChangeImpl(&change, &message::Vector::set_y, y, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Vector>();
		toChange(*change, pool);
		return change;
	}

};

struct Rect  {
	float x;
	float y;
	float w;
	float h;

	void applyChange(const message::Rect& change) {
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

	void toChange(message::Rect& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Rect::set_x, x, pool);
		toChangeImpl(&change, &message::Rect::set_y, y, pool);
		toChangeImpl(&change, &message::Rect::set_w, w, pool);
		toChangeImpl(&change, &message::Rect::set_h, h, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Rect>();
		toChange(*change, pool);
		return change;
	}

};

struct Matrix  {
	float m00;
	float m01;
	float m02;
	float m10;
	float m11;
	float m12;

	void applyChange(const message::Matrix& change) {
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

	void toChange(message::Matrix& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Matrix::set_m00, m00, pool);
		toChangeImpl(&change, &message::Matrix::set_m01, m01, pool);
		toChangeImpl(&change, &message::Matrix::set_m02, m02, pool);
		toChangeImpl(&change, &message::Matrix::set_m10, m10, pool);
		toChangeImpl(&change, &message::Matrix::set_m11, m11, pool);
		toChangeImpl(&change, &message::Matrix::set_m12, m12, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Matrix>();
		toChange(*change, pool);
		return change;
	}

};

struct Number  {
	float value;
	NumberUnits units;

	void applyChange(const message::Number& change) {
		if (change.value() != nullptr) {
			applyChangeImpl(value, *change.value());
		}
		if (change.units() != nullptr) {
			applyChangeImpl(units, *change.units());
		}
	}

	void toChange(message::Number& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Number::set_value, value, pool);
		toChangeImpl(&change, &message::Number::set_units, units, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Number>();
		toChange(*change, pool);
		return change;
	}

};

struct Color  {
	float r;
	float g;
	float b;
	float a;

	void applyChange(const message::Color& change) {
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

	void toChange(message::Color& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Color::set_r, r, pool);
		toChangeImpl(&change, &message::Color::set_g, g, pool);
		toChangeImpl(&change, &message::Color::set_b, b, pool);
		toChangeImpl(&change, &message::Color::set_a, a, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Color>();
		toChange(*change, pool);
		return change;
	}

};

struct Effect  {
	EffectType type;

	void applyChange(const message::Effect& change) {
		if (change.type() != nullptr) {
			applyChangeImpl(type, *change.type());
		}
	}

	void toChange(message::Effect& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Effect::set_type, type, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Effect>();
		toChange(*change, pool);
		return change;
	}

};

struct DropShadowEffect  {
	Color color;
	Vector offset;
	float radius;
	float spread;
	bool visible;
	BlendMode blendMode;
	bool showShadowBehindNode;

	void applyChange(const message::Effect& change) {
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
	}

	void toChange(message::Effect& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Effect::set_color, color, pool);
		toChangeImpl(&change, &message::Effect::set_offset, offset, pool);
		toChangeImpl(&change, &message::Effect::set_radius, radius, pool);
		toChangeImpl(&change, &message::Effect::set_spread, spread, pool);
		toChangeImpl(&change, &message::Effect::set_visible, visible, pool);
		toChangeImpl(&change, &message::Effect::set_blendMode, blendMode, pool);
		toChangeImpl(&change, &message::Effect::set_showShadowBehindNode, showShadowBehindNode, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Effect>();
		toChange(*change, pool);
		return change;
	}

};

struct InnerShadowEffect  {
	Color color;
	Vector offset;
	float radius;
	float spread;
	bool visible;
	BlendMode blendMode;

	void applyChange(const message::Effect& change) {
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
	}

	void toChange(message::Effect& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Effect::set_color, color, pool);
		toChangeImpl(&change, &message::Effect::set_offset, offset, pool);
		toChangeImpl(&change, &message::Effect::set_radius, radius, pool);
		toChangeImpl(&change, &message::Effect::set_spread, spread, pool);
		toChangeImpl(&change, &message::Effect::set_visible, visible, pool);
		toChangeImpl(&change, &message::Effect::set_blendMode, blendMode, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Effect>();
		toChange(*change, pool);
		return change;
	}

};

struct BlurEffect  {
	float radius;
	bool visible;

	void applyChange(const message::Effect& change) {
		if (change.radius() != nullptr) {
			applyChangeImpl(radius, *change.radius());
		}
		if (change.visible() != nullptr) {
			applyChangeImpl(visible, *change.visible());
		}
	}

	void toChange(message::Effect& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Effect::set_radius, radius, pool);
		toChangeImpl(&change, &message::Effect::set_visible, visible, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Effect>();
		toChange(*change, pool);
		return change;
	}

};

struct ColorStop  {
	float position;
	Color color;

	void applyChange(const message::ColorStop& change) {
		if (change.position() != nullptr) {
			applyChangeImpl(position, *change.position());
		}
		if (change.color() != nullptr) {
			applyChangeImpl(color, *change.color());
		}
	}

	void toChange(message::ColorStop& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::ColorStop::set_position, position, pool);
		toChangeImpl(&change, &message::ColorStop::set_color, color, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::ColorStop>();
		toChange(*change, pool);
		return change;
	}

};

struct Paint  {
	PaintType type;
	bool visible;
	float opacity;
	BlendMode blendMode;

	void applyChange(const message::Paint& change) {
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

	void toChange(message::Paint& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Paint::set_type, type, pool);
		toChangeImpl(&change, &message::Paint::set_visible, visible, pool);
		toChangeImpl(&change, &message::Paint::set_opacity, opacity, pool);
		toChangeImpl(&change, &message::Paint::set_blendMode, blendMode, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Paint>();
		toChange(*change, pool);
		return change;
	}

};

struct SolidPaint : public Paint {
	Color color;

	void applyChange(const message::Paint& change) {
		if (change.color() != nullptr) {
			applyChangeImpl(color, *change.color());
		}
	}

	void toChange(message::Paint& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Paint::set_color, color, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Paint>();
		toChange(*change, pool);
		return change;
	}

};

struct GradientPaint : public Paint {
	Matrix transform;
	Array<ColorStop> stops;

	void applyChange(const message::Paint& change) {
		if (change.transform() != nullptr) {
			applyChangeImpl(transform, *change.transform());
		}
		if (change.stops() != nullptr) {
			applyChangeImpl(stops, *change.stops());
		}
	}

	void toChange(message::Paint& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Paint::set_transform, transform, pool);
		toChangeImpl(&change, &message::Paint::set_stops, stops, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Paint>();
		toChange(*change, pool);
		return change;
	}

};

struct ImagePaint : public Paint {
	ImageScaleMode imageScaleMode;
	Matrix transform;

	void applyChange(const message::Paint& change) {
		if (change.imageScaleMode() != nullptr) {
			applyChangeImpl(imageScaleMode, *change.imageScaleMode());
		}
		if (change.transform() != nullptr) {
			applyChangeImpl(transform, *change.transform());
		}
	}

	void toChange(message::Paint& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Paint::set_imageScaleMode, imageScaleMode, pool);
		toChangeImpl(&change, &message::Paint::set_transform, transform, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Paint>();
		toChange(*change, pool);
		return change;
	}

};

struct Path  {
	WindingRule windingRule;
	uint commandsBlob;

	void applyChange(const message::Path& change) {
		if (change.windingRule() != nullptr) {
			applyChangeImpl(windingRule, *change.windingRule());
		}
		if (change.commandsBlob() != nullptr) {
			applyChangeImpl(commandsBlob, *change.commandsBlob());
		}
	}

	void toChange(message::Path& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Path::set_windingRule, windingRule, pool);
		toChangeImpl(&change, &message::Path::set_commandsBlob, commandsBlob, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Path>();
		toChange(*change, pool);
		return change;
	}

};

struct ParentIndex  {
	GUID guid;
	string position;

	void applyChange(const message::ParentIndex& change) {
		if (change.guid() != nullptr) {
			applyChangeImpl(guid, *change.guid());
		}
		if (change.position() != nullptr) {
			applyChangeImpl(position, *change.position());
		}
	}

	void toChange(message::ParentIndex& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::ParentIndex::set_guid, guid, pool);
		toChangeImpl(&change, &message::ParentIndex::set_position, position, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::ParentIndex>();
		toChange(*change, pool);
		return change;
	}

};

struct AssetRef  {
	string key;
	string version;

	void applyChange(const message::AssetRef& change) {
		if (change.key() != nullptr) {
			applyChangeImpl(key, *change.key());
		}
		if (change.version() != nullptr) {
			applyChangeImpl(version, *change.version());
		}
	}

	void toChange(message::AssetRef& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::AssetRef::set_key, key, pool);
		toChangeImpl(&change, &message::AssetRef::set_version, version, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::AssetRef>();
		toChange(*change, pool);
		return change;
	}

};

struct StyleId  {
	GUID guid;
	AssetRef assetRef;

	void applyChange(const message::StyleId& change) {
		if (change.guid() != nullptr) {
			applyChangeImpl(guid, *change.guid());
		}
		if (change.assetRef() != nullptr) {
			applyChangeImpl(assetRef, *change.assetRef());
		}
	}

	void toChange(message::StyleId& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::StyleId::set_guid, guid, pool);
		toChangeImpl(&change, &message::StyleId::set_assetRef, assetRef, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::StyleId>();
		toChange(*change, pool);
		return change;
	}

};

struct ArcData  {
	float startingAngle;
	float endingAngle;
	float innerRadius;

	void applyChange(const message::ArcData& change) {
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

	void toChange(message::ArcData& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::ArcData::set_startingAngle, startingAngle, pool);
		toChangeImpl(&change, &message::ArcData::set_endingAngle, endingAngle, pool);
		toChangeImpl(&change, &message::ArcData::set_innerRadius, innerRadius, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::ArcData>();
		toChange(*change, pool);
		return change;
	}

};

struct VectorData  {
	uint vectorNetworkBlob;

	void applyChange(const message::VectorData& change) {
		if (change.vectorNetworkBlob() != nullptr) {
			applyChangeImpl(vectorNetworkBlob, *change.vectorNetworkBlob());
		}
	}

	void toChange(message::VectorData& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::VectorData::set_vectorNetworkBlob, vectorNetworkBlob, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::VectorData>();
		toChange(*change, pool);
		return change;
	}

};

struct Glyph  {
	uint styleID;
	uint commandsBlob;
	Vector position;
	float fontSize;
	float advance;

	void applyChange(const message::Glyph& change) {
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

	void toChange(message::Glyph& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Glyph::set_styleID, styleID, pool);
		toChangeImpl(&change, &message::Glyph::set_commandsBlob, commandsBlob, pool);
		toChangeImpl(&change, &message::Glyph::set_position, position, pool);
		toChangeImpl(&change, &message::Glyph::set_fontSize, fontSize, pool);
		toChangeImpl(&change, &message::Glyph::set_advance, advance, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Glyph>();
		toChange(*change, pool);
		return change;
	}

};

struct Decoration  {
	Array<Rect> rects;

	void applyChange(const message::Decoration& change) {
		if (change.rects() != nullptr) {
			applyChangeImpl(rects, *change.rects());
		}
	}

	void toChange(message::Decoration& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Decoration::set_rects, rects, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Decoration>();
		toChange(*change, pool);
		return change;
	}

};

struct Baseline  {
	Vector position;
	float width;
	float lineY;
	float lineHeight;
	float lineAscent;
	uint firstCharacter;
	uint endCharacter;

	void applyChange(const message::Baseline& change) {
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

	void toChange(message::Baseline& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::Baseline::set_position, position, pool);
		toChangeImpl(&change, &message::Baseline::set_width, width, pool);
		toChangeImpl(&change, &message::Baseline::set_lineY, lineY, pool);
		toChangeImpl(&change, &message::Baseline::set_lineHeight, lineHeight, pool);
		toChangeImpl(&change, &message::Baseline::set_lineAscent, lineAscent, pool);
		toChangeImpl(&change, &message::Baseline::set_firstCharacter, firstCharacter, pool);
		toChangeImpl(&change, &message::Baseline::set_endCharacter, endCharacter, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::Baseline>();
		toChange(*change, pool);
		return change;
	}

};

struct TextData  {
	string characters;
	Buffer styleOverrideTable;
	Vector layoutSize;
	Array<Baseline> baselines;
	Array<Glyph> glyphs;
	Array<Decoration> decorations;

	void applyChange(const message::TextData& change) {
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

	void toChange(message::TextData& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::TextData::set_characters, characters, pool);
		toChangeImpl(&change, &message::TextData::set_styleOverrideTable, styleOverrideTable, pool);
		toChangeImpl(&change, &message::TextData::set_layoutSize, layoutSize, pool);
		toChangeImpl(&change, &message::TextData::set_baselines, baselines, pool);
		toChangeImpl(&change, &message::TextData::set_glyphs, glyphs, pool);
		toChangeImpl(&change, &message::TextData::set_decorations, decorations, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::TextData>();
		toChange(*change, pool);
		return change;
	}

};

struct SymbolData  {
	GUID symbolID;
	Buffer symbolOverrides;
	float uniformScaleFactor;

	void applyChange(const message::SymbolData& change) {
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

	void toChange(message::SymbolData& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::SymbolData::set_symbolID, symbolID, pool);
		toChangeImpl(&change, &message::SymbolData::set_symbolOverrides, symbolOverrides, pool);
		toChangeImpl(&change, &message::SymbolData::set_uniformScaleFactor, uniformScaleFactor, pool);
	}

	auto* toChange(kiwi::MemoryPool& pool) const {
		auto* change = pool.allocate<message::SymbolData>();
		toChange(*change, pool);
		return change;
	}

};


class BaseNodeMixin  {
private:
	GUID guid_;
	ParentIndex parentIndex_;
	string name_;
	NodeType type_;
	BaseNodeMixinPointer nextSibling_{};

public:

	const GUID getGuid() const {
		return guid_;
	}
	void setGuid(const GUID& value) {
		guid_ = value;
	}
	const ParentIndex getParentIndex() const {
		return parentIndex_;
	}
	void setParentIndex(const ParentIndex& value) {
		parentIndex_ = value;
	}
	const string getName() const {
		return name_;
	}
	void setName(const string& value) {
		name_ = value;
	}
	const NodeType getType() const {
		return type_;
	}
	void setType(const NodeType& value) {
		type_ = value;
	}
	const BaseNodeMixinPointer getNextSibling() const {
		return nextSibling_;
	}
	void setNextSibling(const BaseNodeMixinPointer& value) {
		nextSibling_ = value;
	}

	virtual void applyChange(const message::NodeChange& change) {
		if (change.guid() != nullptr) {
			applyChangeImpl(guid_, *change.guid());
		}
		if (change.parentIndex() != nullptr) {
			applyChangeImpl(parentIndex_, *change.parentIndex());
		}
		if (change.name() != nullptr) {
			applyChangeImpl(name_, *change.name());
		}
		if (change.type() != nullptr) {
			applyChangeImpl(type_, *change.type());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_guid, guid_, pool);
		toChangeImpl(&change, &message::NodeChange::set_parentIndex, parentIndex_, pool);
		toChangeImpl(&change, &message::NodeChange::set_name, name_, pool);
		toChangeImpl(&change, &message::NodeChange::set_type, type_, pool);
	}

};

class SceneNodeMixin  {
private:
	boolean visible_;
	boolean locked_;

public:

	const boolean getVisible() const {
		return visible_;
	}
	void setVisible(const boolean& value) {
		visible_ = value;
	}
	const boolean getLocked() const {
		return locked_;
	}
	void setLocked(const boolean& value) {
		locked_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.visible() != nullptr) {
			applyChangeImpl(visible_, *change.visible());
		}
		if (change.locked() != nullptr) {
			applyChangeImpl(locked_, *change.locked());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_visible, visible_, pool);
		toChangeImpl(&change, &message::NodeChange::set_locked, locked_, pool);
	}

};

class CornerMixin  {
private:
	float cornerRadius_;
	float cornerSmoothing_;

public:

	const float getCornerRadius() const {
		return cornerRadius_;
	}
	void setCornerRadius(const float& value) {
		cornerRadius_ = value;
	}
	const float getCornerSmoothing() const {
		return cornerSmoothing_;
	}
	void setCornerSmoothing(const float& value) {
		cornerSmoothing_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.cornerRadius() != nullptr) {
			applyChangeImpl(cornerRadius_, *change.cornerRadius());
		}
		if (change.cornerSmoothing() != nullptr) {
			applyChangeImpl(cornerSmoothing_, *change.cornerSmoothing());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_cornerRadius, cornerRadius_, pool);
		toChangeImpl(&change, &message::NodeChange::set_cornerSmoothing, cornerSmoothing_, pool);
	}

};

class RectangleCornerMixin  {
private:
	float rectangleTopLeftCornerRadius_;
	float rectangleTopRightCornerRadius_;
	float rectangleBottomLeftCornerRadius_;
	float rectangleBottomRightCornerRadius_;

public:

	const float getRectangleTopLeftCornerRadius() const {
		return rectangleTopLeftCornerRadius_;
	}
	void setRectangleTopLeftCornerRadius(const float& value) {
		rectangleTopLeftCornerRadius_ = value;
	}
	const float getRectangleTopRightCornerRadius() const {
		return rectangleTopRightCornerRadius_;
	}
	void setRectangleTopRightCornerRadius(const float& value) {
		rectangleTopRightCornerRadius_ = value;
	}
	const float getRectangleBottomLeftCornerRadius() const {
		return rectangleBottomLeftCornerRadius_;
	}
	void setRectangleBottomLeftCornerRadius(const float& value) {
		rectangleBottomLeftCornerRadius_ = value;
	}
	const float getRectangleBottomRightCornerRadius() const {
		return rectangleBottomRightCornerRadius_;
	}
	void setRectangleBottomRightCornerRadius(const float& value) {
		rectangleBottomRightCornerRadius_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.rectangleTopLeftCornerRadius() != nullptr) {
			applyChangeImpl(rectangleTopLeftCornerRadius_, *change.rectangleTopLeftCornerRadius());
		}
		if (change.rectangleTopRightCornerRadius() != nullptr) {
			applyChangeImpl(rectangleTopRightCornerRadius_, *change.rectangleTopRightCornerRadius());
		}
		if (change.rectangleBottomLeftCornerRadius() != nullptr) {
			applyChangeImpl(rectangleBottomLeftCornerRadius_, *change.rectangleBottomLeftCornerRadius());
		}
		if (change.rectangleBottomRightCornerRadius() != nullptr) {
			applyChangeImpl(rectangleBottomRightCornerRadius_, *change.rectangleBottomRightCornerRadius());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_rectangleTopLeftCornerRadius, rectangleTopLeftCornerRadius_, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleTopRightCornerRadius, rectangleTopRightCornerRadius_, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleBottomLeftCornerRadius, rectangleBottomLeftCornerRadius_, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleBottomRightCornerRadius, rectangleBottomRightCornerRadius_, pool);
	}

};

class IndividualStrokesMixin  {
private:
	float borderTopWeight_;
	float borderBottomWeight_;
	float borderLeftWeight_;
	float borderRightWeight_;

public:

	const float getBorderTopWeight() const {
		return borderTopWeight_;
	}
	void setBorderTopWeight(const float& value) {
		borderTopWeight_ = value;
	}
	const float getBorderBottomWeight() const {
		return borderBottomWeight_;
	}
	void setBorderBottomWeight(const float& value) {
		borderBottomWeight_ = value;
	}
	const float getBorderLeftWeight() const {
		return borderLeftWeight_;
	}
	void setBorderLeftWeight(const float& value) {
		borderLeftWeight_ = value;
	}
	const float getBorderRightWeight() const {
		return borderRightWeight_;
	}
	void setBorderRightWeight(const float& value) {
		borderRightWeight_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.borderTopWeight() != nullptr) {
			applyChangeImpl(borderTopWeight_, *change.borderTopWeight());
		}
		if (change.borderBottomWeight() != nullptr) {
			applyChangeImpl(borderBottomWeight_, *change.borderBottomWeight());
		}
		if (change.borderLeftWeight() != nullptr) {
			applyChangeImpl(borderLeftWeight_, *change.borderLeftWeight());
		}
		if (change.borderRightWeight() != nullptr) {
			applyChangeImpl(borderRightWeight_, *change.borderRightWeight());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_borderTopWeight, borderTopWeight_, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderBottomWeight, borderBottomWeight_, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderLeftWeight, borderLeftWeight_, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderRightWeight, borderRightWeight_, pool);
	}

};

class MinimalStrokesMixin  {
private:
	Array<PaintUnion> strokePaints_;
	StyleId styleIdForStrokeFill_;
	float strokeWeight_;
	StrokeJoin strokeJoin_;
	StrokeAlign strokeAlign_;
	Array<float> dashPattern_;
	Array<Path> strokeGeometry_;

public:

	const Array<PaintUnion> getStrokePaints() const {
		return strokePaints_;
	}
	void setStrokePaints(const Array<PaintUnion>& value) {
		strokePaints_ = value;
	}
	const StyleId getStyleIdForStrokeFill() const {
		return styleIdForStrokeFill_;
	}
	void setStyleIdForStrokeFill(const StyleId& value) {
		styleIdForStrokeFill_ = value;
	}
	const float getStrokeWeight() const {
		return strokeWeight_;
	}
	void setStrokeWeight(const float& value) {
		strokeWeight_ = value;
	}
	const StrokeJoin getStrokeJoin() const {
		return strokeJoin_;
	}
	void setStrokeJoin(const StrokeJoin& value) {
		strokeJoin_ = value;
	}
	const StrokeAlign getStrokeAlign() const {
		return strokeAlign_;
	}
	void setStrokeAlign(const StrokeAlign& value) {
		strokeAlign_ = value;
	}
	const Array<float> getDashPattern() const {
		return dashPattern_;
	}
	void setDashPattern(const Array<float>& value) {
		dashPattern_ = value;
	}
	const Array<Path> getStrokeGeometry() const {
		return strokeGeometry_;
	}
	void setStrokeGeometry(const Array<Path>& value) {
		strokeGeometry_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.strokePaints() != nullptr) {
			applyChangeImpl(strokePaints_, *change.strokePaints());
		}
		if (change.styleIdForStrokeFill() != nullptr) {
			applyChangeImpl(styleIdForStrokeFill_, *change.styleIdForStrokeFill());
		}
		if (change.strokeWeight() != nullptr) {
			applyChangeImpl(strokeWeight_, *change.strokeWeight());
		}
		if (change.strokeJoin() != nullptr) {
			applyChangeImpl(strokeJoin_, *change.strokeJoin());
		}
		if (change.strokeAlign() != nullptr) {
			applyChangeImpl(strokeAlign_, *change.strokeAlign());
		}
		if (change.dashPattern() != nullptr) {
			applyChangeImpl(dashPattern_, *change.dashPattern());
		}
		if (change.strokeGeometry() != nullptr) {
			applyChangeImpl(strokeGeometry_, *change.strokeGeometry());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_strokePaints, strokePaints_, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill_, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeWeight, strokeWeight_, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeJoin, strokeJoin_, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeAlign, strokeAlign_, pool);
		toChangeImpl(&change, &message::NodeChange::set_dashPattern, dashPattern_, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeGeometry, strokeGeometry_, pool);
	}

};

class MinimalFillsMixin  {
private:
	Array<PaintUnion> fillPaints_;
	StyleId styleIdForStrokeFill_;

public:

	const Array<PaintUnion> getFillPaints() const {
		return fillPaints_;
	}
	void setFillPaints(const Array<PaintUnion>& value) {
		fillPaints_ = value;
	}
	const StyleId getStyleIdForStrokeFill() const {
		return styleIdForStrokeFill_;
	}
	void setStyleIdForStrokeFill(const StyleId& value) {
		styleIdForStrokeFill_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.fillPaints() != nullptr) {
			applyChangeImpl(fillPaints_, *change.fillPaints());
		}
		if (change.styleIdForStrokeFill() != nullptr) {
			applyChangeImpl(styleIdForStrokeFill_, *change.styleIdForStrokeFill());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_fillPaints, fillPaints_, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill_, pool);
	}

};

class DimensionAndPositionMixin  {
private:
	Vector size_;
	Matrix transform_;

public:

	const Vector getSize() const {
		return size_;
	}
	void setSize(const Vector& value) {
		size_ = value;
	}
	const Matrix getTransform() const {
		return transform_;
	}
	void setTransform(const Matrix& value) {
		transform_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.size() != nullptr) {
			applyChangeImpl(size_, *change.size());
		}
		if (change.transform() != nullptr) {
			applyChangeImpl(transform_, *change.transform());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_size, size_, pool);
		toChangeImpl(&change, &message::NodeChange::set_transform, transform_, pool);
	}

};

class ConstraintMixin  {
private:
	ConstraintType horizontalConstraint_;
	ConstraintType verticalConstraint_;

public:

	const ConstraintType getHorizontalConstraint() const {
		return horizontalConstraint_;
	}
	void setHorizontalConstraint(const ConstraintType& value) {
		horizontalConstraint_ = value;
	}
	const ConstraintType getVerticalConstraint() const {
		return verticalConstraint_;
	}
	void setVerticalConstraint(const ConstraintType& value) {
		verticalConstraint_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.horizontalConstraint() != nullptr) {
			applyChangeImpl(horizontalConstraint_, *change.horizontalConstraint());
		}
		if (change.verticalConstraint() != nullptr) {
			applyChangeImpl(verticalConstraint_, *change.verticalConstraint());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_horizontalConstraint, horizontalConstraint_, pool);
		toChangeImpl(&change, &message::NodeChange::set_verticalConstraint, verticalConstraint_, pool);
	}

};

class EffectMixin  {
private:
	Array<Effect> effects_;
	StyleId styleIdForEffect_;

public:

	const Array<Effect> getEffects() const {
		return effects_;
	}
	void setEffects(const Array<Effect>& value) {
		effects_ = value;
	}
	const StyleId getStyleIdForEffect() const {
		return styleIdForEffect_;
	}
	void setStyleIdForEffect(const StyleId& value) {
		styleIdForEffect_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.effects() != nullptr) {
			applyChangeImpl(effects_, *change.effects());
		}
		if (change.styleIdForEffect() != nullptr) {
			applyChangeImpl(styleIdForEffect_, *change.styleIdForEffect());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_effects, effects_, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForEffect, styleIdForEffect_, pool);
	}

};

class ExportMixin  {
private:

public:


	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
	}

};

class BlendMixin  {
private:

public:


	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
	}

};

class AutoLayoutMixin  {
private:
	StackMode stackMode_;
	StackWrap stackWrap_;
	float stackPaddingRight_;
	float stackPaddingBottom_;
	float stackHorizontalPadding_;
	float stackVerticalPadding_;

public:

	const StackMode getStackMode() const {
		return stackMode_;
	}
	void setStackMode(const StackMode& value) {
		stackMode_ = value;
	}
	const StackWrap getStackWrap() const {
		return stackWrap_;
	}
	void setStackWrap(const StackWrap& value) {
		stackWrap_ = value;
	}
	const float getStackPaddingRight() const {
		return stackPaddingRight_;
	}
	void setStackPaddingRight(const float& value) {
		stackPaddingRight_ = value;
	}
	const float getStackPaddingBottom() const {
		return stackPaddingBottom_;
	}
	void setStackPaddingBottom(const float& value) {
		stackPaddingBottom_ = value;
	}
	const float getStackHorizontalPadding() const {
		return stackHorizontalPadding_;
	}
	void setStackHorizontalPadding(const float& value) {
		stackHorizontalPadding_ = value;
	}
	const float getStackVerticalPadding() const {
		return stackVerticalPadding_;
	}
	void setStackVerticalPadding(const float& value) {
		stackVerticalPadding_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.stackMode() != nullptr) {
			applyChangeImpl(stackMode_, *change.stackMode());
		}
		if (change.stackWrap() != nullptr) {
			applyChangeImpl(stackWrap_, *change.stackWrap());
		}
		if (change.stackPaddingRight() != nullptr) {
			applyChangeImpl(stackPaddingRight_, *change.stackPaddingRight());
		}
		if (change.stackPaddingBottom() != nullptr) {
			applyChangeImpl(stackPaddingBottom_, *change.stackPaddingBottom());
		}
		if (change.stackHorizontalPadding() != nullptr) {
			applyChangeImpl(stackHorizontalPadding_, *change.stackHorizontalPadding());
		}
		if (change.stackVerticalPadding() != nullptr) {
			applyChangeImpl(stackVerticalPadding_, *change.stackVerticalPadding());
		}
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_stackMode, stackMode_, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackWrap, stackWrap_, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackPaddingRight, stackPaddingRight_, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackPaddingBottom, stackPaddingBottom_, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackHorizontalPadding, stackHorizontalPadding_, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackVerticalPadding, stackVerticalPadding_, pool);
	}

};

class GeometryMixin : public MinimalStrokesMixin, public MinimalFillsMixin {
private:
	StrokeCap strokeCap_;
	float miterLimit_;
	Array<Path> fillGeometry_;

public:

	const StrokeCap getStrokeCap() const {
		return strokeCap_;
	}
	void setStrokeCap(const StrokeCap& value) {
		strokeCap_ = value;
	}
	const float getMiterLimit() const {
		return miterLimit_;
	}
	void setMiterLimit(const float& value) {
		miterLimit_ = value;
	}
	const Array<Path> getFillGeometry() const {
		return fillGeometry_;
	}
	void setFillGeometry(const Array<Path>& value) {
		fillGeometry_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.strokeCap() != nullptr) {
			applyChangeImpl(strokeCap_, *change.strokeCap());
		}
		if (change.miterLimit() != nullptr) {
			applyChangeImpl(miterLimit_, *change.miterLimit());
		}
		if (change.fillGeometry() != nullptr) {
			applyChangeImpl(fillGeometry_, *change.fillGeometry());
		}
		MinimalStrokesMixin::applyChange(change);
		MinimalFillsMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_strokeCap, strokeCap_, pool);
		toChangeImpl(&change, &message::NodeChange::set_miterLimit, miterLimit_, pool);
		toChangeImpl(&change, &message::NodeChange::set_fillGeometry, fillGeometry_, pool);
		MinimalStrokesMixin::toChange(change, pool);
		MinimalFillsMixin::toChange(change, pool);
	}

};

class LayoutMixin : public DimensionAndPositionMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DimensionAndPositionMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DimensionAndPositionMixin::toChange(change, pool);
	}

};

class DefaultShapeNode : public BaseNodeMixin, public SceneNodeMixin, public ExportMixin, public BlendMixin, public GeometryMixin, public LayoutMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		BaseNodeMixin::applyChange(change);
		SceneNodeMixin::applyChange(change);
		ExportMixin::applyChange(change);
		BlendMixin::applyChange(change);
		GeometryMixin::applyChange(change);
		LayoutMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		BaseNodeMixin::toChange(change, pool);
		SceneNodeMixin::toChange(change, pool);
		ExportMixin::toChange(change, pool);
		BlendMixin::toChange(change, pool);
		GeometryMixin::toChange(change, pool);
		LayoutMixin::toChange(change, pool);
	}

};

class BaseFrameMixin : public DefaultShapeNode, public CornerMixin, public RectangleCornerMixin, public EffectMixin, public ConstraintMixin, public IndividualStrokesMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		CornerMixin::applyChange(change);
		RectangleCornerMixin::applyChange(change);
		EffectMixin::applyChange(change);
		ConstraintMixin::applyChange(change);
		IndividualStrokesMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultShapeNode::toChange(change, pool);
		CornerMixin::toChange(change, pool);
		RectangleCornerMixin::toChange(change, pool);
		EffectMixin::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		IndividualStrokesMixin::toChange(change, pool);
	}

};

class DefaultFrameMixin : public BaseFrameMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		BaseFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		BaseFrameMixin::toChange(change, pool);
	}

};

class SubTextMixin : public DefaultShapeNode {
private:
	uint styleID_;
	Number letterSpacing_;
	Number lineHeight_;

public:

	const uint getStyleID() const {
		return styleID_;
	}
	void setStyleID(const uint& value) {
		styleID_ = value;
	}
	const Number getLetterSpacing() const {
		return letterSpacing_;
	}
	void setLetterSpacing(const Number& value) {
		letterSpacing_ = value;
	}
	const Number getLineHeight() const {
		return lineHeight_;
	}
	void setLineHeight(const Number& value) {
		lineHeight_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.styleID() != nullptr) {
			applyChangeImpl(styleID_, *change.styleID());
		}
		if (change.letterSpacing() != nullptr) {
			applyChangeImpl(letterSpacing_, *change.letterSpacing());
		}
		if (change.lineHeight() != nullptr) {
			applyChangeImpl(lineHeight_, *change.lineHeight());
		}
		DefaultShapeNode::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_styleID, styleID_, pool);
		toChangeImpl(&change, &message::NodeChange::set_letterSpacing, letterSpacing_, pool);
		toChangeImpl(&change, &message::NodeChange::set_lineHeight, lineHeight_, pool);
		DefaultShapeNode::toChange(change, pool);
	}

};

class TextNodeMixin : public DefaultShapeNode {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultShapeNode::toChange(change, pool);
	}

};

class RectangleNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin, public RectangleCornerMixin, public IndividualStrokesMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
		RectangleCornerMixin::applyChange(change);
		IndividualStrokesMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
		RectangleCornerMixin::toChange(change, pool);
		IndividualStrokesMixin::toChange(change, pool);
	}

};

class LineNodeBase : public DefaultShapeNode, public ConstraintMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
	}

};

class EllipseNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	ArcData arcData_;

public:

	const ArcData getArcData() const {
		return arcData_;
	}
	void setArcData(const ArcData& value) {
		arcData_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.arcData() != nullptr) {
			applyChangeImpl(arcData_, *change.arcData());
		}
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_arcData, arcData_, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class PolygonNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	uint count_;

public:

	const uint getCount() const {
		return count_;
	}
	void setCount(const uint& value) {
		count_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.count() != nullptr) {
			applyChangeImpl(count_, *change.count());
		}
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_count, count_, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class StarNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	uint count_;

public:

	const uint getCount() const {
		return count_;
	}
	void setCount(const uint& value) {
		count_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.count() != nullptr) {
			applyChangeImpl(count_, *change.count());
		}
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_count, count_, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class VectorNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
private:
	VectorData vectorData_;

public:

	const VectorData getVectorData() const {
		return vectorData_;
	}
	void setVectorData(const VectorData& value) {
		vectorData_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.vectorData() != nullptr) {
			applyChangeImpl(vectorData_, *change.vectorData());
		}
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_vectorData, vectorData_, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class FrameNodeBase : public DefaultFrameMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultFrameMixin::toChange(change, pool);
	}

};

class SymbolNodeBase : public DefaultFrameMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultFrameMixin::toChange(change, pool);
	}

};

class InstanceNodeBase : public DefaultFrameMixin {
private:
	SymbolData symbolData_;
	Buffer derivedSymbolData_;

public:

	const SymbolData getSymbolData() const {
		return symbolData_;
	}
	void setSymbolData(const SymbolData& value) {
		symbolData_ = value;
	}
	const Buffer getDerivedSymbolData() const {
		return derivedSymbolData_;
	}
	void setDerivedSymbolData(const Buffer& value) {
		derivedSymbolData_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.symbolData() != nullptr) {
			applyChangeImpl(symbolData_, *change.symbolData());
		}
		if (change.derivedSymbolData() != nullptr) {
			applyChangeImpl(derivedSymbolData_, *change.derivedSymbolData());
		}
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_symbolData, symbolData_, pool);
		toChangeImpl(&change, &message::NodeChange::set_derivedSymbolData, derivedSymbolData_, pool);
		DefaultFrameMixin::toChange(change, pool);
	}

};

class TextNodeBase : public TextNodeMixin {
private:
	TextData textData_;

public:

	const TextData getTextData() const {
		return textData_;
	}
	void setTextData(const TextData& value) {
		textData_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.textData() != nullptr) {
			applyChangeImpl(textData_, *change.textData());
		}
		TextNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_textData, textData_, pool);
		TextNodeMixin::toChange(change, pool);
	}

};

class PageNodeBase : public BaseNodeMixin {
private:
	Color backgroundColor_;
	float backgroundOpacity_;
	bool backgroundEnabled_;

public:

	const Color getBackgroundColor() const {
		return backgroundColor_;
	}
	void setBackgroundColor(const Color& value) {
		backgroundColor_ = value;
	}
	const float getBackgroundOpacity() const {
		return backgroundOpacity_;
	}
	void setBackgroundOpacity(const float& value) {
		backgroundOpacity_ = value;
	}
	const bool getBackgroundEnabled() const {
		return backgroundEnabled_;
	}
	void setBackgroundEnabled(const bool& value) {
		backgroundEnabled_ = value;
	}

	void applyChange(const message::NodeChange& change) {
		if (change.backgroundColor() != nullptr) {
			applyChangeImpl(backgroundColor_, *change.backgroundColor());
		}
		if (change.backgroundOpacity() != nullptr) {
			applyChangeImpl(backgroundOpacity_, *change.backgroundOpacity());
		}
		if (change.backgroundEnabled() != nullptr) {
			applyChangeImpl(backgroundEnabled_, *change.backgroundEnabled());
		}
		BaseNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_backgroundColor, backgroundColor_, pool);
		toChangeImpl(&change, &message::NodeChange::set_backgroundOpacity, backgroundOpacity_, pool);
		toChangeImpl(&change, &message::NodeChange::set_backgroundEnabled, backgroundEnabled_, pool);
		BaseNodeMixin::toChange(change, pool);
	}

};

class DocumentNodeBase : public BaseNodeMixin {
private:

public:


	void applyChange(const message::NodeChange& change) {
		BaseNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		BaseNodeMixin::toChange(change, pool);
	}

};


}