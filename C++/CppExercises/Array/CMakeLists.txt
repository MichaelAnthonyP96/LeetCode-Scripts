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

#################################################### DOCUMENTATION #####################################################
if (BUILD_DOCUMENTATION)
    set(DOXYGEN_PROJECT_NAME "arrayUtil")
    set(DOXYGEN_PROJECT_NUMBER "${PROJECT_VERSION}")
    set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
    set(DOXYGEN_GENERATE_LATEX NO)
    set(DOXYGEN_IMAGE_PATH "${PROJECT_SOURCE_DIR}/doc/images")
    set(DOXYGEN_WARN_LOGFILE "${CMAKE_CURRENT_BINARY_DIR}/docs/doxywarn.txt")
    set(ARRAY_DOC_DIRS
            ${CMAKE_CURRENT_SOURCE_DIR}/include
            ${CMAKE_CURRENT_SOURCE_DIR}/src
            )
    doxygen_add_docs(arrayUtilDocs
        ${ARRAY_DOC_DIRS}
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
            COMMENT "Generating arrayUtil documentation..."
            )
endif()

################################################### CUSTOM COMMANDS ####################################################
set_target_properties(arrayUtil
        PROPERTIES LINKER_LANGUAGE CXX
        )



