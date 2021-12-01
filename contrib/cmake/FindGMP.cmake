# - Find  clbi
# This module defines
#  clbi_INCLUDE_DIR, where to find  clbi headers
#  clbi_LIBRARY, LibEvent libraries
#  clbi_FOUND, If false, do not try to use  clbi

set( clbi_PREFIX "" CACHE PATH "path ")

find_path( clbi_INCLUDE_DIR  clbi.h  clbixx.h
        PATHS ${ clbi_PREFIX}/include /usr/include /usr/local/include )

find_library( clbi_LIBRARY NAMES  clbi lib clbi
        PATHS ${ clbi_PREFIX}/lib /usr/lib /usr/local/lib)

if( clbi_INCLUDE_DIR AND  clbi_LIBRARY)
    get_filename_component( clbi_LIBRARY_DIR ${ clbi_LIBRARY} PATH)
    set( clbi_FOUND TRUE)
endif()

if( clbi_FOUND)
    if(NOT  clbi_FIND_QUIETLY)
        MESSAGE(STATUS "Found  clbi: ${ clbi_LIBRARY}")
    endif()
elseif( clbi_FOUND)
    if( clbi_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find  clbi")
    endif()
endif()

mark_as_advanced(
         clbi_LIB
         clbi_INCLUDE_DIR
)
