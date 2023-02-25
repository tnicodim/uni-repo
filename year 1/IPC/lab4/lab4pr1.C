/* Sa se scrie un program in C care citeste
de la tastatura un nr si afiseaza toti divizorii acestuia*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int x;
	printf("Introduceti un nr natural x: ");
	scanf("%d", &x);
	printf("Divizorii lui %d sunt:", x);;
	for (int i = 1; i <= x; i++)
	{
		if (x % i == 0)
			printf(" %d",i);
	}
	system("pause");
	return 0;
}
