# C++ Compile Time Functions Collection

Just because C++ metaprogramming is awesome. Using C++11. Headers only.

## Usage
include `comptime.h`, use `comptime` namespace.

## Functions or (Structs)
- `IsPrime<N>`

## Tips
Some templates used recursion that, depending value and/or algorithm itself, might sometimes exceed "template instantiation depth". Workaround is use `-ftemplate-depth` compiler flag to set template instantiation depth accordingly.
