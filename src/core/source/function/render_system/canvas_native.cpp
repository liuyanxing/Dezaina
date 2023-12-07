#include "canvas.h"
#include "include/core/SkColorType.h"
#include "include/core/SkSurface.h"
#include "include/core/SkColorSpace.h"
#include "include/core/SkSurfaceProps.h"
#include "include/gpu/GrBackendSurface.h"
#include "include/gpu/GrContextOptions.h"
#include "include/gpu/GrTypes.h"
#include "include/gpu/GrDirectContext.h"
#include "include/gpu/gl/GrGLInterface.h"
#include "include/gpu/ganesh/gl/GrGLDirectContext.h"
#include "include/private/gpu/ganesh/GrTypesPriv.h"
#include "src/gpu/ganesh/gl/GrGLDefines.h"
#include "include/gpu/ganesh/SkSurfaceGanesh.h"
#include "include/gpu/ganesh/gl/GrGLBackendSurface.h"


bool Canvas::createSurface() {
    sk_sp<const GrGLInterface> interface = GrGLMakeNativeInterface();
    
    GrContextOptions defaultOptions;
    defaultOptions.fSkipGLErrorChecks = GrContextOptions::Enable::kNo;
    sk_sp<GrDirectContext> context = GrDirectContexts::MakeGL(interface, defaultOptions);
    GrGLFramebufferInfo info;
    info.fFBOID = 0;
    info.fFormat = GR_GL_RGBA8;
    auto backendRenderTarget = GrBackendRenderTargets::MakeGL(width_, height_, 0, 8, info);

    surface_ = SkSurfaces::WrapBackendRenderTarget(
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