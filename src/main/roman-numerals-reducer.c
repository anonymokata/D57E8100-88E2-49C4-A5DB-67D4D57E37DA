#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"

void reduceMatchingNumerals(char *romanNumerals, char reduceBy[], char result[]){
  char partialResult[100] = {'\0'};
  char romanNumeralsCopy[100] = {'\0'};
  char *reduceByCharacter;
  strcpy(romanNumeralsCopy, romanNumerals);

  for(int i = 0; reduceBy[i] != '\0'; i++) {
    partialResult[0] = '\0';
    reduceByCharacter = reduceBy[i];

    replaceSubstring(romanNumeralsCopy, &reduceByCharacter, "", partialResult);

    strcpy(romanNumeralsCopy, partialResult);
  }
  strcat(result, partialResult);
}
