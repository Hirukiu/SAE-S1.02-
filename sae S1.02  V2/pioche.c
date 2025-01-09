#include "pioche.h"
void init(pioche* p) {
	p->c = NULL;
	p->taille = 0;
}
void ajouter(pioche* p, char c) {
	assert((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
	if (c >= 'a' && c <= 'z') {
		c -= 32;
	}
	char* temp = (char*)realloc(p->c, sizeof(char) * (p->taille + 1));
	assert(temp != NULL);
	p->c = temp;
	p->c[p->taille] = c;
	p->taille++;
}
char enlever(pioche* p, int pos) {
	assert(pos >= 0 && pos < p->taille);
	assert(p->taille > 0);
	char tempo = p->c[pos];
	for (int i = pos; i < p->taille - 1; i++) {
		p->c[i] = p->c[i + 1];
	}
	p->taille--;
	char* temp = (char*)realloc(p->c, sizeof(char) * p->taille);
	assert(temp != NULL);
	p->c = temp;
	return tempo;
}
void echanger(pioche* E, int pos, pioche* p) {
	assert(E != NULL);
	assert(p != NULL);
	assert(E->c != NULL);
	assert(pos >= 0 && pos < E->taille);
	char temp = enlever(E, pos);
	ajouter(p, temp);
}
void echangemot(pioche* p1, char* mot, pioche* p2) {
	for (int i = 0; i < strlen(mot); i++) {
		assert(lettrepresent(p1, mot[i]));
	}
	for (int i = 0; i < strlen(mot); i++) {
		echanger(p1, dmdpos(p1, mot[i]), p2);
	}
}
char dmdchar(const pioche* p, int pos) {
	assert(pos > 0);
	return (p->c[pos]);
}
int dmdpos(const pioche* p, char lettre) {
	for (int i = 0; i < taille(p) - 1; i++) {
		if (p->c[i] == lettre)
			return i;
	}
	return -1;
}
int taille(const pioche* p) {
	return (p->taille);
}
void afficher(const pioche* p) {
	for (int i = 0; i < p->taille; i++)
		printf("%c", p->c[i]);
	printf("\n");
}
void trier(pioche* p) {
	for (int i = 0; i < p->taille; i++) {
		int minIndex = i;
		for (int j = i + 1; j < p->taille; j++) {
			if (p->c[j] < p->c[minIndex]) {
				minIndex = j;
			}
		}
		if (minIndex != i) {
			char temp = p->c[i];
			p->c[i] = p->c[minIndex];
			p->c[minIndex] = temp;
		}
	}
}

void LibPioche(pioche* p) {
	if (p->c != NULL) {
		free(p->c);
		p->c = NULL;
	}
	p->taille = 0;
}

void melanger(pioche* p) {
	srand((unsigned int)time(NULL));
	for (int i = p->taille - 1; i > 0; i--) {
		int j = rand() % (i + 1);
		int temp = p->c[i];
		p->c[i] = p->c[j];
		p->c[j] = temp;
	}
}

char* chaine(pioche* p) {
	return(p->c);
}

int lettrepresent(pioche* p, char* l) {
	for (int i = 0; i < strlen(p->c); i++)
		if (l == p->c[i])
			return 1;
	return 0;
}