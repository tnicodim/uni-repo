/*Sa se scrie un program in C care citeste de la tastatura un sir de nr incheiat cu 0
si afiseaza suma nr introduse */

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a[100], i = 0, suma = 0;
	while (1)
	{
		printf("\nIntroduceti numarul de pe pozitia %d a sirului: ", i);
		scanf("%d", &a[i]);
		suma += a[i];
		if (a[i] == 0)
			break;
		i++;
	}
	printf("\nSuma numerelor introduse este: %d\n\n\n", suma);
	system("pause");
	return 0;
}
