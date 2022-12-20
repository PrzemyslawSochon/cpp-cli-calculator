# C++ CLI Calculator

The calculator is my project built from the ground up in C++.
Its primary task is to debug and calculate mathematical expressions.

As for now, it supports:

1. Six different operations:
-exponent,
-division's remainder,
-multiplication,
-division,
-addition,
-subtraction.

2. Multi-operational expressions such as: `1^2%3*4/5+6-7`.
3. Negative and floating variables.
4. Constants: `Pi` (the trigonometric constant) and `e` (the natural logarithm).


## Getting started

To run and compile the project you need:
1. Compiler with C++17 or above support.
2. Terminal emulator.

## Expression debug

The calculator is set to debug an expression, before attempting to solve it.

It's configurable to take two actions:
1. Stop running and print adequate error.
2. If possible, fix the input by itself.

## Calculation

After successfully debugging an expression to the analysis-friendly state it does the following:

1. Stores user input as a string object called `expression`.
2. Looks for the leading operation (configurable in `settings.hpp`) in the string.
3. Copy both operands.
4. Convert string operands to floating variables (double type).
5. Calculate the result of the sub-expression.
6. Swap the sub-expression with a new result.
7. Print the expression.
8. Repeat until no operands are found.

## Configuration

Debugging behavior, order of operations and constants' values are configurable in the `settings.hpp` file.

#### Examples

1. `constexpr std::array <std::string_view, 6>
order_of_operations` holds the order of operations.
By default, it is set to `{'^', '%', '*', '/', '+', '-'};`
You might want to deprecate the priority of a modulo sign '%'.

2. `constexpr bool g_verbose` decides whether or not to prompt the user with debug details. By default, it is set to `true`.

3. `namespace mathConstants` holds constants' values. The contents are self-explanatory.

4. Rest of the file holds inline functions, which I am going to split in the future.

### Links

- Project homepage: https://github.com/PrzemyslawSochon/cpp-cli-calculator
- Repository: https://github.com/PrzemyslawSochon/cpp-cli-calculator


### Licensing

The code in this project is licensed under MIT license.
