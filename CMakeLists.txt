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

include(FetchContent)

FetchContent_Declare(
        cxxopts
        GIT_REPOSITORY https://github.com/jarro2783/cxxopts.git
        GIT_TAG        v3.1.1
)
FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG        10.1.1
)
FetchContent_Declare(
        json
        GIT_REPOSITORY https://github.com/ArthurSonzogni/nlohmann_json_cmake_fetchcontent
        GIT_PROGRESS TRUE
        GIT_SHALLOW TRUE
        GIT_TAG v3.11.2
)

FetchContent_MakeAvailable(cxxopts fmt json)

target_include_directories(
    ${PROJECT_NAME} 
    PRIVATE ${fmt_SOURCE_DIR}/include
    PRIVATE ${cxxopts_SOURCE_DIR}/include
    PRIVATE ${json_SOURCE_DIR}/single_include
)

target_link_libraries(
    ${PROJECT_NAME}
    PRIVATE fmt
    PRIVATE nlohmann_json::nlohmann_json
    PRIVATE cxxopts
)

install(TARGETS ${PROJECT_NAME} DESTINATION bin)
