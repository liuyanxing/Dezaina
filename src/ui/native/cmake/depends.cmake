include(FetchContent)
set(FETCHCONTENT_FULLY_DISCONNECTED OFF)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps)

message(STATUS "Fetching native UI depends")
FetchContent_Declare(
	sdl
	GIT_REPOSITORY https://github.com/libsdl-org/SDL.git
	GIT_TAG				  release-2.26.4
	GIT_SHALLOW			TRUE
	GIT_PROGRESS		TRUE
	USES_TERMINAL_DOWNLOAD	TRUE
	SOURCE_DIR			${FETCHCONTENT_BASE_DIR}/sdl
)

FetchContent_Declare(
	imgui
	GIT_REPOSITORY https://github.com/ocornut/imgui.git
	GIT_TAG				  v1.89.4
	GIT_SHALLOW			TRUE
	GIT_PROGRESS		TRUE
	USES_TERMINAL_DOWNLOAD	TRUE
	SOURCE_DIR			${FETCHCONTENT_BASE_DIR}/imgui
)

FetchContent_MakeAvailable(sdl)
FetchContent_Populate(imgui)

set(SDL_LIBRARIES SDL2main SDL2-static)
set(SDL_INCLUDE_DIR ${sdl_SOURCE_DIR}/include)

add_library(imgui STATIC
	${imgui_SOURCE_DIR}/imgui.cpp
	${imgui_SOURCE_DIR}/imgui_draw.cpp
	${imgui_SOURCE_DIR}/imgui_widgets.cpp
	${imgui_SOURCE_DIR}/imgui_tables.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_sdl2.cpp
	${imgui_SOURCE_DIR}/backends/imgui_impl_opengl3.cpp
)
target_include_directories(imgui PUBLIC ${imgui_SOURCE_DIR} ${SDL_INCLUDE_DIR})
