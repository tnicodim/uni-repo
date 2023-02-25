#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//Tolico Nicodim test grupa 1_1 rand 1
//pr 1

int cmmcp(int n, int digits) {
	int i, aux, k, flag;
	aux = abs(n);
	k = -1;
	for (i = 0; i < digits; i++)
	{
		if ((aux % 10) % 2 == 0)
			if (aux % 10 > k)
				k = aux % 10;
		aux = aux / 10;
	}
	if (k != -1) {
		printf("\nCea mai mare cifra para din numarul %d este %d", n, k);
		return k;
	}
	else
	{
		printf("\nNumarul %d nu are cifre pare", n);
		return -1;
	}
}

int main() {
	int nr1, digits;
	printf("Introduceti un nr de maxim 15 cifre!: ");
	do {
		scanf("%d", &nr1);
		digits = log10(abs(nr1)) + 1;
	} while (digits > 15);
	cmmcp(nr1, digits);
	printf("\n\n");
	return 0;
}