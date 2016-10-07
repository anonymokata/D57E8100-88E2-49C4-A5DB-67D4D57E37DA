#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "common-utils.h"

static const int EXPAND_ARRAY_SIZE = 6;
static char expandIndexes[] = {'V','X','L','C','D','M'};
static char *expandValues[] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *findExpandValues(const char expandBy);
static char findExpandMatchInRomanNumerals(const char *romanNumerals, const char expandBy);
static void replaceExpandByWithExpandedValues(const char *romanNumerals, const char expandMatch, const char *expandedValues, char unSortedResult[]);

void expandNumerals(const char *romanNumerals, const char expandBy, char result[]){
  char expandMatch = findExpandMatchInRomanNumerals(romanNumerals, expandBy);
  char *expandedValues = findExpandValues(expandMatch);

  char unSortedResult[100] = {};
  replaceExpandByWithExpandedValues(romanNumerals, expandMatch, expandedValues, unSortedResult);
  sortRomanNumerals(unSortedResult, result);
}

char findExpandMatchInRomanNumerals(const char *romanNumerals, const char expandBy){
  int romanNumeralsLength = strlen(romanNumerals)-1;

  int expandMatchIndex = 0;
  for (int index = romanNumeralsLength; index >= 0; index--) {
    if(isGreaterThanOrEqual(romanNumerals[index], expandBy)){
        expandMatchIndex = index;
        break;
    }
  }
  return romanNumerals[expandMatchIndex];
}

char *findExpandValues(const char expandBy){
  int matchIndex = 0;
  for (int i = 0; i < EXPAND_ARRAY_SIZE; i++) {
    if(expandIndexes[i] == expandBy){
      matchIndex = i;
    }
  }
  return expandValues[matchIndex];
}

void replaceExpandByWithExpandedValues(const char *romanNumerals, const char expandMatch, const char *expandedValues, char unSortedResult[]){
    char expandedMatchString[2] = {};
    expandedMatchString[0] = expandMatch;

    replaceSubstring(romanNumerals, expandedMatchString, expandedValues, unSortedResult);
}
