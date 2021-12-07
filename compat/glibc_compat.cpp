#if defined(HAVE_CONFIG_H)
#include "config/clbi-config.h"
#endif

#include <cstddef>
#include <cstdint>
#include <cstring>
#include <pthread.h>
#include <stdlib.h>

extern "C" void* memmove(void* a, const void* b, size_t c);
extern "C" void* memcpy(void* a, const void* b, size_t c)
{
    return memmove(a, b, c);
}

#if defined(__i386__) || defined(__arm__)

extern "C" int64_t __udivmoddi4(uint64_t u, uint64_t v, uint64_t* rp);

extern "C" int64_t __wrap___divmoddi4(int64_t u, int64_t v, int64_t* rp)
{
    int32_t c1 = 0, c2 = 0;
    int64_t uu = u, vv = v;
    int64_t w;
    int64_t r;

    if (uu < 0) {
        c1 = ~c1, c2 = ~c2, uu = -uu;
    }
    if (vv < 0) {
        c1 = ~c1, vv = -vv;
    }

    w = __udivmoddi4(uu, vv, (uint64_t*)&r);
    if (c1)
        w = -w;
    if (c2)
        r = -r;

    *rp = r;
    return w;
}
#endif

extern "C" float log2f_old(float x);
#ifdef __i386__
__asm(".symver log2f_old,log2f@GLIBC_2.1");
#elif defined(__amd64__)
__asm(".symver log2f_old,log2f@GLIBC_2.2.5");
#elif defined(__arm__)
__asm(".symver log2f_old,log2f@GLIBC_2.4");
#elif defined(__aarch64__)
__asm(".symver log2f_old,log2f@GLIBC_2.17");
#elif defined(__riscv)
__asm(".symver log2f_old,log2f@GLIBC_2.27");
#endif
extern "C" float __wrap_log2f(float x)
{
    return log2f_old(x);
}

/* glibc-internal users use __explicit_bzero_chk, and explicit_bzero
redirects to that.  */
#undef explicit_bzero
/* Set LEN bytes of S to 0.  The compiler will not delete a call to
this function, even if S is dead after the call.  */
void explicit_bzero (void *s, size_t len)
{
    memset (s, '\0', len);
    /* Compiler barrier.  */
    asm volatile ("" ::: "memory");
}

// Redefine explicit_bzero_chk
void __explicit_bzero_chk (void *dst, size_t len, size_t dstlen)
{
    /* Inline __memset_chk to avoid a PLT reference to __memset_chk.  */
    if (__glibc_unlikely (dstlen < len))
        __chk_fail ();
    memset (dst, '\0', len);
    /* Compiler barrier.  */
    asm volatile ("" ::: "memory");
}
