add_requires("libsdl")
add_requires("imgui v1.89.4", { configs = { sdl2 = true, opengl3 = true } })
add_requires("zlib", "minizip")

target("app")
	set_kind("binary")
	add_files("src/*.cpp")
	add_deps("dea")
	add_packages("libsdl", "imgui", "zlib", "minizip")
	set_rundir("$(projectdir)")
	if is_plat("windows") then
			add_syslinks("gdi32", "user32", "opengl32")
	elseif is_plat("macosx") then
			add_frameworks("CoreFoundation", "CoreGraphics", "CoreText", "CoreServices")
	elseif is_plat("linux") then
			add_deps("fontconfig", "freetype >=2.10")
			add_syslinks("pthread", "GL", "dl", "rt")
	end
target_end()
