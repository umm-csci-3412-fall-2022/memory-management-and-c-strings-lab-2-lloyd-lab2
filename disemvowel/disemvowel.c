#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdio.h>

#include "disemvowel.h"

char *disemvowel(char *str) {
  int vowelcount, len, i, j;
  bool isVowel;
  char *vowels, *result;

  len = strlen(str);
  vowels = (char*) "aeiouAEIOU";

  for(i=0; i<len; i++) {
    for(j=0; j<5; j++) {
      if(str[i] == vowels[j]) {
        vowelcount++;
      }
    }
  }

  result = (char*) calloc((len - vowelcount)+1, sizeof(char));
  for(i=len-1; i>=0; i--) {
    isVowel = false;
    for(j=0; j<5; j++) {
      if(str[i] == vowels[j]) {
        isVowel = true;
      }
    }
    if(!isVowel) {
        result[i-vowelcount] = str[i];
    } else {
        vowelcount--;
    }
  }
  result[strlen(result)-1] = '\0';
  return result;
}
