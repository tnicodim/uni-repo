/*Sa se scrie un program in C care, folosind un meniu interactiv se pot realiza urmatoarele:
0. Iesire
1. Citirea unui vector cu n elemente numere intregi
2. Afisarea elementelor vectorului
3. Afisarea sumei elementelor pare ale vectorului – folosind operatii pe biti
4. Afisarea produsului elementelor impare ale vectorului – folosind operatii pe biti
5. Afisarea elementelor vectorului in ordine crescatoare
6. Afisarea elementelor vectorului care sunt divizibile cu un numar precizat de utilizator de
la tastatura
7. Sa se afiseze elementul cel mai mare al vectorului
8. Sa se afiseze elementul cel mai mic al vectorului
9. Sa se calculeze produsul dintre elementul pozitiv cel mai mic al vectorului cu elementul
cel mai mare al vectorului.
10. Afisarea mediei aritmetice a elementelor vectorului
11. Sa se adune la toate elementele pare ale vectorului un numar precizat de utilizator de la
tastatura, apoi sa se afiseze noul vector.
*/


//Se va folosi alocarea dinamica a memoriei

#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	int* a, *b;
	int opt, ok = 0, n, i, j, evensum = 0, oddproduct = 1, aux, max, min, sort;
	float ma;
	system("color 3");
	printf("\nIntroduceti nr de elemente in vector = ");
	scanf("%d", &n);
	a = (int*)malloc(n * sizeof(int));
	for (i = 0; i < n; i++)
	{
		printf("\na[%d] = ", i);
		scanf("%d", a + i);
	}
	ok = 1;
	while (1)
	{
		printf("\n0. Iesire\n1. Citirea unui vector cu n elemente numere intregi\n2. Afisarea elementelor vectorului\n3. Afisarea sumei elementelor pare ale vectorului folosind operatii pe biti\n4. Afisarea produsului elementelor impare ale vectorului folosind operatii pe biti\n5. Afisarea elementelor vectorului in ordine crescatoare\n6. Afisarea elementelor vectorului care sunt divizibile cu un numar precizat de utilizator de la tastatura\n7. Sa se afiseze elementul cel mai mare al vectorului\n8. Sa se afiseze elementul cel mai mic al vectorului\n9. Sa se calculeze produsul dintre elementul pozitiv cel mai mic al vectorului cu elementul cel mai mare al vectorului.\n10. Afisarea mediei aritmetice a elementelor vectorului\n11. Sa se adune la toate elementele pare ale vectorului un numar precizat de utilizator de la tastatura, apoi sa se afiseze noul vector.");
		printf("\n\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		printf("\n");
		switch (opt)
		{
		case 0:
			printf("\nAti iesit cu succes!\n");
			exit(0);
			break;
		case 1:
			printf("\nIntroduceti nr de elemente in vector = ");
			scanf("%d", &n);
			a = (int*)malloc(n * sizeof(int));
			for (i = 0; i < n; i++)
			{
				printf("\na[%d] = ", i);
				scanf("%d", a + i);
			}
			ok = 1;
			break;
		case 2:
			if (ok)
			{
				for (i = 0; i < n; i++)
					printf("%d ", *(a + i));
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 3:
			if (ok)
			{
				for (i = 0; i < n; i++)
					if ((*(a + i) & 1) == 0)
						evensum += *(a + i);
				printf("\nSuma numerelor pare = %d", evensum);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 4:
			if (ok)
			{
				for (i = 0; i < n; i++)
					if ((*(a + i) & 1) == 1)
						oddproduct *= *(a + i);
				printf("\nProdusul numerelor impare = %d", oddproduct);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 5:
			if (ok)
			{
				//conditia la case 5 este doar sa afisam vectorul in ord crescatoare, nu sa il modificam
				//	de aceea vom folosi un vector auxiliar b;
				b = (int*)malloc(n * sizeof(int));
				for (i = 0; i < n; i++)
					*(b+i) = *(a+i);
				do
				{
					sort = 1;
					for (i = 0; i < n - 1; i++)
					{
						if (*(b + i) > *(b + i + 1))
						{
							aux = *(b + i);
							*(b + i) = *(b + i + 1);
							*(b + i + 1) = aux;
							sort = 0;
						}
					}
				} while (!sort);
				printf("\nMatricea in ordine crescatoare este: ");
				for (i = 0; i < n; i++)
					printf("%d ", *(b + i));
				free(b);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 6:
			if (ok)
			{
				printf("\nIntroduceti divizorul = ");
				scanf("%d", &aux);
				printf("\nNumerele divizibile cu %d sunt: ", aux);
				for (i = 0; i < n; i++)
					if ((*(a + i) % aux) == 0)
						printf("%d ", *(a + i));
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 7:
			if (ok)
			{
				max = *a;
				for (i = 1; i < n; i++)
					if (max < *(a + i))
						max = *(a + i);
				printf("\nElementul max din vector este = %d", max);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 8:
			if (ok)
			{
				min = *a;
				for (i = 1; i < n; i++)
					if (min > *(a + i))
						min = *(a + i);
				printf("\nElementul min din vector este = %d", min);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 9:
			if (ok)
			{
				max = *a;
				for (i = 1; i < n; i++)
					if (max < *(a + i))
						max = *(a + i);
				min = max;
				for (i = 0; i < n; i++)
					if ((min > *(a + i)) && (*(a + i) > 0))
						min = *(a + i);
				if (min > 0)
					printf("\nProdusul dintre max si min pozitiv din vector este = %d", max * min);
				else
					printf("\nNu au fost gasite valori > 0 pentru min");
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 10:
			if (ok)
			{
				aux = 0;
				for (i = 0; i < n; i++)
					aux += *(a + i);
				ma = (float)aux / n;
				printf("\nMedia aritmetica a elementelor din vector este = %.2f", (float)aux / n);
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		case 11:
			if (ok)
			{
				printf("\nIntroduceti nr care va fi adunat = ");
				scanf("%d", &aux);
				printf("\nNoul vector este: ");
				for (i = 0; i < n; i++)
					if ((*(a + i) & 1) == 0)
						printf("%d ", *(a + i) + aux);
					else
						printf("%d ", *(a + i));
			}
			else
				printf("\nNu ati introdus vectorul!");
			break;
		default:
			printf("\nOptiune gresita, incearca din nou");
			break;
		}
		printf("\n\n");
	}
	return 0;
}