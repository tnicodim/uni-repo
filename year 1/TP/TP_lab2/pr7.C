/*
 Se citesc numerele m,n,p fiecare mai mici decat 10, apoi se citesc matricile a[m][n] și b[n][p]. Se
cere să se calculeze matricea „c” care rezultă din înmulțirea matricilor a cu b și să se afișeze.
*/

#include <stdio.h>
#include <stdlib.h>


void afisare(int a[10][10], int n, int m) {
	int i, j;
	printf("\n");
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%5d ", a[i][j]);
		}
		printf("\n");
	}
}

void citire(int a[10][10], int n, int m) {
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < m; j++) {
			printf("[%d][%d]=", i, j);
			scanf("%d", &a[i][j]);
		}
}

void multiply(int a[10][10], int b[10][10], int c[10][10], int m, int n, int p) {
	int i, j, k;
	for (i = 0; i < m; i++)
		for (j = 0; j < p; j++) {
			c[i][j] = 0;
			for (k = 0; k < n; k++)
				c[i][j] += a[i][k] * b[k][j];
		}
}

int main() {
	int a[10][10], b[10][10], c[10][10];
	int m, n, p;
	printf("nr de linii (a): ");
	scanf("%d", &m);
	printf("nr de coloane (a): ");
	scanf("%d", &n);
	printf("nr de coloane (b): ");
	scanf("%d", &p);
	printf("\nMATRICEA a:\n");
	citire(a, m, n);
	printf("\n\nMATRICEA b:\n");
	citire(b, n, p);
	multiply(a, b, c, m, n, p);
	afisare(a, m, n);
	afisare(b, n, p);
	afisare(c, m, p);
	return 0;
}








