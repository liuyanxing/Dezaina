set(TARGET_NAME Dea)

set(TARGET_INCLUE_DIRS
	${CMAKE_CURRENT_SOURCE_DIR}/node/include
	${CMAKE_CURRENT_SOURCE_DIR}/change/include)

add_library(${TARGET_NAME} STATIC)

target_sources(${TARGET_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/dezaina.cpp
	)

add_subdirectory(node)
add_subdirectory(document)
add_subdirectory(resource)
