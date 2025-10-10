cmake_minimum_required(VERSION 3.10)

project(Lab2)

add_library(${CMAKE_PROJECT_NAME}_lib src/Binary.cpp)
add_executable(${CMAKE_PROJECT_NAME}_exe main.cpp)

target_link_libraries(${CMAKE_PROJECT_NAME}_exe PRIVATE ${CMAKE_PROJECT_NAME}_lib)

# Добавление тестов
enable_testing()

add_executable(tests test/test.cpp)
target_link_libraries(tests ${CMAKE_PROJECT_NAME}_lib gtest_main)

# Добавление тестов в тестовый набор
add_test(NAME ProjectTests COMMAND tests)