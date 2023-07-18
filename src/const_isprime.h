#ifndef CONST_ISPRIME_H_
#define CONST_ISPRIME_H_

#include <cstdint>

#define INT_TY_ASRT static_assert(std::is_integral<size_t>::value, "only accept integral types");

namespace comptime {
    template<size_t N, size_t I, bool X = (I * I <= N), bool E = (N % I == 0 || N % (I + 2) == 0)>
    struct IsPrimeLoop {
        INT_TY_ASRT
    };

    template<size_t N, size_t I>
    struct IsPrimeLoop<N, I, true, false> {
        INT_TY_ASRT
        STC(bool) value = IsPrimeLoop<N, I + 6>::value;
    };

    template<size_t N, size_t I, bool E>
    struct IsPrimeLoop<N, I, false, E> {
        INT_TY_ASRT
        STC(bool) value = true;
    };

    template<size_t N, size_t I>
    struct IsPrimeLoop<N, I, true, true> {
        INT_TY_ASRT
        STC(bool) value = false;
    };

    template<size_t N, bool X = (N == 2 || N == 3), bool Y = (N <= 1 || N % 2 == 0 || N % 3 == 0)>
    struct IsPrime {
        INT_TY_ASRT
        STC(bool) value = IsPrimeLoop<N, 5>::value;
    };

    template <size_t N, bool Y>
    struct IsPrime<N, true, Y> {
        INT_TY_ASRT
        STC(bool) value = true;
    };

    template <size_t N, bool X>
    struct IsPrime<N, X, true> {
        INT_TY_ASRT
        STC(bool) value = false;
    };
}

#undef INT_TY_ASRT
#endif