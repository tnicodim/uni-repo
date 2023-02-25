/* Aplicația 3.8: Se dă vectorul {7, -5, 4, 3, -9, 2, -8}. Să se insereze înainte de fiecare valoare din vectorul original
negativul ei. Utilizați pointeri, fără indecși.
*/

#include <stdio.h>
#include <stdlib.h>

int n = 14;

void inserare(int* v) {
	int i, j;
	int *vaux;
	vaux = (int*)malloc(sizeof(int) * 7);
	for (i = 0; i < 7; i++)
		*(vaux+i) = *(v+i);
	i = 0;
	for (j = 0; j <= n; j += 2) {
		*(v+j) = -(*(vaux + i));
		(*(v + j + 1)) = -*(v + j);
		i++;
	}
}


int main() {
	int v[20] = { 7, -5, 4, 3, -9, 2, -8 };
	int i;
	inserare(v);
	printf("\nVectorul v este:\n");
	for (i = 0; i < n; i++)
		printf("%d  ", *(v + i));
	printf("\n\n");
	return 0;
}