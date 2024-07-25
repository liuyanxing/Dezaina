#pragma once

#include "document/include/document.h"
#include "node/src/node-base/node.h"
#include "viewport/viewport.h"
#include <cstdint>

namespace dea::render {

class Render {
public:
	Render(const document::Document& document, const ViewPort& viewPort)
		: viewPort_(viewPort), doc_(document) {};

	void render();
	bool makeSurface();
private:
	bool checkViewPort();
	void updateViewPort();
	void renderNode(node::Node* node);
	const ViewPort& viewPort_;
	const document::Document& doc_;
	float devicePixelRatio_ = 1.0f;
  uint32_t wWidth_ = 0;
  uint32_t wHeight_ = 0;
	uint32_t width_ = 0;
	uint32_t height_ = 0;
};

class RenderLayerSaveScope {
public:
  explicit RenderLayerSaveScope(const node::Node* node)
		: node_(node) {
			if (checkIfNeedSave()) {
				save();
			}
	}
	~RenderLayerSaveScope() {
		if (needSave_) {
			restore();
		}
	}
private:
	bool needSave_ = false;
	const node::Node* node_;
	void save();
	void restore();
	bool checkIfNeedSave();
};

} // namespace dea::render