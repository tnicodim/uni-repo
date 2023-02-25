#include <stdio.h>
#include <math.h>

/*2. Sa se scrie un program in C care citeste 2 numere de la tastatura si verifica daca sunt
divizibile cu 3. Daca sunt divizibile se va face suma dintre ele, daca nu - produsul. */

int main()
{
	int a, b;
	printf("\nIntroduceti a: ");
	scanf("%d", &a);
	printf("\nIntroduceti b: ");
	scanf("%d", &b);
	if ( (a % 3 == 0) && (b % 3 == 0) )
		printf("\nSuma dintre %d si %d este: %d \n \n", a, b, a+b);
	else
		printf("\nProdusul dintre %d si %d este: %d \n \n", a, b, a * b);
	return 0;
}