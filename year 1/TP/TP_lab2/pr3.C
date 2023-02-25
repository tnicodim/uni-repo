/*
Se citesc de la tastatură m și n, fiecare mai mici decat 10. Să se creeze o matrice în care la fiecare
poziție să fie maximul indecșilor acelei poziții și să se afișeze matricea.
*/

#include <stdio.h>
#include <stdlib.h>


void citire(int a[10][10], int n, int m) {
	int i, j, max;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			if (i > j)
				max = i;
			else
				max = j;
			a[i][j] = max;
		}
}

void afisare(int a[10][10], int n, int m) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	printf("\n\n\n");
}

int main() {
	int a[10][10];
	int n,m;
	printf("Numarul de linii n = ");
	scanf("%d", &n);
	printf("Numarul de coloane m = ");
	scanf("%d", &m);
	citire(a, n, m);
	afisare(a, n, m);
	return 0;
}