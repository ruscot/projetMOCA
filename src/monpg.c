#include <stdio.h>
#include "convertir.h"
#include "outils.h"


int main (int argc, char **argv) {
  double val;
  short action;
  short type;
  action = CONTINUER; // initialisation  
  do {
    LireDouble("entrez un nombre : ",  &val);
    if (val == 0)
      action = SORTIR;
    else {
      LireShort("convertir en euros (0) / dollars (1) ? ",
		&type);
      switch (type) {
      case EURO  : dollar_euro(val); break;
      case DOLLAR : euro_dollar(val); break;
      default : Message("Euros (0) /Dollars (1) ?",
			CONTINUER);
      }
    }
  }
  while (action == CONTINUER);
  return 0;
} 

