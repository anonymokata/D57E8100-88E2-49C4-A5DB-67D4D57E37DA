# roman-numeral-calculator
  A library which allows the addition and subtraction of Roman Numerals
  
  I + I = II
  
  X - I = IX
  
  The maximum Roman Numeral is 3999 (MMMCMXCIX)
  
## Build & Test
  "make all" : compiles [Demo, Test-Suite] and runs [Demo, Test-Suite]

  "make demo" : compiles Demo

  "make test" : compile and run Test-Suite

  "make clean" : clean project

  "make valgrind" : run valgrind

## Demo
  "/bin/demo" : example of how to use the add and subtract functions

## Library
  calculator.c
  
  void add(char *romanNumeral1, char *romanNumeral2, char result[], int size)

  void subtract(char *romanNumeral1, char *romanNumeral2, char result[], int size)

  functions add and subtract require a **result[]** of **size >= 100**
