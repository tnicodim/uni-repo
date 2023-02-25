/*5. Sa se scrie un program C care afiseaza cifra unitarilor unei variabile de tip intreg. */

#include <stdio.h>

int main()
{
	int x;
	printf("\nIntroduceti un numar intreg: ");
	scanf("%d", &x);
	printf("\nCifra unitarilor acestui numar este: %d\n", x % 10);
	return 0;
}