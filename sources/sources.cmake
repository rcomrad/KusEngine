#--------------------------------------------------------------------------------

macro(get_sources SOURCE_LIST DIR)
    set(FOLDER_NAMES core event file gui)
    add_sources(${SOURCE_LIST} "${DIR}/sources" "${FOLDER_NAMES}")
endmacro()

#--------------------------------------------------------------------------------
