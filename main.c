#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#include "dataStruct.h"
#include "globals.h"
#include "macro.h"
#include "dico.c"
#include "charFunc.c"
#include "conversion.c"
#include "maillon.c"
#include "wordFunc.c"


int main(int argc, char* argv[])
{
  //Initialisation des variables globals
  separators = SEP;
  current_line = 1;
  current_col = 1;
  //test si bon nombre d'argument
  if (argc < 2){
	printf("Vous avez oublié le nom du fichier d'entrée : \n\t./%s <NOM_FICHIER>\n", argv[0]);
	exit(0);
  }

  FILE* f = NULL;
  f = fopen(argv[1], "r");
  if (f == NULL){
	fprintf(stderr,"Le fichier n'existe pas ou n'a pas pu être ouvert en mode lecture/ecriture\n");
	exit(0);
  }
  unsigned int* line = (unsigned int*) malloc(sizeof(int));
  unsigned int* colonne = (unsigned int*) malloc(sizeof(int));
  char* word = (char*) malloc(sizeof(char)*maxSizeWord);
  dico* dictionary = (dico*) malloc(sizeof(dico));
  while(!feof(f)) {
    word = next_word(f,line,colonne); 
    addToDico(dictionary,word,line,colonne); 
  }
  displayDico(dictionary);
  fclose(f);
  return 0;
}
