#include <stdio.h>
#include <stdlib.h>
#include "outils.h"

void LireDouble(char *phrase, double *nombre) {
  Message(phrase, CONTINUER);
  if (scanf("%lf", nombre) == 0)
    Message("Vous n'avez pas entre un float", SORTIR);
}

void LireShort(char *phrase, short *nombre) {
  Message(phrase, CONTINUER);
  if (scanf("%hd", nombre) == 0)
    Message("Vous n'avez pas entre un entier", SORTIR);
} 
