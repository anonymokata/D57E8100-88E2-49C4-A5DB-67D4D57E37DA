#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _findPrefixIndex(char *subtractivePrefix[], char *roman_numerals);
#define BOGUS_INDEX 6
#define SUBTRACTIVE_PREFIX_SIZE 6

char *convert_subtractive_to_additive_prefix(char *roman_numerals){
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[8] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC", "BOGUS"};

  int prefixIndex = _findPrefixIndex(subtractivePrefix, roman_numerals);

  // char *additivePrefixResult = additivePrefix[prefixIndex];
  // char *result = malloc(sizeof(char)*(sizeof(additivePrefixResult)+1));
  // strcpy(result,additivePrefixResult);
  return additivePrefix[prefixIndex];
}

int _findPrefixIndex(char *subtractivePrefix[], char *roman_numerals){
  int prefixIndex = BOGUS_INDEX;
  int i;
  for (i = 0; i < SUBTRACTIVE_PREFIX_SIZE; i++) {
    if(strcmp(subtractivePrefix[i],roman_numerals) == 0){
      prefixIndex = i;
    }
  }
  return prefixIndex;
}
