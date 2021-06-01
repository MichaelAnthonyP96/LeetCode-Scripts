include_guard()

cmake_minimum_required(VERSION 3.9)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(STRING_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/StringUtilities.hpp
        )

set(STRING_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/StringUtilities.cpp
        )

set(STRING_ALL_FILES
        ${STRING_HEADERS}
        ${STRING_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${STRING_SOURCES} "Source Files")
    source_group(${STRING_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_library(stringUtil SHARED ${STRING_SOURCES})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(stringUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################

####################################################### TESTING ########################################################
if (ENABLE_TESTS)
    add_subdirectory(test)
endif ()

################################################### CUSTOM COMMANDS ####################################################
set_target_properties(stringUtil
        PROPERTIES LINKER_LANGUAGE CXX
        )