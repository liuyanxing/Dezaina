#pragma once

#include "common/object.h"
#include "document/include/document.h"
#include "node/src/node-base/node.h"
#include "viewport/viewport.h"
#include "include/core/SkSurface.h"

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
	void renderNode(node::Node* node);
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
  explicit RenderSaveLayerScope(const node::Node* node)
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
	const node::Node* node_;
	void save() {};
	void restore() {};
	bool checkIfNeedSave() { return true; };
};

} // namespace dea::render