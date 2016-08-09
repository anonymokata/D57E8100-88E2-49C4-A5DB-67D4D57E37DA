#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char * concatinate_roman_numerals(char *roman_numeral1, char *roman_numeral2)
{
  char *result = malloc(16);
  strcpy(result, roman_numeral1);
  return strcat(result,roman_numeral2);
}

char * add(char *roman_numeral1, char *roman_numeral2)
{
    return concatinate_roman_numerals(roman_numeral1, roman_numeral2);
}
