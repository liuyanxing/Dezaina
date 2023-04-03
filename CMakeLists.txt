cmake_minimum_required(VERSION 3.5)

project(Desaina)

set(CMAKE_CXX_STANDARD 20)
set(SOURCE src/main.cpp)

add_executable(Desaina ${SOURCE})

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake/depends.cmake)

set(INCLUDE_DIR
		${PROJECT_SOURCE_DIR}/src/function/nodes/pre_include
		${PROJECT_SOURCE_DIR}/src/function/nodes/include
		${PROJECT_SOURCE_DIR}/src/third_party/kiwi/include
		${SKIA_INCLUDE_DIR}
	)

target_include_directories(Desaina PUBLIC ${INCLUDE_DIR})


# add_dependencies(Desaina build_skia)
