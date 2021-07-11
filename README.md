# HugeInt


_A project developed in order to learn and implement basic Data Structures and Functional Programming techniques._

## Objective
Adding support in C language, for numbers greater than 20 digits along with basic mathematical operations and functions.

## Context
Languages like Java support classes like BigIntegers allowing developers to utilize numbers with upto a 100 digits. HugeInt aims to provide support upto a 1000 digits in the C language along with basic mathematical operations (comparison, addition, subtraction, multiplication) and some mathematical functions (Fibonacci series, factorial).


## Description
Consider the following types in C++: 

INT_MAX: 	Maximum value for a variable of type int is 2147483647
LONG_MAX:	Maximum value for a variable of type long is 2147483647
LLONG_MAX: Maximum value for a variable of type long long is 9,223,372,036,854,775,807
ULLONG_MAX: Maximum value for a variable of type unsigned long long is 18,446,744,073,709,551,615

Now, consider the following case: 

_How to compute factorial of 100 using a C/C++ program?_

Factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long long int.
