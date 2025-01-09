#include "jeu.h"
int main() {
	jeu jeu;
	FILE* fileDico = fopen("ods4.txt", "r");
	char** tabDico = conv_dico(fileDico);
	initJeu(&jeu, tabDico);
}