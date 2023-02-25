#include <stdio.h>
#include <stdlib.h>
#define N 9

void afisare(int a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void insertie(int a[], int n) {
	int i,j,aux;
	for (i = 1; i < n; i++) {
		j = i - 1;
		aux = a[i];
		while (a[j] > aux && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
	}
}

void selectie(int a[], int n) {
	int i, j, k_min, min;
	for (i = 0; i < n-1; i++) {
		k_min = i;
		min = a[i];
		for (j = i; j < n; j++)
			if (min > a[j]) {
				k_min = j;
				min = a[j];
			}
			a[k_min] = a[i];
			a[i] = min;
	}
}

void selectieP(int a[], int n) {
	int i, j, k_min, aux;
	for (i = 0; i < n - 1; i++) {
		k_min = i;
		for (j = i; j < n; j++)
			if (a[k_min] > a[j])
				k_min = j;
		aux = a[k_min];
		a[k_min] = a[i];
		a[i] = aux;
	}
}

void interschimbare(int a[], int n) {
	int i, j, aux;
	for (i = 1; i < n; i++) {
		for(j=n-1;j>=i;j--)
			if (a[j] < a[j - 1]) {
				aux = a[j];
				a[j] = a[j - 1];
				a[j - 1] = aux;
			}
	}
}

int citire_fisier(int a[]) {
	int i;
	FILE* f = NULL;
	i = 0;
	if ((f = fopen("names.txt", "rt")) == NULL)			//rt = read text
		printf("\nFisierul nu exista!");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a[i]);
			i++;
		}
		fclose(f);
	}
	return i;
}

int main() {
	int a[N];
	citire_fisier(a);
	afisare(a, N);
//	insertie(a, N);
//	selectie(a, N);
	interschimbare(a, N);
	afisare(a, N);
	return 0;
}