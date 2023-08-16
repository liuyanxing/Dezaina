#include "canvas.h"
#include "include/core/SkColorType.h"
#include "include/core/SkSurface.h"
#include "include/core/SkColorSpace.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrTypes.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/GrDirectContext.h"
#include "src/gpu/gl/GrGLDefines.h"


bool Canvas::createSurface() {
    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
    
    sk_sp<GrDirectContext> context = GrDirectContext::MakeGL(interface);
    GrBackendRenderTarget backendRenderTarget(width_, height_, 0, 8, {0, GR_GL_RGBA8});

    // surface_ = SkSurface::MakeRenderTarget(context.get(), skgpu::Budgeted::kNo, info);
    surface_ = SkSurface::MakeFromBackendRenderTarget(
        context.get(),
        backendRenderTarget,
        GrSurfaceOrigin::kBottomLeft_GrSurfaceOrigin,
        SkColorType::kRGBA_8888_SkColorType,
        nullptr,
        nullptr
        );

    if (!surface_) {
        SkDebugf("SkSurface::MakeRenderTarget returned null\n");
        return false;
    }
    canvas_ = surface_->getCanvas();
    return true;
}