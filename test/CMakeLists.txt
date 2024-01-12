cmake_minimum_required(VERSION 3.27.9)
project(jotter_test CXX)

find_package(GTest REQUIRED CONFIG)
include(GoogleTest)
enable_testing()

file(GLOB TEST_SOURCES ${PROJECT_SOURCE_DIR}/src/*.cpp ${PROJECT_SOURCE_DIR}/mocks/*.hpp)

add_executable(${PROJECT_NAME} ${ALL_SOURCES} ${TEST_SOURCES})
target_link_libraries(${PROJECT_NAME}
        ${LIBS}
        GTest::gtest_main
        GTest::gmock
)
target_include_directories(${PROJECT_NAME} PRIVATE ${PROJECT_SOURCE_DIR}/../include mock)
