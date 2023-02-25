#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// liste cu subliste
//evidenta.txt	nume prenume disciplina nota

typedef struct sl {
	char disciplina[20];
	float nota;
	struct sl* urm;
}sl;

typedef struct nod {
	char nume[20];
	char prenume[20];
	struct nod* urm;
	sl* prim;
}nod;

nod* rad = NULL;

sl* ad_sl(sl* lista, sl* aux) {  
	aux->urm = lista;
	lista = aux;
	return lista;
}

nod* ad_l(nod* lista, nod* aux,sl* aux1) {  //adaugare la inceput!
	aux->urm = lista;
	lista = aux;
	lista->prim = ad_sl(lista->prim,aux1);
	return lista;
}
nod* cauta_l(nod* l, char nume[]) {
	nod* q = l;
	for (q = l; q != NULL && strcmp(q->nume, nume) != 0; q = q->urm);
	return q;
}
void citire() {
	FILE* f;
	char nume[20], disciplina[20], prenume[20];
	float nota;
	nod* q, *aux;
	sl* a;
	f = fopen("evidenta.txt", "r");
	while (!feof(f)) {
		fscanf(f, "%s%s%s%f", nume, prenume, disciplina, &nota);
		q = cauta_l(rad,nume);
		if (q != NULL) {
			a = (sl*)malloc(sizeof(sl));
			strcpy(a->disciplina, disciplina);
			a->nota = nota;
			q->prim = ad_sl(q->prim, a);
		}
		else {
			a = (sl*)malloc(sizeof(sl));
			strcpy(a->disciplina, disciplina);
			a->nota = nota;
			aux = (nod*)malloc(sizeof(nod));
			strcpy(aux->nume, nume);
			strcpy(aux->prenume, prenume);
			aux->prim = NULL;
			rad = ad_l(rad, aux, a);

		}
	}
}

void afisare(nod* lista) {
	nod* q;
	sl* r;
	for (q = lista; q != NULL; q = q->urm) {
		printf("\n%s %s \t",q->nume,q->prenume);
		for (r = q->prim; r != NULL; r = r->urm)
			printf("\n\t %s %f", r->disciplina, r->nota);
	}
}

int main() {
	citire();
	afisare(rad);
	printf("\n\n");
	return 0;
}