cmake_minimum_required(VERSION 3.27.9)

project(jotter)

set(CMAKE_CXX_STANDARD 20)

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

add_subdirectory(external/fmt)
add_subdirectory(external/json)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC external/fmt/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC fmt
    PRIVATE nlohmann_json
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
