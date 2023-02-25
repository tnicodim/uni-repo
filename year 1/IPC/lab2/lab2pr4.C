/* 4. Sa se scrie un program C care face conversia din grade Celsius în grade Fahrenheit, C = (F – 32)* 5/9 */

#include <stdio.h>

int main()
{
	float tempC;
	printf("\nIntroduceti temperatura in grade Celsius: ");
	scanf("%f", &tempC);
	printf("\n%.2f grade Celsius = %.2f grade Fahrenheit\n",tempC, tempC * 9 / 5 + 32);
	return 0;
}