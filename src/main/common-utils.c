#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"

static void concatenateReplaceSubstring(const char *beforeSubstring, const char *replaceWithString, const char *afterSubstring, char result[]);
static char *makeBeforeSubstring(const char *inputStringCopy, const char *subString, char *beforeSubstring);
static char *makeAfterSubstring(const char *inputStringCopy, const char *subString, char *afterSubstring);
static int doesNotContainSubstring(const char *inputString, const char *subString);
static void doReplace(const char *inputString, const char *subString, const char *replaceWithString, char result[]);
static char sortedRomanNumerals[] = {'I','V','X','L','C','D','M'};

void replaceSubstring(const char *inputString, const char *subString, const char *replaceWithString, char result[])
{
  if(doesNotContainSubstring(inputString,subString)){
    strcat(result, inputString);
  }else{
    doReplace(inputString, subString, replaceWithString, result);
  }
}

void concatenate(const char* romanNumeral1, const char* romanNumeral2, char result[])
{
  strcat(result, romanNumeral1);
  strcat(result, romanNumeral2);
}

int getRomanNumeralSortIndex(const char romanNumeral){
  int sortIndex = -1;
  for (int index = 0; index < sizeof(sortedRomanNumerals); index++) {
    if(romanNumeral == sortedRomanNumerals[index]){
      sortIndex = index;
    }
  }
  return sortIndex;
}

int isGreaterThanOrEqual(const char romanNumeral, const char compareTo){
  int romanNumeralSortIndex = getRomanNumeralSortIndex(romanNumeral);
  int compareToSortIndex = getRomanNumeralSortIndex(compareTo);

  return romanNumeralSortIndex >= compareToSortIndex;
}

static void doReplace(const char *inputString, const char *subString, const char *replaceWithString, char result[]){
  char inputStringCopy[BUFFER_SIZE] = {};
  strcat(inputStringCopy, inputString);

  char beforeSubstring[BUFFER_SIZE] = {};
  makeBeforeSubstring(inputStringCopy, subString, beforeSubstring);

  char afterSubstring[BUFFER_SIZE] = {};
  makeAfterSubstring(inputStringCopy, subString, afterSubstring);

  concatenateReplaceSubstring(beforeSubstring, replaceWithString, afterSubstring, result);
}

static char *makeAfterSubstring(const char *inputStringCopy, const char *subString, char *afterSubstring){
  char *startOfSubstring = strstr(inputStringCopy, subString);
  char *endOfSubstring = startOfSubstring + strlen(subString);

  strcat(afterSubstring, endOfSubstring);

  return afterSubstring;
}

static char *makeBeforeSubstring(const char *inputStringCopy, const char *subString, char *beforeSubstring){
  char *startOfSubstring = strstr(inputStringCopy, subString);
  strncpy(beforeSubstring, inputStringCopy, startOfSubstring - inputStringCopy);

  return beforeSubstring;
}

static void concatenateReplaceSubstring(const char *beforeSubstring, const char *replaceWithString, const char *afterSubstring, char result[]){
  strcat(result, beforeSubstring);
  strcat(result, replaceWithString);
  strcat(result, afterSubstring);
}

static int doesNotContainSubstring(const char *inputString, const char *subString){
  return strstr(inputString, subString) == NULL? 1 : 0;
}
