#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct nod {
	char* nume;
	float nota;
	struct nod* urm;
}nod;

nod* radacina = NULL;

nod* adauga_inceput(nod* lista, nod* aux) {
	aux->urm = lista;
	lista = aux;
	return lista;
}

nod* adauga_sfarsit(nod* lista, nod* aux) {
	nod* last;
	if (lista == NULL) {
		lista = aux;
		return lista;
	}
	last = lista;
	while (last->urm != NULL) {
		last = last->urm;
	}
	last->urm = aux;
	return lista;
}

void afisare(nod* lista) {
	nod* q;
	for (q = lista; q != NULL; q = q->urm)
		printf("%s %f\n", q->nume, q->nota);
}
nod* ad_ordonata(nod* lista, nod* aux) {
	nod* q1, * q2;
	for (q1 = q2 = lista; q1 != NULL && aux->nota > q1->nota; q2 = q1, q1 = q1->urm);
	if (q1 == q2){ 
		aux->urm = lista; 
		lista = aux;
	}
	else {
		q2->urm = aux;
		aux->urm = q1;
	}
	return lista;
}
nod* sterge(nod* lista, float nota) {
	nod* q1, *q2;
	for (q1 = q2 = lista; q1 != NULL && q1->nota != nota; q2 = q1, q1 = q1->urm);
	if (q1 != NULL) {
		if (q1 == q2)
			lista = lista->urm;
		else 
			q2->urm = q1->urm;
		free(q1->nume);
		free(q1);
	}
	return lista;
}
void citire() {
	FILE* f;
	nod* aux;
	char nume[20];
	float nota;
	f = fopen("cal.txt", "rt");
	if (f == NULL)
		printf("Teaca bros");
	while (!feof(f)) {
		fscanf(f, "%s%f", nume, &nota);
		aux = (nod*)malloc(sizeof(nod));
		aux->nume = (char*)malloc(strlen(nume) + 1);
		strcpy(aux->nume, nume);
		aux->nota = nota;
		aux->urm = NULL; //optional ca se initializeaza deja
		//radacina = adauga_inceput(radacina, aux); //1
		//radacina = ad_ordonata(radacina, aux); //2
		radacina = adauga_sfarsit(radacina, aux);
	}
	afisare(radacina);
}

int main() {
	citire();
	radacina = sterge(radacina, 5);
	printf("\n---------------\n");
	afisare(radacina);
	radacina = sterge(radacina, 8);
	printf("\n---------------\n");
	afisare(radacina);
	return 0;

}