#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"
#include "roman-numerals-expander.h"
#include "constants.h"

static int shouldContinue(const char reduceBy, const int loop);
static void makeResult(const char *partialResult, const int loop, char result[]);
static void removeCommonNumerals(const char *romanNumeralsCopy, const char *commonNumeral, char partialResult[]);
static int containsReduceBy(const char *romanNumerals, const char *reduceBy);
static int MAX_LOOP = 30;

void reduceMatchingNumerals(const char *romanNumerals, const char reduceBy[], char result[]){
  char partialResult[BUFFER_SIZE] = {};
  char romanNumeralsCopy[BUFFER_SIZE] = {};
  strcpy(romanNumeralsCopy, romanNumerals);

  int loop = 0;
  int index = 0;
  while(shouldContinue(reduceBy[index], loop)) {
    char reduceByCharacter = reduceBy[index];
    char reduceByCharacterString[2] = {};
    reduceByCharacterString[0] = reduceByCharacter;
    partialResult[0] = '\0';

    if(containsReduceBy(romanNumeralsCopy, reduceByCharacterString)){
      removeCommonNumerals(romanNumeralsCopy,  reduceByCharacterString, partialResult);
      index++;
    }
    else{
      expandNumerals(romanNumeralsCopy, reduceByCharacter , partialResult);
    }

    loop++;
    strcpy(romanNumeralsCopy, partialResult);
  }

  makeResult(partialResult, loop, result);
}

void removeCommonNumerals(const char *romanNumeralsCopy, const char *commonNumeral, char partialResult[]){
  replaceSubstring(romanNumeralsCopy,  commonNumeral, "", partialResult);
}

static int shouldContinue(const char reduceBy, const int loop){
  return reduceBy != '\0' && loop < MAX_LOOP;
}

static void makeResult(const const char *partialResult, const const int loop, char result[]){
  if(loop >= MAX_LOOP){
    strcat(result, "REDUCER FAILED");
  }else{
    strcat(result, partialResult);
  }
}

static int containsReduceBy(const char *romanNumerals, const char *reduceBy){
  return strstr(romanNumerals, reduceBy) != NULL ? 1 : 0;
}
