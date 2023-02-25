/*2. Sa se scrie un program in C care, folosind un meniu interactiv sa contina urmatoarele
optiuni:
1. Citirea unui vector cu n elemente
2. Afisarea vectorului
3. Afisarea elementelor de pe poziitile pare
4. Afisarea produsului elementelor impare
5. Iesire */

#include <stdlib.h>
#include <stdio.h>
#define citire(x) scanf("%d", &x)
int main()
{
	int optiune, v[20], i, p, k, n;
	n,k = 0;
	while (1)
	{
		p = 1;
		printf("\n1. Citirea unui vector cu n elemente\n2. Afisarea vectorului\n3. Afisarea elementelor de pe poziitile pare\n4. Afisarea produsului elementelor impare\n5. Iesire\n\nIntroduceti optiunea dorita: ");
		citire(optiune);
		switch (optiune)
		{
		case 1:
			printf("\nIntroduceti nr de elem pentru vectorul v = ");
			citire(n);
			for (i = 0; i < n; i++)
			{
				printf("\nv[%d] = ", i);
				citire(v[i]);
			}
			k = 1;
			break;
		case 2:
			if (k != 1)
			{
				printf("\n---Nu ati introdus vectorul n!---\n");
				break;
			}
			printf("\n");
			for (i = 0; i < n; i++)
				printf("%d ",v[i]);
			printf("\n");
			break;
		case 3:
			if (k != 1)
			{
				printf("\n---Nu ati introdus vectorul n!---\n");
				break;
			}
			printf("\nElementele de pe pozitiile pare sunt:\n");
			for (i = 0; i < n; i = i + 2)
				printf("%d ", v[i]);
			break;
		case 4:
			if (k != 1)
			{
				printf("\n---Nu ati introdus vectorul n!---\n");
				break;
			}
			for (i = 0; i < n; i++)
			{
				if ((v[i] % 2) == 1)
					p *= v[i];
			}
			printf("\nProdusul elementelor impare este: %d", p);
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
}