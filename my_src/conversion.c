#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include "conversion.h"

int charToNum(char c) {
  return c - 'a' + 1;
}

char numToChar(int i) {   
  return (i + 'a' - 1);
}

maillon_t* stringToMaillon(char* word) {
  if (word == NULL) {
    return NULL;
  } else {
    maillon_t* useLink = (maillon_t*) malloc(sizeof(maillon_t));
    useLink->elem = 0;
    useLink->next = NULL;
    maillon_t* savLink = useLink;
    unsigned int i;
    for(i=0;i<strlen(word);i++) {
      if ((i % 6) == 0 && useLink->elem != 0) { 
	maillon_t* newLink = (maillon_t*) malloc(sizeof(maillon_t));
	newLink->elem = 0;
	newLink->next = NULL;
	useLink->next = newLink;
	useLink = newLink;
      }
      setCharnum(useLink,(i%6),word[i]);
    }
    return savLink;
  }
}

char* maillonToString(maillon_t* link) {
  if (link == NULL) {
    return NULL;
  } else {
    //+2 for the last char
    char* word = (char*) malloc(sizeof(char)*getSizeMaillon(link)+2);
    ///word = NULL;
    maillon_t* useLink = link;
    int index = 0, i = 0;
    while (useLink != NULL) {
      for(i=0;i<=5;i++) {
	      if (isAvailable(getCharnum(useLink,i)) == 0) {break;}
	      else {
	        word[index] = getCharnum(useLink,i);
	        index++;
	      }
      }
      useLink = useLink->next;
    }
    word[index+1] = '\0';
    free(useLink);
    return word;
  }
}
