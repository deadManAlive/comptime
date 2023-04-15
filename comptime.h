#ifndef COMPTIME_H_
#define COMPTIME_H_
#define STC(Ty) static constexpr Ty

#include "src/const_isprime.h"
#include "src/const_fibonacci.h"

#undef STC
#endif