/*13. Se citesc numere de tip intreg pana se vor introduce 2 numere consecutive. Sa se
afiseze cate din aceste numere sunt patrate perfecte.*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
	int a[100], b[100], i = 0, k = 0, test2;
	float test1;
	while (1)
	{
		printf("\nIntroduceti nr de pe pozitia %d a sirului: ", i);
		scanf("%d", &a[i]);
		test1 = sqrt(a[i]);
		test2 = test1;
		if (test2 == test1)
		{
			b[k] = a[i];
			k++;
		}
			if ((a[i - 1] == (a[i] + 1)) || ((a[i - 1] + 1) == a[i]))
			break;
			i++;
	}
	printf("\nPatratele perfecte din sir sunt:");
	for (int j = 0; j < k; j++)
		printf(" %d", b[j]);
	printf("\n\n\n");
	system("pause");
	return 0;
}