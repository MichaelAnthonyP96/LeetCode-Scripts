include_guard()

cmake_minimum_required(VERSION 3.9)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(LIST_TEST_HEADERS
        )

set(LIST_TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SinglyLinkedListTests.cpp
        )

set(LIST_TEST_ALL_FILES
        ${LIST_TEST_HEADERS}
        ${LIST_TEST_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${LIST_TEST_SOURCES} "Source Files")
    source_group(${LIST_TEST_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_executable(listTests ${LIST_TEST_ALL_FILES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(listTests
        PUBLIC
        "$<BUILD_INTERFACE:$<TARGET_PROPERTY:listUtil,INTERFACE_INCLUDE_DIRECTORIES>>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################
target_link_libraries(listTests PUBLIC
        gtest
        gmock
        )

####################################################### TESTING ########################################################
gtest_add_tests(TARGET listTests
        SOURCES ${LIST_TEST_SOURCES}
        EXTRA_ARGS ""
        WORKING_DIRECTORY $<TARGET_FILE_DIR:listTests>
        TEST_PREFIX "List."
        TEST_LIST ALL_LIST_TESTS
        )

set_tests_properties(${ALL_LIST_TESTS} PROPERTIES
        ENVIRONMENT "PATH=$ENV{PATH};"
        )
################################################### CUSTOM COMMANDS ####################################################
set_target_properties(listTests
        PROPERTIES LINKER_LANGUAGE CXX
        )

