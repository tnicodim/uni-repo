/*
2. Sa se realizeze un program care sa rezolve o ecuatie de gradul 2 cu coeficientii cititi de la
tastatura, folosind o functie care sa returneze doua valori - radacinile, si sa precizeze daca are
sau nu radacini reale).
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void radacini(float a, float b, float c, float *x1, float *x2)
{
	float k;
	if (a == 0)
	{
		printf("\nEcuatia nu este de gradul II");
		*x1 = (-b / c);
		*x2 = (-b / c);
	}
	else
	{
		k = pow(b, 2) - 4 * a * c;
		if (k < 0)
		{
			printf("\nSolutiile ecuatiei sunt imaginare");
			*x1 = -999;
			*x2 = -1000;
		}
		else if (k == 0)
		{
			printf("x1 si x2 sunt egale");
			*x1 = (-b / (2 * a));
			*x2 = (-b / (2 * a));
		}
		else
		{
			*x1 = ((-b + sqrt(k)) / (2 * a));
			*x2 = ((-b - sqrt(k)) / (2 * a));
		}
	}
}

int main()
{
	float a, b, c, x1, x2;
	printf("Ecuatia de gradul II are forma ax^2 + bx + c = 0");
	printf("\nIntroduceti a: ");
	scanf("%f", &a);
	printf("\nIntroduceti b: ");
	scanf("%f", &b);
	printf("\nIntroduceti c: ");
	scanf("%f", &c);
	radacini(a, b, c, &x1, &x2);
	if (x1 == x2)
		printf("\nx = %.2f", x1);
	else if ((x1 == -999) && (x2 == -1000))
		printf("\nx1 si x2 sunt numere complexe");
	else
		printf("\nx1 = %.2f\nx2 = %.2f", x1, x2);
	printf("\n");
	return 0;
}