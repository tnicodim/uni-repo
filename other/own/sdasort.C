#include <stdio.h>
#include <stdlib.h>

//NT248 RRR

int n, it;

void sort_insertie(int a[], int n) {
	int i, j, aux;
	for (i = 1; i <= it; i++) {
		j = i - 1;
		aux = a[i];
		while (a[j] > aux && j >= 0) {
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = aux;
	}
}

void sort_selectie(int a[], int n) {
	int i, j, k_min, min;
	for (i = 0; i < it; i++) {
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

void sort_interschimbare(int a[], int n) {
	int i, j, aux;
	for (i = 1; i <= it; i++) {
		for (j = n - 1; j >= i; j--)
			if (a[j] < a[j - 1]) {
				aux = a[j];
				a[j] = a[j - 1];
				a[j - 1] = aux;
			}
	}
}

void sort_amestecare(int a[], int n) {
	int i, j, k, aux, s, d;
	s = 1; d = n - 1;
	do {
		for (i = d; i >= s; i--)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		s = k + 1;
		for (i = s; i <= d; i++)
			if (a[i - 1] > a[i]) {
				aux = a[i];
				a[i] = a[i - 1];
				a[i - 1] = aux;
				k = i;
			}
		d = k - 1;
	} while (s <= d);
}

void sort_Shell(int a[], int n) {
	int m, i, j, k, aux, ii = 0;
	int h[10];
	printf("\nVector of increments (exit==-1):\n");
	do
	{
		scanf("%d", &h[ii]);
		ii++;
	} while (h[ii-1]!=-1);
	for (m = 0; m < it; m++) {
		k = h[m];
		for (i = k; i < n; i++) {
			aux = a[i];
			j = i - k;
			while (a[j] > aux && j >= 0)
			{
				a[j + k] = a[j];
				j = j - k;
			}
			a[j + k] = aux;
		}
	}
}

void afisare(int a[]) {
	int i;
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nTablou:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
}

int sort_Qsort(int a[], int n, int s, int d) {
	int i, j, x, aux, flag = 0;
	x = a[(s + d) / 2];
	i = s; j = d;
	do {
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j) {
			printf("\n!! %d cu %d\n", a[i], a[j]);
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	} while (i <= j);
	flag++;
	if (flag == it)
		return -600;
	if (s < j)
		sort_Qsort(a, n, s, j);
	if (d > i)
		sort_Qsort(a, n, i, d);
}


int main() {
	int v[20], opt,i;
	new_vector:
	i = 0;
	printf("Tablou (exit == -1):\n");
	do
	{
		scanf("%d", &v[i]);
		i++;
	} while (v[i - 1] != -1);
	n = i - 1;
	while (1) {
		bbb:
		afisare(v);
		printf("\nSortare:\n1. Insertie\n2. Selectie\n3. Interschimbare\n4. Shellsort\n5. QuickSort\n10. Tablou nou\n0. Exit\nOption:  ");
		scanf("%d", &opt);
		if (opt == 0)
			exit(-248);
		else if (opt == 10)
			goto new_vector;
		printf("Nr de iteratii: ");
		scanf("%d", &it);
		switch (opt) {
		case 1:
			sort_insertie(v,n);
			break;
		case 2:
			sort_selectie(v, n);
			break;
		case 3:
			sort_interschimbare(v, n);
			break;
		case 4:
			sort_Shell(v, n);
			break;
		case 5:
			sort_Qsort(v, n, 0, n - 1);
			break;
		default:
			printf("\nINVALID CHOICE");
			break;
		}
	}
	return 0;
}