#ifndef _DATASTRUCT_H_
#define _DATASTRUCT_H_

#include <stdint.h>
#include "globals.h"
/**
*\file dataStruct.h
*\brief Définition de toutes les différentes structures
*/

/**
*\struct maillon_t
*\brief Structure maillon_t qui sert à stocker les lettres. Contient un attribut elem pour stocker le caractère et un attribut next pour le maillon suivant.
*/
typedef struct maillon_t maillon_t;
struct maillon_t {
  uint32_t elem;
  maillon_t* next;
};

/**
*\struct emplacement_t
*\brief Structure emplacement_t qui sert à stocker l'emplacement du mot dans le texte. Contient un attribut line pour la ligne du texte, un attribut colonne pour la colonne du texte et un attribut next pour l'emplacement suivant.
*/
typedef struct emplacement_t emplacement_t;
struct emplacement_t {
  unsigned int line;
  unsigned int colonne;
  emplacement_t* next;
};

/**
*\struct mot_t
*\brief Structure mot_t qui sert à stocker les mots. Contient un attribut tete_mot pour stocker le début du mot, l'attribut queue_mot pour la fin du mot, et tete_liste et queue_liste pour stocker l'emplacement du mot.
*/
typedef struct mot_t mot_t;
struct mot_t {
  maillon_t* tete_mot;
  maillon_t* queue_mot;
  emplacement_t* tete_liste;
  emplacement_t* queue_liste;
};

/**
*\struct dico
*\brief Structure dico qui sert à stocker un mot. Contient un attribut mot pour stocker le mot et un attribut next pour le mot suivant.
*/
typedef struct dico dico;
struct dico {
  mot_t* mot;
  dico* next;
};


#endif
