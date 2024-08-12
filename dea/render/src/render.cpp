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

namespace dea::render {

	bool Render::makeSurface() {
    sk_sp<const GrGLInterface> interface = GrGLInterfaces::MakeGLX();
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

  void Render::render(utility::NodeIterWithWorldMatrix& iter, bool isInterNode) {
		while (iter.isValid()) {
      SkAutoCanvasRestore acr(canvas_, true); 

			auto* node = iter.get();
      canvas_->concat(iter.getWorldMatrix());
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
    canvas_->resetMatrix();
    SkAutoCanvasRestore acr(canvas_, true); 

    canvas_->setMatrix(viewport_.projectionMatrix());
    canvas_->concat(Dezaina::instance().getViewport().getViewMatrix());
		document::Document::IterWithWorldMatrix iter{doc_.currentPage()};
    render(iter, false);
  }

  void Render::renderInteraction() {
    auto& interaction = Dezaina::instance().getInteraction();
    if (interaction.root()->empty()) {
      return;
    }
    canvas_->resetMatrix();
    SkAutoCanvasRestore acr(canvas_, true);

    canvas_->setMatrix(viewport_.projectionMatrix());
    canvas_->concat(Dezaina::instance().getViewport().getHudViewMatrix());

    interaction::Interaction::IterWithWorldMatrix iter{interaction.root()};
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
    auto* shapeNode = node_cast<node::DefaultShapeNode*>(node);
    if (!shapeNode) {
      if (auto* page = node::node_cast<node::PageNode*>(node)) {
        auto color = utility::toSkColor(page->getBackgroundColor()); 
        canvas_->drawColor(color);
      }
      return;
    }

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