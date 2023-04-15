# C++ Compile Time Functions Collection

Just because C++ metaprogramming is awesome. Using C++11 (so no `consteval`).

## Usage
include `comptime.h`, use `comptime` namespace.

## Functions or (Structs)
- `bool IsPrime<N>::value`
- `size_t Fibonacci<N>::value` ($N$-th fibonacci from $F_0=0$ and $F_1=1$)

### Note
 - Each `::value` is actually a `static constexpr <Type>`.

## Tips
Some templates used recursion that, depending value and/or algorithm itself, might sometimes exceed "template instantiation depth". Workaround is use `-ftemplate-depth` compiler flag to set template instantiation depth accordingly.
