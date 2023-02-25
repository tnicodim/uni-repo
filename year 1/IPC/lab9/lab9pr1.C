/* 
Scrieti un program care tine evidenta cartilor dintr-o biblioteca, pentru fiecare carte
specificandu-se: titlul, autorul, anul aparitiei, numarul de pagini, domeniul.
1. Adaugarea unei carti
2. Afisarea cartilor dintr-un domeniu citit de la tastatura
3. Cautarea unei carti dupa titlu
4. Cautarea unei carti dupa anul aparitiei.
5. Stergerea unei carti
6. Sortarea cartilor dupa titlu dintr-un anumit domeniu citit de la tastatura
7. Exit 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Carte
{
	char titlu[30];
	char autor[30];
	char domeniu[30];
	int an;
	int pagini;
} C;

void citire(C* carti, int *n)
{
	(*n)++;
	printf("\nTitlul cartii: ");
	getchar();
	gets((carti + *n)->titlu);
	printf("\nAutorul cartii: ");
	gets((carti + *n)->autor);
	printf("\nAnul aparitiei: ");
	scanf("%d", &(carti + *n)->an);
	printf("\nNumarul de pagini: ");
	scanf("%d", &(carti + *n)->pagini);
	printf("\nDomeniul: ");
	getchar();
	gets((carti + *n)->domeniu);
	printf("\n");
}

/* void afisareToate(C* books, int n)
{
	int i;
	for (i = 0; i <= n; i++)
	{
		printf("\n\n");
		printf("%s\n", (books + i)->titlu);
		printf("%s\n", (books + i)->autor);
		printf("%d\n", (books + i)->an);
		printf("%d\n", (books + i)->pagini);
		printf("%s\n", (books + i)->domeniu);
		printf("\n\n");
	}
}  */

void afisareDomeniu(C *carti, int n)
{
	int i;
	char domcautat[30];
	printf("\nDomeniul cautat: ");
	getchar();
	gets(domcautat);
	for (i = 0; i <= n; i++)
		if (strcmp(domcautat, ((carti + i)->domeniu)) == 0)
		{
			printf("\n");
			printf("%s\n", (carti + i)->titlu);
			printf("%s\n", (carti + i)->autor);
			printf("%d\n", (carti + i)->an);
			printf("%d\n", (carti + i)->pagini);
			printf("%s\n", (carti + i)->domeniu);
			printf("\n");
		}
}

void cautareTitlu(C* carti, int n)
{
	int i, k = 0;
	char titlucautat[30];
	printf("\nTitlul cautat: ");
	getchar();
	gets(titlucautat);
	for (i = 0; i <= n; i++)
		if (strcmp(titlucautat, (carti + i)->titlu) == 0)
		{
			printf("\nCartea a fost gasita!\n");
			printf("%s\n", (carti + i)->titlu);
			printf("%s\n", (carti + i)->autor);
			printf("%d\n", (carti + i)->an);
			printf("%d\n", (carti + i)->pagini);
			printf("%s\n", (carti + i)->domeniu);
			printf("\n\n");
			k++;
		}
	if (k == 0)
		printf("\nTitlul specificat nu a fost gasit!\n\n");
}

void cautareAn(C* carti, int n)
{
	int i, k = 0, ancautat;
	printf("\nAnul cautat: ");
	scanf("%d", &ancautat);
	for (i = 0; i <= n; i++)
		if (ancautat == (carti + i)->an)
		{
			printf("\nCartea a fost gasita!\n");
			printf("%s\n", (carti + i)->titlu);
			printf("%s\n", (carti + i)->autor);
			printf("%d\n", (carti + i)->an);
			printf("%d\n", (carti + i)->pagini);
			printf("%s\n", (carti + i)->domeniu);
			printf("\n\n");
			k++;
		}
	if (k == 0)
		printf("\nCarti cu anul de aparitie specificat nu au fost gasite!\n\n");
}

void stergere(C* carti, int *n)
{
	int i, k;
	printf("\nNumarul cartii pentru sters(1,2,3,...): ");
	scanf("%d", &k);
	k = k - 1;
	for (i = k; i < *n; i++)
		*(carti + i) = *(carti + i + 1);
	*n = *n - 1;
	printf("\nAti sters cu success!");
	for (i = 0; i <= *n; i++)
	{
		printf("\n\n");
		printf("%s\n", (carti + i)->titlu);
		printf("%s\n", (carti + i)->autor);
		printf("%d\n", (carti + i)->an);
		printf("%d\n", (carti + i)->pagini);
		printf("%s\n", (carti + i)->domeniu);
		printf("\n\n");
	}
}

/* void sortareTitlu(C* carti, int n)
{
	int i, k = -1;
	char domcautat[30];
	C aux[20];
	printf("\nDomeniul cautat: ");
	getchar();
	gets(domcautat);
	for (i = 0; i <= n; i++)
		if (strcmp(domcautat, ((carti + i)->domeniu)) == 0)
		{
			k++;
			*(aux + k) = *(carti + i);
		}
	for (i = 0; i < k)
		if (strcmp((aux + i)->titlu, (aux + i + 1)->titlu)
} */

int main()
{	
	C books[20];
	int opt, i, n;
	n = -1;
	while (1)
	{
		printf("1. Adaugarea unei carti\n2. Afisarea cartilor dintr-un domeniu citit de la tastatura\n3. Cautarea unei carti dupa titlu\n4. Cautarea unei carti dupa anul aparitiei\n5. Stergerea unei carti\n6. Exit ");
		printf("\nOptiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			citire(&books[0], &n); // citire(books, &n);
			break;
		case 2:
			afisareDomeniu(books, n);
			break;
		case 3:
			cautareTitlu(books, n);
			break;
		case 4:
			cautareAn(books, n);
			break;
		case 5:
			stergere(books, &n);
			break;
		case 6:
			printf("\nIesire din program...\n\n");
			exit(0);
			break;
		default:
			printf("\nOptiune inexistenta!!\n\n");
			break;
		}
	}
	return 0;
}