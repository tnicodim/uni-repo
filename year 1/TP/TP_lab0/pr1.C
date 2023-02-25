/* creati o functie care sa returneze numarul de caractere ce se regasesc intr-un sir de caractere (caracterul cautat se preia de la tastatura)
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cautareCaracter(char sir[]) {
	int i, k;
	char caracter;
	k = 0;
	printf("\nIntroduceti caracterul cautat: ");
	scanf("%c", &caracter);
	for (i = 0; i < strlen(sir); i++)
		if (sir[i] == caracter)
		//	if (sir[i] == caracter || sir[i] == caracter - 32) (daca vrem sa luam in calcul si litera majuscula)
			k++;
	printf("\nLitera %c se intalneste de %d ori in sirul introdus\n\n", caracter, k);
	return k;
}

int main() {
	char sir[30];
	printf("Introduceti sirul de caractere: ");
	gets(sir);
	printf("\n%s", sir);
	cautareCaracter(sir);
	return 0;
}