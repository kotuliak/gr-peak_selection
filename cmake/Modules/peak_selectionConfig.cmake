if(NOT PKG_CONFIG_FOUND)
    INCLUDE(FindPkgConfig)
endif()
PKG_CHECK_MODULES(PC_PEAK_SELECTION peak_selection)

FIND_PATH(
    PEAK_SELECTION_INCLUDE_DIRS
    NAMES peak_selection/api.h
    HINTS $ENV{PEAK_SELECTION_DIR}/include
        ${PC_PEAK_SELECTION_INCLUDEDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/include
          /usr/local/include
          /usr/include
)

FIND_LIBRARY(
    PEAK_SELECTION_LIBRARIES
    NAMES gnuradio-peak_selection
    HINTS $ENV{PEAK_SELECTION_DIR}/lib
        ${PC_PEAK_SELECTION_LIBDIR}
    PATHS ${CMAKE_INSTALL_PREFIX}/lib
          ${CMAKE_INSTALL_PREFIX}/lib64
          /usr/local/lib
          /usr/local/lib64
          /usr/lib
          /usr/lib64
          )

include("${CMAKE_CURRENT_LIST_DIR}/peak_selectionTarget.cmake")

INCLUDE(FindPackageHandleStandardArgs)
FIND_PACKAGE_HANDLE_STANDARD_ARGS(PEAK_SELECTION DEFAULT_MSG PEAK_SELECTION_LIBRARIES PEAK_SELECTION_INCLUDE_DIRS)
MARK_AS_ADVANCED(PEAK_SELECTION_LIBRARIES PEAK_SELECTION_INCLUDE_DIRS)
