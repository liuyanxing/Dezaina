set(TARGET_NAME Dea)

include(${CMAKE_CURRENT_SOURCE_DIR}/depends.cmake)

set(TARGET_INCLUE_DIRS
	${SKIA_INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/node/include
	${CMAKE_CURRENT_SOURCE_DIR}/change/include)

add_library(${TARGET_NAME} STATIC)
target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUE_DIRS})

target_sources(${TARGET_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/dezaina.cpp
	)

add_subdirectory(node)
add_subdirectory(document)
add_subdirectory(resource)
add_subdirectory(viewport)

set(TARGET_LINK_LIBS
  Node
  Document
  Resource
	Viewport
)

target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_LINK_LIBS})
