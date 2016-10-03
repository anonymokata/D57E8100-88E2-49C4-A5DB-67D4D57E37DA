#include <stdio.h>
#include "src/main/calculator.h"

int main(int argc, char *argv[])
{
    char result[100] = {'\0'};
    add("I","I", result);
    printf("add(I,I) = %s\n", result);

    return 0;
}
