cmake_minimum_required(VERSION 3.1)

# set project metadata #########################################################

set(CPPEXERCISES_MAJOR_VERSION 2)
set(CPPEXERCISES_MINOR_VERSION 1)
set(CPPEXERCISES_PATCH_VERSION 0)
set(CPPEXERCISES_EXTRA_VERSION "" CACHE STRING "CPPEXERCISES extra version string")
set(CPPEXERCISES_VERSION "${CPPEXERCISES_MAJOR_VERSION}.${CPPEXERCISES_MINOR_VERSION}")
set(CPPEXERCISES_VERSION
        "${CPPEXERCISES_VERSION}.${CPPEXERCISES_PATCH_VERSION}${CPPEXERCISES_EXTRA_VERSION}")
set(CPPEXERCISES_SHORT_LICENSE "University of Illinois/NCSA Open Source License")
set(CPPEXERCISES_HOMEPAGE_URL "http://git.illinois.rocstar/IR/CPPEXERCISES-NO-IRAD")
set(CPPEXERCISES_AUTHOR "Michael Anthony Pope (lead)")
set(CPPEXERCISES_AUTHOR_EMAIL "michaelpope96@gmail.com")
set(CPPEXERCISES_DESCRIPTION "C++ practice exercises")
set(PROJECT_NAME "CPPEXERCISES version ${CPPEXERCISES_VERSION}")
project(${PROJECT_NAME} CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set project defaults #########################################################
set(default_build_type "Release")
# creating code compilation database
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
# do not install gtest when installing this project
# set(INSTALL_GTEST OFF)

# Options
option(BUILD_SHARED_LIBS "Build shared libraries." ON)
option(ENABLE_MPI "Build with MPI support." ON)
option(ENABLE_TESTS "Build with tests." OFF)

# Installation Directories
include(GNUInstallDirs)

# Setting compile and link options #############################################

# Compiled objects output paths
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# Turn on default warnings for GNU compilers.
if (CMAKE_COMPILER_IS_GNUCC OR CMAKE_COMPILER_IS_GNUCXX)
    # Update if necessary
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wpedantic")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-sign-compare")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wextra -Wno-unused-parameter")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Woverloaded-virtual -Wnon-virtual-dtor")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wstrict-null-sentinel -Wredundant-decls")
    # -Wshadow gives false positives for gcc versions <= 4.8
    if (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wshadow")
    endif (CMAKE_CXX_COMPILER_VERSION VERSION_GREATER 4.9)
    #set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wfloat-conversion")
endif ()

# set up RPATH
set(CMAKE_INSTALL_RPATH "${CMAKE_INSTALL_PREFIX}/lib")
set(CMAKE_INSTALL_RPATH_USE_LINK_PATH TRUE)

# Finding libraries ############################################################
if (NOT ENABLE_MPI)
    add_definitions(-DDUMMY_MPI)
else ()
    find_package(MPI REQUIRED)
    if (MPI_MPICXX_FOUND)
        set(HAVE_MPI true)
    endif (MPI_MPICXX_FOUND)
    include_directories(${MPI_INCLUDE_PATH})
    if (MPI_LIBRARY)
        set(MPI_LIBRARIES ${MPI_LIBRARY})
    endif (MPI_LIBRARY)
    if (MPI_EXTRA_LIBRARY)
        set(MPI_LIBRARIES ${MPI_LIBRARIES} "${MPI_EXTRA_LIBRARY}")
    endif (MPI_EXTRA_LIBRARY)
    # Needed for mpich 2
    add_definitions(-DMPICH_IGNORE_CXX_SEEK)
endif ()

if (ENABLE_TESTS)
    enable_testing()
    add_subdirectory(extern/googletest)
    add_subdirectory(test)
endif ()

# Export CPPEXERCISES as a CMake package
# install(FILES CPPEXERCISESConfig.cmake
#        DESTINATION lib/cmake/CPPEXERCISES)
#install(EXPORT CPPEXERCISES
#        NAMESPACE CPPEXERCISES::
#        DESTINATION lib/cmake/CPPEXERCISES)

add_library(arrayUtil SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/ArrayUtilities.cpp)
target_include_directories(arrayUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(stringUtil SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/StringUtilities.cpp)
target_include_directories(stringUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(mathUtil SHARED ${CMAKE_CURRENT_SOURCE_DIR}/src/MathUtilities.cpp)
target_include_directories(mathUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_library(listUtil SHARED
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ListNodeUtilities.cpp
        ${CMAKE_CURRENT_SOURCE_DIR}/src/ListNode.cpp)
target_include_directories(listUtil
        PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>)

add_executable(main ${CMAKE_CURRENT_SOURCE_DIR}/main.cpp)
target_link_libraries(main PUBLIC arrayUtil stringUtil mathUtil)

# Documentation
#option(BUILD_DOCUMENTATION "Create and install the HTML based API documentation (requires Doxygen)" OFF)
#if(BUILD_DOCUMENTATION)
#    find_package(Doxygen)
#    if(NOT DOXYGEN_FOUND)
#        message(FATAL_ERROR "Doxygen is needed to build the documentation.")
#    endif()
#    set(doxyfile_in ${CMAKE_CURRENT_SOURCE_DIR}/doc/CPPEXERCISES.cfg.in)
#    set(doxyfile ${CMAKE_CURRENT_BINARY_DIR}/CPPEXERCISES.cfg)
#    set(documentation ${CMAKE_CURRENT_BINARY_DIR}/docs)
#    configure_file(${doxyfile_in} ${doxyfile} @ONLY)
#    add_custom_command(OUTPUT ${documentation}
#            COMMAND ${DOXYGEN_EXECUTABLE} ${doxyfile}
#            MAIN_DEPENDENCY ${doxyfile} ${doxyfile_in}
#            DEPENDS ${doxyfile} ${doxy_extra_files}
#            COMMENT "Generating documentation")
#    add_custom_target(docs ALL DEPENDS ${documentation})
#    install(DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/docs
#            DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/CPPEXERCISES)
#endif()

# Packaging ####################################################################
set(CPACK_PACKAGE_NAME "CPPEXERCISES")
set(CPACK_PACKAGE_VENDOR "${CPPEXERCISES_AUTHOR}")
set(CPACK_PACKAGE_VERSION "${CPPEXERCISES_VERSION}")
set(CPACK_PACKAGE_VERSION_MAJOR "${CPPEXERCISES_MAJOR_VERSION}")
set(CPACK_PACKAGE_VERSION_MINOR "${CPPEXERCISES_MINOR_VERSION}")
set(CPACK_PACKAGE_VERSION_PATCH "${CPPEXERCISES_PATCH_VERSION}")
set(CPACK_PACKAGE_DESCRIPTION "${CPPEXERCISES_DESCRIPTION}")
set(CPACK_PACKAGE_DESCRIPTION_SUMMARY "${CPPEXERCISES_DESCRIPTION}")
set(CPACK_PACKAGE_HOMEPAGE_URL "")
set(CPACK_PACKAGE_CONTACT "${CPPEXERCISES_AUTHOR_EMAIL}")
#set(CPACK_PACKAGE_INSTALL_DIRECTORY "") # Use default location.
#set(CPACK_PACKAGE_ICON "") # image used by GUI installers
#set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/LICENSE")
#set(CPACK_RESOURCE_FILE_README "${CMAKE_SOURCE_DIR}/README.md")

if (WIN32)
    set(CPACK_GENERATOR NSIS)
else ()
    if (CMAKE_VERSION VERSION_LESS 3.10)
        message(WARNING "CMake 3.10 or above is required to build a DEB package.")
    else ()
        set(CPACK_GENERATOR DEB)
        #set(CPACK_DEBIAN_PACKAGE_NAME "")
        #set(CPACK_DEBIAN_PACKAGE_VERSION "")
        #set(CPACK_DEBIAN_PACKAGE_ARCHITECTURE "")
        #set(CPACK_DEBIAN_PACKAGE_MAINTAINER "")
        #set(CPACK_DEBIAN_PACKAGE_DESCRIPTION "")
        set(CPACK_DEBIAN_PACKAGE_SECTION "science")
        #set(CPACK_DEBIAN_COMPRESSION_TYPE "gzip")
        #set(CPACK_DEBIAN_PACKAGE_PRIORITY "optional")
        set(CPACK_DEBIAN_PACKAGE_HOMEPAGE "${CPACK_PACKAGE_HOMEPAGE_URL}")
        set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)
        set(CPACK_DEBIAN_PACKAGE_DEBUG ON)  # For testing only
        #set(CPACK_DEBIAN_PACKAGE_PREDEPENDS "")
        #set(CPACK_DEBIAN_PACKAGE_ENHANCES "")
        #set(CPACK_DEBIAN_PACKAGE_BREAKS "")
        #set(CPACK_DEBIAN_PACKAGE_CONFLICTS "")
        #set(CPACK_DEBIAN_PACKAGE_PROVIDES "")
        #set(CPACK_DEBIAN_PACKAGE_REPLACES "")
        #set(CPACK_DEBIAN_PACKAGE_RECOMMENDS "")
        #set(CPACK_DEBIAN_PACKAGE_SUGGESTS "")
        #set(CPACK_DEBIAN_PACKAGE_CONTROL_EXTRA "")

        set(CPACK_DEBIAN_PACKAGE_CONTROL_STRICT_PERMISSION TRUE)  # CMake 3.4
        #set(CPACK_DEBIAN_PACKAGE_SOURCE "")  # CMake 3.5
        #set(CPACK_DEB_COMPONENT_INSTALL OFF)  # CMake 3.6
        set(CPACK_DEBIAN_FILE_NAME "DEB-DEFAULT")  # CMake 3.6
        #set(CPACK_DEBIAN_PACKAGE_RELEASE "1")  # CMake 3.6
        set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS ON)  # CMake 3.6
        #set(CPACK_DEBIAN_PACKAGE_GENERATE_SHLIBS_POLICY "=")  # CMake 3.6
        #set(CPACK_DEBIAN_ARCHIVE_TYPE "gnutar")  # CMake 3.7
        #set(CPACK_DEBIAN_PACKAGE_EPOCH "")  # Cmake 3.10
    endif ()
endif ()
# Lists exe and text label used for Start Menu shortcuts
#set(CPACK_PACKAGE_EXECUTABLES "")
# Must have matching Start Menu shortcut to create a Desktop link
#set(CPACK_CREATE_DESKTOP_LINKS "")

# WIN32 NOTE: - Run CPack from a MSVC environment as dumpbin is required
#               for the fixup_bundle search of DLL dependecies.
#             - The system libraries pulled in are release DLLs.
#               Do NOT package in Debug! THAT APPLIES TO DEPENDENCIES TOO!!
include(CPack)
