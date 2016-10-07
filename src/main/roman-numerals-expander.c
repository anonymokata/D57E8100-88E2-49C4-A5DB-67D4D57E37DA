#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "common-utils.h"

static const int EXPAND_ARRAY_SIZE = 6;
static char expandIndexes[] = {'V','X','L','C','D','M'};
static char *expandValues[] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *findExpandValues(char expandBy);
static char findExpandMatchInRomanNumerals(char *romanNumerals, char expandBy);
static void replaceExpandByWithExpandedValues(char *romanNumerals, char expandMatch, char *expandedValues, char unSortedResult[]);

void expandNumerals(char *romanNumerals, char expandBy, char result[]){
  char expandMatch = findExpandMatchInRomanNumerals(romanNumerals, expandBy);
  char *expandedValues = findExpandValues(expandMatch);

  char unSortedResult[100] = {};
  replaceExpandByWithExpandedValues(romanNumerals, expandMatch, expandedValues, unSortedResult);
  sortRomanNumerals(unSortedResult, result);
}

char findExpandMatchInRomanNumerals(char *romanNumerals, char expandBy){
  int romanNumeralsLength = strlen(romanNumerals)-1;

  for (int index = romanNumeralsLength; index >= 0; index--) {
    if(isGreaterThanOrEqual(romanNumerals[index], expandBy)){
       return romanNumerals[index];
    }
  }
  return -1;
}

char *findExpandValues(char expandBy){
  int matchIndex = 0;
  for (int i = 0; i < EXPAND_ARRAY_SIZE; i++) {
    if(expandIndexes[i] == expandBy){
      matchIndex = i;
    }
  }
  return expandValues[matchIndex];
}

void replaceExpandByWithExpandedValues(char *romanNumerals, char expandMatch, char *expandedValues, char unSortedResult[]){
    char expandedMatchString[2] = {};
    expandedMatchString[0] = expandMatch;

    replaceSubstring(romanNumerals, expandedMatchString, expandedValues, unSortedResult);
}
