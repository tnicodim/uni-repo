/*1. Sa se scrie un program in C care sa citeasca de la tastatura doua matrice patratice de
numere intregi, de dimensiune specificata de utilizator si sa afiseze suma celor doua
matrice. */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum, m1, m2, i, j, v1[10][10], v2[10][10];
	printf("\nIntroduceti marimea matricei patratice v1: ");
	scanf("%d", &m1);
	printf("\nIntroduceti marimea matricei patratice v2: ");
	scanf("%d", &m2);
	if (m1 != m2)
	{
		printf("\nMatricele nu pot fi adunate! (sunt de dimensiuni diferite)\n\n\n");
		exit(0);
	}
	printf("\nIntroduceti elementele matricei v1:");
	for (i = 0; i < m1; i++)
		for (j = 0; j < m1; j++)
		{
			printf("\nv1[%d][%d]= ", i + 1, j + 1);
			scanf("%d", &v1[i][j]);
		}
	printf("\nIntroduceti elementele matricei v2:");
	for (i = 0; i < m2; i++)
		for (j = 0; j < m2; j++)
		{
			printf("\nv2[%d][%d]= ", i + 1, j + 1);
			scanf("%d", &v2[i][j]);
		}
	printf("\nSuma celor 2 matrice este matricea: ");
	for (i = 0; i < m2; i++)
	{
		printf("\n");
		for (j = 0; j < m2; j++)
		{
			printf("%3d", v1[i][j] + v2[i][j]);
		}
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}