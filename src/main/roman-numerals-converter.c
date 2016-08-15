#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _findPrefixIndex(char *prefixArray[], int arraySize, char *roman_numerals);
char *convert_internal_sum(char *roman_numerals);

#define NO_INDEX -1
#define SUBTRACTIVE_PREFIX_ARRAY_SIZE 6
#define INTERNAL_SUM_ARRAY_SIZE 6
char *internalSumPrefix[7] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
char *internalSumValue[8] = {"V","X","L","C","D","M"};
char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
char *additivePrefix[8] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};

char *convert_subtractive_to_additive_prefix(char *roman_numerals){
  int prefixIndex = _findPrefixIndex(subtractivePrefix, SUBTRACTIVE_PREFIX_ARRAY_SIZE, roman_numerals);

  return (prefixIndex == NO_INDEX) ? roman_numerals : additivePrefix[prefixIndex];
}

char *convert_internal_sums(char *roman_numerals){
  int i;
  for (i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
    if(strstr(roman_numerals, internalSumPrefix[i]) != NULL){
      roman_numerals = replace_substring(roman_numerals, internalSumPrefix[i], internalSumValue[i]);
    }
  }

  return roman_numerals;
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
