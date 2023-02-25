/*Liste multiplu inlantuite
fisier evidenta.txt ce contine nume, disciplina, nota
a) evidenta ordonata alfabetic
b) evidenta ordonata dupa disciplina
c) pentru o anumita disciplina afisati evidenta ordonata dupa note*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nod {
	char nume[20],disciplina[20];
	float nota;
	struct nod* urm1;
	struct nod* urm2;
	struct nod* urm3;
}nod;

nod* r1 = NULL;
nod* r2 = NULL;
nod* r3 = NULL;

nod* sterge1(nod* lista, char nume[], char disciplina[]) {
	nod* q1, * q2;
	for (q1 = q2 = lista; q1 != NULL && ((strcmp(q1->nume, nume) != 0) || (strcmp(q1->disciplina, disciplina) != 0)); q2 = q1, q1 = q1->urm1);
	if (q1 != NULL) {
		if (q1 == q2)
			lista = lista->urm1;
		else
			q2->urm1 = q1->urm1;
	}
	return lista;
}
nod* ad1(nod* lista, nod* aux) {
	nod *q1, *q2;
	for (q1 = q2 = lista; q1 != NULL && strcmp(aux->nume, q1->nume) > 0; q2 = q1, q1 = q1->urm1);
	if (q1 == q2) {
		aux->urm1 = lista;
		lista = aux;
	}
	else {
		q2->urm1 = aux;
		aux->urm1 = q1;
	}
	return lista;
}

nod* ad2(nod* lista, nod* aux) {
	nod* q1, * q2;
	for (q1 = q2 = lista; q1 != NULL && strcmp(aux->disciplina, q1->disciplina) > 0; q2 = q1, q1 = q1->urm2);
	if (q1 == q2) {
		aux->urm2 = lista;
		lista = aux;
	}
	else {
		q2->urm2 = aux;
		aux->urm2 = q1;
	}
	return lista;
}

nod* ad3(nod* lista, nod* aux) {
	nod* q1, * q2;
	for (q1 = q2 = lista; q1 != NULL && (aux->nota < q1->nota); q2 = q1, q1 = q1->urm3);
	if (q1 == q2) {
		aux->urm3 = lista;
		lista = aux;
	}
	else {
		q2->urm3 = aux;
		aux->urm3 = q1;
	}
	return lista;
}

void af1(nod* lista) {
	nod* q = lista;
	while (q != NULL) {
		printf("\n%s %s %f", q->nume, q->disciplina, q->nota);
		q = q->urm1;
	}
}

void af2(nod* lista) {
	nod* q = lista;
	while (q != NULL) {
		printf("\n%s %s %f", q->nume, q->disciplina, q->nota);
		q = q->urm2;
	}
}

void af3(nod* lista, char disciplina[]) {
	nod* q = lista;
	while (q != NULL) {
		if (strcmp(q->disciplina, disciplina)==0)
			printf("\n%s %s %f", q->nume, q->disciplina, q->nota);
		q = q->urm3;
	}
}

void citire(void) {
	FILE* f;
	nod* aux = NULL;
	f = fopen("evidenta.txt", "rt");
	if (f == NULL)
		printf("Teaca bros");
	while (!feof(f)) {
		aux = (nod*)malloc(sizeof(nod));
		fscanf(f,"%s %s %f", aux->nume, aux->disciplina, &aux->nota);
		r1 = ad1(r1, aux);
		r2 = ad2(r2, aux);
		r3 = ad3(r3, aux);
	}
	r1 = sterge1(r1, "N1", "D2");
	af1(r1);
	printf("\n------------------------------");
	af2(r2);
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~");
	af3(r3, "D2");
}

//void citire(void)
//{
//	FILE* f = NULL;
//	nod* aux = NULL;
//
//	f = fopen("evidenta.txt", "rt");
//	while (!feof(f)) {
//		aux = (nod*)malloc(sizeof(nod));
//		fscanf(f, "%s %s %f", aux->nume, aux->disciplina, &aux->nota);
//
//		r1 = ad1(r1, aux);
//		r2 = ad2(r2, aux);
//		r3 = ad3(r3, aux);
//	}
//
//	r1 = sterge1(r1, "N1", "D2");
//
//	af1(r1);
//	printf("\n--------------------\n");
//
//	af2(r2);
//	printf("\n--------------------\n");
//
//	af3(r3, "D2");
//	printf("\n--------------------\n");
//}


int main() {
	citire();
	return 0;
}