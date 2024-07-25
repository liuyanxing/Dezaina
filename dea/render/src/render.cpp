#include "render.h"
#include "document/include/document.h"
#include "node/include/node.h"
#include "geometry/geometry.h"
#include "paint.h"

namespace dea::render {
	void Render::render() {
		if (!checkViewPort()) {
			updateViewPort();
			if (!makeSurface()) {
				return;
			}
		}

		document::Document::Iter iter{doc_.root()};
		while (iter.isValid()) {
			auto* node = iter.get();
			renderNode(node);
			++iter;
		}
	}

	void Render::renderNode(node::Node* node) {
		RenderLayerSaveScope scope{node};
		{
			auto* fill =	geometry::getOrBuildFill(node);
			if (fill) {
				// render fill
			}
			auto& fillPaintDrawers = buildFillPaintDrawers(node);
		  for (auto& drawer : fillPaintDrawers) {
				// render fill
				drawer->draw();
			}
		}
		{
			auto* stroke = geometry::getOrBuildStroke(node);
			if (stroke) {
				// render stroke
			}
			auto& strokePaintDrawers = buildStrokePaintDrawers(node);
			for (auto& drawer : strokePaintDrawers) {
				// render stroke
				drawer->draw();
			}
		}
	}

	bool Render::checkViewPort() {
		return viewPort_.width() == width_ && viewPort_.height() == height_ && viewPort_.devicePixelRatio() == devicePixelRatio_; 
	}

	void Render::updateViewPort() {
		width_ = viewPort_.width();
		height_ = viewPort_.height();
		devicePixelRatio_ = viewPort_.devicePixelRatio();
		wWidth_ = width_ * devicePixelRatio_;
		wHeight_ = height_ * devicePixelRatio_;
	}
}