#include<stdio.h>
#define read(x) scanf("%d", &x);
#define EXIT 0;

typedef struct Masina
{
	char nume[20];
	float pret_kilogram;
	float pret;
};

int Validare(char* nume)
{
	if (strlen(nume) < 3) return 0;
	if (nume[0] < 'A' || nume[0] > 'Z') return 0;
	if (nume[1] < 'A' || nume[1] > 'Z') return 0;

	int i;
	for (i = 2; i < strlen(nume); i++)
	{
		if (nume[i] < '0' || nume[i] > '9') return 0;
	}

	return 1;
}
void Citire(struct Masina* M, int* n)
{
	int i, j, sum;
	char nume[20];
	printf("Introduceti nr de masini: ");
	scanf("%d", n);

	for (i = 0; i < *n; i++)
	{
		do
		{
			printf("Numele: ");
			scanf("%s", nume);

		} while (!Validare(nume));// primele 2 caractere sunt litere mari, urmatoarele sunt cifre
		strcpy((M + i)->nume, nume);

		printf("Pret_kilogram: ");
		scanf("%f", &(M + i)->pret_kilogram);

		sum = 0;
		for (j = 2; j < strlen(nume); j++)
		{
			sum += nume[j] - 48;// extragerea din "caracterul cifra" - cifra reala(int)
		}

		(M + i)->pret = sum;
	}

}

// afisare in mod descrescator
void Afisare(struct Masina* M, int n)
{
	int i, j;
	struct Masina Aux;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n - 1; j++)
		{
			if ((M + j)->pret_kilogram > (M + j + 1)->pret_kilogram)
			{
				Aux = *(M + j + 1);
				*(M + j + 1) = *(M + j);
				*(M + j) = Aux;

			}
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("Numele: %s\n", (M + i)->nume);
		printf("Pret_kilogram: %.1f\n", (M + i)->pret_kilogram);
		printf("Pret: %.1f\n", (M + i)->pret);
		printf("\n");
	}
}

// intr-o matrice de caractere se introduc toate numele din structuri cu lungime para(nu se foloseste functia strcpy)
void Matrice(struct Masina* M, int n)
{
	char m[20][50];
	int i, j, k = 0;

	for (i = 0; i < n; i++)
	{
		if (strlen((M + i)->nume) % 2 == 0) // se cauta numele cu lungime para
		{
			for (j = 0; j < strlen((M + i)->nume); j++)
			{
				m[k][j] = (M + i)->nume[j];// fiecare caracter in parte din nume se copie in matrice
			}
			m[k][j] = '\0'; // caracterul terminativ
			k++; // variabila pentru indexul la matrice
		}
	}

	for (i = 0; i < k; i++)
	{
		printf("%s\n", m[i]);
	}
}

int main()
{
	int opt, n;
	struct Masina M[50];

	enum { citire = 1, afisare, matrice };
	do
	{
		printf("Meniu\n");
		printf("0 - Iesire\n");
		printf("1 - Citire\n");
		printf("2 - Afisare\n");
		printf("2 - Matrice\n");
		printf("Optiunea: ");
		scanf("%d", &opt);

		switch (opt)
		{
		default: printf("Invalid Input!\n");
			break;
		case 0: exit(1);
			break;
		case citire: Citire(M, &n);
			break;
		case afisare: Afisare(M, n);
			break;
		case matrice: Matrice(M, n);
			break;
		}

	} while (opt);
	return 1;
}