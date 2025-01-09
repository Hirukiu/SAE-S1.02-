#pragma once
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include <stdio.h>
#include <time.h>
typedef struct {
	char* c;
	size_t taille;
}pioche;
/**
* @brief permet d'initialiser une pioche avec 1 charactére
* @param[out] p la pioche a initialiser
* @pre le charactère doit etre une lettre
*/
void init(pioche* p);
/**
* @brief retire une lettre d'une pioche et donne la lettre retirée
* @param[out] p la pioche a qui elever le charactère
* @param[in] pos la position du charactere a retirer
* @return la lettre suppimée
* @pre la position doit etre supérieure �  0 et inférieur � la taille max du tableau
* @pre il doit y avoir au moins un charactére
*/
char enlever(pioche* p, int pos);
/**
* @brief ajoute une lettre d'une pioche
* @param[out] p la pioche auquel ajouter le charactére
* @param[in]  c le charactére a ajouter
* @pre le charactère doit etre une lettre et la pioche doit etre initialisée
*/
void ajouter(pioche* p, char c);
/**
 * @brief retire un charactére dans une pioche et la remet dans une autre
 * @param E la pioche auquel enlever le charactére
 * @param pos la position du charactére �  enlever
 * @param p la pioche auquel ajouter le charactére
 * @pre les 2 pioche , E et p doivent étre initialiser *
 * @pre la position doit étre une position valable dans la pioche
 * @pre la pioche �  enlever le charactére doit avoir au moins un charatére
 */
void echanger(pioche* E, int pos, pioche* p);
/**
 * @brief echange un mot complet dans les pioches
 * @param p1 la pioche auquel on enleve le mot
 * @param mot a bouger
 * @param p2 la pioche auquel on ajoute le mot
 * @pre le mot existe dans p1
*/
void echangemot(pioche* p1, char* mot, pioche* p2);
/**
 * @brief verifie qu'une lettre est present dans une pioche
 * @param p la pioche
 * @param lettre la lettre
 * @return 1 si oui 0 si non
*/
int lettrepresent(pioche* p, char* lettre);
/**
* @brief  donne le charactére dans la pioche �  une position précise
* @param[in] p la pioche dans laquel on veut le charactére
* @param[in] pos la position du chararcére dans la pioche
* @return le charatère dans la pioche p �  la position pos
* @pre la position doit étre valable +
*/
char dmdchar(const pioche* p, int pos);
/**
* @brief  donne la position dans la pioche �  pour une lettre
* @param[in] p la pioche dans laquel on veut la position
* @param[in] lettre le charactere chercher
* @return la position du charactere
*/
int dmdpos(const pioche* p, char lettre);
/**
* @brief donne le nombre de charactére dans la pioche
* @param[in] p pioche
* @return le nombre de characére dans la pioche
*/
int taille(const pioche* p);
/**
 * @brief affiche la pioche
 * @param[in] p la pioche � afficher
 * @param[in] p la pioche �  afficher
 */
void afficher(const pioche* p);
/**
 * @brief trie la pioche
 * @param[out] p la pioche � trier
 * @param[out] p la pioche �  trier
 */
void trier(pioche* p);
/**
* @brief  lib�re une pioche
* @param p  la pioche �  liberer
*/
void LibPioche(pioche* p);
/**
* @brief  melange une pioche
* @param p la pioche � melanger
*/
void melanger(pioche* p);
/**
* @brief donne la chaine de charact�re contenu dans une pioche
* @param p  la pioche dont on veut la chaine de charact�re
* @return  la chaine de charact�re
*/
char* chaine(pioche* p);