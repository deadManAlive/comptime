#ifndef CONST_FIBONACCI_H_
#define CONST_FIBONACCI_H_

namespace comptime {
    template<size_t N, size_t I, size_t A, size_t B, bool L = (I <= N)>
    struct FibonacciLoop {};

    template<size_t N, size_t I, size_t A, size_t B>
    struct FibonacciLoop<N, I, A, B, true> {
        STC(size_t) value = FibonacciLoop<N, I + 1, B, A + B>::value;
    };

    template<size_t N, size_t I, size_t A, size_t B>
    struct FibonacciLoop<N, I, A, B, false> {
        STC(size_t) value = B;
    };

    template<size_t N>
    struct Fibonacci {
        STC(size_t) value = FibonacciLoop<N, 1, 1, 0>::value;
    };
}

#endif