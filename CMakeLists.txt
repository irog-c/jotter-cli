cmake_minimum_required(VERSION 3.27.9)
project(jotter)
set(CMAKE_CXX_STANDARD 23)

set(ALL_SOURCES
    "${PROJECT_SOURCE_DIR}/src/note_manager.cpp"
    "${PROJECT_SOURCE_DIR}/src/common.cpp"
    "${PROJECT_SOURCE_DIR}/src/config.cpp"
    "${PROJECT_SOURCE_DIR}/src/main.cpp"
)

add_executable(${PROJECT_NAME} ${ALL_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

find_package(cxxopts)
find_package(fmt)
find_package(nlohmann_json)

target_link_libraries(
    ${PROJECT_NAME}
    fmt::fmt
    nlohmann_json::nlohmann_json
    cxxopts::cxxopts
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
