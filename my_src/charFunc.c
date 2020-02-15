#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "charFunc.h"


void setCharnum(maillon_t* link, int k, char c) {
  if (link == NULL) {
    printf("setCharnum : link null\n");
  } else {
    link->elem = (link->elem & ~getMask(k)) + ((unsigned int)charToNum(c) << (5*(5-k)));
  }
}

char getCharnum(maillon_t* link, int k) {
  if (link == NULL) {
    printf("getCharnum : link null\n");
    return '#';
  } else {
    return numToChar((link->elem & getMask(k)) >> (5*(5-k)));
  }
}

int isAvailable(char c) {
  if (c < 'a' || c > 'z') {
    return 0;
  } else {
    return 1;
  }
}
