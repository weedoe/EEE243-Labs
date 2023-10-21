/*
 * Declarations for the EEE243 lab 4 string manipulation functions.
 * All functions assume that strings passed as parameters are null-terminated.
 *
 * Déclarations pour le labo 4 de GEF243 sur les fonctions de maniputation
 * de chaînes de caractères. Toutes les fonctions assument que les chaînes
 * se terminent par le caractère nul.
 *
 * author : Dr Greg Phillips, Dr Sylvain Leblanc, Dr Vincent Roberge
 * version: 17 Novembre 2020
 */

#ifndef STRINGLIB_H_
#define STRINGLIB_H_

#include <stdbool.h>

/*
 * Returns the number of characters in 'a' before the null character.
 * Retourne le nombre de caractères dans 'a' avant le caractère nul.
 */
int count_chars(char a[]);

/*
 * Removes any space characters from the right end of 'a'.
 * Enlève les caractères espaces du côté droit de 'a'.
 */
void trim_right(char a[]);

/*
 * Removes any space characters from the left end of 'a'.
 * Enlève les caractères espaces du côté gauche de 'a'.
 */
void trim_left(char a[]);


/*
 * Adds extra spaces at the right end of 'a' to make it 'n' characters long.
 * If 'a' is already 'n' characters or longer, does nothing. Assumes 'a'
 * has at least 'n'+1 characters allocated.
 *
 * Ajoute des espaces supplémentaires à l'extrémité droite de 'a' pour lui
 * donner 'n' caractères. Si 'a' a déjà 'n' caractères ou plus, la fonction
 * ne fait rien. Cette fonction suppose que 'a' a au moins 'n'+1 caractères
 * alloués.
 */
void pad_right(char a[], int n);

/*
 * Adds extra spaces at the left end of 'a' to make it 'n' characters long.
 * If 'a' is already 'n' characters or longer, does nothing.
 *
 * Ajoute des espaces supplémentaires à l'extrémité gauche de 'a' pour lui
 * donner 'n' caractères. Si 'a' a déjà 'n' caractères ou plus, la fonction
 * ne fait rien.
 */
void pad_left(char a[], int n);

/*
 * Centers 'a' by adding spaces to the left and right to bring it to the
 * length 'n'. If 'a' is already of the specified length or longer, does not
 * change 'a'. If an odd number of spaces have to be added, puts the extra
 * blank on the right.
 *
 * Centre 'a' en lui ajoutant des espaces à gauche et à droite pour l'amener
 * à une longueur 'n'. Si 'a' a déjà la longueur spécifiée ou plus, la fonction
 * ne fait rien. Si un nombre impair d'espaces est ajoutés, ajoutez l'espace
 * additionnel sur le côté droit.
 */
void center(char a[], int n);

/*
 * Returns true if 'a' is a palindrome, false otherwise. This function
 * is case insensitive. As an example RADar is a palindrome
 *
 * Retourne vrai si 'a' est un palindrone, faux sinon. Cette fonction
 * ne fait pas la différence entre les majuscules et les minuscules.
 * Par example, RADar est un palindrome.
 */
bool is_palindrome(char a[]);

/*
 * Shortens 'a' to length 'n'. If 'a' is already shorter than 'n', does
 * nothing.
 *
 * Racourcit 'a' à une longueur 'n'. Si 'a' est déjà plus court que 'n',
 * ne fait rien.
 */
void truncate(char a[], int n);

/*
 * Makes the first letter of 'a' upper-case if it is not already. The first
 * letter is not necessarily the first character of 'a'.
 *
 * Met en majuscule la première lettre de 'a'. La première lettre n'est pas
 * nécessairement le premier caractère de 'a'.
 */
void capitalize(char a[]);

/*
 * Capitalizes the first letter of every word in 'a'. The first letter of a
 * word is any letter at the beginning of 'a' or preceded by a space.
 *
 * Met en majuscule la première lettre de chaque mot de 'a'. La première
 * lettre d'un mot est une lettre au début de 'a' ou une lettre précédée
 * d'un espace.
 */
void capitalize_words(char a[]);

/*
 * Returns true if all characters in 'a' are alphabetic (letters), false
 * otherwise. Spaces are not alphabetic.
 *
 * Retroune vrai si tous les caractères de 'a' sont alphabétiques (lettres),
 * faux sinon. Les espaces ne sont pas des caractères alphabétiques.
 */
bool is_alpha(char a[]);

/*
 * Reverses the order of the characters in 'a'.
 *
 * Inverse l'ordre des caractères des 'a'.
 */
void reverse(char a[]);


/*
 * Returns the number of times the character 'c' appears in 'a'.
 * The function is case sensitive.
 *
 * Retourne le nombre de fois que le caractère 'c' apparait dans 'a'.
 * La fonction est sensible aux majuscules et minuscules.
 */
int count_occurrences(char a[], char c);

/*
 * Removes every occurrence of 'c' from 'a', resulting in a logically shorter string.
 * The function is case sensitive.
 *
 * Supprime chaque occurrence de 'c' de 'a', ce qui entraîne une chaîne logiquement
 * plus courte. La fonction est sensible aux majuscules et minuscules.
 */
void delete_char(char a[], char c);

#endif /* STRINGLIB_H_ */
