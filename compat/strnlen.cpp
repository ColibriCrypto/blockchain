// Copyright (c) 2021 The CLBI Core developers
//      
//   

#if defined(HAVE_CONFIG_H)
#include "config/clbi-config.h"
#endif

#include <cstring>

#if HAVE_DECL_STRNLEN == 0
size_t strnlen( const char *start, size_t max_len)
{
    const char *end = (const char *)memchr(start, '\0', max_len);

    return end ? (size_t)(end - start) : max_len;
}
#endif // HAVE_DECL_STRNLEN
