#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

static const int SUBTRACTIVE_PREFIX_ARRAY_SIZE = 6;
static const int ADDITIVE_PREFIX_ARRAY_SIZE = 6;
static const int INTERNAL_SUM_ARRAY_SIZE = 6;
static char *subtractivePrefix[6] = {"IV","IX","XL","XC","CD","CM"};
static char *additivePrefix[6] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
static char *internalSumPrefix[6] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
static char *internalSumValue[6] = {"V","X","L","C","D","M"};

char *convertSubtractiveToAdditivePrefix(char *romanNumerals){
  char *result = calloc(100, sizeof(char));
  char copyOfInput[100] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  char tempResult[100] = {'\0'};
  for (int i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
      memset(tempResult, 0, sizeof tempResult);
      replaceSubstring(copyOfInput, subtractivePrefix[i], additivePrefix[i], tempResult);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}

char *convertAdditiveToSubtractivePrefix(char *romanNumerals){
  char *result = calloc(100, sizeof(char));
  char copyOfInput[100] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  char tempResult[100] = {'\0'};
  for (int i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
      memset(tempResult, 0, sizeof tempResult);
      replaceSubstring(copyOfInput, additivePrefix[i], subtractivePrefix[i],tempResult);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}

char *convertInternalSums(char *romanNumerals){
  char *result = calloc(100, sizeof(char));
  char copyOfInput[100] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  char tempResult[100] = {'\0'};
  for (int i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
      memset(tempResult, 0, sizeof tempResult);
      replaceSubstring(copyOfInput, internalSumPrefix[i], internalSumValue[i],tempResult);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}
