#ifndef _WORDFUNC_H_
#define _WORDFUNC_H_
#include "dataStruct.h"

/**
*\file wordFunc.h
*\brief Fonction sur les mots
*/

/**
*\fn mot_t* initMot()
*\brief Initialise une structure de type initMot
*\return Renvoie la structure initialisée
*/
mot_t* initMot();

/**
*\fn mot_t* generateMot_t (char * word, unsigned int * line, unsigned int *colonne)
*\brief Fonction qui stocke un mot dans une structure de type mot_t
*\param word mot que l'on souhaite stocker
*\param line la ligne du mot que l'on souhaite ajouter
*\param colonne la colonne du mot que l'on souhaite ajouter 
*\return Renvoie la structure de donnée contenant le mot
*/
mot_t* generateMot_t (char * word, unsigned int * line, unsigned int *colonne);

/**
*\fn char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol)
*\brief Fonction qui lit le prochain mot dans le texte
*\param f le fichier contenant le texte
*\param nblin la ligne courante du texte
*\param nbcol la colonne courante du texte
*\return Renvoie le mot lu
*/
char *next_word(FILE *f, unsigned int *nblin, unsigned int *nbcol);

/**
*\fn int compareWord(mot_t* w1, mot_t* w2)
*\brief Fonction qui compare deux mot entre eux
*\param w1 le premier mot
*\param w2 le deuxième mot 
*\return Renvoi 1 si w1 NULL ou si taille de w2 < taille de w1, -1 si w2 NULL ou si taille de w1 < taille de w2 sinon 0 si taille égale
*/
int compareWord(mot_t* w1, mot_t* w2);

/**
*\fn void addTailWord(dico* dictionary, mot_t* linkWord)
*\brief Fonction qui ajoute un mot à la fin du dictionnaire
*\param dictionary le dictionnaire courant
*\param linkWord mot à ajouter
*\return Ne renvoi rien
*/
void addTailWord(dico* dictionary, mot_t* linkWord);

/**
*\fn void addHeadWord(dico* dictionary, mot_t* linkWord)
*\brief Fonction qui ajoute un mot mot au début du dictionnaire
*\param dictionary le dictionnaire courant
*\param linkWord le mot à ajouter
*\return Ne renvoi rien
*/
void addHeadWord(dico* dictionary, mot_t* linkWord);

/**
*\fn void incWord(emplacement_t* location, unsigned int line, unsigned int colonne)
*\brief Fonction qui ajoute une location d'un mot dans le texte
*\param location du mot auquel on souhaite ajouter une occurence 
*\param line la ligne du mot que l'on souhaite ajouter
*\param colonne la colonne du mot que l'on souhaite ajouter 
*\return Ne renvoi rien
*/
void incWord(emplacement_t* location, unsigned int line, unsigned int colonne);

/**
*\fn void displayWord(mot_t* word, FILE *filedes)
*\brief Fonction qui écrit un mot du texte dans un fichier
*\param word le mot que l'on souhaite écrire
*\param filedes fichier destination
*\return Ne renvoi rien
*/
void displayWord(mot_t* word, FILE *filedes);
#endif
