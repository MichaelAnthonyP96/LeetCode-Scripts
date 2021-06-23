include_guard()

cmake_minimum_required(VERSION 3.9)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(HEAP_TEST_HEADERS
        )

set(HEAP_TEST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/HeapUtilTests.cpp
        )

set(HEAP_TEST_ALL_FILES
        ${HEAP_TEST_HEADERS}
        ${HEAP_TEST_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${HEAP_TEST_SOURCES} "Source Files")
    source_group(${HEAP_TEST_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_executable(HeapTests ${HEAP_TEST_ALL_FILES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(HeapTests
        PUBLIC
        "$<BUILD_INTERFACE:$<TARGET_PROPERTY:HeapUtil,INTERFACE_INCLUDE_DIRECTORIES>>"
        "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>"
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################
target_link_libraries(HeapTests PUBLIC
        HeapUtil
        gtest
        gmock
        )

####################################################### TESTING ########################################################
gtest_add_tests(TARGET HeapTests
        SOURCES ${HEAP_TEST_SOURCES}
        EXTRA_ARGS ""
        WORKING_DIRECTORY $<TARGET_FILE_DIR:HeapTests>
        TEST_PREFIX "Heap."
        TEST_HEAP ALL_HEAP_TESTS
        )

set_tests_properties(${ALL_HEAP_TESTS} PROPERTIES
        ENVIRONMENT "PATH=$ENV{PATH};"
        )
################################################### CUSTOM COMMANDS ####################################################
set_target_properties(HeapTests
        PROPERTIES LINKER_LANGUAGE CXX
        )

