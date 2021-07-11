# HugeInt


_A project developed in order to learn and implement basic Data Structures and Functional Programming techniques._

## Objective
Adding support in C language, for numbers greater than 20 digits along with basic mathematical operations and functions.

## Context
Languages like Java support classes like BigIntegers allowing developers to utilize numbers with upto a 100 digits. HugeInt aims to provide support upto a 1000 digits in the C language along with basic mathematical operations (comparison, addition, subtraction, multiplication) and some mathematical functions (Fibonacci series, factorial).


## Description

 Macros  | Description        | Value
------------- | ------------- | ----------------
INT_MAX  | Maximum value for a variable of type int | 2147483647
LONG_MAX  | Maximum value for a variable of type long | 2147483647
LLONG_MAX | Maximum value for a variable of type long long | 9,223,372,036,854,775,807
ULLONG_MAX | Maximum value for a variable of type unsigned long long | 18,446,744,073,709,551,615

Now, consider the following case: 

> _How to compute factorial of 100 using a C/C++ program?_

>> Factorial of 100 has 158 digits. It is not possible to store these many digits even if we use long long int.

HugeInt will help us efficiently handle numbers with large digits in C language. With very few syntactical changes it could be also used in C++. The following features have been implemented in `HugeInt` .
1. hugeIntAdd : Function to add huge integers
2. hugeIntDifference : Funtion to subtract two huge integers
3. hugeIntMultiply : Function to Multiply two huge integers
4. hugeIntMod : Function to perform Modular division between two huge integers
5. hugeIntGCD : Function to calculate Greatest Common Divisor
6. hugeIntFibonacci : Function to return `n`th Fibonacci number of a given number
7. hugeIntFactorial : Function to calculate Factorial of given huge Integer

For Verification of Calculations use - https://www.omnicalculator.com/math#s-19
Most of other calculators rounds off to `e` and the output may not be accurate upto the last digit.
