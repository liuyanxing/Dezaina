#pragma once

#include "base/object.h"
#include "document.h"
#include "viewport/viewport.h"
#include "include/core/SkSurface.h"
#include "geometry.h"
#include "paint.h"

#include <cstdint>

namespace dea::render {

class Render : public base::NonCopyable {
public:
	Render(const document::Document& document, const Viewport& viewPort)
		: viewport_(viewPort), doc_(document) {};

	void render();
	bool makeSurface();
private:
	bool checkViewPort();
	void updateViewPort();
  void renderDocument();
  void renderInteraction();
	void render(node::NodeIterWithWorldMatrix& iter, bool isInterNode);
	void renderNode(node::Node* node, bool isInterNode);
	void renderGeometry(const geometry::GeometryType& geometry, const PaintDrawers& drawers);

	const Viewport& viewport_;
	const document::Document& doc_;
	float devicePixelRatio_ = 1.0f;
  uint32_t wWidth_ = 0;
  uint32_t wHeight_ = 0;
	uint32_t width_ = 0;
	uint32_t height_ = 0;
	sk_sp<SkSurface> surface_;
  SkCanvas* canvas_ = nullptr;
};

class RenderSaveLayerScope {
public:
  explicit RenderSaveLayerScope(node::NodeConstPtr node)
		: node_(node) {
			if (checkIfNeedSave()) {
				save();
			}
	}
	~RenderSaveLayerScope() {
		if (needSave_) {
			restore();
		}
	}

	void init() {}

private:
	bool needSave_ = false;
	node::NodeConstPtr node_;
	void save() {};
	void restore() {};
	bool checkIfNeedSave() { return true; };
};

} // namespace dea::render