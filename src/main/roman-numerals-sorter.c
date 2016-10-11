#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../main/common-utils.h"

static int compareRomanNumerals(const void * a, const void * b);

const char *sortRomanNumerals(const char *romanNumerals, char result[])
{
  char romanNumeralsCopy[100] = {};
  strcpy(romanNumeralsCopy, romanNumerals);

  qsort(romanNumeralsCopy, strlen(romanNumerals), sizeof(char), compareRomanNumerals);

  strcpy(result,romanNumeralsCopy);
  return result;
}

int compareRomanNumerals(const void *a, const void *b){
  int sortIndexOfA = getRomanNumeralSortIndex(*(char*)a);
  int sortIndexOfB = getRomanNumeralSortIndex(*(char*)b);
  return sortIndexOfA < sortIndexOfB;
}
