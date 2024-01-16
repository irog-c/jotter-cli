cmake_minimum_required(VERSION 3.27.9)
project(jotter)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if (MSVC)
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /O /W4 /Wall")
else ()
    set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3 -Wall -Wextra")
endif ()

file(GLOB ALL_SOURCES "${PROJECT_SOURCE_DIR}/src/*.cpp")

add_executable(${PROJECT_NAME} ${ALL_SOURCES})
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/include)

find_package(cxxopts)
find_package(fmt)
find_package(nlohmann_json)
find_package(ICU)

set(LIBS fmt::fmt nlohmann_json::nlohmann_json cxxopts::cxxopts ICU::uc)
target_link_libraries(${PROJECT_NAME} ${LIBS})

if (NOT BUILD_TESTING STREQUAL OFF)
    list(REMOVE_ITEM ALL_SOURCES "${PROJECT_SOURCE_DIR}/src/main.cpp")
    add_subdirectory(test)
endif ()

install(TARGETS ${PROJECT_NAME})
