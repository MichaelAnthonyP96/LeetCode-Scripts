include_guard()

cmake_minimum_required(VERSION 3.9)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(STRING_TEST_HEADERS
        )

set(STRING_TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/stringUtilTests.cpp
        )

set(STRING_TEST_ALL_FILES
        ${STRING_TEST_HEADERS}
        ${STRING_TEST_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${STRING_TEST_SOURCES} "Source Files")
    source_group(${STRING_TEST_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_executable(stringTests ${STRING_TEST_ALL_FILES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(stringTests
        PUBLIC
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################
target_link_libraries(stringTests PUBLIC
        gtest
        gmock
        stringUtil
        )

####################################################### TESTING ########################################################
gtest_add_tests(TARGET stringTests
        SOURCES ${STRING_TEST_SOURCES}
        EXTRA_ARGS ""
        WORKING_DIRECTORY $<TARGET_FILE_DIR:stringTests>
        TEST_PREFIX "String."
        TEST_STRING ALL_STRING_TESTS
        )

set_tests_properties(${ALL_STRING_TESTS} PROPERTIES
        ENVIRONMENT "PATH=$ENV{PATH};"
        )
################################################### CUSTOM COMMANDS ####################################################
set_target_properties(stringTests
        PROPERTIES LINKER_LANGUAGE CXX
        )

