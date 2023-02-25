/* Sa se scrie un program care sa implementeze urmatorul meniu interactiv:
1. Citirea unui vector de la tastatura cu elem de tip intreg
2. Afisarea vectorului
3. Sa se numere de cate ori apare un anumit elem citit de la tastatura in vector
4. Sa se calculeze min si max din vector
5. Sa se sorteze vectorul descrescator
6. Sa se calculeze cel mai mare div comun al vectorului
0. Iesire
*/


#include <stdio.h>
#include <stdlib.h>

int main()
{
	int vector[20];
	int iesire, cmmdc, aux, max, min, k, elemcautat, n, i, j, optiune, ok;
	ok = 0;
	iesire = 0;
	while (1)
	{
		if (iesire == 1)
			break;
		printf("\n1. Citirea unui vector de la tastatura cu elem de tip intreg");
		printf("\n2. Afisarea vectorului");
		printf("\n3. Sa se numere de cate ori apare un anumit elem citit de la tastatura in vector");
		printf("\n4. Sa se calculeze min si max din vector");
		printf("\n5. Sa se sorteze vectorul descrescator");
		printf("\n6. Sa se calculeze cel mai mare div comun al vectorului");
		printf("\n0. Iesire");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &optiune);
		switch (optiune)
		{
		case 1:
		{
			ok = 1;
			printf("\nDati nr de elemente:");
			scanf("%d", &n);
			for (i = 0; i < n; i++)
			{
				printf("\nIntroduceti elementul de pe pozitia %d a vectorului: ",i);
				scanf("%d", &vector[i]);
			}
			break;
		}
		case 2:
		{
			if (ok)
			{
				for (i = 0; i < n; i++)
				{
					printf("%d ", vector[i]);
				}
			}
			else
				printf("\nApasati tasta 1 pentru a citi vectorul!");
			break;

		}
		case 3:
		{
			if (ok)
			{
				k = 0;
				printf("\nIntroduceti nr cautat: ");
				scanf("%d", &elemcautat);
				for (i = 0; i < n; i++)
				{
					if (elemcautat == vector[i])
						k++;
				}
				printf("\nNumarul %d se intalneste de %d ori in vector", elemcautat, k);
			}
			else
				printf("\nApasati tasta 1 pentru a citi vectorul!");
			break;
		}
		case 4:
		{
			if (ok)
			{
				max = vector[0];
				min = vector[0];
				for (i = 0; i < n; i++)
				{
					if (vector[i] > max)
						max = vector[i];
					if (vector[i] < min)
						min = vector[i];
				}
				printf("\nMax din vector este %d", max);
				printf("\nMin din vector este %d", min);
			}
			else
				printf("\nApasati tasta 1 pentru a citi vectorul!");
			break;
		}
		case 5:
		{
			if (ok)
			{
				for (i = 0; i < n-1; i++)
					for (j = i + 1; j < n; j++)
						if (vector[i] < vector[j])
						{
							aux = vector[i];
							vector[i] = vector[j];
							vector[j] = aux;
						}
			}
			else
				printf("\nApasati tasta 1 pentru a citi vectorul!");
			break;
		}
		case 6:
		{
			if (ok)
			{
				cmmdc = vector[0];
				for (i = 1; i < n; i++)
				{
					aux = vector[i];
					while (aux != cmmdc)
					{
						if (aux > cmmdc)
							aux = aux - cmmdc;
						else if (aux < cmmdc)
							cmmdc = cmmdc - aux;
					}
				}
				printf("\nCel mai mare divizor comun = %d", cmmdc);
			}
			else
				printf("\nApasati tasta 1 pentru a citi vectorul!");
			break;
		}
		case 0:
		{
			iesire = 1;
			break;
		}
		default:
			printf("\nOptiune gresita");
			break;
		}
	}
	system("pause");
	return 0;
}