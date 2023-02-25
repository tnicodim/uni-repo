/* Aplicația 2.11: Se citește de la tastatură o matrice cu n<=20 linii și coloane. Să se memoreze într-un vector
suma tuturor elementelor de pe fiecare linie și într-un alt vector, suma tuturor elementelor de pe fiecare coloană.
Să se afișeze cei doi vectori. Se vor utiliza pointeri atât pentru vectori cât și pentru matrici.
*/

#include <stdio.h>
#include <stdlib.h>

void citire(int **a, int size) {
	int i, j;
	for (i = 0; i < size; i++)
		for (j = 0; j < size; j++)
		{
			printf("mat[%d][%d] = ", i + 1, j + 1);
			scanf("%d", *a + i * size + j);
		}
}

void afisare(int** a, int size){
	int i, j;
	for (i = 0; i < size; i++)
	{
		printf("\n");
		for (j = 0; j < size; j++)
			printf("%3d ", *(*a + i*size + j));
	}
}

void sumLinii(int** a, int size, int* vlinii) {
	int i, j, sum;
	for (i = 0; i < size; i++){
		sum = 0;
		for (j = 0; j < size; j++)
			sum += *(*a + i * size + j);
		*(vlinii + i) = sum;
	}
	printf("\nVectorul cu sumele liniilor:\n");
	for (i = 0; i < size; i++)
		printf("%d ", *(vlinii + i));
}

void sumColoane(int** a, int size, int* vcoloane) {
	int i, j, sum;
	for (i = 0; i < size; i++){
		sum = 0;
		for (j = 0; j < size; j++)
			sum += *(*a + j * size + i);
		*(vcoloane + i) = sum;
	}
	printf("\nVectorul cu sumele coloanelor:\n");
	for (i = 0; i < size; i++)
		printf("%d ", *(vcoloane + i));
}

int main() {
	int **mat, size, *vlinii, *vcoloane;
	printf("Marimea matricei = ");
	scanf("%d", &size);
	mat = (int**)malloc(sizeof(int*));
	mat[0] = (int*)malloc(sizeof(int) * size * size);
	vlinii = (int*)malloc(sizeof(int) * size);
	vcoloane = (int*)malloc(sizeof(int) * size);
	citire(mat, size);
	afisare(mat, size);
	printf("\n");
	sumLinii(mat, size, vlinii);
	printf("\n");
	sumColoane(mat, size, vlinii);
	printf("\n-------------------------------------------\n");
	return 0;
}