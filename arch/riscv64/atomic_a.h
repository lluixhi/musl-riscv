#define a_cas a_cas
static inline int a_cas(volatile int *p, int t, int s)
{
        int old, tmp;
        __asm__("li %1, 1\n"
                "1:\n\t"
                "lr.w %0, %2\n\t"
                "bne %0, %3, 1f\n\t"
                "sc.w %1, %4, %2\n\t"
                "bnez %1, 1b\n"
                "1:"
                : "=rJ"(old), "=rJ"(tmp), "+A"(*(p))
                : "r"(t), "r"(s));
        return old;
}

#define a_swap a_swap
static inline int a_swap(volatile int *p, int v)
{
        int old;
        __asm__("amoswap.w %0, %2, %1"
                : "=rJ"(old), "+A"(*(p))
                : "r"(v));
        return old;
}

#define a_fetch_add a_fetch_add
static inline int a_fetch_add(volatile int *p, int v)
{
        int tmp;
        __asm__("amoadd.w %0, %2, %1"
                :"=rJ"(tmp), "+A"(*(p))
                :"r"(v));
        return tmp;
}

#define a_fetch_and a_fetch_and
static inline int a_fetch_and(volatile int *p, int v)
{
        int tmp;
        __asm__("amoand.w %0, %2, %1"
                :"=rJ"(tmp), "+A"(*(p))
                :"r"(v));
        return tmp;
}

#define a_fetch_or a_fetch_or
static inline int a_fetch_or(volatile int *p, int v)
{
        int tmp;
        __asm__("amoor.w %0, %2, %1"
                :"=rJ"(tmp), "+A"(*(p))
                :"r"(v));
        return tmp;
}

#define a_and_64 a_and_64
static inline void a_and_64(volatile uint64_t *p, uint64_t v)
{
        int tmp;
        __asm__("amoand.d %0, %2, %1"
                :"=rJ"(tmp), "+A"(*(p))
                :"r"(v));
}

#define a_or_64 a_or_64
static inline void a_or_64(volatile uint64_t *p, uint64_t v)
{
        int tmp;
        __asm__("amoor.d %0, %2, %1"
                :"=rJ"(tmp), "+A"(*(p))
                :"r"(v));
}

#define a_cas_p a_cas_p
static inline void *a_cas_p(volatile void *p, void *t, void *s)
{
        void *old;
        int tmp;
        __asm__("li %1, 1\n"
                "1:\n\t"
                "lr.d %0, %2\n\t"
                "bne %0, %3, 1f\n\t"
                "sc.d %1, %4, %2\n\t"
                "bnez %1, 1b\n"
                "1:"
                : "=rJ"(old), "=rJ"(tmp), "+A"(*((long *)p))
                : "r"(t), "r"(s));
        return old;
}

