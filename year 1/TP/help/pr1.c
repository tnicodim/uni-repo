//v2
/* Fisier text text.in care contine: litere, semne, \n, \t, \r
* in text.out -> text fara duplicatii,newline,tab,cr
* "citire cu success", nr de caractere citite fara \0 \n \r
* afisare -> nr caractere scrise in text.out
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char text[30][50];
int n;
int carcitite = 0, carscrise = 0;


int citireFisier()
{
	int i = 0;
	FILE* f = NULL;
	if ((f = fopen("text.in.txt", "r")) == NULL)
		printf("\nFisierul nu exista");
	else {
		while (!feof(f)) {
			fgets(text[i], 50, f);
			i++;
		}
		fclose(f);
	}
	n = i;
	for (i = 0; i <= n; i++)
		carcitite += strlen(text[i]);
	return 1;
}

int main() {
	int i, j, k, m = 0;
	char aux;
	if (citireFisier())
		printf("Citirea a fost efectuata cu success!\n");
	else
		printf("Eroare la citire!");
	for (i = 0; i <= n; i++)
		for (j = 0; text[i][j] != '\0'; j++)
		{
			if (text[i][j] == ' ')
			{
				k = j + 1;
				while (text[i][j] == text[i][k]) {
					m++;
					k++;
				}
				if (m != 0) {
					for (k = j; text[i][k] != '\0'; k++) {
						text[i][k] = text[i][k + m + 1];
						if (text[i][k] == '\0')
							break;
					}
				}
			}
			m = 0;
		}
	for (i = 0; i <= n; i++) {
		printf("%s", text[i]);
		carscrise += strlen(text[i]);
	}
	printf("\nCaractere la inceput: %d", carcitite);
	printf("\nCaractere dupa schimbare %d", carscrise);
	return 0;
}