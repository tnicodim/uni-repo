/* 2. Sa se scrie un program C care afiseaza produsul a doua variabile întregi, citite de la
tastatura. */

#include <stdio.h>

int main()
{
	int a, b;
	printf("\nIntroduceti valoarea lui a: ");
	scanf("%d", &a);
	printf("\nIntroduceti valoarea lui b: ");
	scanf("%d", &b);
	printf("\nProdusul numerelor a si b este: %d\n", a * b);
	return 0;
}