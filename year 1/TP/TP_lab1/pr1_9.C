// Scrieţi o funcţie care parcurge un vector și returnează indicii elementelor minim şi maxim

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void citire(int a[], int size) {
	int i;
	for (i = 0; i < size; i++) {
			printf("a[%d]= ", i);
			scanf("%d", &a[i]);
		}
}

void minmaxvector(int a[], int size, int* imax, int* imin) {
	int i;
	for (i = 0; i < size; i++) {
		if (a[i] > a[*imax])
			*imax = i;
		if (a[i] < a[*imin])
			*imin = i;
	}
}

int main()
{
	int imax, imin, size;
	int v[20];
	imax = 0;
	imin = 0;
	printf("Numarul de elemente din matrice: ");
	scanf("%d", &size);
	citire(v, size);
	minmaxvector(v, size, &imax, &imin);
	printf("\nIndicele elementului minim este %d", imin);
	printf("\nIndicele elementului maxim este %d", imax);
	printf("\n");
	return 0;
}
