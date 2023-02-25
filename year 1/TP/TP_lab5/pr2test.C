#include <stdio.h>
#include <stdlib.h>

//Tolico Nicodim test grupa 1_1 rand 1
//pr 2

int n = 20;

void inserare(int* v) {
	int i, j;
	int* vaux;
	vaux = (int*)malloc(sizeof(int) * 10);
	for (i = 0; i < 10; i++)
		*(vaux + i) = *(v + i);
	i = 0;
	for (j = 1; j <= n; j += 2) {
		*(v + j) = *(vaux + i)*3;
		(*(v + j - 1)) = *(vaux + i);
		i++;
	}
}


int main() {
	int v[25] = { 2, -3, 4, 24, -15, 0, 12, 10, -5, 11 };
	int i;
	inserare(v);
	printf("\nVectorul v este:\n");
	for (i = 0; i < n; i++)
		printf("%d  ", *(v + i));
	printf("\n\n");
	return 0;
}