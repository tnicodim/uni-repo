/* Problema 7.6.
Să se scrie un program care gestionează date despre un grup de studenţi. Pentru fiecare student se memorează
Numele şi numărul matricol. Programul trebuie să implementeze următoarele operaţii:
-citirea numărului de studenţi şi a datelor acestora;
-afişarea datelor tuturor studenţilor;
-sortarea listei de studenţi în ordinea alfabetică a numelor;
-sortarea listei de studenţi în ordinea crescătoare a numerelor matricole;
-căutarea unui student pentru care se precizează numele şi afişarea poziţiei pe care o ocupă acesta în lista
ordonată alfabetic după numele studenţilor;
-căutarea unui student pentru care se precizează numărul matricolşi afişarea poziţiei pe care o ocupă
acesta în lista ordonată crescător după numărul matricol al studenţilor;
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int n = -1;

typedef struct{
	char nume[20];
	int matricol;
}s;

void citire(s *stud) {
	n++;
    getchar();
	printf("\nNume = ");
    gets((stud+n)->nume);
	printf("Nr matricol = ");
	scanf("%d", &(stud+n)->matricol);
}

void afisare(s* stud, int i) {
       printf("\nStudent %d:\nNume: %s\nNr matricol: %d\n", i, (stud+i)->nume, (stud+i)->matricol);
}

void sortNume(s* stud) {
    int i,j;
    s aux;
    for (i = 0; i < n; i++)
        for (j = i+1; j <= n;j++)
            if (strcmp(stud[i].nume, stud[j].nume) > 0)
            {
                aux = stud[i];
                stud[i] = stud[j];
                stud[j] = aux;
            }
}

void sortMatricol(s* stud) {
    int i, j;
    s aux;
    for (i = 0; i < n; i++)
        for (j = i + 1; j <= n; j++)
            if (stud[i].matricol>stud[j].matricol)
            {
                aux = stud[i];
                stud[i] = stud[j];
                stud[j] = aux;
            }
}

void cautareNume(s* stud) {
    int i, k = 0;
    char numeCautat[15];
    printf("\nNumele cautat: ");
    gets(numeCautat);
    sortNume(stud);
    for (i = 0; i <= n; i++)
        if (strcmp(numeCautat, stud[i].nume) == 0) {
            afisare(stud, i);
            k++;
        }
    if (!k)
           printf("\nNu exista asa student!");
}

void cautareMatricol(s* stud) {
    int i,k = 0;
    int matricolCautat;
    printf("\nNr matricol cautat: ");
    scanf("%d", &matricolCautat);
    sortMatricol(stud);
    for (i = 0; i <= n; i++)
        if (matricolCautat == stud[i].matricol) {
            afisare(stud, i);
            k++;
        }
    if (!k)
        printf("\nNu exista asa student!");
}

int main()
{
    s stud[20];
    int optiune, i;
    while (1)
    {
        printf("\n1. Adaugarea unui student.\n");
        printf("2. Afisarea tuturor studentilor\n");
        printf("3. Sortarea studentilor in ord. alfabetica a numelor\n");
        printf("4. Sortarea studentior in ord. cresc. a nr. matricol\n");
        printf("5. Cautarea dupa nume in lista ord. alfabetic dupa nume\n");
        printf("6. Cautarea dupa nr matricol in lista ord. cresc. dupa nr matricol\n");
        printf("0. Iesire\n");
        printf("Alegeti o optiune: ");
        scanf("%d", &optiune);
        switch (optiune) {
        case 0:
            exit(0);
        case 1:
            citire(stud);
            break;
        case 2:
            for (i = 0; i <= n; i++)
                afisare(stud, i);
            break;
        case 3:
            sortNume(stud);
            break;
        case 4:
            sortMatricol(stud);
            break;
        case 5:
            cautareNume(stud);
            break;
        case 6:
            cautareMatricol(stud);
            break;
        default:
            printf("\nOptiune gresita!\n");
            break;

        }
    }
}