/*Plecand de la orice numar intreg pozitiv:
Daca nr este par: n = n/2
Daca nr este impar: n = 3*n + 1
Procesul continua pana cand n = 1
Sa se afiseze si nr de pasi necesari pentru a a junge la 1;
*/

#include <stdio.h>

int main()
{
	int n,pasi=0;
	printf("\nDati numarul natural n= ");
	scanf("%d", &n);
	while (n != 1)
	{
		if (n % 2 == 0)
		{
			printf("\n%d este par, atunci il impartim la 2: %d", n, n / 2);
			n /= 2;
		}
		else
		{
			printf("\n%d este impar, atunci calculam (3*n+1): %d", n, n * 3 + 1);
			n = 3 * n + 1;
		}
			pasi++;
	}
	printf("\nNumarul de pasi este %d", pasi);
	return 0;
}