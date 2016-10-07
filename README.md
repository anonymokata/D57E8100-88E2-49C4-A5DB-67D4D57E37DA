# roman-numeral-calculator
## Build & Test
  "make all" : compiles [Demo, Test-Suite] and run Test-Suite

  "make demo" : compiles Demo

  "make test" : compile and run Test-Suite

  "make clean" : clean project

  "make valgrind" : run valgrind

## Demo
  "/bin/demo" : example of how to use the add and subtract functions

## Calculator Library
  void add(char *romanNumeral1, char *romanNumeral2, char result[], int size)

  void subtract(char *romanNumeral1, char *romanNumeral2, char result[], int size)

  functions add and subtract require a buffer of size > **100**
