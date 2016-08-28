#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

int _findPrefixIndex(char *prefixArray[], int arraySize, char *roman_numerals);
int _numeralsContainsInternalSum(char *roman_numerals,char *internalSumPrefix);
int _numeralsContainsAdditivePrefix(char *roman_numerals,char *additivePrefix);
int _numeralsContainsSubtractivePrefix(char *roman_numerals,char *subtractivePrefix);
char *convert_internal_sum(char *roman_numerals);

#define NO_INDEX -1
#define SUBTRACTIVE_PREFIX_ARRAY_SIZE 6
#define ADDITIVE_PREFIX_ARRAY_SIZE 6
#define INTERNAL_SUM_ARRAY_SIZE 6

char *convert_subtractive_to_additive_prefix(char *romanNumerals){
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};

  int i;
  for (i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
    if(_numeralsContainsSubtractivePrefix(romanNumerals, subtractivePrefix[i])){
      romanNumerals = replace_substring(romanNumerals, subtractivePrefix[i], additivePrefix[i]);
    }
  }
  return romanNumerals;
}

char *convert_additive_to_subtractive_prefix(char *romanNumerals){
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};

  int i;
  for (i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
    if(_numeralsContainsAdditivePrefix(romanNumerals, additivePrefix[i])){
      romanNumerals = replace_substring(romanNumerals, additivePrefix[i], subtractivePrefix[i]);
    }
  }
  return romanNumerals;
}

char *convert_internal_sums(char *romanNumerals){
  char *internalSumPrefix[7] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
  char *internalSumValue[7] = {"V","X","L","C","D","M"};

  int i;
  for (i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
    if(_numeralsContainsInternalSum(romanNumerals, internalSumPrefix[i])){
      romanNumerals = replace_substring(romanNumerals, internalSumPrefix[i], internalSumValue[i]);
    }
  }
  return romanNumerals;
}

int _numeralsContainsInternalSum(char *roman_numerals,char *internalSumPrefix){
  return strstr(roman_numerals, internalSumPrefix) != NULL;
}

int _numeralsContainsAdditivePrefix(char *roman_numerals,char *additivePrefix){
  return strstr(roman_numerals, additivePrefix) != NULL;
}

int _numeralsContainsSubtractivePrefix(char *roman_numerals,char *subtractivePrefix){
  return strstr(roman_numerals, subtractivePrefix) != NULL;
}

int _findPrefixIndex(char *prefixArray[], int arraySize, char *roman_numerals){
  int prefixIndex = NO_INDEX;
  int i;
  for (i = 0; i < arraySize; i++) {
    if(strcmp(prefixArray[i],roman_numerals) == 0){
      prefixIndex = i;
    }
  }
  return prefixIndex;
}
