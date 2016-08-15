#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"

char *_concatinate_roman_numerals(char *roman_numeral1, char *roman_numeral2);

char *add(char *roman_numeral1, char *roman_numeral2)
{
    char *additiveNumerals1 = convert_subtractive_to_additive_prefix(roman_numeral1);
    char *additiveNumerals2 = convert_subtractive_to_additive_prefix(roman_numeral2);

    char *combinedNumerals = _concatinate_roman_numerals(additiveNumerals1, additiveNumerals2);
    char *sortnedNumerals = sort_roman_numerals(combinedNumerals);
    char *internalSumsNumerals = convert_internal_sums(sortnedNumerals);
    char *subtractivePrefixNumerals = convert_additive_to_subtractive_prefix(internalSumsNumerals);
    return subtractivePrefixNumerals;
}

char *_concatinate_roman_numerals(char *roman_numeral1, char *roman_numeral2)
{
  char *result = malloc(strlen(roman_numeral1));
  strcpy(result, roman_numeral1);
  return strcat(result,roman_numeral2);
}
