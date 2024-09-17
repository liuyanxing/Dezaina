add_requires("libsdl")
add_requires("imgui v1.89.4", { configs = { sdl2 = true, opengl3 = true } })

target("app")
set_kind("binary")
add_files("src/*.cpp")
add_deps("dea", "loader")
add_packages("libsdl", "imgui")
set_rundir("$(projectdir)")
