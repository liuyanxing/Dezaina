#include "canvas.h"
#include "include/core/SkColorType.h"
#include "include/core/SkSurface.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkSurfaceProps.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrContextOptions.h"
#include "include/gpu/GrTypes.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/GrDirectContext.h"
#include "include/private/gpu/ganesh/GrTypesPriv.h"
#include "src/gpu/ganesh/gl/GrGLDefines.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"


bool Canvas::createSurface() {
    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
    
    GrContextOptions defaultOptions;
    defaultOptions.fSkipGLErrorChecks = GrContextOptions::Enable::kNo;
    sk_sp<GrDirectContext> context = GrDirectContext::MakeGL(interface, defaultOptions);
    // GrBackendRenderTarget backendRenderTarget(width_, height_, 0, 8, GrMockRenderTargetInfo(GrColorType::kRGBA_8888_SRGB, 0));

    // surface_ = SkSurface::MakeFromBackendRenderTarget(
    //     context.get(),
    //     backendRenderTarget,
    //     GrSurfaceOrigin::kBottomLeft_GrSurfaceOrigin,
    //     SkColorType::kRGBA_8888_SkColorType,
    //     nullptr,
    //     nullptr
    //     );
    // // surface_ = SkSurface::MakeRenderTarget(context.get(), skgpu::Budgeted::kNo, info);
    SkImageInfo info = SkImageInfo::Make(width_, height_, kRGBA_8888_SkColorType, kPremul_SkAlphaType);
    // SkImageInfo info = SkImageInfo::MakeN32Premul(width_, height_);
    surface_ = SkSurfaces::RenderTarget(context.get(), skgpu::Budgeted::kNo, info, 0, nullptr);

    if (!surface_) {
        SkDebugf("SkSurface::MakeRenderTarget returned null\n");
        return false;
    }
    canvas_ = surface_->getCanvas();
    return true;
}