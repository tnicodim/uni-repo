#include<stdio.h>
#include<stdlib.h>

void matr(int** a, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("a[%d][%d]= ", i + 1, j + 1);
			scanf("%d", *a + i * m + j);
		}
	}
}
void afis(int** a, int n, int m) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			printf("%d ", *(*a + i * m + j));
		}
		printf("\n");
	}

}

void ad(int** a, int* n, int m) {
	int i, j, prod = 1, k;
	(*n)++;
	a[0] = realloc(a[0], ((*n) * m * sizeof(int)));
	for (j = 0; j < m; j++) {
		prod = 1;
		for (i = 0; i < *n - 1; i++)
			prod *= *(*a + i * m + j);
		*(*a + i * m + j) = prod;
	}
}
int main() {
	int** a, n, m, i, ** b;

	printf("Nr.linii: "); scanf("%d", &n);
	printf("Nr. coloane: "); scanf("%d", &m);

	a = (int**)malloc(n * sizeof(int*));
	a[0] = (int*)malloc(n * m * sizeof(int));
	matr(a, n, m);
	afis(a, n, m);
	ad(a, &n, m);
	printf("\n");
	afis(a, n, m);
	return 0;
}