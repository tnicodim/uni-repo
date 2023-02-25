#include <stdio.h>
#include <stdlib.h>

void deplasare(int a[], int s, int d) {
	int i, j, test, x;
	i = s; j = 2 * i;
	x = a[i];
	test = 1;
	while (j <= d && test == 1) {
		if (j < d)
			if (a[j] < a[j + 1])
				j++;
			if (x < a[j]) {
					a[i] = a[j];
					i = j;
					j = 2 * i;
				}
				else
					test = 0;
	}
	a[i] = x;
}

void HeapSort(int a[], int n) {
	int s, d, aux;
	s = n / 2 + 1;
	d = n;
	while (s > 1) {
		s--;
		deplasare(a, s, d);
	}
	while (d > 0) {
		aux = a[1];
		a[1] = a[d];
		a[d] = aux;
		d--;
		deplasare(a, 1, d);
	}
}

void afisare(int a[], int n) {
	int i;
	for (i = 1; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int a[11] = { 0,6,3,10,9,8,7,1,2,13,11 };
	int n = 11;
	afisare(a, n);
	HeapSort(a, n-1);
	afisare(a, n);
	return 0;
}