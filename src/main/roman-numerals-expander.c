#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "roman-numerals-sorter.h"
#include "common-utils.h"

static char expandIndexes[6] = {'V','X','L','C','D','M'};
static char *expandValues[6] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *makeExpandedValues(char expandBy);
static char findExpandMatchInRomanNumerals(char *romanNumerals, char *expandBy);

void expandNumerals(char *romanNumerals, char *expandBy, char result[]){
  char partialResult[100] = {'\0'};

  char *expandMatch = findExpandMatchInRomanNumerals(romanNumerals, expandBy);
  char *expandedValue = makeExpandedValues(expandMatch);

  replaceSubstring(romanNumerals, &expandMatch, expandedValue, partialResult);
  sortRomanNumerals(partialResult, result);
}

char findExpandMatchInRomanNumerals(char *romanNumerals, char *expandBy){
  int romanNumeralsLength = strlen(romanNumerals)-1;

  for (int index = romanNumeralsLength; index >= 0; index--) {
    if(isGreaterThanOrEqual(romanNumerals[index], expandBy[0])){
       return romanNumerals[index];
    }
  }
}

char *makeExpandedValues(char expandBy){
  int matchIndex = 0;
  for (int i = 0; i < 6; i++) {
    if(expandIndexes[i] == expandBy){
      matchIndex = i;
    }
  }
  return expandValues[matchIndex];
}
