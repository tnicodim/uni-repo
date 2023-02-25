/*Se citeste un numar n. Sa se calculeze produsul cifrelor pare din numar.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int n,digits, produs = 1;
	printf("Introduceti un nr natural n: ");
	scanf("%d", &n);
	digits = log10(n) + 1; // Gasim cate cifre avem in nr n
	for (int i = 1; i <= digits; i++)
	{
		if ((n % 10) % 2 == 0)
			produs *= n % 10;
		n = n / 10;
	}
	printf("\nProdusul cifrelor pare din numarul introdus este %d\n", produs);
	system("pause");
	return 0;
}