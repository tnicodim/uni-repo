#include <stdio.h>

/*7. Fie a si b doua numere intregi citite de la tastatura. Scrieti un algoritm care sa verifice
daca a si b sunt numere consecutive.*/

int main()
{
	int a, b;
	printf("\nIntroduceti numarul a: ");
	scanf("%d", &a);
	printf("\nIntroduceti numarul b: ");
	scanf("%d", &b);
	if ((a + 1 == b) || (b + 1 == a))
		printf("\nNumerele %d si %d sunt consecutive\n\n", a, b);
	else
		printf("\nNumerele %d si %d nu sunt consecutive\n\n", a, b);
	return 0;
}