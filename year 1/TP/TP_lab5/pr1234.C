/*
* P1. Scrieti o functie care intoarce numarul de caractere dintr-un sir sir2
* P2. Scrieti o functie care intoarce numarul de caractere c dintr-un sir sir3 ( *sir3 si c se
transmit ca parametri)
* P3. Scrieti o functie care compara doua siruri de caractere sir1 cu sir2
* P4. Scrieti o functie care permite cautarea unui subsir sub intr-un sir s
*/

#include <stdio.h>
#include <string.h>

int stringLength(char sir[]){
	int i = 0;
	while (sir[i] != '\0')
		i++;
	return i;
}

int numberChar(char sir[], char c){
	int i, k = 0;
	for (i = 0; i < stringLength(sir); i++)
		if (sir[i] == c)
			k++;
	return k;
}

int stringCompare(char sir1[], char sir2[])
{
	int i, length;
	if (stringLength(sir1) > stringLength(sir2))
		length = stringLength(sir2);
	else
		length = stringLength(sir1);
	for (i = 0; i < length; i++)
		if (sir1[i] > sir2[i])
			return 1;
		else if (sir1[i] < sir2[i])
			return -1;
	return 0;
}

int cautareSubsir(char sir1[], char subsir[]) {
	int i,k=0;
	for (i = 0; i < stringLength(sir1); i++) {
		if (sir1[i] == subsir[k])
		{
			k++;
		}
		while (k != 0 && k < stringLength(subsir)) {
			i++;
			if (sir1[i] == subsir[k])
				k++;
		}
		if (k == stringLength(subsir))
			return 1;
		else
			k = 0;
	}
	return 0;
}

int main() {
	char sir[20], sir2[20], char_cautat, sir_cautat[20];
	int i;
	printf("Introduceti sirul de caractere:\n");
	scanf("%s", sir);
	printf("\nNumarul de caractere din %s este %d\n\n", sir, stringLength(sir));
	printf("\nCe caracter doriti sa cautati in sir?\n");
	getchar();
	scanf("%c", &char_cautat);
	printf("\nCaracterul %c se intalneste de %d ori in sir\n\n", char_cautat,numberChar(sir, char_cautat));
	printf("Introduceti al 2-lea sir de caractere:\n");
	scanf("%s", sir2);
	if (stringCompare(sir, sir2) == 1)
		printf("\nSir 1 > Sir 2");
	else if (stringCompare(sir, sir2) == -1)
		printf("\nSir 1 < Sir 2");
	else
		printf("\nSir1 = Sir2");
	printf("\nCe subsir doriti sa cautati in sir?\n");
	scanf("%s", sir_cautat);
	if (cautareSubsir(sir, sir_cautat))
		printf("\nSubsirul %s a fost gasit in %s", sir_cautat, sir);
	else
		printf("\nSubsirul %s NU a fost gasit in %s", sir_cautat, sir);
	printf("\n\n");

}