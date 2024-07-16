#include <stdio.h>
#include <stdlib.h>
#define n 26
#define inf 9999
int noduri[n], arce[n][n];

void initializare() {
	int i, j;
	for (i = 0; i < n; i++)
		noduri[i] = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			arce[i][j] = 0;
}

void graf() {
	int i, j = 0;
	for (i = 0; i < n; i++) {
		noduri[i] = 'A' + j;
		j++;
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			if (noduri[i] == 'A' || noduri[i] == 'E' || noduri[i] == 'I' || noduri[i] == 'O' || noduri[i] == 'U')
				if (noduri[j] != 'A' && noduri[j] != 'E' && noduri[j] != 'I' && noduri[j] != 'O' && noduri[j] != 'U') // pozitiile vocalelor 
					arce[i][j] = noduri[i] + noduri[j]; // arce de la vocale la consoane 
}

void printNodes() {
	int i, j;
	for (i = 0; i < n; i++)
		printf("%d ", noduri[i]);
	printf("\n");
}

void printArces() {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++)
			printf("%3d ", arce[i][j]);
		printf("\n");
	}
}

void arcNou(int x, int y, int pondere) {
	int i, j = -1, k = -1;
	for (i = 0; i < n; i++) {
		if (noduri[i] == x)
			k = i;
		if (noduri[i] == y)
			j = i;
	}
	if (j == -1 || k == -1) {
		printf("\nEroare.\n");
		return;
	}
	arce[k][j] = pondere;

}

void prim(int start) {
	int vizitat[n], pos = -1, min, i, j, suma = 0, nr_vizitate = 1;
	for (i = 0; i < n; i++) {
		vizitat[i] = -1;
		if (noduri[i] == start)
			pos = i;
	}
	if (pos == -1) {
		printf("Nu exista nodul cerut!");
		return;
	}
	vizitat[pos] = 1;
	printf("Parcurgerea nodurilor:\n");
	printf("%c ", noduri[pos]);
	while (nr_vizitate < n) {
		min = inf;
		for (i = 0; i < n; i++)
			for (j = 0; j < n; j++)
				if (vizitat[i] == 1 && vizitat[j] == -1 && arce[i][j] < min && i != j && arce[i][j] != 0) {
					pos = j;
					min = arce[i][j];
				}
		vizitat[pos] = 1;
		nr_vizitate++;
		if (min != inf) {
			suma += min;
			printf("%c ", noduri[pos]);
		}
	}
	printf("\nSuma ponderilor arcelor care constituie graful de acoperire minima este: %d ", suma);

}

int main() {
	int opt, pondere;
	char s, x, y;
	initializare();
	graf();
	while (1) {
		printf("\n1.Afisare noduri.");
		printf("\n2.Afisare matricea arcelor.");
		printf("\n3.Afisarea arborelui de acoperire minima. ");
		printf("\n4.Adaugare arc nou.");
		printf("\n5.Iesire.");
		printf("\nIntroduceti optiunea dorita: ");
		scanf("%d", &opt);
		switch (opt)
		{
		case 1:
			printNodes();
			break;
		case 2:
			printArces();
			break;
		case 3:
			printf("\nIntroduceti nodul de la care doriti sa incepeti: ");
			getchar();
			scanf("%c", &s);
			prim(toupper(s));
			break;
		case 4:
			printf("\nIntroduceti nodul de la care doriti sa incepeti un arc: ");
			getchar();
			scanf("%c", &x);
			printf("\nIntroduceti nodul la care doriti sa ajungeti cu arcul: ");
			getchar();
			scanf("%c", &y);
			printf("\nIntroduceti ponderea arcului de la %c la %c: ", x, y);
			scanf("%d", &pondere);
			arcNou(toupper(x), toupper(y), pondere);
			break;
		case 5:
			exit(0);
			break;
		default:
			printf("Ati introdus optiunea incorecta!");
			break;
		}
	}
}