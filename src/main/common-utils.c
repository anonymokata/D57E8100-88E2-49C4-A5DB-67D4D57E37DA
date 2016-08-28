#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_substring(char *inputString, char *substring, char *replaceWith)
{
  char *result = malloc(1000);
  memset(result, '\0', strlen(result));

  char beforeSubstring[200];
  memset(beforeSubstring, '\0', sizeof(beforeSubstring));

  char afterSubstring[200];
  memset(afterSubstring, '\0', sizeof(afterSubstring));

  char inputCopy[200];
  memset(inputCopy, '\0', sizeof(inputCopy));
  strcpy(inputCopy, inputString);

  char *substringStart = strstr(inputCopy, substring);
  strncpy(beforeSubstring, inputString, substringStart - inputCopy);

  char *afterSubstringStart = substringStart + strlen(substring);
  strcpy(afterSubstring, afterSubstringStart);

  strcat(result, beforeSubstring);
  strcat(result, replaceWith);
  strcat(result, afterSubstring);
  return result;
}

char *concatenate(char *roman_numeral1, char *roman_numeral2)
{
  char *result[1000];
  memset(result, '\0', sizeof(result));

  strcat(result, roman_numeral1);
  strcat(result, roman_numeral2);

  return result;

}
