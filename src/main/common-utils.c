#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *concatenateResult(char *beforeSubstring, char *replaceWithString, char *afterSubstring);
static char *makeBeforeSubstring(const char *copyOfInput, char *substring, char *beforeSubstring);
static char *makeAfterSubstring(const char *copyOfInput, char *substring, char *afterSubstring);

char *replace_substring(char *inputString, char *substring, char *replaceWithString)
{
  char copyOfInput[200] = {'\0'};
  strcpy(copyOfInput, inputString);

  char beforeSubstring[200] = {'\0'};
  makeBeforeSubstring(copyOfInput, substring,beforeSubstring);

  char afterSubstring[200] = {'\0'};
  makeAfterSubstring(copyOfInput, substring, afterSubstring);

  return concatenateResult(beforeSubstring, replaceWithString, afterSubstring);
}

char *concatenate(char *roman_numeral1, char *roman_numeral2)
{
  char *result = calloc(1000, sizeof(char));

  strcat(result, roman_numeral1);
  strcat(result, roman_numeral2);

  return result;
}

static char *makeAfterSubstring(const char *copyOfInput, char *substring, char *afterSubstring){
  char *startOfSubstring = strstr(copyOfInput, substring);
  char *endOfSubstring = startOfSubstring + strlen(substring);

  strcpy(afterSubstring, endOfSubstring);

  return afterSubstring;
}

static char *makeBeforeSubstring(const char *copyOfInput, char *substring, char *beforeSubstring){
  char *startOfSubstring = strstr(copyOfInput, substring);
  strncpy(beforeSubstring, copyOfInput, startOfSubstring - copyOfInput);

  return beforeSubstring;
}

static char *concatenateResult(char *beforeSubstring, char *replaceWithString, char *afterSubstring){
  char *result = calloc(1000, sizeof(char));
  strcat(result, beforeSubstring);
  strcat(result, replaceWithString);
  strcat(result, afterSubstring);
  return result;
}
