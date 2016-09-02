#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"
#include "common-utils.h"

char *add(char *roman_numeral1, char *roman_numeral2)
{
    char *additiveNumerals1 = convert_subtractive_to_additive_prefix(roman_numeral1);
    char *additiveNumerals2 = convert_subtractive_to_additive_prefix(roman_numeral2);

    char *combinedNumerals = concatenate(additiveNumerals1, additiveNumerals2);
    char *sortnedNumerals = sort_roman_numerals(combinedNumerals);
    char *internalSumsNumerals = convert_internal_sums(sortnedNumerals);
    char *subtractivePrefixNumerals = convert_additive_to_subtractive_prefix(internalSumsNumerals);
    return subtractivePrefixNumerals;
}
