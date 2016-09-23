#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"
#include "common-utils.h"

static void cleanUp(char **pointers, ...);

char *add(char *romanNumeral1, char *romanNumeral2)
{
    char *additiveNumerals1 = convertSubtractiveToAdditivePrefix(romanNumeral1);
    char *additiveNumerals2 = convertSubtractiveToAdditivePrefix(romanNumeral2);

    char *combinedNumerals = concatenate(additiveNumerals1, additiveNumerals2);
    char *sortnedNumerals = sortRomanNumerals(combinedNumerals);
    char *internalSumsNumerals = convertInternalSums(sortnedNumerals);
    char *subtractivePrefixNumerals = convertAdditiveToSubtractivePrefix(internalSumsNumerals);

    return subtractivePrefixNumerals;
}

void cleanUp(char **pointers, ...){
  free(*pointers);
}
