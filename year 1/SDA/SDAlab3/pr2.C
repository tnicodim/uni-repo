#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef enum studii{medii,superioare,doctorat}studii;
typedef enum profil{economic,tehnic}profil;

//TDA - articol -> structura
typedef struct data_nastere {
	int zi, luna, an;
}data_nastere;
typedef struct inf_medii {
	float medie_bac, medie_4ani;
}inf_medii;

//TDA - articol cu variante -> uniune, camp selector
typedef union informatii {
	inf_medii i_n;
	float nota_l;
	profil p;
}informatii;

typedef struct angajat {
	char nume[20], prenume[20];
	data_nastere d_n;
	float salariu;
	studii s;
	informatii inf;
}ang;

int citire(ang a[]) {
	int i = 0;
	FILE* f;
	if ((f = fopen("lista_angajati.txt", "rt")) == NULL)
		printf("......");
	else {
		while (!feof(f)) {
			fscanf(f, "%s %s %d.%d.%d %f %d", a[i].nume, a[i].prenume, &a[i].d_n.zi, &a[i].d_n.luna, &a[i].d_n.an, &a[i].salariu, &a[i].s);
			switch (a[i].s) {
			case medii:fscanf(f, "%f%f", &a[i].inf.i_n.medie_4ani, &a[i].inf.i_n.medie_bac); break;
			case superioare:fscanf(f, "%f", &a[i].inf.nota_l); break;
			case doctorat:fscanf(f, "%d", &a[i].inf.p); break;
			}
			i++;
		}
		fclose(f);
	}
	return i;
}

void afisare(ang a[], int i) {
	printf("\n----------------------------------------------------");
	printf("\nNume: %s\nPrenume: %s\nData Nasterii: %d.%d.%d \nSalariu: %.2f\nStudii: %d", a[i].nume, a[i].prenume, a[i].d_n.zi, a[i].d_n.luna, a[i].d_n.an, a[i].salariu, a[i].s);
	switch (a[i].s) {
	case medii:printf("\nMedie 4 ani: %.3f\nMedie BAC: %.3f", a[i].inf.i_n.medie_4ani, a[i].inf.i_n.medie_bac); break;
	case superioare:printf("\nMedie Licenta: %.3f", a[i].inf.nota_l); break;
	case doctorat:printf("\nProfilul Doctoratului: "); if (a[i].inf.p == 0) printf("economic"); else printf("tehnic"); break;
	}
	printf("\n----------------------------------------------------");
}

void afisaretotala(ang a[], int n) {
	int i;
	for (i = 0; i < n; i++)
		afisare(a, i);
}

void cautareNume(ang a[], int n) {
	char numeCautat[20];
	int i;
	printf("\nIntroduceti numele cautat: ");
	scanf("%s", numeCautat);
	for (i = 0; i < n; i++)
		if (strcmp(a[i].nume, numeCautat) == 0)
			afisare(a, i);
}

int main() {
	ang vector_angajati[10];
	int n, opt;
	n = citire(vector_angajati);
	while (1) {
		printf("\n1. Afisare angajati\n2. Cautare angajat dupa nume\n0. Exit");
		printf("\nIntroduceti optiunea dorita:");
		scanf("%d", &opt);
		switch (opt)
		{
		case 0:
			exit(0);
		case 1:
			afisaretotala(vector_angajati, n);
			break;
		case 2:
			cautareNume(vector_angajati,n);
			break;
		}
	}
	return 0;
}