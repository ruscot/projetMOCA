#ifndef _CHARFUNC_H_
#define _CHARFUNC_H_
#include "dataStruct.h"
#include "dico.h"
#include "globals.h"

/**
*\file charFunc.h
*\brief Fonction sur les caractères 
*/


/**
*\fn emplacement_t* initEmplacement()
*\brief Fonction qui initialise une structure de type emplacement_t 
*\return Renvoie la structure initialisée 
*/
emplacement_t* initEmplacement();

/**
*\fn void setCharnum(maillon_t* link, int k, char c)
*\brief Fonction qui initialise link->elem en fonction de k et c
*\param link maillon dont l'élément doit être initialisé
*\param k valeur du masque à appliquer 
*\param c caractère à stocker
*\return Ne renvoi rien
*/
void inline setCharnum(maillon_t* link, int k, char c);

/**
*\fn char getCharnum(maillon_t* link, int k)
*\brief Fonction qui renvoie la valeur du caractère stocké dans link->elem
*\param  link maillon_t contenant le caractère à renvoyer 
*\param k masque permettant de récupérer le caractère 
*\return Renvoie le caractère stocké dans la structure
*/
char inline getCharnum(maillon_t* link, int k);


#endif
