//problema 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct televizor {
	char marca[20];
	int diagonala;
	int pret;
} T;


void binar(int nr)
{
	unsigned int i;
	for (i = 1 << 16; i > 0; i = i / 2) {
		if (nr & i)
			printf("1");
		else
			printf("0");
	}
}

void citire(T* tele, int* n)
{
	int i, aux, validare;
	(*n)++;
	do {
		validare = 1;
		printf("\nIntroduceti marca: ");
		scanf("%s", (tele + *n)->marca);
		if (!(((tele + *n)->marca)[0] >= 'A' && ((tele + *n)->marca)[0] <= 'Z'))
			validare = 0;
		for (i = 1; i < strlen((tele + *n)->marca); i++)
			if (!((((tele + *n)->marca)[i] >= 'a' && ((tele + *n)->marca)[i] <= 'z') || (((tele + *n)->marca)[i] >= '0' && ((tele + *n)->marca)[i] <= '9')))
				validare = 0;
	} while (validare != 1);
	(tele + *n)->diagonala = 1;
	for (i = 1; i < strlen((tele + *n)->marca); i++)
	{
		if (((tele + *n)->marca)[i] == '2')
			(tele + *n)->diagonala *= 2;
		if (((tele + *n)->marca)[i] == '3')
			(tele + *n)->diagonala *= 3;
		if (((tele + *n)->marca)[i] == '4')
			(tele + *n)->diagonala *= 4;
		if (((tele + *n)->marca)[i] == '5')
			(tele + *n)->diagonala *= 5;
		if (((tele + *n)->marca)[i] == '6')
			(tele + *n)->diagonala *= 6;
		if (((tele + *n)->marca)[i] == '7')
			(tele + *n)->diagonala *= 7;
		if (((tele + *n)->marca)[i] == '8')
			(tele + *n)->diagonala *= 8;
		if (((tele + *n)->marca)[i] == '9')
			(tele + *n)->diagonala *= 9;
	}
	printf("Diagonala este %d\n", (tele + *n)->diagonala);
	printf("Introduceti pretul: ");
	scanf("%d", &(tele + *n)->pret);
	printf("\n\n");
}

void afisare(T* tele, int n)
{
	int i;
	for (i = 0; i <= n; i++) {
		printf("\nTelevizorul %d:\n--------------\nMarca: %s\nDiagonala: %d\nPretul: %d\n\n", i, (tele + i)->marca, (tele + i)->diagonala, (tele + i)->pret);
	}
}

void afisareDescrescator(T* tele, int n)
{
	int i, j;
	T aux;
	for (i = 0; i < n; i++)
		for (j = i + 1; j <= n; j++)
			if ((tele + i)->pret < (tele + j)->pret) {
				aux = *(tele + i);
				*(tele + i) = *(tele + j);
				*(tele + j) = aux;
			}
	afisare(tele, n);
}

void afisareBinar(T* tele, int n)
{
	int i;
	for (i = 0; i <= n; i++)
		if ((tele + i)->diagonala <= 65535)
		{
			printf("\nReprezentarea binara a diagonalei egala cu %d a televizorului %d este ", (tele + i)->diagonala, i);
			binar((tele + i)->diagonala);
			printf("\n-------------\n");
		}
}


int main() {
	T televizoare[10];
	int n, opt;
	n = -1;
	while (1) {
		printf("1. Adaugarea unui nou televizor\n2. Afisarea televizoarelor in ordine descrescatoare dupa pret (bubble sort)\n3. Afisarea reprezentarilor binare ale diagonalelor televizoarelor (maxim 2 octeti)\nIntroduceti optiunea: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(1);
			break;
		case 1:
			citire(televizoare, &n);
			break;
		case 2:
			afisareDescrescator(televizoare, n);
			break;
		case 3:
			afisareBinar(televizoare, n);
			break;
		default:
			printf("\nOptiune inexistenta!");
			break;
		}
	}
	return 0;
}