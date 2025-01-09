#include "jeu.h"
#pragma warning (disable:4996)

int lettreok(char* mot, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (mot[i] == 'k' || mot[i] == 'w' || mot[i] == 'x' || mot[i] == 'y' || mot[i] == 'z')
            return 0;
    }
    return 1;
}

char** conv_dico(FILE* fileDico) {
    assert(fileDico != NULL);
    char** tab = malloc(dico_mot * sizeof(char*));
    assert(tab != NULL);
    for (int i = 0; i < dico_mot; i++) {
        if (sizeof(tab[i]) >= 3 || sizeof(tab[i]) <= 8) {
            if (lettreok(tab[i], sizeof(tab[i]))) {
                tab[i] = malloc(taille_mot_max * sizeof(char));
                assert(tab[i] != NULL);
                size_t len = strlen(tab[i]);
                if (len > 0 && tab[i][len - 1] == '\n')
                    tab[i][len - 1] = '\0';
            }
        }
    }
    return tab;
}

int dichothomie(char** dico, char* mot, int taille) {
    assert(taille > 0);
    int pos = taille / 2;
    while (strcmp(dico[pos], mot) != 0 || pos != 0) {
        if (strcmp(dico[pos], mot) < 0)
            pos += pos / 2;
        else
            pos = pos / 2;
    }
    return (pos);
}

int dichorecu(char** dico, char* mot, int min, int max) {
    if (min > max) {
        return -1;
    }
    int pos = min + (max - min) / 2;
    int cmp = strcmp(dico[pos], mot);
    if (strcmp(mot, dico[pos]) == 0) {
        return pos;
    }
    else if (strcmp(dico[pos], mot) > 0) {
        return dichorecu(dico, mot, min, pos - 1);
    }
    else {
        return dichorecu(dico, mot, pos + 1, max);
    }
}

int initJeu(jeu* J, char** dico) {
    J->nbmotsjoues = 0;
    J->motjoues = NULL;
    char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                       'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int occurrences[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                          5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    init(&J->P);
    init(&J->P1);
    init(&J->P2);
    int total_lettres = sizeof(lettres) / sizeof(lettres[0]);
    for (int k = 0; k < total_lettres; k++) {
        for (int j = 0; j < occurrences[k]; j++) {
            ajouter(&J->P, lettres[k]);
        }
    }
    melanger(&J->P);
    for (int i = 0; i < chevalet; i++) {
        echanger(&J->P, J->P.taille - 1, &J->P1);
        echanger(&J->P, J->P.taille - 1, &J->P2);
    }
    trier(&J->P1);
    trier(&J->P2);
    printf("1 : %.12s \n", chaine(&J->P1));
    printf("2 : %.12s \n", chaine(&J->P2));
    Pretour(J, dico);
}

char* demandeJoueurpre(jeu* J, int joueur, char** dico) {
    int valable = 0;
    char mot[preMotMax + 1];
    while (valable == 0) {

        printf("%d>  ", joueur);
        scanf(" %s", mot);
        for (int i = 0; mot[i]; i++)
            mot[i] = toupper(mot[i]);

        if (dichorecu(dico, mot, 0, dico_mot - 1) >= 0 && strlen(mot) == 4) {
            for (int i = 0; i < strlen(mot) - 1; i++) {
                if (joueur = 1) {
                    if (dmdpos(&J->P1, mot[i]) != -1) {
                        valable = 1;
                    }
                    else {
                        valable = 0;
                        break;
                    }
                }
                else {
                    if (dmdpos(&J->P2, mot[i]) != -1) {
                        valable = 1;
                    }
                    else {
                        valable = 0;
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < J->nbmotsjoues; i++) {
            if (J->motjoues[i] == mot)
                valable = 0;
        }
    }
    return(mot);
}

int Pretour(jeu* J, char** dico) {
    char* mot1 = demandeJoueurpre(J, 1, dico);
    J->nbmotsjoues++;
    char** temp = (char**)realloc(J->motjoues, sizeof(char*) * J->nbmotsjoues);
    assert(temp != NULL);
    J->motjoues = temp;
    char* mot2 = demandeJoueurpre(J, 2, dico);
    J->nbmotsjoues++;
    temp = (char**)realloc(J->motjoues, sizeof(char*) * J->nbmotsjoues);
    assert(temp != NULL);
    J->motjoues = temp;
    J->motjoues[0] = mot1;
    J->motjoues[1] = mot2;
    if (strcmp(mot1, mot2) > 0) {
        echangemot(&J->P1, mot1, &J->rail);
        echangemot(&J->P2, mot2, &J->rail);
    }
    else {
        echangemot(&J->P2, mot2, &J->rail);
        echangemot(&J->P1, mot1, &J->rail);
    }
}