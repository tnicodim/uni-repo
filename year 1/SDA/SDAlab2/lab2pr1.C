#include <stdio.h>

//s             m                  d  
//0 1  2  3  4  5  6  7  8  9  10 11 <-pozitii
//0 12 15 23 25 28 39 45 47 50 55 56
//s=0 d=11 m=(s+d)/2


int cautareLiniara(int a[], int x, int n)
{
	int i;
	i = 0;
	while (a[i] != x && i < n)
		i++;
	return i;
}

int tehnicaFanionului(int a[], int x, int n)
{
	int i;
	i = 0;
	a[n] = x;
	while (a[i] != x)
		i++;
	return i;
}

int cautareBinara(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (a[m] < x)
			s = m + 1;
		else
			d = m - 1;
	} while (s<=d && a[m] != x);
	return m;
}

int cautareBinaraP(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	do {
		m = (s + d) / 2;
		if (x > a[m])
			s = m + 1;
		else
			d = m;
	} while (s < d);
	return d;
}

int cautareInterpolare(int a[], int x, int n)
{
	int s, d, m;
	s = 0;
	d = n - 1;
	m = -1;
	if (x >= a[s] && x <=a[d])
		do {
			m = s + (x - a[s]) * (d - s) / (a[d] - a[s]);
			if (x > a[m]) 
				s = m + 1;
			else
				d = m - 1;
		} while (a[m] != x && s < d && x <= a[d] && x >= a[s] && a[d] != a[s]);
		return m;
}

int citireFisier(int a[])
{
	int i;
	FILE* f = NULL;
	i = 0;
	if ((f = fopen("num.txt", "r")) == NULL)
		printf("\nFisierul nu exista");
	else {
		while (!feof(f)) {
			fscanf(f, "%d", &a[i]);
			i++;
		}
		fclose(f);
	}
	return i;
}

int main() {
	int a[20], x, n, p, i;
	n = citireFisier(a);
	printf("\nTabloul este: ");
	for (i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\nIntroduceti elementul cautat: ");
	scanf("%d", &x);
	p=cautareLiniara(a, x, n);
	if (p < n)
		printf("\nPozitie %d", p);
	else
		printf("\nElementul nu exista in tablou");
	
	p = tehnicaFanionului(a, x, n);
	if (p < n)
		printf("\nPozitie %d", p);
	else
		printf("\nElementul nu exista in tablou");
	
	p = cautareBinara(a, x, n);
	if (a[p] == x)
		printf("\nPozitie %d", p);
	else
		printf("\nElementul nu exista in tablou");

	p = cautareBinaraP(a, x, n);
	if (a[p] == x)
		printf("\nPozitie %d", p);
	else
		printf("\nElementul nu exista in tablou");
	
	p = cautareInterpolare(a, x, n);
	if (a[p] == x)
		printf("\nPozitie %d", p);
	else
		printf("\nElementul nu exista in tablou");
	printf("\n-----------------------------\n\n");
		return 0;
}