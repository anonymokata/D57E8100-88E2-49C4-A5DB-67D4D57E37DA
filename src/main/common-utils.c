#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void concatenateReplaceSubstring(const char *beforeSubstring, const char *replaceWithString, const char *afterSubstring, char result[]);
static char *makeBeforeSubstring(const char *inputStringCopy, const char *subString, char *beforeSubstring);
static char *makeAfterSubstring(const char *inputStringCopy, const char *subString, char *afterSubstring);
static int doesNotContainSubstring(const char *inputString, const char *subString);
static void doReplace(const char *inputString, const char *subString, const char *replaceWithString, char result[]);
static int findRomanNumeralKey(const char numeral);
static const int NUMERALS_ARRAY_SIZE = 7;
static char romanNumeralKeys[] = {'I','V','X','L','C','D','M'};
static int romanNumeralValues[] = {1,5,10,50,100,500,1000};

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

int isGreaterThanOrEqual(const int romanNumeral, const int compareTo){
  int romanNumeralKey = findRomanNumeralKey(romanNumeral);
  int compareToKey = findRomanNumeralKey(compareTo);

  int romanNumeralValue = romanNumeralValues[romanNumeralKey];
  int compareToValue = romanNumeralValues[compareToKey];

  return romanNumeralValue >= compareToValue;
}

static int findRomanNumeralKey(const char numeral){
  int key = 0;
  for (int i = 0; i < NUMERALS_ARRAY_SIZE; i++) {
    if(romanNumeralKeys[i] == numeral){
      key = i;
    }
  }
  return key;
}

static void doReplace(const char *inputString, const char *subString, const char *replaceWithString, char result[]){
  char inputStringCopy[100] = {};
  strcat(inputStringCopy, inputString);

  char beforeSubstring[100] = {};
  makeBeforeSubstring(inputStringCopy, subString, beforeSubstring);

  char afterSubstring[100] = {};
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
