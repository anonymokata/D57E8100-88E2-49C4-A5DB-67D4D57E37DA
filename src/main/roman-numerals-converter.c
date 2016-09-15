#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

int _findPrefixIndex(char *prefixArray[], int arraySize, char *romanNumerals);
int _numeralsContainsInternalSum(char *romanNumerals,char *internalSumPrefix);
int _numeralsContainsAdditivePrefix(char *romanNumerals,char *additivePrefix);
int _numeralsContainsSubtractivePrefix(char *romanNumerals,char *subtractivePrefix);
char *convertInternalSum(char *romanNumerals);

#define NO_INDEX -1
#define SUBTRACTIVE_PREFIX_ARRAY_SIZE 6
#define ADDITIVE_PREFIX_ARRAY_SIZE 6
#define INTERNAL_SUM_ARRAY_SIZE 6

char *convertSubtractiveToAdditivePrefix(char *romanNumerals){
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};

  int i;
  for (i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
    if(_numeralsContainsSubtractivePrefix(romanNumerals, subtractivePrefix[i])){
      romanNumerals = replaceSubstring(romanNumerals, subtractivePrefix[i], additivePrefix[i]);
    }
  }
  return romanNumerals;
}

char *convertAdditiveToSubtractivePrefix(char *romanNumerals){
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};

  int i;
  for (i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
    if(_numeralsContainsAdditivePrefix(romanNumerals, additivePrefix[i])){
      romanNumerals = replaceSubstring(romanNumerals, additivePrefix[i], subtractivePrefix[i]);
    }
  }
  return romanNumerals;
}

char *convertInternalSums(char *romanNumerals){
  char *internalSumPrefix[7] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
  char *internalSumValue[7] = {"V","X","L","C","D","M"};

  int i;
  for (i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
    if(_numeralsContainsInternalSum(romanNumerals, internalSumPrefix[i])){
      romanNumerals = replaceSubstring(romanNumerals, internalSumPrefix[i], internalSumValue[i]);
    }
  }
  return romanNumerals;
}

int _numeralsContainsInternalSum(char *romanNumerals,char *internalSumPrefix){
  return strstr(romanNumerals, internalSumPrefix) != NULL;
}

int _numeralsContainsAdditivePrefix(char *romanNumerals,char *additivePrefix){
  return strstr(romanNumerals, additivePrefix) != NULL;
}

int _numeralsContainsSubtractivePrefix(char *romanNumerals,char *subtractivePrefix){
  return strstr(romanNumerals, subtractivePrefix) != NULL;
}

int _findPrefixIndex(char *prefixArray[], int arraySize, char *romanNumerals){
  int prefixIndex = NO_INDEX;
  int i;
  for (i = 0; i < arraySize; i++) {
    if(strcmp(prefixArray[i],romanNumerals) == 0){
      prefixIndex = i;
    }
  }
  return prefixIndex;
}
