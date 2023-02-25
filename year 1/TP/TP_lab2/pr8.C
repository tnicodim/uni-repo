/*
Funcție pentru construirea unei matrici pătratice cu primele n*n pătrate perfecte
*/

#include <stdio.h>
#include <stdlib.h>

void matrPatratica(int a[10][10], int n) {
	int i, j, k;
	k = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			a[i][j] = k * k;
			k++;
		}
}

void afisare(int a[10][10], int n) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%6d ", a[i][j]);
		}
		printf("\n");
	}
}

int main(){
	int a[10][10];
	int n;
	printf("Marimea matricei = ");
	scanf("%d", &n);
	matrPatratica(a, n);
	afisare(a, n);
	return 0;
}