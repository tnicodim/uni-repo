/* Sa se citeasca si sa se afiseze o matrice folosind urmatorul meniu:
1. citirea matricei
2. afisare matrice
0. iesire
Se va folosi alocarea dinamica de memorie
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int** matrice;
	int optiune, i, j, size;
	printf("\nDati nr de linii si coloane: ");
	scanf("%d", &size);
	matrice = (int**)malloc(sizeof(int*));
	matrice[0] = (int*)malloc(sizeof(int) * size * size);
	while (1)
	{
		printf("\n1.Citirea matricei");
		printf("\n2.Afisarea matricei");
		printf("\n0.Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("\nDati nr de linii si coloane: ");
			scanf("%d", &size);
			matrice = (int**)malloc(sizeof(int*));
			matrice[0] = (int*)malloc(sizeof(int) * size * size);
			for (i = 0; i < size; i++)
				for (j = 0; j < size; j++)
				{
					printf("Introduceti matrice[%d][%d] = ", i + 1, j + 1);
					scanf("%d", *matrice + i * size + j);
				}
			break;
		case 2:
			for (i = 0; i < size; i++)
			{
				printf("\n");
				for (j = 0; j < size; j++)
					printf("%d ", *(*matrice + i * size + j));
			}
			break;
		}
	}
	system("pause");
	return 0;
}