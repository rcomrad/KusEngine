cmake_minimum_required(VERSION 3.17)
project(BasicGame VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(SFML_STATIC_LIBRARIES TRUE)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/bin")

set(SFML_ROOT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W")
set(SFML_ROOT "${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W")
set(SFML_DIR "${SFML_ROOT_DIR}/lib/cmake/SFML")
find_package(SFML 2.5 COMPONENTS audio graphics window network system REQUIRED)
#include_directories(${SFML_ROOT_DIR} "/include") 
include_directories("${SFML_ROOT_DIR}/include") 
include_directories(${SFML_INCUDE_PATH})
link_directories("${SFML_ROOT_DIR}/lib") 
link_directories(${SFML_INCUDE_PATH})

set(SFML_FIND_PATH ${CMAKE_PREFIX_PATH})
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

#find_path(SFML_INCLUDE_DIR SFML/Config.hpp
#        PATH_SUFFIXES include
#        PATHS ${SFML_ROOT_DIR})
#https://github.com/CaffeinatedTech/nibbles/blob/main/nibbles-01/cmake_modules/FindSFML.cmake
#https://www.cyberforum.ru/sfml/thread2822667.html
#https://github.com/microsoft/vscode/issues/15908
add_executable(${PROJECT_NAME} "sources/main/main.cpp")

#target_compile_definitions(${PROJECT_NAME} PROJECT_PATH = "${CMAKE_CURRENT_SOURCE_DIR}")
#target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-network sfml-audio sfml-window sfml-graphics)
target_link_libraries(${PROJECT_NAME} PUBLIC sfml-system sfml-window sfml-network sfml-graphics sfml-audio sfml-main)
#target_include_directories("${SFML_ROOT_DIR}/include")

add_subdirectory("sources")

set(Configuration "D")

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)

set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME "${PROJECT_NAME}")
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX "_V${CMAKE_PROJECT_VERSION}_${Configuration}.exe")