#include <stdio.h>
#include <stdlib.h>

//sa se citeasca numele prenumele nota varsa studentilor din fisierul ev.txt

typedef struct stud {
	char nume[20], prenume[20];
	float nota;
	int varsta;
}stud;

int citire_fisier(stud tab[]) {
	int i;
	FILE* f = NULL;
	i = 0;
	if ((f = fopen("ev.txt", "rt")) == NULL)			//rt = read text
		printf("\nFisierul nu exista");
	else {
		while (!feof(f)) {
			fscanf(f, "%s %s %f %d",tab[i].nume, tab[i].prenume, &tab[i].nota, &tab[i].varsta);
			i++;
		}
		fclose(f);
	}
	return i;
}

void afisare(stud tab[], int n) {
	int i;
	FILE* f = NULL;
	for (i = 0; i < n; i++)
		printf("%s %s %d %.3f\n", tab[i].nume, tab[i].prenume, tab[i].varsta, tab[i].nota);
}

void printare_5(stud tab[], int n) {
	int i;
	FILE* f;
	f = fopen("ev_trecator.txt", "wt");
	for (i = 0; i < n; i++) {
		if (tab[i].nota >= 5)
			fprintf(f, "%s %s %.3f %d\n", tab[i].nume, tab[i].prenume, tab[i].nota, tab[i].varsta);
	}
	fclose(f);
}
int main(){
	int n;
	stud tab[20];
	n = 0;
	n = citire_fisier(tab);
	afisare(tab, n);
	printare_5(tab, n);
	return 0;
}