#ifndef _CHARFUNC_H_
#define _CHARFUNC_H_
#include "dataStruct.h"
#include "dico.h"
#include "globals.h"
#include "macro.h"
#include "conversion.h"
#include "maillon.h"
#include "wordFunc.h"

void setCharnum(maillon_t* link, int k, char c);

char getCharnum(maillon_t* link, int k);

int isAvailable(char c);

#endif
