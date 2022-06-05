function(get_sources
         PATH_TO_SOURCES_DIR SOURCES_NAME)
    set(DIRS_NAMES core domain game gui logic main space)

    foreach(DIR_NAME IN LISTS DIRS_NAMES)
        include(${PATH_TO_SOURCES_DIR}/${DIR_NAME}/${DIR_NAME}_sources.cmake)

        string(TOUPPER ${DIR_NAME} UPPER_DIR_NAME)
        list(TRANSFORM ${UPPER_DIR_NAME}_SOURCES PREPEND
             ${PATH_TO_SOURCES_DIR}/${DIR_NAME}/)

        list(APPEND SOURCES ${${UPPER_DIR_NAME}_SOURCES})
    endforeach()

    set(${SOURCES_NAME} ${SOURCES} PARENT_SCOPE)
endfunction()
