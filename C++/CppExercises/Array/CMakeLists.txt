include_guard()

cmake_minimum_required(VERSION 3.15)

############################################# SOURCE/HEADER DETERMINATION ##############################################
set(ARRAY_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ArrayUtilities.hpp
        )

set(ARRAY_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ArrayUtilities.cpp
        )

################################################### DECLARE BINARIES ###################################################
add_library(arrayUtil SHARED
        ${ARRAY_SOURCES}
        )

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(arrayUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        )

################################################# COMPILE DEFINITIONS ##################################################

################################################### LINK LIBRARIES #####################################################
#target_link_libraries(arrayUtil
#        PUBLIC
#        )

####################################################### TESTING ########################################################
if (ENABLE_TESTS)
    add_subdirectory(test)
endif ()

################################################### CUSTOM COMMANDS ####################################################
set_target_properties(arrayUtil
        PROPERTIES LINKER_LANGUAGE CXX
        )



