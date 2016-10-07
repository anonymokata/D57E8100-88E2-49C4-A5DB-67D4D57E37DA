#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static int getValueOfRomanNumeral(const char romanNumeral);
static int compareRomanNumerals(const void * a, const void * b);

const char *sortRomanNumerals(const char *romanNumerals, char result[])
{
  char romanNumeralsArray[strlen(romanNumerals)];
  strncpy(romanNumeralsArray, romanNumerals, strlen(romanNumerals) + 1);

  qsort(romanNumeralsArray, strlen(romanNumerals), sizeof(char), compareRomanNumerals);

  strcpy(result,romanNumeralsArray);
  return result;
}

int compareRomanNumerals(const void * a, const void * b){
  int valueOfA = getValueOfRomanNumeral(*(char*)a);
  int valueOfB = getValueOfRomanNumeral(*(char*)b);
  return ( valueOfB - valueOfA);
}

int getValueOfRomanNumeral(const char romanNumeral){
  char romanNumeralsIndex[] = {'I','V','X','L','C','D','M'};
  int romanNumeralsValue[] = {1,5,10,50,100,500,1000};

  int valueIndex;
  int i;
  for (i = 0; i < sizeof(romanNumeralsIndex); i++) {
    if(romanNumeral == romanNumeralsIndex[i]){
      valueIndex = i;
    }
  }

  return romanNumeralsValue[valueIndex];
}
