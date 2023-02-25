/* 
1. Sa se realizeze un program care, folosind un meniu, sa calculeze ariile mai multor figuri
geometrice, fiecare arie fiind calculata folosind cate o functie.
*/


#include <stdlib.h>
#include <math.h>
#include <stdio.h>

double ariaTriunghi()
{
	float a, b, c;
	double p, s;
	printf("\na=");
	scanf("%f", &a);
	printf("\nb=");
	scanf("%f", &b);
	printf("\nc=");
	scanf("%f", &c);
	if ((a + b > c) && (a + c > b) && (b + c > a))
	{
		p = (a + b + c) / 2;
		s = sqrt(p * (p - a) * (p - b) * (p - c));
		return s;
	}
	else
		printf("\nAsa triunghi nu exista!");
	
}

double ariaCerc()
{
	const float pi = 3.14519;
	float r;
	printf("\nr=");
	scanf("%f", &r);
	return pi * r * r;
}

double ariaPatrat()
{
	float l;
	printf("\nl=");
	scanf("%f", &l);
	return l * l;
}

double ariaDreptunghi()
{
	float L,l;
	printf("\nL=");
	scanf("%f", &L);
	printf("\nl=");
	scanf("%f", &l);
	return L * l;
}


int main()
{
	int opt;
	while (1)
	{
		system("color 0D");
		printf("\n1. Calculati aria unui triunghi\n2. Calculati aria unui patrat\n3. Calculati aria unui dreptunghi\n4. Calculati aria unui cerc\n0. Iesire");
		printf("\nIntroduceti optiunea: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printf("\nAria triunghiului este: %.2f", ariaTriunghi());
			break;
		case 2:
			printf("\nAria patratului este: %.2f", ariaPatrat());
			break;
		case 3:
			printf("\nAria dreptunghiului este: %.2f", ariaDreptunghi());
			break;
		case 4:
			printf("\nAria cercului este: %.2f", ariaCerc());
			break;
		case 0:
			exit(0);
		default:
			printf("\nAsa optiune nu exista!");
			break;
		}
	}
	return 0;
}