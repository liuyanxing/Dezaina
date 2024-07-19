#pragma once

#include <string>
#include <variant>

#include "common/buffer.h"
#include "message.h"
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

struct SolidPaint  {
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

struct GradientPaint  {
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

struct ImagePaint  {
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
protected:
	GUID guid;
	ParentIndex parentIndex;
	string name;
	NodeType type;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_guid, guid, pool);
		toChangeImpl(&change, &message::NodeChange::set_parentIndex, parentIndex, pool);
		toChangeImpl(&change, &message::NodeChange::set_name, name, pool);
		toChangeImpl(&change, &message::NodeChange::set_type, type, pool);
	}

};

class SceneNodeMixin  {
protected:
	boolean visible;
	boolean locked;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_visible, visible, pool);
		toChangeImpl(&change, &message::NodeChange::set_locked, locked, pool);
	}

};

class CornerMixin  {
protected:
	float cornerRadius;
	float cornerSmoothing;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_cornerRadius, cornerRadius, pool);
		toChangeImpl(&change, &message::NodeChange::set_cornerSmoothing, cornerSmoothing, pool);
	}

};

class RectangleCornerMixin  {
protected:
	float rectangleTopLeftCornerRadius;
	float rectangleTopRightCornerRadius;
	float rectangleBottomLeftCornerRadius;
	float rectangleBottomRightCornerRadius;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_rectangleTopLeftCornerRadius, rectangleTopLeftCornerRadius, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleTopRightCornerRadius, rectangleTopRightCornerRadius, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleBottomLeftCornerRadius, rectangleBottomLeftCornerRadius, pool);
		toChangeImpl(&change, &message::NodeChange::set_rectangleBottomRightCornerRadius, rectangleBottomRightCornerRadius, pool);
	}

};

class IndividualStrokesMixin  {
protected:
	float borderTopWeight;
	float borderBottomWeight;
	float borderLeftWeight;
	float borderRightWeight;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_borderTopWeight, borderTopWeight, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderBottomWeight, borderBottomWeight, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderLeftWeight, borderLeftWeight, pool);
		toChangeImpl(&change, &message::NodeChange::set_borderRightWeight, borderRightWeight, pool);
	}

};

class MinimalStrokesMixin  {
protected:
	Array<PaintUnion> strokePaints;
	StyleId styleIdForStrokeFill;
	float strokeWeight;
	StrokeJoin strokeJoin;
	StrokeAlign strokeAlign;
	Array<float> dashPattern;
	Array<Path> strokeGeometry;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_strokePaints, strokePaints, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeWeight, strokeWeight, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeJoin, strokeJoin, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeAlign, strokeAlign, pool);
		toChangeImpl(&change, &message::NodeChange::set_dashPattern, dashPattern, pool);
		toChangeImpl(&change, &message::NodeChange::set_strokeGeometry, strokeGeometry, pool);
	}

};

class MinimalFillsMixin  {
protected:
	Array<PaintUnion> fillPaints;
	StyleId styleIdForStrokeFill;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_fillPaints, fillPaints, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForStrokeFill, styleIdForStrokeFill, pool);
	}

};

class DimensionAndPositionMixin  {
protected:
	Vector size;
	Matrix transform;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_size, size, pool);
		toChangeImpl(&change, &message::NodeChange::set_transform, transform, pool);
	}

};

class ConstraintMixin  {
protected:
	ConstraintType horizontalConstraint;
	ConstraintType verticalConstraint;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_horizontalConstraint, horizontalConstraint, pool);
		toChangeImpl(&change, &message::NodeChange::set_verticalConstraint, verticalConstraint, pool);
	}

};

class EffectMixin  {
protected:
	Array<Effect> effects;
	StyleId styleIdForEffect;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_effects, effects, pool);
		toChangeImpl(&change, &message::NodeChange::set_styleIdForEffect, styleIdForEffect, pool);
	}

};

class ExportMixin  {
protected:

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
	}

};

class BlendMixin  {
protected:

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
	}

};

class AutoLayoutMixin  {
protected:
	StackMode stackMode;
	StackWrap stackWrap;
	float stackPaddingRight;
	float stackPaddingBottom;
	float stackHorizontalPadding;
	float stackVerticalPadding;

public:

	void applyChange(const message::NodeChange& change) {
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_stackMode, stackMode, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackWrap, stackWrap, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackPaddingRight, stackPaddingRight, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackPaddingBottom, stackPaddingBottom, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackHorizontalPadding, stackHorizontalPadding, pool);
		toChangeImpl(&change, &message::NodeChange::set_stackVerticalPadding, stackVerticalPadding, pool);
	}

};

class GeometryMixin : public MinimalStrokesMixin, public MinimalFillsMixin {
protected:
	StrokeCap strokeCap;
	float miterLimit;
	Array<Path> fillGeometry;

public:

	void applyChange(const message::NodeChange& change) {
		MinimalStrokesMixin::applyChange(change);
		MinimalFillsMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_strokeCap, strokeCap, pool);
		toChangeImpl(&change, &message::NodeChange::set_miterLimit, miterLimit, pool);
		toChangeImpl(&change, &message::NodeChange::set_fillGeometry, fillGeometry, pool);
		MinimalStrokesMixin::toChange(change, pool);
		MinimalFillsMixin::toChange(change, pool);
	}

};

class LayoutMixin : public DimensionAndPositionMixin {
protected:

public:

	void applyChange(const message::NodeChange& change) {
		DimensionAndPositionMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DimensionAndPositionMixin::toChange(change, pool);
	}

};

class DefaultShapeNode : public BaseNodeMixin, public SceneNodeMixin, public ExportMixin, public BlendMixin, public GeometryMixin, public LayoutMixin {
protected:

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
protected:

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
protected:

public:

	void applyChange(const message::NodeChange& change) {
		BaseFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		BaseFrameMixin::toChange(change, pool);
	}

};

class SubTextMixin : public DefaultShapeNode {
protected:
	uint styleID;
	Number letterSpacing;
	Number lineHeight;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_styleID, styleID, pool);
		toChangeImpl(&change, &message::NodeChange::set_letterSpacing, letterSpacing, pool);
		toChangeImpl(&change, &message::NodeChange::set_lineHeight, lineHeight, pool);
		DefaultShapeNode::toChange(change, pool);
	}

};

class TextNodeMixin : public DefaultShapeNode {
protected:

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultShapeNode::toChange(change, pool);
	}

};

class RectangleNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin, public RectangleCornerMixin, public IndividualStrokesMixin {
protected:

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
protected:

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
protected:
	ArcData arcData;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_arcData, arcData, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class PolygonNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
protected:
	uint count;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_count, count, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class StarNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
protected:
	uint count;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_count, count, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class VectorNodeBase : public DefaultShapeNode, public ConstraintMixin, public CornerMixin {
protected:
	VectorData vectorData;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultShapeNode::applyChange(change);
		ConstraintMixin::applyChange(change);
		CornerMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_vectorData, vectorData, pool);
		DefaultShapeNode::toChange(change, pool);
		ConstraintMixin::toChange(change, pool);
		CornerMixin::toChange(change, pool);
	}

};

class FrameNodeBase : public DefaultFrameMixin {
protected:

public:

	void applyChange(const message::NodeChange& change) {
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultFrameMixin::toChange(change, pool);
	}

};

class SymbolNodeBase : public DefaultFrameMixin {
protected:

public:

	void applyChange(const message::NodeChange& change) {
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		DefaultFrameMixin::toChange(change, pool);
	}

};

class InstanceNodeBase : public DefaultFrameMixin {
protected:
	SymbolData symbolData;
	Buffer derivedSymbolData;

public:

	void applyChange(const message::NodeChange& change) {
		DefaultFrameMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_symbolData, symbolData, pool);
		toChangeImpl(&change, &message::NodeChange::set_derivedSymbolData, derivedSymbolData, pool);
		DefaultFrameMixin::toChange(change, pool);
	}

};

class TextNodeBase : public TextNodeMixin {
protected:
	TextData textData;

public:

	void applyChange(const message::NodeChange& change) {
		TextNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_textData, textData, pool);
		TextNodeMixin::toChange(change, pool);
	}

};

class PageNodeBase : public BaseNodeMixin {
protected:
	Color backgroundColor;
	float backgroundOpacity;
	bool backgroundEnabled;

public:

	void applyChange(const message::NodeChange& change) {
		BaseNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		toChangeImpl(&change, &message::NodeChange::set_backgroundColor, backgroundColor, pool);
		toChangeImpl(&change, &message::NodeChange::set_backgroundOpacity, backgroundOpacity, pool);
		toChangeImpl(&change, &message::NodeChange::set_backgroundEnabled, backgroundEnabled, pool);
		BaseNodeMixin::toChange(change, pool);
	}

};

class DocumentNodeBase : public BaseNodeMixin {
protected:

public:

	void applyChange(const message::NodeChange& change) {
		BaseNodeMixin::applyChange(change);
	}

	void toChange(message::NodeChange& change, kiwi::MemoryPool& pool) const {
		BaseNodeMixin::toChange(change, pool);
	}

};


}