#include <stdio.h>
#include <math.h>

/*Sa se scrie un program in C care sa rezolve ecuatia de gradul II, ax2+bx+c=0, pentru
a,b,c numere intregi citite de la tastatura.*/

int main()
{
	float a, b, c, x, k;
	printf("\nEcuatia de gradul II are forma ax^2 + bx + c = 0");
	printf("\nIntroduceti nr intreg a: ");
	scanf("%f", &a);
	printf("\nIntroduceti nr intreg b: ");
	scanf("%f", &b);
	printf("\nIntroduceti nr intreg c: ");
	scanf("%f", &c);
	if ((roundf(a) == a) && (roundf(b) == b) && (roundf(c) == c))
	{
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
	}
	else
		printf("\nNumerele introduse nu sunt intregi.");
	return 0;
}