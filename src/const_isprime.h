#ifndef CONST_ISPRIME_H_
#define CONST_ISPRIME_H_

#define STC(Ty) static constexpr Ty

#ifndef INTTYPE
#define INTTYPE int
#endif
static_assert(std::is_integral<INTTYPE>::value, "only accept integral");

namespace comptime {
    template<INTTYPE N, INTTYPE I, bool X = (I * I <= N), bool E = (N % I == 0 || N % (I + 2) == 0)>
    struct IsPrimeLoop {};

    template<INTTYPE N, INTTYPE I>
    struct IsPrimeLoop<N, I, true, false> {
        STC(bool) value = IsPrimeLoop<N, I + 6>::value;
    };

    template<INTTYPE N, INTTYPE I, bool E>
    struct IsPrimeLoop<N, I, false, E> {
        STC(bool) value = true;
    };

    template<INTTYPE N, INTTYPE I>
    struct IsPrimeLoop<N, I, true, true> {
        STC(bool) value = false;
    };

    template<INTTYPE N, bool X = (N == 2 || N == 3), bool Y = (N <= 1 || N % 2 == 0 || N % 3 == 0)>
    struct IsPrime {
        STC(bool) value = IsPrimeLoop<N, 5>::value;
    };

    template <INTTYPE N, bool Y>
    struct IsPrime<N, true, Y> {
        STC(bool) value = true;
    };

    template <INTTYPE N, bool X>
    struct IsPrime<N, X, true> {
        STC(bool) value = false;
    };
}


#undef STRSPC
#undef STC
#endif