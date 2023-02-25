/* Sa se scrie o aplicatie in C pentru evidenta masinilor dintrun showroom
    despre fiecare masina se cunosc urmatoarele informatii:
   marca-model-pret
    Sa se creeze un meniu interactiv care sa permita urmatoarele:
    1. Adaugarea unei masini. Masina va fi considerata introdusa corect daca primul caracter din marca este litera mare,
    iar modelul va avea forma xx-xxxxx, x fiind litera sau cifra.
    2. Afisarea tuturor masinilor
    3. Afisarea masinilor de o anumita marca
    4. Afisarea masinilor care au un pret intre doua valori date de la tastatura
    5. Cautarea unei masini dupa marca si model
    0. Iesire
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct masini {
    char marca[15];
    char model[8];
    int pret;
} M;

int validareModel(char model[8])
{
    int i;
    if (model[2] != '-')
        return 0;
    for (i = 0; i < 2; i++)
        if (!((model[i] >= 'a' && model[i] <= 'z') || (model[i] >= 'A' && model[i] <= 'Z')))
            return 0;
    for (i = 3; i < 8; i++)
        if (!( (model[i] >= 'a' && model[i] <= 'z') || (model[i] >= 'A' && model[i] <= 'Z') ))
            return 0;
    return 1;
}

void citire(M* shroom, int* n) {
    (*n)++;
    do {
        printf("\nMarca: ");
        scanf("%s", (shroom + *n)->marca);
    } while (!((shroom + *n)->marca[0] >= 'A' && (shroom + *n)->marca[0] <= 'Z'));
    do {
    printf("Model: ");
    scanf("%s", (shroom + *n)->model);
    ((shroom + *n)->model)[8] = '\0';
    } while (!(validareModel((shroom + *n)->model)));
    printf("Pret($): ");
    scanf("%d", &(shroom + *n)->pret);
    printf("\n");
}

void afisare(M* shroom, int n) {
    printf("\nMarca: %s", (shroom + n)->marca);
    printf("\nModel: %s", (shroom + n)->model);
    printf("\nPret($): %d", (shroom + n)->pret);
    printf("\n");
}

void afisareMarca(M* shroom, int n) {
    char marcaCautata[15];
    int i;
    printf("Marca cautata este:");
    scanf("%s", marcaCautata);
    for (i = 0; i <= n; i++) {
        if (strcmp((shroom + i)->marca, marcaCautata) == 0){
            afisare(shroom, i);
            printf("\n");
    }
    }
}

void afisareValori(M* shroom, int n) {
    int val1, val2;
    int i;
    printf("Valoarea minima = ");
    scanf("%d", &val1);
    printf("Valoarea maxima = ");
    scanf("%d", &val2);
    for (i = 0; i <= n; i++) {
        if ((shroom + i)->pret >=val1 && (shroom + i)->pret <= val2) {
            afisare(shroom, i);
            printf("\n");
        }
    }
}

void afisareMarcaModel(M* shroom, int n) {
    char marcaCautata[15];
    char modelCautat[8];
    int i;
    printf("Marca cautata este:");
    scanf("%s", marcaCautata);
    printf("Modelul cautat este:");
    scanf("%s", modelCautat);
    for (i = 0; i <= n; i++) {
        if ((strcmp((shroom + i)->marca, marcaCautata) == 0) && (strcmp((shroom + i)->model, modelCautat) == 0)) {
            afisare(shroom, i);
            printf("\n");
        }
    }
}

int main() {
    M showroom[10];
    int opt, n, i;
    n = -1;
    while (1) {
        printf("1. Adaugarea unei masini\n2. Afisarea tuturor masinilor\n3. Afisarea masinilor de o anumita marca\n4. Afisarea masinilor care au un pret intre doua valori\n5. Cautarea unei masini dupa marca si model\n0. Iesire\n--------------------\nIntroduceti optiunea: ");
        scanf("%d", &opt);
        printf("--------------------\n");
        switch (opt) {
        case 0:
            printf("\nExiting......\n\n");
            exit(1);
        case 1:
            citire(showroom, &n);
            break;
        case 2:
            for (i=0; i<=n; i++)
                afisare(showroom, i);
            printf("\n");
            break;
        case 3:
            afisareMarca(showroom, n);
            break;
        case 4:
            afisareValori(showroom, n);
            break;
        case 5:
            afisareMarcaModel(showroom, n);
            break;
        default:
            printf("~~~~~~~~~~~~~~~~~~~~\nOPTIUNE INEXISTENTA\n~~~~~~~~~~~~~~~~~~~~\n");
        }
    }
    return 0;
}