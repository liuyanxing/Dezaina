#include "render.h"
#include "document/include/document.h"
#include "node/include/node.h"
#include "geometry/geometry.h"
#include "paint.h"

#include "include/core/SkColorSpace.h"
#include "include/core/SkCanvas.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/gpu/ganesh/gl/GrGLBackendSurface.h"
#include "include/gpu/ganesh/gl/glx/GrGLMakeGLXInterface.h"
#include "include/gpu/ganesh/gl/GrGLDirectContext.h"
#include "include/gpu/gl/GrGLInterface.h"
#include <GL/gl.h>

namespace dea::render {

	bool Render::makeSurface() {
    sk_sp<const GrGLInterface> interface = GrGLInterfaces::MakeGLX();
    sk_sp<GrDirectContext> context = GrDirectContexts::MakeGL(interface);

		GrGLFramebufferInfo info;
		info.fFBOID = 0;
    info.fFormat = GL_RGBA8;
		auto backendRT = GrBackendRenderTargets::MakeGL(width_,
																											height_,
																											0,
																											8,
																											info);
		surface_ = SkSurfaces::WrapBackendRenderTarget(context.get(),
                                                           backendRT,
                                                           kBottomLeft_GrSurfaceOrigin,
                                                           kRGBA_8888_SkColorType,
																													 nullptr,
																													 nullptr
                                                           );
    if (!surface_) {
      return false;
    }
    canvas_ = surface_->getCanvas();
    return true;
	}

	void Render::render() {
		if (!checkViewPort()) {
			updateViewPort();
			if (!makeSurface()) {
				return;
			}
		}

    if (!canvas_) {
      if (!makeSurface()) {
        return;
      }
    }
    canvas_->clear(SK_ColorWHITE);
    canvas_->drawColor(SK_ColorRED);

		document::Document::Iter iter{doc_.root()};
		while (iter.isValid()) {
			auto* node = iter.get();
			renderNode(node);
			++iter;
		}
    canvas_->recordingContext()->asDirectContext()->flush();
	}

	void Render::renderNode(node::Node* node) {
		// RenderLayerSaveScope scope{node};
		// {
		// 	auto* fill =	geometry::getOrBuildFill(node);
		// 	if (fill) {
		// 		// render fill
		// 	}
		// 	auto& fillPaintDrawers = buildFillPaintDrawers(node);
		//   for (auto& drawer : fillPaintDrawers) {
		// 		// render fill
		// 		// drawer->draw();
		// 	}
		// }
		// {
		// 	auto* stroke = geometry::getOrBuildStroke(node);
		// 	if (stroke) {
		// 		// render stroke
		// 	}
		// 	auto& strokePaintDrawers = buildStrokePaintDrawers(node);
		// 	for (auto& drawer : strokePaintDrawers) {
		// 		// render stroke
		// 		// drawer->draw();
		// 	}
		// }
	}

	bool Render::checkViewPort() {
		return viewport_.width() == width_ && viewport_.height() == height_ && viewport_.devicePixelRatio() == devicePixelRatio_; 
	}

	void Render::updateViewPort() {
		width_ = viewport_.width();
		height_ = viewport_.height();
		devicePixelRatio_ = viewport_.devicePixelRatio();
		wWidth_ = width_ * devicePixelRatio_;
		wHeight_ = height_ * devicePixelRatio_;
	}
}