cmake_minimum_required(VERSION 3.17)
project(KusEngine VERSION 2.0)
set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin)

if(WIN32)
    set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_W)
else()
    set(SFML_ROOT_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libraries/SFML-2.5.1_L)
endif()

set(SFML_DIR ${SFML_ROOT_DIR}/lib/cmake/SFML)

find_package(SFML 2.5.1 COMPONENTS system window graphics audio REQUIRED)

find_package( Boost 1.40 COMPONENTS program_options REQUIRED )

include(${CMAKE_CURRENT_SOURCE_DIR}/sources/sources.cmake)

get_sources(${CMAKE_CURRENT_SOURCE_DIR}/sources SOURCES)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE ${Boost_INCLUDE_DIR})

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/sources)

target_compile_definitions(${PROJECT_NAME} PRIVATE
                           LINUS_LINUX LOGS_OUTPUT_TYPE=1 ERRORS_OUTPUT_TYPE=4)
if(WIN32)
    target_compile_definitions(${PROJECT_NAME} PRIVATE BILL_WINDOWS)
else()
    target_compile_definitions(${PROJECT_NAME} PRIVATE LINUS_LINUX)
endif()

target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system sfml-window sfml-network sfml-graphics sfml-audio)

set(Configuration D)
set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/bin/$<0:>)
set_target_properties(${PROJECT_NAME} PROPERTIES OUTPUT_NAME ${PROJECT_NAME})
set_target_properties(${PROJECT_NAME} PROPERTIES SUFFIX _V${CMAKE_PROJECT_VERSION}_${Configuration}.exe)
