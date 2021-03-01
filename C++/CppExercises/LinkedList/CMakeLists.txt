############################################# SOURCE/HEADER DETERMINATION ##############################################
set(LIST_HEADERS
        ${CMAKE_CURRENT_SOURCE_DIR}/include/ListADT.hpp
        ${CMAKE_CURRENT_SOURCE_DIR}/include/SinglyLinkedList.hpp
        )

set(LIST_SOURCES
        ${CMAKE_CURRENT_SOURCE_DIR}/src/SinglyLinkedList.cpp
        )

set(LIST_ALL_FILES
        ${LIST_HEADERS}
        ${LIST_SOURCES}
        )

if (MSVC OR XCODE)
    source_group(${LIST_SOURCES} "Source Files")
    source_group(${LIST_HEADERS} "Header Files")
endif ()
################################################### DECLARE BINARIES ###################################################
add_library(listUtil SHARED ${LIST_HEADERS})

################################################# INCLUDE DIRECTORIES ##################################################
target_include_directories(listUtil
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
set_target_properties(listUtil
        PROPERTIES LINKER_LANGUAGE CXX
        )