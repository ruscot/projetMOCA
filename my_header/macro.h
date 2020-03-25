#ifndef _MACRO_H_
#define _MACRO_H_

/**
*\file macro.h
*\brief Contient les différentes macro utiles au programme.
*/

/**
*\brief Macro SizeLetter qui donne la taille d'une lettre
*/
#define SizeLetter 5

/**
*\brief Macro maxSizeWord qui nous donne la taille maximum d'un mot.
*/
#define maxSizeWord 25

/**
*\brief Macro SEP qui contient les différents séparateurs possbile dans un texte.
*/
#define SEP " ;:/,.-'?!"   

/**
*\brief Macro TEXTE pour le TEXTE qu'on utilise en entrée.
*/
#define TEXTE "hugo.txt"

/**
*\brief Macro DICORES qui contient le fichiers ou l'on stocke le dictionnaire créé.
*/
#define DICORES "donnees/res1.txt"

/**
*\brief Macro CHARTONUM(char c) fonction qui renvoie c - 'a' + 1
*/
#define CHARTONUM(c) (((c) - 'a') + 1)

/**
*\brief Macro NUMTOCHAR(int i) fonction qui renvoie i + 'a' - 1
*/
#define NUMTOCHAR(i) (((i) + 'a') - 1)

/**
*\brief Macro ISAVAILABLE(char c) fonction qui renvoie 0 si c n'est pas compris entre a et z, sinon 1
*/
#define INFA(c) c < 'a'
#define SUPZ(c) c > 'z'
#define ISAVAILABLE(c) (INFA(c) || SUPZ(c) ? 0 : 1)

#endif