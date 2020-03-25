#ifndef _DICO_H_
#define _DICO_H_

#include "dataStruct.h"
#include "globals.h"
#include "macro.h"
#include "charFunc.h"
#include "conversion.h"
#include "maillon.h"
#include "wordFunc.h"

/**
*\file dico.h
*\brief Fonction sur les caractères 
*/

/**
*\fn dico* initDico()
*\brief Fonction qui initialise une structure de type dico
*\return Renvoie la structure initialisée 
*/
dico* initDico();

/**
*\fn void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne)
*\brief Fonction qui ajout au dictionnaire un mot avec sa ligne et sa colonne dans le texte
*\param dictionary le dictionnaire courant
*\param word le mot que l'on souhaite ajouter
*\param line la ligne du mot que l'on souhaite ajouter
*\param colonne la colonne du mot que l'on souhaite ajouter 
*\return Ne renvoi rien
*/
void addToDico(dico* dictionary, char* word, unsigned int* line, unsigned int* colonne);

/**
*\fn void displayDico(dico* dictionary)
*\brief Fonction qui affiche le dictionnaire
*\param dictionary le dictionnaire à afficher
*\return Ne renvoi rien
*/
void displayDico(dico* dictionary);

/**
*\fn void insertDico(dico* dictionary, mot_t* linkWord)
*\brief Fonction qui insére un mot dans le dictionnaire 
*\param dictionary le dictionnaire contenant les mots
*\param linkWord le mot à ajouter
*\return Ne renvoi rien
*/
void insertDico(dico* dictionary, mot_t* linkWord);

/**
*\fn unsigned int getMask(int k)
*\brief Fonction qui renvoie le masque correspondant à l'entier k
*\param k entier pour avoir le masque
*\return Le masque de type unsigned int
*/
unsigned int inline getMask(int k);

#endif
