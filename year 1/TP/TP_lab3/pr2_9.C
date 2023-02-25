/* Aplicația 2.9: Se citește de la tastatură un număr n<=10 și un număr m<=20. Se cere să se scrie un program
care generează o matrice cu m linii și n coloane în care sunt puse toate numerele de la 1,2,3,...,m*n. Se vor
utiliza pointeri.
*/


#include <stdio.h>
#include <stdlib.h>

int main() {
	int** mat;
	int n, m, i, j, k=1;
	printf("n=");
	scanf("%d", &n);
	printf("m=");
	scanf("%d", &m);
	mat = (int**)malloc(sizeof(int*));
	mat[0] = (int*)malloc(sizeof(int) * n * m);
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			*(*mat+i*n+j) = k++;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%4d ", *(*mat + i * n + j));
	}
	printf("\n\n");
	return 0;
}