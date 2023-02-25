/* Aplicația 2.10: Se citește de la tastatură o matrice pătratică cu n<=50 linii și coloane. Să se interschimbe
elementele de deasupra diagonalei principale cu elementele de sub diagonala principală, elementele de pe
diagonala principală rămânând la fel.
*/

#include <stdio.h>
#include <stdlib.h>

void citire(int a[50][50],int size) {
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			printf("mat[%d][%d] = ", i + 1, j + 1);
			scanf("%d", &a[i][j]);
		}
}

void diagonalSwap(int a[50][50], int size) {
	int i, j, aux;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
			if (i > j) {
				aux = a[i][j];
				a[i][j] = a[j][i];
				a[j][i] = aux;
			}
}

void afisare(int a[50][50], int size) {
	int i, j;
	for (i = 0; i < size; i++)
	{
		printf("\n");
		for (j = 0; j < size; j++)
			printf("%3d ", a[i][j]);
	}
}

int main() {
	int a[50][50], size;
	printf("Marimea matricei = ");
	scanf("%d", &size);
	citire(a, size);
	printf("\nMatricea inainte de swap");
	afisare(a, size);
	diagonalSwap(a, size);
	printf("\nMatricea inainte dupa swap");
	afisare(a, size);
	printf("\n\n");
	return 0;
}