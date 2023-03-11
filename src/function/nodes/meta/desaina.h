#include <string>
#include <vector>
#include "desaina_kiwi.h"

using  uint = uint32_t;
using string = std::string;

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

struct Matrix {
	float m00;
	float m01;
	float m02;
	float m10;
	float m11;
	float m12;
};
struct KiwiNumber {
	float value;
	NumberUnits units;
};
struct GUID {
	uint sessionId;
	uint localId;
};
struct RGB {
	float r;
	float g;
	float b;
};
struct RGBA {
	float r;
	float g;
	float b;
	float a;
};
struct ColorStop {
	float position;
	RGBA color;
};

class Vector {
private:
	static float x_default;
	float x;
	static float y_default;
	float y;
public:
	float get_x() {
		return x;
	};
	void set_x (const float& value) {
		x = value;
	};
	float get_y() {
		return y;
	};
	void set_y (const float& value) {
		y = value;
	};
void setWithKiwiData(const Desaina_Kiwi::Vector& data) {
	if (data.x() != nullptr) {
		x = *data.x();
	}
	if (data.y() != nullptr) {
		y = *data.y();
	}
}
};
class MinimalBlendMixin {
private:
	static float opacity_default;
	float opacity;
	BlendMode blendMode;
public:
	float get_opacity() {
		return opacity;
	};
	void set_opacity (const float& value) {
		opacity = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::MinimalBlendMixin& data) {
	if (data.opacity() != nullptr) {
		opacity = *data.opacity();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
	}
}
};
class Effect_kiwi {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::Effect_kiwi& data) {
}
};
class Effect {
private:
	EffectType type;
public:
	EffectType get_type() {
		return type;
	};
	void set_type (const EffectType& value) {
		type = value;
	};
void setWithKiwiData(const Desaina_Kiwi::Effect& data) {
	if (data.type() != nullptr) {
		type = *data.type();
	}
}
};
class DropShadowEffect {
private:
	RGBA color;
	Vector offset;
	static float radius_default;
	float radius;
	static float spread_default;
	float spread;
	static bool visible_default;
	bool visible;
	BlendMode blendMode;
	bool showShadowBehindNode;
public:
	RGBA get_color() {
		return color;
	};
	void set_color (const RGBA& value) {
		color = value;
	};
	Vector get_offset() {
		return offset;
	};
	void set_offset (const Vector& value) {
		offset = value;
	};
	float get_radius() {
		return radius;
	};
	void set_radius (const float& value) {
		radius = value;
	};
	float get_spread() {
		return spread;
	};
	void set_spread (const float& value) {
		spread = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
	bool get_showShadowBehindNode() {
		return showShadowBehindNode;
	};
	void set_showShadowBehindNode (const bool& value) {
		showShadowBehindNode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::DropShadowEffect& data) {
	if (data.color() != nullptr) {
		color = *data.color();
	}
	if (data.offset() != nullptr) {
		offset = *data.offset();
	}
	if (data.radius() != nullptr) {
		radius = *data.radius();
	}
	if (data.spread() != nullptr) {
		spread = *data.spread();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
	}
	if (data.showShadowBehindNode() != nullptr) {
		showShadowBehindNode = *data.showShadowBehindNode();
	}
}
};
class InnerShadowEffect {
private:
	RGBA color;
	Vector offset;
	static float radius_default;
	float radius;
	static float spread_default;
	float spread;
	static bool visible_default;
	bool visible;
	BlendMode blendMode;
public:
	RGBA get_color() {
		return color;
	};
	void set_color (const RGBA& value) {
		color = value;
	};
	Vector get_offset() {
		return offset;
	};
	void set_offset (const Vector& value) {
		offset = value;
	};
	float get_radius() {
		return radius;
	};
	void set_radius (const float& value) {
		radius = value;
	};
	float get_spread() {
		return spread;
	};
	void set_spread (const float& value) {
		spread = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::InnerShadowEffect& data) {
	if (data.color() != nullptr) {
		color = *data.color();
	}
	if (data.offset() != nullptr) {
		offset = *data.offset();
	}
	if (data.radius() != nullptr) {
		radius = *data.radius();
	}
	if (data.spread() != nullptr) {
		spread = *data.spread();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
	}
}
};
class BlurEffect {
private:
	static float radius_default;
	float radius;
	static bool visible_default;
	bool visible;
public:
	float get_radius() {
		return radius;
	};
	void set_radius (const float& value) {
		radius = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
void setWithKiwiData(const Desaina_Kiwi::BlurEffect& data) {
	if (data.radius() != nullptr) {
		radius = *data.radius();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
}
};
class MinimalFillsMixin {
private:
	std::vector<Paint> fills;
	string fillStyleId;
public:
	std::vector<Paint> get_fills() {
		return fills;
	};
	void set_fills (const std::vector<Paint>& value) {
		fills = value;
	};
	string get_fillStyleId() {
		return fillStyleId;
	};
	void set_fillStyleId (const string& value) {
		fillStyleId = value;
	};
void setWithKiwiData(const Desaina_Kiwi::MinimalFillsMixin& data) {
	if (data.fills() != nullptr) {
		fills = *data.fills();
	}
	if (data.fillStyleId() != nullptr) {
		fillStyleId = *data.fillStyleId();
	}
}
};
class DimensionAndPositionMixin {
private:
	static float width_default;
	float width;
	static float height_default;
	float height;
	Matrix transform;
public:
	float get_width() {
		return width;
	};
	void set_width (const float& value) {
		width = value;
	};
	float get_height() {
		return height;
	};
	void set_height (const float& value) {
		height = value;
	};
	Matrix get_transform() {
		return transform;
	};
	void set_transform (const Matrix& value) {
		transform = value;
	};
void setWithKiwiData(const Desaina_Kiwi::DimensionAndPositionMixin& data) {
	if (data.width() != nullptr) {
		width = *data.width();
	}
	if (data.height() != nullptr) {
		height = *data.height();
	}
	if (data.transform() != nullptr) {
		transform = *data.transform();
	}
}
};
class Constraints {
private:
	ConstraintType horizontal;
	ConstraintType vertical;
public:
	ConstraintType get_horizontal() {
		return horizontal;
	};
	void set_horizontal (const ConstraintType& value) {
		horizontal = value;
	};
	ConstraintType get_vertical() {
		return vertical;
	};
	void set_vertical (const ConstraintType& value) {
		vertical = value;
	};
void setWithKiwiData(const Desaina_Kiwi::Constraints& data) {
	if (data.horizontal() != nullptr) {
		horizontal = *data.horizontal();
	}
	if (data.vertical() != nullptr) {
		vertical = *data.vertical();
	}
}
};
class ConstraintMixin {
private:
	Constraints constraints;
public:
	Constraints get_constraints() {
		return constraints;
	};
	void set_constraints (const Constraints& value) {
		constraints = value;
	};
void setWithKiwiData(const Desaina_Kiwi::ConstraintMixin& data) {
	if (data.constraints() != nullptr) {
		constraints = *data.constraints();
	}
}
};
class LayoutMixin {
private:
	static float rotation_default;
	float rotation;
	LayoutAlignType layoutAlign;
	uint layoutGrow;
public:
	float get_rotation() {
		return rotation;
	};
	void set_rotation (const float& value) {
		rotation = value;
	};
	LayoutAlignType get_layoutAlign() {
		return layoutAlign;
	};
	void set_layoutAlign (const LayoutAlignType& value) {
		layoutAlign = value;
	};
	uint get_layoutGrow() {
		return layoutGrow;
	};
	void set_layoutGrow (const uint& value) {
		layoutGrow = value;
	};
void setWithKiwiData(const Desaina_Kiwi::LayoutMixin& data) {
	if (data.rotation() != nullptr) {
		rotation = *data.rotation();
	}
	if (data.layoutAlign() != nullptr) {
		layoutAlign = *data.layoutAlign();
	}
	if (data.layoutGrow() != nullptr) {
		layoutGrow = *data.layoutGrow();
	}
}
};
class RectangleNode {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::RectangleNode& data) {
}
};
class FrameNode {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::FrameNode& data) {
}
};
class PageNode {
private:
	std::vector<Paint> backgrounds;
public:
	std::vector<Paint> get_backgrounds() {
		return backgrounds;
	};
	void set_backgrounds (const std::vector<Paint>& value) {
		backgrounds = value;
	};
void setWithKiwiData(const Desaina_Kiwi::PageNode& data) {
	if (data.backgrounds() != nullptr) {
		backgrounds = *data.backgrounds();
	}
}
};
class Node_Change_kiwi {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::Node_Change_kiwi& data) {
}
};
class BaseNodeMixin {
private:
	string id;
	GUID parent;
	string name;
public:
	string get_id() {
		return id;
	};
	void set_id (const string& value) {
		id = value;
	};
	GUID get_parent() {
		return parent;
	};
	void set_parent (const GUID& value) {
		parent = value;
	};
	string get_name() {
		return name;
	};
	void set_name (const string& value) {
		name = value;
	};
void setWithKiwiData(const Desaina_Kiwi::BaseNodeMixin& data) {
	if (data.id() != nullptr) {
		id = *data.id();
	}
	if (data.parent() != nullptr) {
		parent = *data.parent();
	}
	if (data.name() != nullptr) {
		name = *data.name();
	}
}
};
class SceneNodeMixin {
private:
	static bool visible_default;
	bool visible;
	bool locked;
public:
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	bool get_locked() {
		return locked;
	};
	void set_locked (const bool& value) {
		locked = value;
	};
void setWithKiwiData(const Desaina_Kiwi::SceneNodeMixin& data) {
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.locked() != nullptr) {
		locked = *data.locked();
	}
}
};
class IndividualStrokesMixin {
private:
	static float strokeTopWeight_default;
	float strokeTopWeight;
	static float strokeBottomWeight_default;
	float strokeBottomWeight;
	static float strokeLeftWeight_default;
	float strokeLeftWeight;
	static float strokeRightWeight_default;
	float strokeRightWeight;
public:
	float get_strokeTopWeight() {
		return strokeTopWeight;
	};
	void set_strokeTopWeight (const float& value) {
		strokeTopWeight = value;
	};
	float get_strokeBottomWeight() {
		return strokeBottomWeight;
	};
	void set_strokeBottomWeight (const float& value) {
		strokeBottomWeight = value;
	};
	float get_strokeLeftWeight() {
		return strokeLeftWeight;
	};
	void set_strokeLeftWeight (const float& value) {
		strokeLeftWeight = value;
	};
	float get_strokeRightWeight() {
		return strokeRightWeight;
	};
	void set_strokeRightWeight (const float& value) {
		strokeRightWeight = value;
	};
void setWithKiwiData(const Desaina_Kiwi::IndividualStrokesMixin& data) {
	if (data.strokeTopWeight() != nullptr) {
		strokeTopWeight = *data.strokeTopWeight();
	}
	if (data.strokeBottomWeight() != nullptr) {
		strokeBottomWeight = *data.strokeBottomWeight();
	}
	if (data.strokeLeftWeight() != nullptr) {
		strokeLeftWeight = *data.strokeLeftWeight();
	}
	if (data.strokeRightWeight() != nullptr) {
		strokeRightWeight = *data.strokeRightWeight();
	}
}
};
class GeometryMixin {
private:
	StrokeCap strokeCap;
	static float strokeMiterLimit_default;
	float strokeMiterLimit;
	std::vector<KiwiPath> fillGeometry;
public:
	StrokeCap get_strokeCap() {
		return strokeCap;
	};
	void set_strokeCap (const StrokeCap& value) {
		strokeCap = value;
	};
	float get_strokeMiterLimit() {
		return strokeMiterLimit;
	};
	void set_strokeMiterLimit (const float& value) {
		strokeMiterLimit = value;
	};
	std::vector<KiwiPath> get_fillGeometry() {
		return fillGeometry;
	};
	void set_fillGeometry (const std::vector<KiwiPath>& value) {
		fillGeometry = value;
	};
void setWithKiwiData(const Desaina_Kiwi::GeometryMixin& data) {
	if (data.strokeCap() != nullptr) {
		strokeCap = *data.strokeCap();
	}
	if (data.strokeMiterLimit() != nullptr) {
		strokeMiterLimit = *data.strokeMiterLimit();
	}
	if (data.fillGeometry() != nullptr) {
		fillGeometry = *data.fillGeometry();
	}
}
};
class CornerMixin {
private:
	static float cornerRadius_default;
	float cornerRadius;
	static float cornerSmoothing_default;
	float cornerSmoothing;
public:
	float get_cornerRadius() {
		return cornerRadius;
	};
	void set_cornerRadius (const float& value) {
		cornerRadius = value;
	};
	float get_cornerSmoothing() {
		return cornerSmoothing;
	};
	void set_cornerSmoothing (const float& value) {
		cornerSmoothing = value;
	};
void setWithKiwiData(const Desaina_Kiwi::CornerMixin& data) {
	if (data.cornerRadius() != nullptr) {
		cornerRadius = *data.cornerRadius();
	}
	if (data.cornerSmoothing() != nullptr) {
		cornerSmoothing = *data.cornerSmoothing();
	}
}
};
class RectangleCornerMixin {
private:
	static float topLeftRadius_default;
	float topLeftRadius;
	static float topRightRadius_default;
	float topRightRadius;
	static float bottomLeftRadius_default;
	float bottomLeftRadius;
	static float bottomRightRadius_default;
	float bottomRightRadius;
public:
	float get_topLeftRadius() {
		return topLeftRadius;
	};
	void set_topLeftRadius (const float& value) {
		topLeftRadius = value;
	};
	float get_topRightRadius() {
		return topRightRadius;
	};
	void set_topRightRadius (const float& value) {
		topRightRadius = value;
	};
	float get_bottomLeftRadius() {
		return bottomLeftRadius;
	};
	void set_bottomLeftRadius (const float& value) {
		bottomLeftRadius = value;
	};
	float get_bottomRightRadius() {
		return bottomRightRadius;
	};
	void set_bottomRightRadius (const float& value) {
		bottomRightRadius = value;
	};
void setWithKiwiData(const Desaina_Kiwi::RectangleCornerMixin& data) {
	if (data.topLeftRadius() != nullptr) {
		topLeftRadius = *data.topLeftRadius();
	}
	if (data.topRightRadius() != nullptr) {
		topRightRadius = *data.topRightRadius();
	}
	if (data.bottomLeftRadius() != nullptr) {
		bottomLeftRadius = *data.bottomLeftRadius();
	}
	if (data.bottomRightRadius() != nullptr) {
		bottomRightRadius = *data.bottomRightRadius();
	}
}
};
class DefaultShapeMixin {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::DefaultShapeMixin& data) {
}
};
class EffectMixin {
private:
	std::vector<Effect> effects;
	string effectStyleId;
public:
	std::vector<Effect> get_effects() {
		return effects;
	};
	void set_effects (const std::vector<Effect>& value) {
		effects = value;
	};
	string get_effectStyleId() {
		return effectStyleId;
	};
	void set_effectStyleId (const string& value) {
		effectStyleId = value;
	};
void setWithKiwiData(const Desaina_Kiwi::EffectMixin& data) {
	if (data.effects() != nullptr) {
		effects = *data.effects();
	}
	if (data.effectStyleId() != nullptr) {
		effectStyleId = *data.effectStyleId();
	}
}
};
class BaseFrameMixin {
private:
	LayoutMode layoutMode;
	AxisSizingMode primaryAxisSizingMode;
	AxisSizingMode counterAxisSizingMode;
	PrimaryAxisAlignItems primaryAxisAlignItems;
	CounterAxisAlignItems counterAxisAlignItems;
	static float paddingLeft_default;
	float paddingLeft;
	static float paddingRight_default;
	float paddingRight;
	static float paddingTop_default;
	float paddingTop;
	static float paddingBottom_default;
	float paddingBottom;
	static float itemSpacing_default;
	float itemSpacing;
	bool itemReverseZIndex;
	bool strokesIncludedInLayout;
	static float horizontalPadding_default;
	float horizontalPadding;
	static float verticalPadding_default;
	float verticalPadding;
	static bool clipsContent_default;
	bool clipsContent;
public:
	LayoutMode get_layoutMode() {
		return layoutMode;
	};
	void set_layoutMode (const LayoutMode& value) {
		layoutMode = value;
	};
	AxisSizingMode get_primaryAxisSizingMode() {
		return primaryAxisSizingMode;
	};
	void set_primaryAxisSizingMode (const AxisSizingMode& value) {
		primaryAxisSizingMode = value;
	};
	AxisSizingMode get_counterAxisSizingMode() {
		return counterAxisSizingMode;
	};
	void set_counterAxisSizingMode (const AxisSizingMode& value) {
		counterAxisSizingMode = value;
	};
	PrimaryAxisAlignItems get_primaryAxisAlignItems() {
		return primaryAxisAlignItems;
	};
	void set_primaryAxisAlignItems (const PrimaryAxisAlignItems& value) {
		primaryAxisAlignItems = value;
	};
	CounterAxisAlignItems get_counterAxisAlignItems() {
		return counterAxisAlignItems;
	};
	void set_counterAxisAlignItems (const CounterAxisAlignItems& value) {
		counterAxisAlignItems = value;
	};
	float get_paddingLeft() {
		return paddingLeft;
	};
	void set_paddingLeft (const float& value) {
		paddingLeft = value;
	};
	float get_paddingRight() {
		return paddingRight;
	};
	void set_paddingRight (const float& value) {
		paddingRight = value;
	};
	float get_paddingTop() {
		return paddingTop;
	};
	void set_paddingTop (const float& value) {
		paddingTop = value;
	};
	float get_paddingBottom() {
		return paddingBottom;
	};
	void set_paddingBottom (const float& value) {
		paddingBottom = value;
	};
	float get_itemSpacing() {
		return itemSpacing;
	};
	void set_itemSpacing (const float& value) {
		itemSpacing = value;
	};
	bool get_itemReverseZIndex() {
		return itemReverseZIndex;
	};
	void set_itemReverseZIndex (const bool& value) {
		itemReverseZIndex = value;
	};
	bool get_strokesIncludedInLayout() {
		return strokesIncludedInLayout;
	};
	void set_strokesIncludedInLayout (const bool& value) {
		strokesIncludedInLayout = value;
	};
	float get_horizontalPadding() {
		return horizontalPadding;
	};
	void set_horizontalPadding (const float& value) {
		horizontalPadding = value;
	};
	float get_verticalPadding() {
		return verticalPadding;
	};
	void set_verticalPadding (const float& value) {
		verticalPadding = value;
	};
	bool get_clipsContent() {
		return clipsContent;
	};
	void set_clipsContent (const bool& value) {
		clipsContent = value;
	};
void setWithKiwiData(const Desaina_Kiwi::BaseFrameMixin& data) {
	if (data.layoutMode() != nullptr) {
		layoutMode = *data.layoutMode();
	}
	if (data.primaryAxisSizingMode() != nullptr) {
		primaryAxisSizingMode = *data.primaryAxisSizingMode();
	}
	if (data.counterAxisSizingMode() != nullptr) {
		counterAxisSizingMode = *data.counterAxisSizingMode();
	}
	if (data.primaryAxisAlignItems() != nullptr) {
		primaryAxisAlignItems = *data.primaryAxisAlignItems();
	}
	if (data.counterAxisAlignItems() != nullptr) {
		counterAxisAlignItems = *data.counterAxisAlignItems();
	}
	if (data.paddingLeft() != nullptr) {
		paddingLeft = *data.paddingLeft();
	}
	if (data.paddingRight() != nullptr) {
		paddingRight = *data.paddingRight();
	}
	if (data.paddingTop() != nullptr) {
		paddingTop = *data.paddingTop();
	}
	if (data.paddingBottom() != nullptr) {
		paddingBottom = *data.paddingBottom();
	}
	if (data.itemSpacing() != nullptr) {
		itemSpacing = *data.itemSpacing();
	}
	if (data.itemReverseZIndex() != nullptr) {
		itemReverseZIndex = *data.itemReverseZIndex();
	}
	if (data.strokesIncludedInLayout() != nullptr) {
		strokesIncludedInLayout = *data.strokesIncludedInLayout();
	}
	if (data.horizontalPadding() != nullptr) {
		horizontalPadding = *data.horizontalPadding();
	}
	if (data.verticalPadding() != nullptr) {
		verticalPadding = *data.verticalPadding();
	}
	if (data.clipsContent() != nullptr) {
		clipsContent = *data.clipsContent();
	}
}
};
class DefaultFrameMixin {
private:
public:
void setWithKiwiData(const Desaina_Kiwi::DefaultFrameMixin& data) {
}
};
class Paint {
private:
	PaintType type;
public:
	PaintType get_type() {
		return type;
	};
	void set_type (const PaintType& value) {
		type = value;
	};
void setWithKiwiData(const Desaina_Kiwi::Paint& data) {
	if (data.type() != nullptr) {
		type = *data.type();
	}
}
};
class SolidPaint {
private:
	RGB color;
	static bool visible_default;
	bool visible;
	static float opacity_default;
	float opacity;
	BlendMode blendMode;
public:
	RGB get_color() {
		return color;
	};
	void set_color (const RGB& value) {
		color = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	float get_opacity() {
		return opacity;
	};
	void set_opacity (const float& value) {
		opacity = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::SolidPaint& data) {
	if (data.color() != nullptr) {
		color = *data.color();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.opacity() != nullptr) {
		opacity = *data.opacity();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
	}
}
};
class GradientPaint {
private:
	Matrix gradientTransform;
	std::vector<ColorStop> gradientStops;
	bool visible;
	static float opacity_default;
	float opacity;
	BlendMode blendMode;
public:
	Matrix get_gradientTransform() {
		return gradientTransform;
	};
	void set_gradientTransform (const Matrix& value) {
		gradientTransform = value;
	};
	std::vector<ColorStop> get_gradientStops() {
		return gradientStops;
	};
	void set_gradientStops (const std::vector<ColorStop>& value) {
		gradientStops = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	float get_opacity() {
		return opacity;
	};
	void set_opacity (const float& value) {
		opacity = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::GradientPaint& data) {
	if (data.gradientTransform() != nullptr) {
		gradientTransform = *data.gradientTransform();
	}
	if (data.gradientStops() != nullptr) {
		gradientStops = *data.gradientStops();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.opacity() != nullptr) {
		opacity = *data.opacity();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
	}
}
};
class ImagePaint {
private:
	ScaleMode scaleMode;
	string imageHash;
	Matrix imageTransform;
	float scalingFactor;
	float rotation;
	bool visible;
	float opacity;
	BlendMode blendMode;
public:
	ScaleMode get_scaleMode() {
		return scaleMode;
	};
	void set_scaleMode (const ScaleMode& value) {
		scaleMode = value;
	};
	string get_imageHash() {
		return imageHash;
	};
	void set_imageHash (const string& value) {
		imageHash = value;
	};
	Matrix get_imageTransform() {
		return imageTransform;
	};
	void set_imageTransform (const Matrix& value) {
		imageTransform = value;
	};
	float get_scalingFactor() {
		return scalingFactor;
	};
	void set_scalingFactor (const float& value) {
		scalingFactor = value;
	};
	float get_rotation() {
		return rotation;
	};
	void set_rotation (const float& value) {
		rotation = value;
	};
	bool get_visible() {
		return visible;
	};
	void set_visible (const bool& value) {
		visible = value;
	};
	float get_opacity() {
		return opacity;
	};
	void set_opacity (const float& value) {
		opacity = value;
	};
	BlendMode get_blendMode() {
		return blendMode;
	};
	void set_blendMode (const BlendMode& value) {
		blendMode = value;
	};
void setWithKiwiData(const Desaina_Kiwi::ImagePaint& data) {
	if (data.scaleMode() != nullptr) {
		scaleMode = *data.scaleMode();
	}
	if (data.imageHash() != nullptr) {
		imageHash = *data.imageHash();
	}
	if (data.imageTransform() != nullptr) {
		imageTransform = *data.imageTransform();
	}
	if (data.scalingFactor() != nullptr) {
		scalingFactor = *data.scalingFactor();
	}
	if (data.rotation() != nullptr) {
		rotation = *data.rotation();
	}
	if (data.visible() != nullptr) {
		visible = *data.visible();
	}
	if (data.opacity() != nullptr) {
		opacity = *data.opacity();
	}
	if (data.blendMode() != nullptr) {
		blendMode = *data.blendMode();
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
	std::vector<Paint> get_strokes() {
		return strokes;
	};
	void set_strokes (const std::vector<Paint>& value) {
		strokes = value;
	};
	string get_strokeStyleId() {
		return strokeStyleId;
	};
	void set_strokeStyleId (const string& value) {
		strokeStyleId = value;
	};
	float get_strokeWeight() {
		return strokeWeight;
	};
	void set_strokeWeight (const float& value) {
		strokeWeight = value;
	};
	StrokeJoin get_strokeJoin() {
		return strokeJoin;
	};
	void set_strokeJoin (const StrokeJoin& value) {
		strokeJoin = value;
	};
	Align get_strokeAlign() {
		return strokeAlign;
	};
	void set_strokeAlign (const Align& value) {
		strokeAlign = value;
	};
	std::vector<float> get_dashPattern() {
		return dashPattern;
	};
	void set_dashPattern (const std::vector<float>& value) {
		dashPattern = value;
	};
	std::vector<KiwiPath> get_strokeGeometry() {
		return strokeGeometry;
	};
	void set_strokeGeometry (const std::vector<KiwiPath>& value) {
		strokeGeometry = value;
	};
void setWithKiwiData(const Desaina_Kiwi::MinimalStrokesMixin& data) {
	if (data.strokes() != nullptr) {
		strokes = *data.strokes();
	}
	if (data.strokeStyleId() != nullptr) {
		strokeStyleId = *data.strokeStyleId();
	}
	if (data.strokeWeight() != nullptr) {
		strokeWeight = *data.strokeWeight();
	}
	if (data.strokeJoin() != nullptr) {
		strokeJoin = *data.strokeJoin();
	}
	if (data.strokeAlign() != nullptr) {
		strokeAlign = *data.strokeAlign();
	}
	if (data.dashPattern() != nullptr) {
		dashPattern = *data.dashPattern();
	}
	if (data.strokeGeometry() != nullptr) {
		strokeGeometry = *data.strokeGeometry();
	}
}
};
class VectorVertex {
private:
	static float x_default;
	float x;
	static float y_default;
	float y;
	StrokeCap strokeCap;
	StrokeJoin strokeJoin;
	static float cornerRadius_default;
	float cornerRadius;
public:
	float get_x() {
		return x;
	};
	void set_x (const float& value) {
		x = value;
	};
	float get_y() {
		return y;
	};
	void set_y (const float& value) {
		y = value;
	};
	StrokeCap get_strokeCap() {
		return strokeCap;
	};
	void set_strokeCap (const StrokeCap& value) {
		strokeCap = value;
	};
	StrokeJoin get_strokeJoin() {
		return strokeJoin;
	};
	void set_strokeJoin (const StrokeJoin& value) {
		strokeJoin = value;
	};
	float get_cornerRadius() {
		return cornerRadius;
	};
	void set_cornerRadius (const float& value) {
		cornerRadius = value;
	};
void setWithKiwiData(const Desaina_Kiwi::VectorVertex& data) {
	if (data.x() != nullptr) {
		x = *data.x();
	}
	if (data.y() != nullptr) {
		y = *data.y();
	}
	if (data.strokeCap() != nullptr) {
		strokeCap = *data.strokeCap();
	}
	if (data.strokeJoin() != nullptr) {
		strokeJoin = *data.strokeJoin();
	}
	if (data.cornerRadius() != nullptr) {
		cornerRadius = *data.cornerRadius();
	}
}
};
class VectorSegment {
private:
	static float start_default;
	float start;
	static float end_default;
	float end;
	Vector tangentStart;
	Vector tangentEnd;
public:
	float get_start() {
		return start;
	};
	void set_start (const float& value) {
		start = value;
	};
	float get_end() {
		return end;
	};
	void set_end (const float& value) {
		end = value;
	};
	Vector get_tangentStart() {
		return tangentStart;
	};
	void set_tangentStart (const Vector& value) {
		tangentStart = value;
	};
	Vector get_tangentEnd() {
		return tangentEnd;
	};
	void set_tangentEnd (const Vector& value) {
		tangentEnd = value;
	};
void setWithKiwiData(const Desaina_Kiwi::VectorSegment& data) {
	if (data.start() != nullptr) {
		start = *data.start();
	}
	if (data.end() != nullptr) {
		end = *data.end();
	}
	if (data.tangentStart() != nullptr) {
		tangentStart = *data.tangentStart();
	}
	if (data.tangentEnd() != nullptr) {
		tangentEnd = *data.tangentEnd();
	}
}
};
class VectorPath {
private:
	WindingRule windingRule;
	string data;
public:
	WindingRule get_windingRule() {
		return windingRule;
	};
	void set_windingRule (const WindingRule& value) {
		windingRule = value;
	};
	string get_data() {
		return data;
	};
	void set_data (const string& value) {
		data = value;
	};
void setWithKiwiData(const Desaina_Kiwi::VectorPath& data) {
	if (data.windingRule() != nullptr) {
		windingRule = *data.windingRule();
	}
	if (data.data() != nullptr) {
		data = *data.data();
	}
}
};
class KiwiPath {
private:
	WindingRule windingRule;
	static uint commandsBlob_default;
	uint commandsBlob;
	static uint styleID_default;
	uint styleID;
public:
	WindingRule get_windingRule() {
		return windingRule;
	};
	void set_windingRule (const WindingRule& value) {
		windingRule = value;
	};
	uint get_commandsBlob() {
		return commandsBlob;
	};
	void set_commandsBlob (const uint& value) {
		commandsBlob = value;
	};
	uint get_styleID() {
		return styleID;
	};
	void set_styleID (const uint& value) {
		styleID = value;
	};
void setWithKiwiData(const Desaina_Kiwi::KiwiPath& data) {
	if (data.windingRule() != nullptr) {
		windingRule = *data.windingRule();
	}
	if (data.commandsBlob() != nullptr) {
		commandsBlob = *data.commandsBlob();
	}
	if (data.styleID() != nullptr) {
		styleID = *data.styleID();
	}
}
};
