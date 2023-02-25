/*
Se citește de la tastatură un număr natural n<=25. Se citesc apoi, folosind o functie citire()
elementele întregi ale unei matrici a[n][n]. Realizati o funcție pentru suma elementelor intregi, pare aflate
deasupra diagonalei principale a matricei a[25][25]
*/


#include <stdio.h>
#include <stdlib.h>

void citire(int a[25][25], int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
}
void afisare(int a[25][25], int n) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

int sumTopRightEven(int a[25][25], int n) {
	int i, j, sum;
	sum = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (i < j && (a[i][j] % 2 == 0))
				sum += a[i][j];
		}
	}
	return sum;
}

int main() {
	int a[25][25];
	int n;
	printf("Dimensiunea matricei n = ");
	scanf("%d", &n);
	citire(a, n);
	afisare(a, n);
	printf("\nSuma elementelor pare aflate deasupra diagonalei principale este %d\n\n\n", sumTopRightEven(a, n));
	return 0;
}