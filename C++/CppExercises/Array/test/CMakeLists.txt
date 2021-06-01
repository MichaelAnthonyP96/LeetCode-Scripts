include_guard()

cmake_minimum_required(VERSION 3.15)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(ARRAY_TEST_HEADERS
        )

set(ARRAY_TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/arrayUtilTests.cpp
        )

set(ARRAY_TEST_ALL_FILES
        ${ARRAY_TEST_HEADERS}
        ${ARRAY_TEST_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${ARRAY_TEST_SOURCES} "Source Files")
    source_group(${ARRAY_TEST_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_executable(arrayTests ${ARRAY_TEST_ALL_FILES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(arrayTests
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################
target_link_libraries(arrayTests PUBLIC
        gtest
        gmock
        arrayUtil
        )

####################################################### TESTING ########################################################
gtest_add_tests(TARGET arrayTests
        SOURCES ${ARRAY_TEST_SOURCES}
        EXTRA_ARGS ""
        WORKING_DIRECTORY $<TARGET_FILE_DIR:arrayTests>
        TEST_PREFIX "Array."
        TEST_ARRAY ALL_ARRAY_TESTS
        )

set_tests_properties(${ALL_ARRAY_TESTS} PROPERTIES
        ENVIRONMENT "PATH=$ENV{PATH};"
        )
################################################### CUSTOM COMMANDS ####################################################
set_target_properties(arrayTests
        PROPERTIES LINKER_LANGUAGE CXX
        )

