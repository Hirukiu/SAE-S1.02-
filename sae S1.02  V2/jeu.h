#pragma once
#include "pioche.h"
enum { chevalet = 12, dico_mot = 369086, Taille_rail = 8, taille_mot_max = 16, preMotMax = 4 };
typedef enum { P1, P2 }etat;
typedef struct {
	pioche P;
	pioche rail;
	pioche P1;
	pioche P2;
	etat e;
	char** motjoues;
	int nbmotsjoues;
}jeu;
/**
 * @brief   initialise un Jeu avec tout les chevalet distribuée pour 2 joueur et demande le premmier mot de 4 de long a mettre sur le rail
 * @param J le Jeu à initialiser
 * @return 1 si la partie peut continuer ou 0 si la partie doit s'arreter
*/
int initJeu(jeu* J);
/**
 * @brief verifie que le mot ne contient pas les lettres k, w, x, y, z
 * @param  mot le mot a verifier
 * @param size la taille du mot
 * @return 0 si oui et 1 si non
 */
int lettreok(char* mot, const int size);
/**
 * @brief trouve la position d'une chaine de charactÃ©re dans une liste de chaine de charactÃ©re
 * @param dico la liste de chaine de charactÃ©re
 * @param mot le mot a rechercher
 * @param taille la taille de la liste
 * @return la position du mot dans la liste ou 0 si il n'y as pas le mot dans la liste
 */
int dichothomie(char** dico, char* mot, int taille);
/**
 * @brief trouve la position d'une chaine de charactére dans une liste de chaine de charactére
 * @param dico la liste de chaine de charactére
 * @param mot le mot a rechercher
 * @param min la position auquel on veut commencer à charcher (la valeur de la postition la plus basse à laquel on veut chercher)
 * @param max la position auquel on veut finir de charcher (la valeur de la postition la plus haute à laquel on veut chercher)
 * @return la position du mot dans la liste ou 0 si il n'y as pas le mot dans la liste
*/
int dichorecu(char** dico, char* mot, int min, int max);
/**
 * @brief  converti un fichier texte en tableau de chaine de charactére de taille max 369085 et de chaine de charactére max de 16
*/
char** conv_dico();

/**
 * @brief demande au joueur un mot de 4 lettre valable dans une liste de chaine de charactére
 * @param J le jeu
 * @param joueur le joueur qui doit rentrer un mot
 * @param dico la liste de mot valable
 * @return le mot valable
 */
char* demandejoueurpre(jeu* J, int joueur, char** dico);
/**
 * @brief demande aux joueur un premier mot de 4 lettre à mettre sur le rail pour debuter le jeu , si un des 2 joueur ne peut pas composer de mot la partie s'arrete , et si le mot rentrer par le joueur n'est pas dans la liste de mot donnée on redemande au joueur un mot
 * @param j le jeu à debuter
 * @return 1 si la partie se deroule comme il le faut 0 si la partie doit s'arreter
*/
int Pretour(jeu* j);