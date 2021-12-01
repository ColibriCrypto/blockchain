# - Find    
# This module defines
#    _INCLUDE_DIR, where to find     headers
#    _LIBRARY,     libraries
#    _FOUND, If false, do not try to use    

set(   _PREFIX "" CACHE PATH "path ")

find_path(   _INCLUDE_DIR   .h
        PATHS ${   _PREFIX}/include /usr/include /usr/local/include
        PATH_SUFFIXES   )

find_library(   _LIBRARY NAMES    lib  
        PATHS ${   _PREFIX}/lib /usr/lib /usr/local/lib)

if(   _INCLUDE_DIR AND    _LIBRARY)
    get_filename_component(   _LIBRARY_DIR ${   _LIBRARY} PATH)
    set(   _FOUND TRUE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
           DEFAULT_MSG
           _INCLUDE_DIR
           _LIBRARY
)

if(   _FOUND)
    file(STRINGS "${   _INCLUDE_DIR}/  .h"   _API_VERSION_STR REGEX "^#define[\t ]+  _API_VERSION[\t ]+[0-9]+")
    if(  _API_VERSION_STR MATCHES "^#define[\t ]+  _API_VERSION[\t ]+([0-9]+)")
        set(  _API_VERSION "${CMAKE_MATCH_1}")
        if (${  _API_VERSION} GREATER "10" OR ${  _API_VERSION} EQUAL "10")
            if(NOT    _FIND_QUIETLY)
                message(STATUS "Found    API version " ${  _API_VERSION})
            endif()
            set(   _FOUND true)
        else()
            message(FATAL_ERROR "Unsupported    version!")
        endif()
    endif()
else()
    if(   _FIND_REQUIRED)
        message(FATAL_ERROR "Could not find    ")
    endif()
endif()

mark_as_advanced(
           _LIBRARY
           _INCLUDE_DIR
)