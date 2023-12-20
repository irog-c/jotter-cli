cmake_minimum_required(VERSION 3.27.9)

project(jotter)

set(CMAKE_CXX_STANDARD 20)

include_directories(
    ${PROJECT_SOURCE_DIR}/include
    ${PROJECT_SOURCE_DIR}/src
)

set(ALL_SOURCES
    "${PROJECT_SOURCE_DIR}/include/note_manager.hpp"
    "${PROJECT_SOURCE_DIR}/include/common.hpp"
    "${PROJECT_SOURCE_DIR}/include/config.hpp"
    "${PROJECT_SOURCE_DIR}/src/note_manager.cpp"
    "${PROJECT_SOURCE_DIR}/src/common.cpp"
    "${PROJECT_SOURCE_DIR}/src/config.cpp"
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})

add_subdirectory(external/fmt)
add_subdirectory(external/json)
add_subdirectory(external/cxxopts)

target_include_directories(
    ${PROJECT_NAME} 
    PUBLIC external/fmt/include
    PUBLIC external/cxxopts/include
)

target_link_libraries(
    ${PROJECT_NAME}
    PUBLIC fmt
    PRIVATE nlohmann_json
    PRIVATE cxxopts
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
