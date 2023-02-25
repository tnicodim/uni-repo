#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
P4: Se defineste o structura „Punct” cu membrii „a” si „b”numere reale.
Se cere o valoare v<=10 si apoi v puncte. Sa se calculeze distanta dintre cele mai
apropiate doua puncte si sa se afiseze.
Se va folosi din <math.h> functia „sqrt” (square root), pentru extragerea radicalului. 
*/

typedef struct {
	double a, b;
}Punct;

void citire(Punct* p, int* n) {
	(*n)++;
	printf("\na=");
	scanf("%lf", &(p + *n)->a);
	printf("b=");
	scanf("%lf", &(p + *n)->b);
}

void afisareDistMin(Punct* p, int n) {
	int i, j, k1 = 0, k2 = 1; 
	double min, d;
	min = sqrt(pow(p->a - (p + 1)->a, 2) + pow(p->b - (p + 1)->b, 2));
	for (i=0;i<n;i++)
		for (j=i+1;j<=n;j++)
			if (sqrt(pow((p+i)->a - (p + j)->a, 2) + pow((p+i)->b - (p + j)->b, 2)) < min) {
				min = sqrt(pow((p + i)->a - (p + j)->a, 2) + pow((p + i)->b - (p + j)->b, 2));
				k1 = i;
				k2 = j;
			}
	printf("\n\nPunctele %d si %d sunt cele mai apropiate:\na%d=%.3lf\nb%d=%.3lf\n\na%d=%.3lf\nb%d=%.3lf\n\ndistance = %.3lf", k1, k2, k1, (p+k1)->a, k1, (p + k1)->b, k2, (p + k2)->a, k2, (p + k2)->b, min);
}

int main() {
	Punct p[10];
	int i, nr, n = -1;
	printf("Nr de puncte: ");
	scanf("%d", &nr);
	for (i = 0; i < nr; i++)
		citire(p, &n);
	afisareDistMin(p, n);
	return 0;
}