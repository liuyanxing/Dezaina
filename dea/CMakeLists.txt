set(TARGET_NAME Dea)

include(${CMAKE_CURRENT_SOURCE_DIR}/depends.cmake)
set(TARGET_LINK_LIBS
    skia
  )

set(TARGET_INCLUE_DIRS
    ${CMAKE_CURRENT_SOURCE_DIR}
    ${SKIA_INCLUDE_DIR}  
)

set(TARGET_LINK_DIRS
  ${skia_BINARY_DIR}
  ${JSON_INCLUDE_DIR}
)

set(SUB_DIR
    common
    geometry
    viewport
    utility
)
set(SUB_MODULES
    command
    document
    node
    change
    render
    resource
    event
    interaction
)

foreach(SUBDIR ${SUB_DIR})
    # Glob source files
    set(SUBDIR_SOURCES)
    aux_source_directory(./${SUBDIR} SUBDIR_SOURCES)

    # Combine sources and headers
    set(SUBDIR_FILES ${SUBDIR_SOURCES})

    # Add sources and headers under subdir named folder
    string(REPLACE "/" "\\" SUBDIR_NAME ${SUBDIR})
    source_group("${SUBDIR_NAME}" FILES ${SUBDIR_FILES})

    # Add sources and headers to library target
    set(LIB_SOURCES ${LIB_SOURCES} ${SUBDIR_FILES})
endforeach(SUBDIR)

foreach(SUBDIR ${SUB_MODULES})
    # Glob source files
    set(TARGET_INCLUE_DIRS ${TARGET_INCLUE_DIRS} ./${SUBDIR}/include)
    set(SUBDIR_SOURCES)
    aux_source_directory(./${SUBDIR}/src SUBDIR_SOURCES)

    # Combine sources and headers
    set(SUBDIR_FILES ${SUBDIR_SOURCES})

    # Add sources and headers under subdir named folder
    string(REPLACE "/" "\\" SUBDIR_NAME ${SUBDIR})
    source_group("${SUBDIR_NAME}" FILES ${SUBDIR_FILES})

    # Add sources and headers to library target
    set(MODULE_SOURCES ${MODULE_SOURCES} ${SUBDIR_FILES})
endforeach(SUBDIR)

list(APPEND SOURCES
		${LIB_SOURCES}
    ${MODULE_SOURCES}
		${CMAKE_CURRENT_SOURCE_DIR}/dezaina.cpp
		) 
add_library(${TARGET_NAME} STATIC ${SOURCES})

if (BUILD_SKIA)
  add_dependencies(${TARGET_NAME} build_skia)
endif()

target_compile_definitions(${TARGET_NAME} PUBLIC
  SK_DEBUG
	SK_GL
	SK_GANESH
  # SK_TRIVIAL_ABI=[[clang::trivial_abi]]
)

target_link_directories(${TARGET_NAME} PUBLIC ${TARGET_LINK_DIRS})
target_include_directories(${TARGET_NAME} PUBLIC ${TARGET_INCLUE_DIRS})
target_link_libraries(${TARGET_NAME} PUBLIC ${TARGET_LINK_LIBS})
