include_guard()

cmake_minimum_required(VERSION 3.9)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(HEAP_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/HeapUtilities.h
        )

set(HEAP_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/HeapUtilities.cpp
        )

set(HEAP_ALL_FILES
        ${HEAP_HEADERS}
        ${HEAP_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${HEAP_SOURCES} "Source Files")
    source_group(${HEAP_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_library(HeapUtil SHARED ${HEAP_ALL_FILES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(HeapUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################

####################################################### TESTING ########################################################
if (ENABLE_TESTS)
    add_subdirectory(test)
endif ()

################################################### CUSTOM COMMANDS ####################################################
set_target_properties(HeapUtil
        PROPERTIES LINKER_LANGUAGE CXX
        )