#ifndef COMPTIME_H_
#define COMPTIME_H_

#include <type_traits>

#ifndef INTTYPE
#define INTTYPE int
#endif
static_assert(std::is_integral<INTTYPE>::value, "only accept integral");

#include "src/const_isprime.h"

#endif