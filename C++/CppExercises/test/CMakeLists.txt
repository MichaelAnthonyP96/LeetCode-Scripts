cmake_minimum_required(VERSION 3.1)

set ( TEST_ENV_PATH_OPTIONS "PATH=${CMAKE_CURRENT_BINARY_DIR}/../bin:$ENV{PATH}")

# Catch testing framework library
add_library(catch ${CMAKE_CURRENT_SOURCE_DIR}/catch/catchmain.cpp)
target_include_directories(catch
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/catch/>)
set_target_properties(catch PROPERTIES LINKER_LANGUAGE CXX)

add_executable(runStringUtilTests stringUtilTests.cpp)
target_link_libraries(runStringUtilTests PUBLIC catch stringUtil)
target_include_directories(runStringUtilTests
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>)

add_executable(runMathUtilTests ${CMAKE_CURRENT_SOURCE_DIR}/mathUtilTests.cpp)
target_link_libraries(runMathUtilTests PUBLIC catch mathUtil)
target_include_directories(runMathUtilTests
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>)

add_executable(runArrayUtilTests ${CMAKE_CURRENT_SOURCE_DIR}/arrayUtilTests.cpp)
target_link_libraries(runArrayUtilTests PUBLIC catch arrayUtil)
target_include_directories(runArrayUtilTests
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>)

add_executable(runListNodeUtilTests ${CMAKE_CURRENT_SOURCE_DIR}/listUtilTests.cpp)
target_link_libraries(runListNodeUtilTests PUBLIC catch listUtil)
target_include_directories(runListNodeUtilTests
        PUBLIC
        $<BUILD_INTERFACE:${PROJECT_SOURCE_DIR}/include/>)

add_test(NAME stringUtilTests
        COMMAND ${PROJECT_BINARY_DIR}/bin/runStringUtilTests
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/)
add_test(NAME mathUtilTests
        COMMAND ${PROJECT_BINARY_DIR}/bin/runMathUtilTests
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/)
add_test(NAME arrayUtilTests
        COMMAND ${PROJECT_BINARY_DIR}/bin/runArrayUtilTests
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/)
add_test(NAME listNodeUtilTests
        COMMAND ${PROJECT_BINARY_DIR}/bin/runListNodeUtilTests
        WORKING_DIRECTORY ${PROJECT_BINARY_DIR}/)