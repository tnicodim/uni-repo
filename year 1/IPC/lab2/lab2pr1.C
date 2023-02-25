/*1. Sa se scrie un program care sa citeasca de la tastatura numele si varsta dvs. si sa le
afiseze.*/

#include <stdio.h>

int main()
{
	int age;
	char nume[15],prenume[15];
	printf("\nIntroduceti numele dvs: ");
	scanf("%s",&nume);
	printf("\nIntroduceti prenumele dvs: ");
	scanf("%s", &prenume);
	printf("\nIntroduceti varsta dvs: ");
	scanf("%d",&age);
	printf("\nVa numiti %s %s si aveti %d ani.\n", nume,	prenume, age);
	return 0;
}