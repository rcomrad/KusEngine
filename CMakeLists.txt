cmake_minimum_required(VERSION 3.17)
project(ProjectTemplate VERSION 1.0)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SFML_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W")
set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W")
find_package(SFML 2.5 COMPONENTS system window graphics audio main REQUIRED)

include_directories("${SFML_ROOT_DIR}/include") 
include_directories(PUBLIC ${SFML_INCUDE_PATH})

add_executable(${PROJECT_NAME} "sources/main/main.cpp")
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-system sfml-window sfml-network sfml-graphics sfml-audio sfml-main)
add_subdirectory("sources")

set(Configuration "D")
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_V${CMAKE_PROJECT_VERSION}_${Configuration}.exe")