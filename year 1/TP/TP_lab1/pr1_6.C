// Să se scrie o funcție recursivă pentru calculul cmmdc și să se testeze aceasta pe două numere de la tastatură

#include <stdio.h>
#include <stdlib.h>

int cmmdc(int a, int b) {
	if (a == b)
		return a;
	else if (a > b)
		return cmmdc(a - b, b);
	else if (a < b)
		return cmmdc(a, b - a);
}


int main() {
	int x, y;
	printf("x="); scanf("%d", &x);
	printf("y="); scanf("%d", &y);
	printf("\nCel mai mic divizor comun pentru %d si %d este %d\n\n", x, y, cmmdc(x,y));
	return 0;
}