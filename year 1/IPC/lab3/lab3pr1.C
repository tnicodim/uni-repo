#include <stdio.h>
#include <math.h>

/*1. Sa se scrie un program in C care sa rezolve o ecuatie de gradul 2, cu coeficientii a, b, c
reali introdusi de la tastatura.*/

int main()
{
	float a, b, c, x, k;
	printf("\nEcuatia de gradul II are forma ax^2 + bx + c = 0");
	printf("\nIntroduceti a: ");
	scanf("%f", &a);
	printf("\nIntroduceti b: ");
	scanf("%f", &b);
	printf("\nIntroduceti c: ");
	scanf("%f", &c);
	if (a == 0)
	{
		printf("\nEcuatia nu este de gradul II");
		printf("\nSolutia ecuatiei este x = %.2f ", (-b / c));
	}
	else
	{
		k = pow(b, 2) - 4 * a * c;
		if (k < 0)
			printf("\nSolutiile ecuatiei sunt imaginare");
		else
		{
			printf("\nx1 = %.2f", ((-b + sqrt(k)) / (2 * a)));
			printf("\nx2 = %.2f", ((-b - sqrt(k)) / (2 * a)));
		}
	}
	return 0;
}