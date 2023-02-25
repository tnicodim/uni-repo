/* Prin intermediul unui program C, se citește de la tastatură un număr natural n<=110. Se
mai citesc, prin intermediul unei functii, apoi, cele n elementele întregi ale unui vector v[n].
Realizati o funcție pentru sortarea crescătoare a elementelor naturale cu valoare impară a vectorului v[] si
o functie care afiseaza elementele inainte si dupa sortare
*/



#include <stdio.h>
#include <stdlib.h>

void citire(int a[],int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("a[%d]= ",i);
		scanf("%d", &a[i]);
	}
}

void sortareCresc(int a[], int n) {
	int i,j, aux;
	for (i = 0; i < n - 1; i++) {
		if (a[i] % 2 != 1)
			continue;
		for (j = i + 1; j < n; j++)
		{
			if (a[j] % 2 != 1)
				continue;
			if (a[i] > a[j]) {
				aux = a[i];
				a[i] = a[j];
				a[j] = aux;
			}
		}
	}
}

void printareVectori(int a[], int b[], int n) {
	int i;
	printf("\nVectorul initial:\n");
	for (i = 0; i < n; i++)
		printf("%d ", b[i]);
	printf("\nVectorul cu elementele impare sortate crescator:\n");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n\n\n");
}

int main() {
	int a[110], b[110], n, i;
	printf("Introduceti numarul de elemente din vector (<=110): ");
	scanf("%d", &n);
	citire(a, n);
	for (i = 0; i < n; i++)
		b[i] = a[i];
	sortareCresc(a, n);
	printareVectori(a, b, n);
	return 0;
}