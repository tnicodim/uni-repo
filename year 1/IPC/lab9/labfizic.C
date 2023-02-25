/* Sa se creeze un meniu interactiv care efectueaza urm. operatii:
1. Citirea a 2 matrici de la tastatura (elem primei matrici nu se va citi diagonala principala, care va fi initializata cu 2) (matr 2 diag secund - 5)
2. Afisarea celor 2 matrici
3. Sa se sorteze crescator o anumita linie din ambele matrici dupa care sa se afiseze matricele modificate
4. Sa se faca suma celor 2 matrici (aij+bij) si sa se afiseze matricea suma
5. Sa se faca produsul elem de pe cadrul matricei doar pt elem pare
0. Iesire
*/

#include <stdio.h>
#include <stdlib.h>

void produscadru(int a[10][10], int n)
{
	int p = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || j == 0 || i == n - 1 || j == n - 1)
				if (a[i][j] % 2 == 0)
					p = p * a[i][j];
		}
	}
	printf("\nProdusul elementelor de pe cadrul matricii = %d\n", p);
}

void sortare(int m1[10][10], int m2[10][10], int n)
{
	int linie,i,j,ord, aux;
	printf("\nLinia pt sortare = ");
	scanf("%d", &linie);
	linie = linie - 1;
	do
	{
		ord = 1;
		for (j = 0; j < n-1; j++)
			if (m1[linie][j] > m1[linie][j + 1])
			{
				aux = m1[linie][j];
				m1[linie][j] = m1[linie][j + 1];
				m1[linie][j + 1] = aux;
				ord = 0;
			}
	} while (ord != 0);
	do
	{
		ord = 1;
		for (j = 0; j < n - 1; j++)
			if (m2[linie][j] > m2[linie][j + 1])
			{
				aux = m2[linie][j];
				m2[linie][j] = m2[linie][j + 1];
				m2[linie][j + 1] = aux;
				ord = 0;
			}
	} while (!ord);
}

void sum(int m1[10][10], int m2[10][10], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d ", m1[i][j] + m2[i][j]);
	}
	printf("\n\n");
}

void citire(int m1[10][10], int m2[10][10], int marime)
{
	int i, j;
	printf("Matricea 1:\n");
	for (i = 0; i < marime; i++)
		for (j = 0; j < marime; j++)
		{
			if (i == j)
			{
				m1[i][j] = 2;
				printf("m1[%d][%d] = %d\n", i+1, j+1, m1[i][j]);
			}
			else
			{
				printf("m1[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &m1[i][j]);
			}
		}
	printf("\nMatricea 2:\n");
	for (i = 0; i < marime; i++)
		for (j = 0; j < marime; j++)
		{
			if (i == marime - j - 1)
			{
				m2[i][j] = 5;
				printf("m2[%d][%d] = %d\n", i + 1, j + 1, m2[i][j]);
			}
			else
			{
				printf("m2[%d][%d] = ", i + 1, j + 1);
				scanf("%d", &m2[i][j]);
			}
		}

}

void afisare(int a[10][10], int n)
{
	int i, j;
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < n; j++)
			printf("%d ", a[i][j]);
	}
}

int main()
{
	int opt, mat1[10][10], mat2[10][10], marime;
	while (1)
	{
		printf("1. Citirea a 2 matrici de la tastatura\n2. Afisarea celor 2 matrici\n3. Sa se sorteze o anumita linie din ambele matrici dupa care sa se afiseze matricele modificate\n4. Sa se faca suma celor 2 matrici(aij + bij) si sa se afiseze matricea suma\n5. Produsul elementelor pare de pe cadrul matricii\n0. Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("\nMarimea matricelor = ");
			scanf("%d", &marime);
			citire(mat1, mat2, marime);
			break;
		case 2:
			printf("\nm1:\n");
			afisare(mat1, marime);
			printf("\n\nm2:\n");
			afisare(mat2, marime);
			printf("\n\n");
			break;
		case 3:
			sortare(mat1, mat2, marime);
			break;
		case 4:
			sum(mat1, mat2, marime);
			break;
		case 5:
			printf("\nProdusul pentru m1:");
			produscadru(mat1, marime);
			printf("\nProdusul pentru m2:");
			produscadru(mat2, marime);
			break;
		case 0:
			exit(0);
		default:
			printf("\n\tOptiune inexistenta!\n\n");
			break;
		}
	}
	return 0;
}