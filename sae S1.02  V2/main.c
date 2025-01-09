#include "jeu.h"
int main() {
    jeu jeu;
    clock_t start = clock();

    initJeu(&jeu);
    Pretour(&jeu);

    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Durée du code : %f secondes\n", elapsed_time);
}