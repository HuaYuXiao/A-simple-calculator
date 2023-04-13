# A-simple-calculator-in-C
SUSTech CS205

Implement a calculator which can multiply two numbers.

## Requirements

When you run the program as follows, it will output the expression and the result. The two numbers
should be input through the command line arguments. If the two numbers are integers, the
program will multiply them in integer format.
```
$./mul 2 3
2 * 3 = 6
```
If the input contains some non-integer numbers, the program will try to interpret the input as floating-
point numbers.
```
./mul 3.1416 2
3.1416 * 2 = 6.
./mul 3.1415 2.0e-
3.1415 * 0.02 = 0.
```
It can tell that the input is not a number.
```
./mul a 2
The input cannot be interpret as numbers!
```
If you input some big integers, what will happen? Please describe some possible solutions, and try to
implement them.
```
./mul 1234567890 1234567890
```
If you input some big floating-point numbers, what will happen? Please describe some possible
solutions, and try to implement them.
```
./mul 1.0e200 1.0e
```
