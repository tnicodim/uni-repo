#include <stdio.h>
#include <math.h>

/*3. Sa se realizeze un program care citeste doua numere reale de la tastaura si apoi afiseaza
un meniu cu urmatoarele optiuni:
1. Suma numerelor introduse
2. Diferenta numerelor introduse
3. Produsul numerelor introdue
4. Raportul numerelor introduse
5. Iesire
Optiunea dvs: */

int main()
{
	float a, b;
	int k;
	k = 0;
	printf("\nIntroduceti a: ");
	scanf("%f", &a);
	printf("\nIntroduceti b: ");
	scanf("%f", &b);
	while (k != 5)
	{
		printf("\n1. Suma numerelor introduse\n2. Diferenta numerelor introduse\n3. Produsul numerelor introduse\n4. Raportul numerelor introduse\n5. Iesire\n\n");
		printf("Optiunea dvs: ");
		scanf("%d", &k);
		switch (k)
		{
		case 1:
		{
			printf("\nSuma numerelor introduse este: %.2f", a + b);
			break;
		}
		case 2:
		{
			printf("\nDiferenta numerelor introduse este: %.2f", a - b);
			break;
		}
		case 3:
		{
			printf("\nProdusul numerelor introduse este: %.2f",a * b);
			break;
		}
		case 4:
		{
			printf("\nRaportul numerelor introduse este: %.2f", a / b);
			break;
		}
		case 5:
		{
			printf("\nA-ti iesit cu success din program\n\n\n");
			break;
		}
		default:
			printf("Asa optiune nu exista");
			break;
		}
	}
	return 0;
}