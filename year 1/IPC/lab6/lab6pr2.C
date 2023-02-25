/*
1. Citire matrice
2. Afisare matrice
3. Suma elem prime de pe o anumita linie citita de la tastatura
4. Sa se afiseze elem pe cadrul matricii care au minim 2 cifre
0. Iesire
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a[10][10], k, i, j, opt, n, l, primesum = 0, prime = 0, digits = 0;
	while (1)
	{
		printf("\n1. Citire matrice\n2. Afisare matrice\n3. Suma elem prime de pe o anumita linie citita de la tastatura\n4. Sa se afiseze elem pe cadrul matricii care au minim 2 cifre\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(0);
			break;
		case 1:
			printf("\nIntroduceti marimea matricei patratice: ");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					printf("\na[%d][%d] = ", i + 1, j + 1);
					scanf("%d", &a[i][j]);
				}
			break;
		case 2:
			for (i = 0; i < n; i++)
			{
				printf("\n");
				for (j = 0; j < n; j++)
					printf("%d ", a[i][j]);
			}
			break;
		case 3:
			primesum = 0;
			printf("\nIntroduceti linia dorita: ");
			scanf("%d", &l);
			i = l - 1;
			for (j = 0; j < n; j++)
			{
				prime = 1;
				for (k = 2; k < a[i][j] / 2; k++)
					if ((a[i][j] % k) == 0)
						prime = 0;
				if (prime == 1)
					primesum += a[i][j];
			}
			printf("\nSuma nr prime de pe linia %d este %d", l, primesum);
			break;
		case 4:
			printf("\nElementele care au cel putin 2 cifre sunt: ");
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					digits = log10(a[i][j]) + 1; // Gasim cate cifre avem in nr a[i][j]
					if (digits >= 2)
						printf("%d ", a[i][j]);
				}
			break;
		default:
			printf("\nNu exista asa optiune!\n");
			break;
		}
	}
	system("pause");
	return 0;
}