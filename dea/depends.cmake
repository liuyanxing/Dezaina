include(FetchContent)
set(FETCHCONTENT_FULLY_DISCONNECTED OFF)
set(FETCHCONTENT_QUIET OFF)
set(FETCHCONTENT_BASE_DIR ${PROJECT_SOURCE_DIR}/deps)

option(BUILD_SKIA "Build Skia" ON)
option(FETCH_SKIA "Build Skia" ON)

if (FETCH_SKIA)
  message(STATUS "Fetching skia")
  FetchContent_Declare(
    skia
    GIT_REPOSITORY  https://github.com/google/skia.git
    GIT_TAG         chrome/m128
    GIT_SHALLOW			TRUE
    GIT_PROGRESS		TRUE
    USES_TERMINAL_DOWNLOAD	TRUE
    SOURCE_DIR			${FETCHCONTENT_BASE_DIR}/skia
  )

  if (NOT skia_POPULATED)
    FetchContent_Populate(skia)
  endif()
else()
  set(skia_SOURCE_DIR ${PROJECT_SOURCE_DIR}/deps/skia)
  set(skia_BINARY_DIR ${PROJECT_SOURCE_DIR}/deps/skia/out/Debug)
endif()

if (BUILD_SKIA)
  set(gn_path "${skia_SOURCE_DIR}/bin/gn")
  set(clang_win "\"C:/Program Files/LLVM\"")
  add_custom_target(
      build_skia
      WORKING_DIRECTORY ${skia_SOURCE_DIR}
      COMMAND python3 tools/git-sync-deps
      COMMAND python3 bin/fetch-ninja
      COMMAND "${gn_path};gen;${skia_BINARY_DIR}/$<CONFIG>;--args=is_debug=true skia_use_fontconfig=false skia_use_gl=true is_official_build=false is_component_build=false skia_use_system_freetype2=false skia_use_freetype=true clang_win=${clang_win} extra_cflags=[\"/MDd\"]"
      COMMAND ${skia_SOURCE_DIR}/third_party/ninja/ninja -C ${skia_BINARY_DIR}/$<CONFIG> skia
      VERBATIM
      COMMAND_EXPAND_LISTS
      USES_TERMINAL
  )
endif()

set(SKIA_INCLUDE_DIR ${skia_SOURCE_DIR})
set(skia_link_directories ${skia_BINARY_DIR}/$<CONFIG>)
