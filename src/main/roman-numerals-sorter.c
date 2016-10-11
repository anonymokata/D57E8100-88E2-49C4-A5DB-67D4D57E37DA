#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getRomanNumeralSortIndex(const char romanNumeral);
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

int getRomanNumeralSortIndex(const char romanNumeral){
  char sortedRomanNumerals[] = {'I','V','X','L','C','D','M'};

  int sortIndex = 0;
  for (int index = 0; index < sizeof(sortedRomanNumerals); index++) {
    if(romanNumeral == sortedRomanNumerals[index]){
      sortIndex = index;
    }
  }

  return sortIndex;
}
