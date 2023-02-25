/* Sa se scrie un program in C care citeste de la tastatura un numar intreg
si afiseaza daca acesta este numar prim sau nu. */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int x, k = 0;
	printf("Introduceti un nr natural x: ");
	scanf("%d", &x);
	for (int i = 2; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			k = 1;
			printf("\n\nNumarul %d nu este prim.",x);
			break;
		}
	}
	if (k == 0)
		printf("\n\nNumarul %d este prim.", x);
	system("pause");
	return 0;
}
