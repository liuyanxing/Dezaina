

package("skia")

    set_homepage("https://skia.org/")
    set_description("A complete 2D graphic library for drawing Text, Geometries, and Images.")
    set_license("BSD-3-Clause")

    add_urls("https://github.com/google/skia.git")
    add_versions("128", "chrome/m128")

    add_deps("gn", "python", "ninja", {kind = "binary"})

    add_includedirs("include")
    add_includedirs("include/..")
    add_includedirs("include/ports")
    if is_plat("windows") then
        add_syslinks("gdi32", "user32", "opengl32")
    elseif is_plat("macosx") then
        add_frameworks("CoreFoundation", "CoreGraphics", "CoreText", "CoreServices")
    elseif is_plat("linux") then
        add_deps("fontconfig", "freetype >=2.10")
        add_syslinks("pthread", "GL", "dl", "rt")
    end
    add_links("skia")

    on_install("macosx", "linux", "windows", function (package)
        local args = {
                      is_debug = true,
                    }
        if package:is_arch("x86") then
            args.target_cpu    = "x86"
        elseif package:is_arch("x64") then
            args.target_cpu    = "x64"
        elseif package:is_arch("arm64") then
            args.target_cpu    = "arm64"
        end
        if not package:is_plat("windows") then
            args.cc            = package:build_getenv("cc")
            args.cxx           = package:build_getenv("cxx")
        else
            args.extra_cflags  = {(package:config("vs_runtime"):startswith("MT") and "/MT" or "/MD")}
        end
        if package:is_plat("macosx") then
            args.extra_ldflags = {"-lstdc++"}
            local xcode = import("core.tool.toolchain").load("xcode", {plat = package:plat(), arch = package:arch()})
            args.xcode_sysroot = xcode:config("xcode_sysroot")
        end

        os.vrunv("python", {"tools/git-sync-deps"})

        -- installation
        import("package.tools.gn").build(package, args, {buildir = "out"})
        os.mv("include", package:installdir())
        os.cd("out")
        os.rm("obj")
        os.rm("*.ninja")
        os.rm("*.ninja*")
        os.rm("*.gn")
        if package:is_plat("windows") then
            os.mv("*.lib", package:installdir("lib"))
            os.trymv("*.dll", package:installdir("bin"))
            os.mv("*.exe", package:installdir("bin"))
        else
            os.mv("*.a", package:installdir("lib"))
            os.trymv("*.so", package:installdir("lib"))
            os.trymv("*.dylib", package:installdir("lib"))
            os.trymv("*", package:installdir("bin"))
        end
    end)

    on_test(function (package)
        assert(package:check_cxxsnippets({test = [[
            void test() {
                SkPaint paint;
                paint.setStyle(SkPaint::kFill_Style);
            }
        ]]}, {configs = {languages = "c++17"}, includes = "core/SkPaint.h"}))
    end)

package_end()


add_requires("fmt", {configs = {header_only = true}})
add_requires("spdlog", {configs = {header_only = true, fmt_external = true}})
add_requireconfs("spdlog.fmt", {override = true, configs = {header_only = true}})
add_requires("nlohmann_json")
if (has_config("render")) then
    add_requires("skia")
end
