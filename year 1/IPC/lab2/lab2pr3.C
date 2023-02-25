/* 3. Sa se scrie un program C care converteste un unghi din grade in radiani
(rad=grad*pi/180). */

#include <stdio.h>

int main()
{
	const float pi = 3.1416;
	float angle;
	printf("\nIntroduceti masura unui unghi in grade: ");
	scanf("%f", &angle);
	printf("\nUnghiul introdus are %f rad", (angle * pi / 180));
	return 0;
}