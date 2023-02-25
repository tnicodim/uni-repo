#include <stdio.h>
#include <math.h>

/*5. Se citesc 3 variabile reale a, b si c. Sa se calculeze valoare expresiei:
sqrt((a+b)) daca c > 0
a/b daca c = 0
a*b daca c < 0
*/

int main()
{
	float a, b;
	int c;
	printf("\nIntroduceti a: ");
	scanf("%f", &a);
	printf("\nIntroduceti b: ");
	scanf("%f", &b);
	printf("\nIntroduceti c: ");
	scanf("%d", &c);
	if (c > 0)
		printf("(a+b)^2 = %.2f", sqrt((a + b)));
	else if (c = 0)
		printf("a/b = %.2f", a / b );
	else
		printf("a*b = %.2f", a * b);
	return 0;
}