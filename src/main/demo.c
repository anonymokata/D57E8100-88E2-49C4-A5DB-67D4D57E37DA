#include <stdio.h>
#include "src/main/calculator.h"

int main(int argc, char *argv[])
{
    char addResult[100] = {'\0'};
    add("I","I", addResult, 100);
    printf("add(I,I) = %s\n", addResult);

    char subtractResult[100] = {'\0'};
    subtract("X","I", subtractResult, 100);
    printf("subtract(X,I) = %s\n", subtractResult);

    return 0;
}
