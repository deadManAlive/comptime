#include <iostream>

#define INTTYPE unsigned long long
#include "comptime.h"

using comptime::IsPrime;

int main() {
    constexpr INTTYPE z = 1746987019;
    std::cout << z << " " << (IsPrime<z>::value ? "is a prime." : "is not a prime.") << std::endl;
}