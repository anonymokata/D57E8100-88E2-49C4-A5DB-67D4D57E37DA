#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int _getValueOfRomanNumeral(char romanNumeral);
int _compareRomanNumerals(const void * a, const void * b);

const char *sortRomanNumerals(const char *romanNumerals)
{
  char romanNumeralsArray[strlen(romanNumerals)];
  strncpy(romanNumeralsArray, romanNumerals, strlen(romanNumerals) + 1);

  qsort(romanNumeralsArray, strlen(romanNumerals), sizeof(char), _compareRomanNumerals);

  char *result = malloc(sizeof(char)*(sizeof(romanNumeralsArray)+1));
  strcpy(result,romanNumeralsArray);
  return result;
}

int _compareRomanNumerals(const void * a, const void * b){
  int valueOfA = _getValueOfRomanNumeral(*(char*)a);
  int valueOfB = _getValueOfRomanNumeral(*(char*)b);
  return ( valueOfB - valueOfA);
}

int _getValueOfRomanNumeral(char romanNumeral){
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
