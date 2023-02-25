/*
Funcție pentru transpusa unei matrici mat1[20][30], cu elemente numere reale, in mat2[30][20]
*/

#include <stdio.h>
#include <stdlib.h>

void citire(float a[20][30], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			printf("a[%d][%d]=", i, j);
			scanf("%f", &a[i][j]);
		}
}
void afisare(float a[30][30], int n, int m) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%.2f ", a[i][j]);
		}
		printf("\n");
	}
}


void afisareTranspusa(float a[20][30], float b[30][20], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++)
			b[j][i] = a[i][j];
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			printf("%.2f ", b[i][j]);
		}
		printf("\n");
	}

}

int main() {
	float mat1[20][30], mat2[30][20];
	int n, m;
	printf("Nr de linii n = ");
	scanf("%d", &n);
	printf("Nr de coloane m = ");
	scanf("%d", &m);
	citire(mat1, n, m);
	afisare(mat1, n, m);
	printf("\n-----------------------------------------\n");
	afisareTranspusa(mat1, mat2, n, m);
	return 0;
}