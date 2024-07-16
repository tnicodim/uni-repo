#include <stdio.h>

void sort_selectie(int a[], int n) {
	int i, j, k_min, min;
	for (i = 0; i < 3; i++) {
		k_min = i;
		min = a[i];
		for (j = i; j < 4; j++)
			if (min > a[j]) {
				k_min = j;
				min = a[j];
			}
		a[k_min] = a[i];
		a[i] = min;
	}
}

void afisare(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

int main() {
	int a[11] = { 8,16,17,12,11,1,2,16,9,18 };
	int n = 10;
	afisare(a, n);
	sort_selectie(a, n);
	afisare(a, n);
	return 0;
}