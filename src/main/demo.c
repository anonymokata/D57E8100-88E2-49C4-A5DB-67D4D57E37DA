#include <stdio.h>
#include "src/main/calculator.h"
#include "constants.h"

int main(int argc, char *argv[])
{
    char addResult[BUFFER_SIZE] = {'\0'};
    add("I","I", addResult, BUFFER_SIZE);
    printf("add(I,I) = %s\n", addResult);

    char subtractResult[BUFFER_SIZE] = {'\0'};
    subtract("X","I", subtractResult, BUFFER_SIZE);
    printf("subtract(X,I) = %s\n", subtractResult);

    return 0;
}
