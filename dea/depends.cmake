include(FetchContent)
set(FETCHCONTENT_FULLY_DISCONNECTED OFF)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps)

option(BUILD_SKIA "Build Skia" ON)

message(STATUS "Fetching skia")
FetchContent_Declare(
	skia
	GIT_REPOSITORY  https://github.com/google/skia.git
	GIT_TAG         chrome/m113
	GIT_SHALLOW			TRUE
	GIT_PROGRESS		TRUE
	USES_TERMINAL_DOWNLOAD	TRUE
	SOURCE_DIR			${FETCHCONTENT_BASE_DIR}/skia
)

if (NOT skia_POPULATED)
	FetchContent_Populate(skia)
endif()

# execute_process(
# 		COMMAND_ERROR_IS_FATAL ANY
# 		COMMAND python -c "import platform; print(platform.machine().lower())"
# 		OUTPUT_VARIABLE gn_arch
# )
# list(TRANSFORM gn_arch REPLACE "x86_64" "amd64")

if (BUILD_SKIA)
  set(gn_path bin/gn)

  add_custom_target(
      build_skia
      WORKING_DIRECTORY ${skia_SOURCE_DIR}
      COMMAND python tools/git-sync-deps
      COMMAND "${gn_path};gen;${skia_BINARY_DIR}/$<CONFIG>;--args=is_debug=true is_official_build=false is_component_build=false skia_use_system_freetype2=false skia_use_freetype=true"
      COMMAND ninja -C ${skia_BINARY_DIR}/$<CONFIG> skia
      VERBATIM
      COMMAND_EXPAND_LISTS
      USES_TERMINAL
  )
endif()

set(SKIA_INCLUDE_DIR ${skia_SOURCE_DIR})
set(SKIA_LIB_DIR ${skia_BINARY_DIR}/$<CONFIG>)
