include_guard()

cmake_minimum_required(VERSION 3.9)

set(DOXYGEN_PROJECT_NAME "${PROJECT_NAME}")
set(DOXYGEN_PROJECT_NUMBER "${PROJECT_VERSION}")
set(DOXYGEN_OUTPUT_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}")
set(DOXYGEN_GENERATE_LATEX NO)
set(DOXYGEN_IMAGE_PATH "${PROJECT_SOURCE_DIR}/docs/images/icon.png")
set(DOXYGEN_PROJECT_LOGO "${PROJECT_SOURCE_DIR}/docs/images/icon.png")
set(DOXYGEN_GENERATE_TREEVIEW YES)
set(DOXYGEN_HTML_EXTRA_STYLESHEET
        ${PROJECT_SOURCE_DIR}/extern/doxygen-awesome-css/doxygen-awesome.css
        ${PROJECT_SOURCE_DIR}/extern/doxygen-awesome-css/doxygen-awesome-sidebar-only.css)
set(DOXYGEN_WARN_LOGFILE "${CMAKE_CURRENT_BINARY_DIR}/doxywarn.txt")
set(DOC_DIRS
        ${PROJECT_SOURCE_DIR}/Array/src
        ${PROJECT_SOURCE_DIR}/Array/include
        ${PROJECT_SOURCE_DIR}/LinkedList/src
        ${PROJECT_SOURCE_DIR}/LinkedList/include
        )

doxygen_add_docs(Docs
        ${DOC_DIRS}
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
        COMMENT "Generating project documentation..."
        )
