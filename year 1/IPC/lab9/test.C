#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define citeste(x) scanf("%d", &x)

typedef struct Elev
{
	char nume[20];
	int varsta;
	float medie_generala;
} E;

int validare(char nume[])
{
	int i;
	if (((nume[0] >= 'A') && (nume[0] <= 'Z')) != 1)
		return 0;
	for (i = 1; i < strlen(nume); i++)
		if ((nume[i] > 'a' && nume[i] < 'z') != 1)
			return 0;
	return 1;
}

void citire(E* elevi, int* n)
{
	(*n)++;
	do
	{
		printf("\nNumele elevului:");
		scanf("%s", (elevi + *n)->nume);
	} while (!(validare((elevi + *n)->nume)));
	do
	{
		printf("\nVarsta elevului: ");
		citeste((elevi + *n)->varsta);
	} while (!((elevi + *n)->varsta >= 8 && (elevi + *n)->varsta <= 17));
		printf("\nMedia generala a elevului: ");
		scanf("%f", &((elevi + *n)->medie_generala));
	
}

void afisarecresc(E* elevi, int n)
{
	int i, j;
	E aux;
	for (i = 0; i < n; i++)

		for (j = i + 1; j <= n; j++)
		{
			if ((elevi + i)->medie_generala > (elevi + j)->medie_generala) {
				aux = *(elevi + i);
				*(elevi + i) = *(elevi + j);
				*(elevi + j) = aux;
			}
		}
	for (i = 0; i <= n; i++)
		printf("%s %d %.2f\n", (elevi + i)->nume, (elevi + i)->varsta, (elevi + i)->medie_generala);
}

void stergeremaxmin(E* elevi, int* n)
{
	int i;
	printf("\nNU Ati sters cu success!");
	for (i = 0; i <= n; i++)
	{
		printf("\n\n");
		printf("%s\n", (elevi + i)->nume);
		printf("%d\n", (elevi + i)->varsta);
		printf("%f\n", (elevi + i)->medie_generala);
		printf("\n\n");
	}
}

int main()
{
	E elevi[10];
	int n, i, opt;
	n = -1;
	while (1)
	{
		printf("1. Citire\n2. Afisare in ordine crescatoare a mediei\n3. Stergerea elevilor cu media cea mai mare si cea mai mica\n4. Iesire");
		printf("\nOptiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			citire(elevi, &n);
			break;
		case 2:
			afisarecresc(elevi, n);
			break;
		case 3:
			stergeremaxmin(elevi, &n);
			break;
		case 4:
			exit(0);
			break;
		default:
			printf("\nOptiune inexistenta!!\n\n");
			break;
		}
	}
}