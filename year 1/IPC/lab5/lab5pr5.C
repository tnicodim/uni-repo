/* 5. Sa se scrie un program in C care sa citeasca de la tastatura o matrice patratica. Sa se creeze
un meniu interactive cu urmatoarele optiuni:
1. Afisarea matricii patratice
2. Sa se afiseze suma numerelor pare deasupra diagonalei principale
3. Sa se afiseze produsul elementelor impare de pe diagonal secundara
4. Sa se afiseze elementele prime din matrice
5. Iesire*/

#include <stdio.h>
#include <stdlib.h>
#define citire(x) scanf("%d", &x)

int main()
{
	int v[10][10], n, optiune, i, j, sum, p, prime, k;
	printf("\nIntroduceti marimea matricei patratice v = ");
	citire(n);
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			printf("\nv[%d][%d]= ", i + 1, j + 1);
			scanf("%d", &v[i][j]);
		}
	while (1)
	{
		prime, sum = 0;
		p = 1;
		printf("\n1. Afisarea matricii patratice\n2. Afisarea suma numerelor pare deasupra diagonalei principale\n3. Afisarea produsul elementelor impare de pe diagonala secundara\n4. Afisarea elementelor prime din matrice\n5. Iesire\nIntroduceti optiunea dorita: ");
		citire(optiune);
		switch (optiune)
		{
		case 1:
			for (i = 0; i < n; i++)
			{
				printf("\n");
				for (j = 0; j < n; j++)
					printf("%3d", v[i][j]);
			}
			printf("\n");
			break;
		case 2:
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if ((i < j) && ((v[i][j] % 2) == 0))
							sum += v[i][j];
				}
			printf("\nSuma numerelor pare deasupra diagonalei principale este: %d", sum);
			break;
		case 3:
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					if (((i + j) == (n - 1)) && ((v[i][j] % 2) == 1))
						p *= v[i][j];
				}
			printf("\nProdusul elem impare de pe diagonala secundara este: %d", p);
			break;
		case 4:
			for (i = 0; i < n; i++)
				for (j = 0; j < n; j++)
				{
					prime = 0;
					for (k = 1; k <= v[i][j]; k++)
						if ((v[i][j] % k) == 0)
							prime++;
					if (prime > 2)
						continue;
					else 
						printf("\n%d este numar prim", v[i][j]);
				}
			printf("\n");
			break;
		case 5:
			printf("\nAti iesit cu success din program!");
			exit(0);
			break;
		default:
			printf("\nAti introdus o optiune inexistenta, incercati din nou!");
			break;
		}
	}
	system("pause");
	return 0;
}