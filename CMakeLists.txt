cmake_minimum_required(VERSION 3.5)

project(Desaina)
set(SOURCE src/main.cpp)

add_executable(Desaina ${SOURCE})

set(INCLUDE_Dir
		${PROJECT_SOURCE_DIR}/src/function/nodes/include
		${PROJECT_SOURCE_DIR}/src/third_party/kiwi/include
	)

target_include_directories(Desaina PUBLIC ${INCLUDE_Dir})
