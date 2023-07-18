#include <iostream>
#include "comptime.h"

using comptime::IsPrime;
using comptime::Fibonacci;

int main() {
    const auto z = 51131;
    std::cout << z << " " << (IsPrime<z>::value ? "is a prime." : "is not a prime.") << std::endl;

    constexpr size_t y = 15;
    std::cout << "#" << y << " Fib: " << Fibonacci<y>::value << std::endl;
}