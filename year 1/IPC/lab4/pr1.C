// sa se calculeze suma n primelor n numere naturale folosind
// for, while, do while loop. se va implementa si un meniu

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, opt;
	printf("\nDati un nr natural n=");
	scanf("%d", &n);
	do 
	{
		int total = 0;
		int i = 0;
		printf("\n1. For loop");
		printf("\n2. While loop");
		printf("\n3. Do while loop");
		printf("\n4. Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
		{
			for (i = 1; i <= n; i++)
				total += i;
			printf("\nSuma este %d", total);
		}
			break;
		case 2:
		{
			while (i <= n)
			{
				total += i;
				i++;
			}
			printf("\nSuma este: %d",total);
			break;
		}
		case 3:
		{
			do
			{
				total += i;
				i++;
			}
				while(i <= n);
			printf("Suma este: %d\n", total);
			break;
		}
		case 4:
		{
			break;
		}
		default:
		{
			break;
		}
		}
		if (opt == 4)
			break;
	} while (1);
	system("pause");
	return 0;
}