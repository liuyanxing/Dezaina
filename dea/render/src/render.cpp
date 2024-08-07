#include "render.h"
#include "dezaina.h"
#include "document/include/document.h"
#include "include/core/SkColor.h"
#include "include/core/SkPaint.h"
#include "node/include/node.h"

#include "include/core/SkColorSpace.h"
#include "include/core/SkCanvas.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/gpu/ganesh/gl/GrGLBackendSurface.h"
#include "include/gpu/ganesh/gl/glx/GrGLMakeGLXInterface.h"
#include "include/gpu/ganesh/gl/GrGLDirectContext.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "utility/skia.h"
#include <GL/gl.h>
#include <variant>

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

  void Render::renderDocument() {
    canvas_->resetMatrix();
    SkAutoCanvasRestore acr(canvas_, true); 

    canvas_->setMatrix(viewport_.projectionMatrix());
		document::Document::Iter iter{doc_.currentPage()};
		while (iter.isValid()) {
			auto* node = iter.get();
			renderNode(node);
			++iter;
		}
    auto* context = canvas_->recordingContext()->asDirectContext();
    if (context != nullptr) {
      context->flush();
      context->submit();
    }
  }

  void Render::renderInteraction() {
    canvas_->resetMatrix();
    SkAutoCanvasRestore acr(canvas_, true);

    canvas_->setMatrix(viewport_.projectionMatrix());
    auto& interaction = Dezaina::instance().getInteraction();
    interaction::Interaction::Iter iter{interaction.root()};
		while (iter.isValid()) {
			auto* node = iter.get();
			renderNode(node, true);
			++iter;
		}
    auto* context = canvas_->recordingContext()->asDirectContext();
    if (context != nullptr) {
      context->flush();
      context->submit();
    }
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
    renderDocument();
    renderInteraction();

  }

	void Render::renderNode(node::Node* node, bool isInterNode) {
    auto* shapeNode = node_cast<node::DefaultShapeNode*>(node);
    if (!shapeNode) {
      if (auto* page = node::node_cast<node::PageNode*>(node)) {
        auto color = utility::toSkColor(page->getBackgroundColor()); 
        canvas_->drawColor(color);
        auto& viewport = Dezaina::instance().getViewport();
        auto viewMatrix = isInterNode ? viewport.getHudViewMatrix() : viewport.getViewMatrix();
        canvas_->concat(viewMatrix);
        return;
      }
      return;
    }

    canvas_->concat(utility::toSkMatrix(shapeNode->getTransform()));
		RenderSaveLayerScope scope{node};
  
    auto fill = isInterNode ? geometry::buildFill(node) :	geometry::getOrBuildFill(node);
    if (!fill.isEmpty()) {
      renderGeometry(fill, buildFillPaintDrawers(node));
    };
    auto stroke = isInterNode ? geometry::buildStroke(node) : geometry::getOrBuildStroke(node);
    if (!stroke.isEmpty()) {
      renderGeometry(stroke, buildStrokePaintDrawers(node));
    }

	}

  void Render::renderGeometry(const geometry::GeometryType& geometry, const PaintDrawers& drawers) {
      SkAutoCanvasRestore acr(canvas_, true); 
      SkPaint paint;
      paint.setAntiAlias(true);
      canvas_->clipPath(geometry, true);
			for (auto& drawer : drawers) {
        std::visit([this](auto&& d) {
          d.draw(canvas_);
        }, drawer);
			}
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