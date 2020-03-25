#ifndef _MAILLON_H_
#define _MAILLON_H_
#include "dataStruct.h"

/**
*\file maillon.h
*\brief Fonction utiles pour les maillons
*/

/**
*\fn maillon_t* initMaillon()
*\brief Fonction qui initialise une structure de type maillon.
*\return Renvoie un maillon initialisé
*/
maillon_t* initMaillon();

/**
*\fn int getSizeMaillon(maillon_t* link)
*\brief Fonction qui nous donne la taille d'un maillon
*\param link maillon dont on veut savoir la taille 
*\return Renvoi un entier correspondant à la taille du maillon
*/
int getSizeMaillon(maillon_t* link);

#endif
