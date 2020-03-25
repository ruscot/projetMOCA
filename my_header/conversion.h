#ifndef _CONVERSION_H_
#define _CONVERSION_H_
#include "dataStruct.h"
#include "dico.h"
#include "globals.h"

/**
*\file conversion.h
*\brief Fonction de conversion
*/

/**
*\fn maillon_t* stringToMaillon(char* word)
*\brief Fonction qui convertie une chaine de caractère en maillon
*\param word la chaine de caractère à convertir
*\return Renvoie le maillon contenant la chaine
*/
maillon_t* stringToMaillon(char* word);

/**
*\fn char* maillonToString(maillon_t* link)
*\brief Fonction qui convertie un maillon en chaine de caractère
*\param link le maillon à convertir 
*\return Renvoie la chaine de caractère correspondante
*/
char* maillonToString(maillon_t* link);

#endif
