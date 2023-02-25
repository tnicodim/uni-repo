#include <stdio.h>
#include <math.h>

/*Se citesc de la tastatura 3 numere reale pozitive, a b si c. Scrieti un program în C care
sa verifice daca numerele citite pot constitui laturile unui triunghi. In caz afirmativ,
determinati tipul triunghiului (echilateral, isoscel sau dreptunghic) si afisati aria sa.*/

int main()
{
	float a, b, c, p, s, max;
	printf("\nIntroduceti cele 3 lungimi ale laturilor:\n");
	scanf("%f %f %f", &a, &b, &c);
	if ((a < (b + c)) && (b < (a + c)) && (c < (a + b)))
	{
		max = a;
		if (max < b)
			max = b;
		if (max < c)
			max = c;
		printf("\nCele trei segmente pot forma un triunghi!");
		if ((a == b) && (b == c))
			printf("\nTriunghiul este echilateral");
		else if ((a == b) || (b == c) || (a == c))
			printf("\nTriunghiul este isoscel");
		if (pow(a,2) + pow(b,2) + pow(c,2) - pow(max,2) == pow(max,2))
			printf("\nTriunghiul este dreptunghic");
		p = (a + b + c) / 2;
		s = sqrt((p * (p - a) * (p - b) * (p - c)));
		printf("\nAria triunghiului este: %.2f (u.m.) \n", s);
	}
	else
		printf("Cele trei segmente nu pot forma triunghi! \n");
	return 0;
}