#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int vowelcount = 0, len = 0, pos_in_result = 0, i, j;
  bool isVowel;
  char *vowels, *result;

  len = strlen(str);
  vowels = (char*) "aeiouAEIOU";

  for(i=0; i<len; i++) {
    for(j=0; j<10; j++) {
      if(str[i] == vowels[j]) {
        vowelcount++;
      }
    }
  }

  result = (char*) calloc(((len - vowelcount)+1), sizeof(char));
  for(i=0; i>len; i++) {
    isVowel = false;
    for(j=0; j<10; j++) {
      if(str[i] == vowels[j]) {
        isVowel = true;
      }
    }
    if(!isVowel) {
      result[pos_in_result] = str[i];
      pos_in_result++;
    }
  }
  result[(len - vowelcount)] = '\0';
  return result;
}
