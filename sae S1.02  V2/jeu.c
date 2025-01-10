#include "jeu.h"
#pragma warning (disable:4996)

int lettreok(char* mot, const int size) {
    for (int i = 0; i < size - 1; i++) {
        if (mot[i] == 'k' || mot[i] == 'w' || mot[i] == 'x' || mot[i] == 'y' || mot[i] == 'z')
            return 0;
    }
    return 1;
}
int tailleu(char** dico) {
    FILE* f = fopen("ods4.txt", "r");
    assert(f != NULL);
    char** tab = NULL;
    int compteur = 0;

    char mot[taille_mot_max];
    while (fscanf(f, "%15s", mot) != EOF)
        compteur++;
    fclose(f);
    return compteur;
}

char** conv_dico() {
    FILE* f = fopen("ods4.txt", "r");
    assert(f != NULL);
    char** tab = NULL;
    int compteur = 0;
    char mot[taille_mot_max];

    while (fscanf(f, "%15s", mot) != EOF) {
        char** tmp = (char**)realloc(tab, sizeof(char*) * (compteur + 1));
        assert(tmp != NULL);
        tab = tmp;
        tab[compteur] = (char*)malloc(strlen(mot) + 1);
        assert(tab[compteur] != NULL);
        strcpy(tab[compteur], mot);
        compteur++;
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

int initJeu(jeu* J) {
    J->nbmotsjoues = 0;
    J->motjoues = NULL;
    char lettres[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J',
                       'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V' };
    int occurrences[] = { 9, 1, 2, 3, 14, 1, 1, 1, 7, 1,
                          5, 3, 6, 5, 2, 1, 6, 7, 6, 5, 2 };
    init(&J->P);
    init(&J->P1);
    init(&J->P2);
    init(&J->rail);
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

    printf("1 : ");
    afficher(&J->P1);
    printf("2 : ");
    afficher(&J->P2);
}

char* demandeJoueurpre(jeu* J, int joueur, char** dico) {
    int valable = 0;
    char mot[preMotMax +1];
    while (valable == 0) {
        printf("%d>  ", joueur);
        scanf(" %s", mot);
        for (int i = 0; mot[i]; i++)
            mot[i] = toupper(mot[i]);
        
        if (dichorecu(dico, mot, 0, dico_mot - 1) >= 0 && strlen(mot) == 4) {
            for (int i = 0; i < strlen(mot); i++) {
                if (joueur == 1) {
                    if (dmdpos(&J->P1, mot[i]) != -1) {
                        valable = 1;
                    }
                    else {
                        valable = 0;
                        break;
                    }
                }
                else if (joueur == 2){
                    if (dmdpos(&J->P2, mot[i]) != -1) {
                        valable = 1;
                        printf("%s", J->motjoues[0]);
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
    return mot;
}

int Pretour(jeu* J) {
    char** dico = conv_dico();
    char* mot1 = demandeJoueurpre(J, 1, dico);
    J->nbmotsjoues++;
    printf("%s\n", mot1);

    char** temp = (char**)realloc(J->motjoues, sizeof(char*) * J->nbmotsjoues);
    assert(temp != NULL);
    J->motjoues = temp;

    printf("%s\n", mot1);

    char* mot2 = demandeJoueurpre(J, 2, dico);
    J->nbmotsjoues++;
    temp = (char**)realloc(J->motjoues, sizeof(char*) * J->nbmotsjoues);
    assert(temp != NULL);
    J->motjoues = temp;;

    if (strcmp(mot1, mot2) > 0) {
        echangemot(&J->P1, mot1, &J->rail);
        echangemot(&J->P2, mot2, &J->rail);
    }
    else {
        echangemot(&J->P2, mot2, &J->rail);
        echangemot(&J->P1, mot1, &J->rail);
    }

    printf("1 : ");
    afficher(&J->P1);
    printf("2 : ");
    afficher(&J->P2);
    printf("R : ");
    afficher(&J->rail);

    free(mot1);
    free(mot2);
}