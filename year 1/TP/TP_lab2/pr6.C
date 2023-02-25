/*
Funcție pentru adaugarea unei noi linii cu elemente nule, dupa linia de indice 2 in matricea
a[26][25]
*/

#include <stdio.h>
#include <stdlib.h>

void citire(int a[26][25], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			printf("a[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
}
void afisare(int a[26][25], int n, int m) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
}

void new_line_0(int a[26][25], int n, int m) {
	int i, j, v[25], v2[25];
	for (i = 1; i < n+1; i++)
		for (j = 0; j < m; j++) {
			if (i == 1) {
				v[j] = a[i][j];
				v2[j] = a[i + 1][j];
				a[i][j] = 0;
				a[i + 1][j] = v[j];
			}
			else
			{
				a[i][j] = v[j];
				v[j] = v2[j];
				v2[j] = a[i + 1][j];
			}
		}
}



int main() {
	float a[26][25];
	int n, m;
	printf("Nr de linii n = ");
	scanf("%d", &n);
	printf("Nr de coloane m = ");
	scanf("%d", &m);
	citire(a, n, m);
	afisare(a, n, m);
	printf("\n-----------------------------------------\n");
	new_line_0(a, n, m);
	afisare(a, n+1, m);
	return 0;
}