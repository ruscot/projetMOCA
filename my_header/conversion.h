#ifndef _CONVERSION_H_
#define _CONVERSION_H_
#include "dataStruct.h"
#include "dico.h"
#include "globals.h"
#include "macro.h"
#include "charFunc.h"
#include "maillon.h"
#include "wordFunc.h"

int charToNum(char c);

char numToChar(int i);

maillon_t* stringToMaillon(char* word);

char* maillonToString(maillon_t* link);

#endif
