#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

#define NO_INDEX -1
#define SUBTRACTIVE_PREFIX_ARRAY_SIZE 6
#define ADDITIVE_PREFIX_ARRAY_SIZE 6
#define INTERNAL_SUM_ARRAY_SIZE 6

char *convertSubtractiveToAdditivePrefix(char *romanNumerals){
  char *result = calloc(1000, sizeof(char));
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
  char copyOfInput[1000] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  int i;
  char tempResult[1000] = {'\0'};
  for (i = 0; i < SUBTRACTIVE_PREFIX_ARRAY_SIZE; i++) {
      memset(tempResult, 0, sizeof tempResult);

      replaceSubstring(copyOfInput, subtractivePrefix[i], additivePrefix[i], tempResult);

      memset(copyOfInput, 0, sizeof copyOfInput);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}

char *convertAdditiveToSubtractivePrefix(char *romanNumerals){
  char *result = calloc(1000, sizeof(char));
  char *additivePrefix[7] = {"IIII","VIIII","XXXX","LXXXX","CCCC","DCCCC"};
  char *subtractivePrefix[7] = {"IV","IX","XL","XC","CD","CM"};
  char copyOfInput[100] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  int i;
  char tempResult[1000] = {'\0'};
  for (i = ADDITIVE_PREFIX_ARRAY_SIZE - 1; i >= 0; i--) {
      memset(tempResult, 0, sizeof tempResult);
      replaceSubstring(copyOfInput, additivePrefix[i], subtractivePrefix[i],tempResult);
      memset(copyOfInput, 0, sizeof copyOfInput);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}

char *convertInternalSums(char *romanNumerals){
  char *result = calloc(1000, sizeof(char));
  char *internalSumPrefix[7] = {"IIIII","VV","XXXXX","LL","CCCCC","DD"};
  char *internalSumValue[7] = {"V","X","L","C","D","M"};
  char copyOfInput[100] = {'\0'};
  strcpy(copyOfInput, romanNumerals);

  int i;
  char tempResult[1000] = {'\0'};
  for (i = 0; i < INTERNAL_SUM_ARRAY_SIZE; i++) {
      memset(tempResult, 0, sizeof tempResult);
      replaceSubstring(copyOfInput, internalSumPrefix[i], internalSumValue[i],tempResult);
      memset(copyOfInput, 0, sizeof copyOfInput);
      strcpy(copyOfInput, tempResult);
  }

  strcat(result, tempResult);
  return result;
}
