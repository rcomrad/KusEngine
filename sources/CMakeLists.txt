set(DIRS core domain events game gui main space)
foreach(DIR IN LISTS DIRS)
    add_subdirectory(${DIR})
    target_include_directories(${DIR} PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}")
    target_link_libraries(${PROJECT_NAME} PRIVATE ${DIR})
endforeach()

