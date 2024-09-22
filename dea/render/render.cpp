#include "render.h"
#include "core/SkRect.h"
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
#include "utility.h"

namespace dea::render {

	bool Render::makeSurface() {
    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
    sk_sp<GrDirectContext> context = GrDirectContexts::MakeGL(interface);

		GrGLFramebufferInfo info;
		info.fFBOID = 0;
    #define GR_GL_RGBA8 0x8058
    info.fFormat = GR_GL_RGBA8;
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

  void Render::render(node::NodeIterWithWorldMatrix& iter, bool isInterNode) {
    canvas_->resetMatrix();
    SkAutoCanvasRestore acr(canvas_, true);
    canvas_->setMatrix(toSkMatrix(viewport_.getVPMatrix()));

		while (iter.isValid()) {
      SkAutoCanvasRestore acr(canvas_, true); 

			auto* node = iter.get();
      canvas_->concat(toSkMatrix(iter.getWorldMatrix()));
      if (isInterNode) {
        canvas_->scale(1 / viewport_.getViewScale(), 1 / viewport_.getViewScale());
      }
			renderNode(node, isInterNode);
			++iter;
		}
    auto* context = canvas_->recordingContext()->asDirectContext();
    if (context != nullptr) {
      context->flush();
      context->submit();
    }
  }

  void Render::renderDocument() {
    document::Document::IterWithWorldMatrix iter{doc_.currentPage()};
    render(iter, false);
  }

  void Render::renderInteraction() {
    auto& interaction = Dezaina::instance().getInteraction();
    if (interaction.root()->empty()) {
      return;
    }

    interaction::IterWithWorldMatrix iter{interaction.root()};
    render(iter, true);
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
    auto* shapeNode = node_cast<node::DefaultShapeNode>(node);
    if (!shapeNode) {
      if (auto* page = node::node_cast<node::PageNode>(node)) {
        auto color = toSkColor(page->getBackgroundColor()); 
        canvas_->drawColor(color);
      }
      return;
    }

		RenderSaveLayerScope scope{node};

    auto& fillPaints = buildFillPaintDrawers(node);
    if (!fillPaints.empty()) {
      auto fill = isInterNode ? render::buildFill(node) : render::getOrBuildFill(node);
      renderGeometry(fill, fillPaints);
    };

    auto& strokePaints = buildStrokePaintDrawers(node);
    if (!strokePaints.empty()) {
      auto stroke = isInterNode ? render::buildStroke(node) : render::getOrBuildStroke(node);
      renderGeometry(stroke, strokePaints);
    }
	}

  void Render::renderGeometry(const render::GeometryType& geometry, const PaintDrawers& drawers) {
    SkAutoCanvasRestore acr(canvas_, true); 
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