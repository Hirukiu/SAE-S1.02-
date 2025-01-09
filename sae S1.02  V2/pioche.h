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
* @brief permet d'initialiser une pioche avec 1 charact√©re
* @param[out] p la pioche a initialiser
* @pre le charact√®re doit etre une lettre
*/
void init(pioche* p);
/**
* @brief retire une lettre d'une pioche et donne la lettre retir√©e
* @param[out] p la pioche a qui elever le charact√®re
* @param[in] pos la position du charactere a retirer
* @return la lettre suppim√©e
* @pre la position doit etre sup√©rieure √  0 et inf√©rieur √ la taille max du tableau
* @pre il doit y avoir au moins un charact√©re
*/
char enlever(pioche* p, int pos);
/**
* @brief ajoute une lettre d'une pioche
* @param[out] p la pioche auquel ajouter le charact√©re
* @param[in]  c le charact√©re a ajouter
* @pre le charact√®re doit etre une lettre et la pioche doit etre initialis√©e
*/
void ajouter(pioche* p, char c);
/**
 * @brief retire un charact√©re dans une pioche et la remet dans une autre
 * @param E la pioche auquel enlever le charact√©re
 * @param pos la position du charact√©re √  enlever
 * @param p la pioche auquel ajouter le charact√©re
 * @pre les 2 pioche , E et p doivent √©tre initialiser *
 * @pre la position doit √©tre une position valable dans la pioche
 * @pre la pioche √  enlever le charact√©re doit avoir au moins un charat√©re
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
* @brief  donne le charact√©re dans la pioche √  une position pr√©cise
* @param[in] p la pioche dans laquel on veut le charact√©re
* @param[in] pos la position du chararc√©re dans la pioche
* @return le charat√®re dans la pioche p √  la position pos
* @pre la position doit √©tre valable +
*/
char dmdchar(const pioche* p, int pos);
/**
* @brief  donne la position dans la pioche √  pour une lettre
* @param[in] p la pioche dans laquel on veut la position
* @param[in] lettre le charactere chercher
* @return la position du charactere
*/
int dmdpos(const pioche* p, char lettre);
/**
* @brief donne le nombre de charact√©re dans la pioche
* @param[in] p pioche
* @return le nombre de charac√©re dans la pioche
*/
int taille(const pioche* p);
/**
 * @brief affiche la pioche
 * @param[in] p la pioche ‡ afficher
 * @param[in] p la pioche √  afficher
 */
void afficher(const pioche* p);
/**
 * @brief trie la pioche
 * @param[out] p la pioche ‡ trier
 * @param[out] p la pioche √  trier
 */
void trier(pioche* p);
/**
* @brief  libÈre une pioche
* @param p  la pioche √  liberer
*/
void LibPioche(pioche* p);
/**
* @brief  melange une pioche
* @param p la pioche ‡ melanger
*/
void melanger(pioche* p);
/**
* @brief donne la chaine de charactÈre contenu dans une pioche
* @param p  la pioche dont on veut la chaine de charactÈre
* @return  la chaine de charactÈre
*/
char* chaine(pioche* p);