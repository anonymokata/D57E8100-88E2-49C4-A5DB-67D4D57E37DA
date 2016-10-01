#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"
#include "common-utils.h"

char *add(char *romanNumeral1, char *romanNumeral2)
{
    char *additiveNumerals1 = calloc(100, sizeof(char));
    char *additiveNumerals2 = calloc(100, sizeof(char));

    convertSubtractiveToAdditivePrefix(romanNumeral1, additiveNumerals1);
    convertSubtractiveToAdditivePrefix(romanNumeral2,additiveNumerals2);

    char *combinedNumerals = concatenate(additiveNumerals1, additiveNumerals2);
    char *sortnedNumerals = sortRomanNumerals(combinedNumerals);

    char *internalSumsNumerals = calloc(100, sizeof(char));
    convertInternalSums(sortnedNumerals,internalSumsNumerals);

    char *subtractivePrefixNumerals = calloc(100, sizeof(char));
    convertAdditiveToSubtractivePrefix(internalSumsNumerals,subtractivePrefixNumerals);

    return subtractivePrefixNumerals;
}
