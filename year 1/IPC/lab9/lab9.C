#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Sa se scrie o aplicatie in C pentru evidenta masinilor dintrun showroom
    despre fiecare masina se cunosc urmatoarele informatii:
    marca
    model
    pret
    Sa se creeze un meniu interactiv care sa permita urmatoarele:
    1. Adaugarea unei masini. Masina va fi considerata introdusa corect daca primul caracter din marca este litera mare,
    iar modelul va avea forma xx-xxxxx, x fiind litera sau cifra.
    2. Afisarea tuturor masinilor
    3. Afisarea masinilor de o anumita marca
    4. Afisarea masinilor care au un pret intre doua valori date de la tastatura
    5. Cautarea unei masini dupa marca si model
    6. Sa se afiseze masinile care au un pret divizibil cu 3
    0. Iesire
*/

//citire(&masini[0], &n);
// for (i = 0; i < n + 1; i++) 

typedef struct Masina
{
    char marca[20];
    char model[9];
    unsigned int pret;
} M;

int este_cifra_sau_litera(char* sir)
{
    int i;

    if (sir[2] != '-')
        return 0;

    for (i = 0; i < 8; i++)
    {
        if (i != 2)
            if (!((sir[i] >= 'A' && sir[i] <= 'Z') || (sir[i] >= 'a' && sir[i] <= 'z') || (sir[i] >= '0' && sir[i] <= '9')))
                return 0;
    }

    return 1;
}

void citire(M* mas, int* n)
{
    (*n)++;
    do
    {
        printf("Scrieti marca masinii:\n");
        scanf("%s", (mas + *n)->marca);
    } while (!((mas + *n)->marca[0] >= 'A' && (mas + *n)->marca[0] <= 'Z'));
    do
    {
        printf("Scrieti modelul masinii:\n");
        scanf("%s", (mas + *n)->model);
    } while (!este_cifra_sau_litera((mas + *n)->model));
    printf("Scrieti pretul:\n");
    scanf("%d", &((mas + *n)->pret));
}

void afisare(M* mas, int n)
{
    printf("%s\n", (mas + n)->marca);
    printf("%s\n", (mas + n)->model);
    printf("%d\n", (mas + n)->pret);
}

void afisare_marca(M* mas, int n, char mrc[20])
{
    int i;
    for (i = 0; i <= n; i++)
        if (strcmp((mas + i)->marca, mrc) == 0)
            afisare(mas, i);
}

void afisare_marca_model(M* mas, int n, char mrc[20], char mdl[20])
{
    int i;
    for (i = 0; i <= n; i++)
        if (strcmp((mas + i)->marca, mrc) == 0 && strcmp((mas + i)->model, mdl) == 0)
            afisare(mas, i);
}

void afisare_masini_intre_pret(M* mas, int n, unsigned int min, unsigned int max)
{
    int i;
    for (i = 0; i <= n; i++)
        if ((mas + i)->pret >= min && (mas + i)->pret <= max)
            afisare(mas, i);
}

void afisare_pret_divizibil(M* mas, int n)
{
    int i;
    for (i = 0; i <= n; i++)
        if ((mas + i)->pret % 3 == 0)
            afisare(mas, i);
}


int main()
{
    M masini[20];
    int optiune, n, i;
    char mrc[20], mdl[20];
    unsigned int min, max;
    n = -1;
    while (1)
    {
        printf("1. Adaugarea unei masini.\n");
        printf("2. Afisarea tuturor masinilor\n");
        printf("3. Afisarea masinilor de o anumita marca\n");
        printf("4. Afisarea masinilor care au un pret intre doua valori date de la tastatura\n");
        printf("5. Cautarea unei masini dupa marca si model\n");
        printf("6. Sa se afiseze masinile care au un pret divizibil cu 3\n");
        printf("0. Iesire\n");
        printf("Alegeti o optiune:\n");
        scanf("%d", &optiune);
        switch (optiune)
        {
        case 1:
            citire(masini, &n);
            break;
        case 2:
            for (i = 0; i <= n; i++)
                afisare(masini, i);
            break;
        case 3:
            printf("Scrieti marca cautata: \n");
            scanf("%s", mrc);
            afisare_marca(masini, n, mrc);
            break;
        case 4:
            printf("Introduceti pretul minim: ");
            scanf("%d", &min);
            printf("Introduceti pretul maxim: ");
            scanf("%d", &max);
            afisare_masini_intre_pret(masini, n, min, max);
            break;
        case 5:
            printf("Scrieti marca cautata: \n");
            scanf("%s", mrc);
            printf("Scrieti modelul cautat: \n");
            scanf("%s", mdl);
            afisare_marca_model(masini, n, mrc, mdl);
            break;
        case 6:
            afisare_pret_divizibil(masini, n);
            break;
        case 0:
            exit(0);
            break;

        default:
            printf("Optiune gresita\n");
            break;
        }
    }

    return 0;
}