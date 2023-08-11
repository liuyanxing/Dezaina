set(TARGET_NAME DesainaCore)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/depends.cmake)

set(TARGET_LINK_DIRS ${SKIA_LIB_DIR})
set(TARGET_INCLUE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/source/function
	${CMAKE_CURRENT_SOURCE_DIR}/source/function/nodes/include_gen
	${CMAKE_CURRENT_SOURCE_DIR}/source/function/nodes/source
	${CMAKE_CURRENT_SOURCE_DIR}/source/third_party/kiwi/include
	${CMAKE_CURRENT_SOURCE_DIR}/source
	${PROJECT_SOURCE_DIR}/src
	${SKIA_INCLUDE_DIR})
set(TARGET_LINK_LIBS skia)

file(GLOB_RECURSE SOURCE_FILES CONFIGURE_DEPENDS "*.cpp")
add_library(${TARGET_NAME} STATIC ${SOURCE_FILES})

add_dependencies(${TARGET_NAME} build_skia)

set_target_properties(${TARGET_NAME} PROPERTIES CXX_STANDARD 20)

target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUE_DIRS})
target_link_directories(${TARGET_NAME} PUBLIC ${TARGET_LINK_DIRS})

target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_LINK_LIBS})