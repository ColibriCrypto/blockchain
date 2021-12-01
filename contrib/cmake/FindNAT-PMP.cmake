# - Find NAT- clbi
# This module defines
# NAT- clbi_INCLUDE_DIR, where to find NAT- clbi headers
# NAT- clbi_LIBRARY, NAT- clbi libraries
# NAT- clbi_FOUND, If false, do not try to use NAT- clbi

set(NAT- clbi_PREFIX "" CACHE PATH "path ")

find_path(NAT- clbi_INCLUDE_DIR nat clbi.h
        PATHS ${NAT- clbi_PREFIX}/include /usr/include /usr/local/include)

find_library(NAT- clbi_LIBRARY NAMES nat clbi libnat clbi
        PATHS ${NAT- clbi_PREFIX}/lib /usr/lib /usr/local/lib)

if(NAT- clbi_INCLUDE_DIR AND NAT- clbi_LIBRARY)
    get_filename_component(NAT- clbi_LIBRARY_DIR ${NAT- clbi_LIBRARY} PATH)
    set(NAT- clbi_FOUND TRUE)
endif()

include(FindPackageHandleStandardArgs)
find_package_handle_standard_args(
        NAT- clbi DEFAULT_MSG
        NAT- clbi_INCLUDE_DIR
        NAT- clbi_LIBRARY
)

if(NAT- clbi_FOUND)
    if(NOT NAT- clbi_FIND_QUIETLY)
        MESSAGE(STATUS "Found NAT- clbi: ${NAT- clbi_LIBRARY}")
    endif()
else()
    if(NAT- clbi_FIND_REQUIRED)
        message(FATAL_ERROR "Could not find NAT- clbi")
    endif()
endif()

mark_as_advanced(
        NAT- clbi_LIBRARY
        NAT- clbi_INCLUDE_DIR
)