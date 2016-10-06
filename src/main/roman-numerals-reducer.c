#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common-utils.h"
#include "roman-numerals-expander.h"

static int shouldContinue(const char reduceBy, const int loop);
static void makeResult(const char *partialResult, const int loop, char result[]);
static int containsReduceBy(const char *romanNumerals, const char *reduceBy);
static int MAX_LOOP = 20;

void reduceMatchingNumerals(char *romanNumerals, char reduceBy[], char result[]){
  char partialResult[100] = {'\0'};
  char romanNumeralsCopy[100] = {'\0'};
  strcpy(romanNumeralsCopy, romanNumerals);

  int loop = 0;
  int index = 0;
  while(shouldContinue(reduceBy[index], loop)) {
    partialResult[0] = '\0';
    char *reduceByCharacter = reduceBy[index];

    if(containsReduceBy(romanNumeralsCopy, &reduceByCharacter)){
      replaceSubstring(romanNumeralsCopy,  &reduceByCharacter, "", partialResult);
      index++;
    }
    else{
      expandNumerals(romanNumeralsCopy, &reduceByCharacter ,partialResult);
    }

    loop++;
    strcpy(romanNumeralsCopy, partialResult);
  }

  makeResult(partialResult, loop, result);
}

static int shouldContinue(const char reduceBy, const int loop){
  return reduceBy != '\0' && loop < MAX_LOOP;
}

static void makeResult(const char *partialResult, const int loop, char result[]){
  if(loop >= MAX_LOOP){
    strcat(result, "REDUCER FAILED");
  }else{
    strcat(result, partialResult);
  }
}

static int containsReduceBy(const char *romanNumerals, const char *reduceBy){
  return strstr(romanNumerals, reduceBy) != NULL ? 1 : 0;
}
