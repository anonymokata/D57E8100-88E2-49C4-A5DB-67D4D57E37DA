#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "common-utils.h"

static char expandIndexes[6] = {'V','X','L','C','D','M'};
static char *expandValues[6] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *makeExpandedValues(char expandBy);

void expandNumerals(char *romanNumerals, char *expandBy, char result[]){
  char partialResult[100] = {'\0'};
  char *expandedValues;
  char *expandMatch;
  int size = strlen(romanNumerals)-1;

  for (int i = size; i >= 0; i--) {
    if(isGreaterThanOrEqual(romanNumerals[i], expandBy[0])){
       expandMatch = romanNumerals[i];
       expandedValues = makeExpandedValues(expandMatch);
       break;
    }
  }

  replaceSubstring(romanNumerals, &expandMatch, expandedValues, partialResult);
  sortRomanNumerals(partialResult, result);
}

static char *makeExpandedValues(char expandBy){
  int matchIndex = 0;
  for (int i = 0; i < 6; i++) {
    if(expandIndexes[i] == expandBy){
      matchIndex = i;
    }
  }
  return expandValues[matchIndex];
}
