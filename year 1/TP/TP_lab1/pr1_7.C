/* : Folosind funcții standard din biblioteca matematică C (math.h), să se scrie o funcție care primește 
ca parametri coordonatele reale a două puncte (x0,y0,x1,y1) și returnează unghiul în grade [0-360] dintre segmentul (x0,y0)-(x1,y1) și axa OX
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define pi 3.14159265359

float unghiSegmentOX(float x1, float x0, float y1, float y0) {
	float unghi, panta;
	panta = (y1 - y0)/(x1 - x0);
	unghi = atan(panta)/pi * 180;
	return unghi;
}

int main() {
	float x1, x0, y1, y0;

	printf("Introduceti coordonatele punctelor:\n");
	printf("x0="); scanf("%f", &x0);
	printf("y0="); scanf("%f", &y0);
	printf("x1="); scanf("%f", &x1);
	printf("y1="); scanf("%f", &y1);
	printf("\nUnghiul intre segmentul introdus si axa OX este %.2f", unghiSegmentOX(x1, x0, y1, y0));
	return 0;
}