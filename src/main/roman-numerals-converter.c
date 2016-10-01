#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

static const int SUBTRACTIVE_PREFIX_ARRAY_SIZE = 6;
static const int ADDITIVE_PREFIX_ARRAY_SIZE = 6;
static const int INTERNAL_SUM_ARRAY_SIZE = 6;
static char *subtractivePrefixes[6] = {"IV","IX","XL","XC","CD","CM"};
static char *additivePrefixes[6] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
static char *internalSumPrefix[6] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *internalSumValue[6] = {"V","X","L","C","D","M"};

char *convertSubtractiveToAdditivePrefix(char *romanNumerals, char result[]){
  char partialResult[100] = {'\0'};
  char romanNumeralsCopy[100] = {'\0'};
  strcpy(romanNumeralsCopy, romanNumerals);

  for (int i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, subtractivePrefixes[i], additivePrefixes[i], partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}

char *convertAdditiveToSubtractivePrefix(char *romanNumerals, char result[]){
  char partialResult[100] = {'\0'};
  char romanNumeralsCopy[100] = {'\0'};
  strcpy(romanNumeralsCopy, romanNumerals);


  for (int i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, additivePrefixes[i], subtractivePrefixes[i],partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}

char *convertInternalSums(char *romanNumerals, char result[]){
  char partialResult[100] = {'\0'};
  char romanNumeralsCopy[100] = {'\0'};
  strcpy(romanNumeralsCopy, romanNumerals);

  for (int i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
      partialResult[0] = '\0';
      replaceSubstring(romanNumeralsCopy, internalSumPrefix[i], internalSumValue[i],partialResult);
      strcpy(romanNumeralsCopy, partialResult);
  }

  strcat(result, partialResult);
  return result;
}
