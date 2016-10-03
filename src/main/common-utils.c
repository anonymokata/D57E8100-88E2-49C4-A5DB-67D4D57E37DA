#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static void concatenateReplaceSubstring(char *beforeSubstring, char *replaceWithString, char *afterSubstring, char result[]);
static char *makeBeforeSubstring(const char *inputStringCopy, char *subString, char *beforeSubstring);
static char *makeAfterSubstring(const char *inputStringCopy, char *subString, char *afterSubstring);
static int doesNotContainSubstring(const char *inputString, const char *subString);
static void doReplace(char *inputString, char *subString, char *replaceWithString, char result[]);

void replaceSubstring(char *inputString, char *subString, char *replaceWithString, char result[])
{
  if(doesNotContainSubstring(inputString,subString)){
    strcat(result, inputString);
  }else{
    doReplace(inputString, subString, replaceWithString, result);
  }
}

void concatenate(char* romanNumeral1, char* romanNumeral2, char result[])
{
  strcat(result, romanNumeral1);
  strcat(result, romanNumeral2);
}

static void doReplace(char *inputString, char *subString, char *replaceWithString, char result[]){
  char inputStringCopy[100] = {'\0'};
  strcpy(inputStringCopy, inputString);

  char beforeSubstring[100] = {'\0'};
  makeBeforeSubstring(inputStringCopy, subString, beforeSubstring);

  char afterSubstring[100] = {'\0'};
  makeAfterSubstring(inputStringCopy, subString, afterSubstring);

  concatenateReplaceSubstring(beforeSubstring, replaceWithString, afterSubstring, result);
}

static char *makeAfterSubstring(const char *inputStringCopy, char *subString, char *afterSubstring){
  char *startOfSubstring = strstr(inputStringCopy, subString);
  char *endOfSubstring = startOfSubstring + strlen(subString);

  strcpy(afterSubstring, endOfSubstring);

  return afterSubstring;
}

static char *makeBeforeSubstring(const char *inputStringCopy, char *subString, char *beforeSubstring){
  char *startOfSubstring = strstr(inputStringCopy, subString);
  strncpy(beforeSubstring, inputStringCopy, startOfSubstring - inputStringCopy);

  return beforeSubstring;
}

static void concatenateReplaceSubstring(char *beforeSubstring, char *replaceWithString, char *afterSubstring, char result[]){
  strcat(result, beforeSubstring);
  strcat(result, replaceWithString);
  strcat(result, afterSubstring);
}

static int doesNotContainSubstring(const char *inputString, const char *subString){
  return strstr(inputString, subString) == NULL? 1 : 0;
}
