#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *replace_substring(char *inputString, char *substring, char *replaceWith)
{
  char result[1024];
  char *substringAndRest;
  substringAndRest = strstr(inputString, substring);

  strncpy(result, inputString, substringAndRest - inputString);
  result[substringAndRest - inputString] = '\0';
  sprintf(result+(substringAndRest - inputString), "%s%s", replaceWith, substringAndRest+strlen(substring));

  return result;
}
