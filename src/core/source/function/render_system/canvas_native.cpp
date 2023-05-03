#include "canvas.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/GrDirectContext.h"


void Canvas::createSurface() {
    sk_sp<const GrGLInterface> interface = nullptr;
    
    sk_sp<GrDirectContext> context = GrDirectContext::MakeGL(interface);
    SkImageInfo info = SkImageInfo::MakeN32Premul(width_, height_);

    surface_ = SkSurface::MakeRenderTarget(context.get(), skgpu::Budgeted::kNo, info);

    if (!surface_) {
        SkDebugf("SkSurface::MakeRenderTarget returned null\n");
        return;
    }
    canvas_ = surface_->getCanvas();
}