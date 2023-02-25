#include <stdio.h>
#include <math.h>

// Se considera un nr natural n . Sa se verifice daca n este o putere a lui 2, folosind operatii pe biti
// 8(10) = 1000 (2) 7(10) = 0111 (2)
int main()
{
	int n;
	printf("\nIntroduceti numarul n in baza 10: ");
	scanf("%d", &n);
	if ((n & (n - 1)) == 0)
	{
		printf("\n%d este puterea lui 2", n);
	}
	else
	{
		printf("\n%d nu este puterea lui 2", n);
	}
	return 0;
}