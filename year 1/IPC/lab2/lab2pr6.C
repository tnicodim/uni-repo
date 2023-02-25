/* 6. Sa se scrie un program care citeste de la tastatura lungimile laturilor unui triunghi si afiseaza aria acestuia, calculata cu formula lui Heron. */

#include <stdio.h>
#include <math.h>

int main()
{
	float a, b, c, p, aria;
	printf("\nIntroduceti valoarea a = ");
	scanf("%f", &a);
	printf("\nIntroduceti valoarea b = ");
	scanf("%f", &b);
	printf("\nIntroduceti valoarea c = ");
	scanf("%f", &c);
	p = (a + b + c) / 2;
	aria = sqrt((p * (p - a) * (p - b) * (p - c)));
	printf("\nAria triunghiului este: %.3f (u.m.) \n", aria);
	return 0;
}