#include <stdio.h>

void amestecare(int a[], int n) {
	int i, j, k, aux, s, d;
	s = 1; d = n - 1;
	do {
		for (i=d; i>=s; i--)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		s = k + 1;
		for (i=s; i<=d; i++)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		d = k - 1;
	} while (s <= d);
}

void assaf(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void Shell(int a[], int n) {
	int m, i, j, k, aux;
	int h[3] = { 3,2,1 };
	for (m = 0; m < 3; m++) {
		k = h[m];
		for (i = k; i < n; i++) {
			aux = a[i];
			j = i - k;
			while (a[j]>aux && j>=0)
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
	}
}

void Qsort(int a[], int n, int s, int d) {
	int i, j, x, aux;
	x = a[(s + d) / 2];
	i = s; j = d;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	if (s < j)
		Qsort(a, n, s, j);
	if (d > i)
		Qsort(a, n, i, d);
}

int main() {
	int a[10] = {1,0,3,2,10,7,9,8,11,6};
	int n = 10;
	assaf(a, n);
	//amestecare(a, n);
	//Shell(a, n);
	Qsort(a, n, 0, n - 1);
	assaf(a, n);
	return 0;
}