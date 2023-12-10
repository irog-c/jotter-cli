cmake_minimum_required(VERSION 3.27.9)

project(jotter)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

set(ALL_SOURCES
    "${PROJECT_SOURCE_DIR}/include/jotter.hpp"
    "${PROJECT_SOURCE_DIR}/src/jotter.cpp"
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})
set_property(TARGET ${PROJECT_NAME} PROPERTY CXX_STANDARD 20)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)