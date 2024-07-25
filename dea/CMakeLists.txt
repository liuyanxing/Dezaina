set(TARGET_NAME Dea)

include(${CMAKE_CURRENT_SOURCE_DIR}/depends.cmake)

set(TARGET_INCLUE_DIRS
	${SKIA_INCLUDE_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}/node/include
	${CMAKE_CURRENT_SOURCE_DIR}/change/include)

set(SUBDIRECTORIES
    common
    viewport
)
foreach(SUBDIR ${SUBDIRECTORIES})
    # Glob source files
    set(SUBDIR_SOURCES)
    aux_source_directory(./${SUBDIR} SUBDIR_SOURCES)

    # Glob header files
    file(GLOB SUBDIR_HEADERS "./${SUBDIR}/*.h*")

    # Combine sources and headers
    set(SUBDIR_FILES ${SUBDIR_SOURCES} ${SUBDIR_HEADERS})

    # Add sources and headers under subdir named folder
    string(REPLACE "/" "\\" SUBDIR_NAME ${SUBDIR})
    source_group("${SUBDIR_NAME}" FILES ${SUBDIR_FILES})

    # Add sources and headers to library target
    set(LIB_SOURCES ${LIB_SOURCES} ${SUBDIR_FILES})
endforeach(SUBDIR)

list(APPEND SOURCES
		${LIB_SOURCES}
		${CMAKE_CURRENT_SOURCE_DIR}/dezaina.cpp
		)

add_library(${TARGET_NAME} STATIC ${SOURCES})

add_subdirectory(node)
add_subdirectory(document)
add_subdirectory(resource)

set(TARGET_LINK_LIBS
  Node
  Document
  Resource
)

target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUE_DIRS})
target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_LINK_LIBS})
