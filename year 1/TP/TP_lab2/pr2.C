/* Se citește de la tastatură un număr natural n<=10. Se citesc apoi elementele întregi ale unei
matrici a[n][n]. Să se afișeze dacă matricea „a” este o matrice unitate. Notă: o matrice unitate are pe diagonala
principală 1 și în rest 0.
*/


#include <stdio.h>
#include <stdlib.h>

void citire(int a[10][10], int n) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
}
void afisare(int a[10][10], int n) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void matrUnitate(int a[10][10], int n) {
	int flag, i, j;
	flag = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (i == j)
				if (a[i][j] != 1) {
					flag = 0;
					goto jump;
				}
			if (i != j)
				if (a[i][j] != 0) {
					flag = 0;
					goto jump;
				}


		}
jump:
	if (flag)
		printf("\nMatricea introdusa este matrice unitate\n\n");
	else
		printf("\nMatricea introdusa NU este matrice unitate\n\n");
}

int main() {
	int a[10][10];
	int n;
	printf("Dimensiunea matricii n=");
	scanf("%d", &n);
	citire(a, n);
	afisare(a, n);
	matrUnitate(a, n);
	return 0;
}