/*Sa se scrie un program in C care citeste de la tastatura un sir de nr incheiat cu 0
si afiseaza media aritmetica a nr introduse */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[100], i = 0;
	float  MA = 0.0;
	while (1)
	{
		printf("\nIntroduceti numarul de pe pozitia %d a sirului: ", i);
		scanf("%d", &a[i]);
		MA += a[i];
		if (a[i] == 0)
			break;
		i++;
	}
	MA = MA / i;
	printf("\nMedia aritmetica a numerelor introduse este: %f\n\n\n", MA);
	system("pause");
	return 0;
}
