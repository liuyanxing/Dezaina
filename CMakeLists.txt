cmake_minimum_required(VERSION 3.5)

project(Desaina)
set(SOURCE src/main.cpp)

add_executable(Desaina ${SOURCE})

set(THIRD_PARTY_INCLUDE
		${PROJECT_SOURCE_DIR}/src/third_party/kiwi/include)

target_include_directories(Desaina PRIVATE ${PROJECT_SOURCE_DIR}/src/function/nodes/include)
target_include_directories(Desaina PRIVATE ${THIRD_PARTY_INCLUDE})

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)