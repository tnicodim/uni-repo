/*Să se scrie un program care ține evidența jucăriilor dintr-un magazin de jucării. Pentru fiecare jucărie se
specifică în parte: nume, material și preț.
Să se facă un meniu interactiv care să conţină următoarele operaţii:
0. Ieșire
1. Adăugarea unei noi jucării în stocul magazinului.
Observații:
• Numele jucăriilor este considerat citit corect dacă este format doar din litere mici.
• Prețul fiecărei jucării este dat automat, fiind egal cu media aritmetică a caracterelor ASCII al numelui
acestora. (ex. dacă numele este abc, atunci prețul este egal cu (97+98+99)/3).
2. Afișarea jucăriilor din magazin în ordine alfabetică după nume.
3. Să se afișeze câte jucării au lungimea materialelor mai mică cu 2 decât o putere a lui 2. Se vor utiliza
doar operații pe biți.
Observații:
· Programul se va implementa folosind vectori de structuri.
· Pentru fiecare opțiune se va crea o funcție, iar variabilele se vor transmite prin adresă.
· Nu este permisă folosirea variabilelor globale. */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Magazin {
	char nume[15], material[15];
	int pret;
}Mag;

int verif(char nume[15]) {
	int i, valid;
	do {
		valid = 1;
		for (i = 0; i < strlen(nume); i++)
			if (!(nume[i] >= 'a' && nume[i] <= 'z')) return 0;
	} while (!valid);
}

void adauga(Mag* m, int* nr) {
	(*nr)++;
	int i, aux = 0;


	do {
		printf("\nNume: ");
		scanf("%s", m[*nr].nume);
	} while (!verif(m[*nr].nume));
	printf("Material: ");
	scanf("%s", m[*nr].material);
	m[*nr].pret = 0;
	for (i = 0; i < strlen(m[*nr].nume); i++) {
		m[*nr].pret += m[*nr].nume[i];
		aux++;
	}
	m[*nr].pret /= aux;
	printf("Pret: %d", m[*nr].pret);


}

void sortare(Mag* m, int* nr) {
	int i, flag = 0;
	Mag aux;
	do {
		flag = 1;
		for (i = 0; i < *nr; i++)
			if (strcmp(m[i].nume, m[i + 1].nume) > 0) {
				aux = m[i + 1];
				m[i + 1] = m[i];
				m[i] = aux;
				flag = 0;
			}
	} while (!flag);
}

void afis(Mag* m, int* nr) {
	int i;
	for (i = 0; i <= *nr; i++) {
		printf("\nNumele: %s", m[i].nume);
		printf("\nMaterial :%s", m[i].material);
		printf("\nPret: %d", m[i].pret);
		printf("\n--------------");
	}
}

void lungimebin(Mag* m, int* nr) {
	int i, j, aux;
	int flag;

	for (j = 0; j <= *nr; j++) {
		flag = strlen(m[j].material);
		flag += 2;
		aux = 0;
		for (i = flag; i >= 0; i--)
			if ((flag >> i) & 1)
				aux++;

		if (aux == 1)
		{ 
			printf("\n%s", m[j].nume);
		printf("\n%s", m[j].material);
		printf("\n%d", m[j].pret);
		printf("\n------------\n");
		}
	}
}


int main() {
	system("color 0B");
	int nr = -1;
	Mag m[15];
	enum meniu { iesire, adaugare, afisare, lungime }op;
	do {
		printf("\n1. Adaugarea unei noi jucarii in stocul magazinului.");
		printf("\n2. Afisarea jucariilor din magazin in ordine alfabetica dupa nume.");
		printf("\n3. Sa se afiseze cate jucarii au lungimea materialelor mai mica cu 2 decat o putere a lui 2.");
		printf("\n0. Iesire ");
		printf("\nAlegeti optiunea dorita: ");
		scanf("%d", &op);
		switch (op)
		{
		case iesire:
			exit(0);
			break;
		case adaugare:
			adauga(m, &nr);
			break;
		case afisare:
			sortare(m, &nr);
			afis(m, &nr);
			break;
		case lungime:
			lungimebin(m, &nr);
			break;
		default:
			printf("\nOptiune inexistenta\n");
			break;
		}
	} while (1);
	return 0;
}