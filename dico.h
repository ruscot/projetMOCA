#ifndef _DICO_H_
#define _DICO_H_
#include "dataStruct.h"

void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne);

void displayDico(dico* dictionary);

void insertDico(dico* dictionary, mot_t* linkWord);

unsigned int getMask(int k);

#endif
