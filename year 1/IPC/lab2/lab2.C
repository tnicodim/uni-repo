#include <stdio.h>

int main()
{
	float x;
	int a, b;
	char c;
	printf("Introduceti primul nr ");
	scanf("%d",&a);
	printf("\nIntroduceti al doilea nr ");
	scanf("%d", &b);
	printf("\nIntroduceti caracterul ");
	getchar();
	scanf("%c", &c);
	printf("\nSuma este %d", a + b);
	printf("\nCodul ASCII al caracterului %c este %d", c, c);
	printf("\nDati un nr real ");
	scanf("%f", &x);
	printf("\nValoarea citita este %10.3f", x);
	return 0;
}