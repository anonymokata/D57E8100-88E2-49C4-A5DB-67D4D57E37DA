#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "roman-numerals-converter.h"

char *_concatinate_roman_numerals(char *roman_numeral1, char *roman_numeral2);

char *add(char *roman_numeral1, char *roman_numeral2)
{
    char *combinedNumeral = _concatinate_roman_numerals(roman_numeral1, roman_numeral2);

    return sort_roman_numerals(combinedNumeral);
}

char *_concatinate_roman_numerals(char *roman_numeral1, char *roman_numeral2)
{
  char *result = malloc(strlen(roman_numeral1));
  strcpy(result, roman_numeral1);
  return strcat(result,roman_numeral2);
}
