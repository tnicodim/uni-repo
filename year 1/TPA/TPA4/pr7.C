/*7. Implementati o functie care primeste citeste de la intrarea standard o expresie aritmetica
scrisa in notatie poloneza si returneaza valoarea acesteia. Spre deosebire de implementarea de la curs,
va trebui sa prelucrati numere (nu doar cifre) (reale, cu semn).

Varianta simplificata: numere naturale (multicifra).
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 50

float v[MAX], value;
char saux[10];
int k = -1;


void push(float n);
void pop();
void show();
float prefix(char* s) {
	int i, ii, j = 0;
	for (i = strlen(s) - 1; i >= 0; i--) {
		if (s[i] == '0' || s[i] == '1' || s[i] == '2' || s[i] == '3' || s[i] == '4' || s[i] == '5' || s[i] == '6' || s[i] == '7' || s[i] == '8' || s[i] == '9') {
			ii = i;
			while (s[i] != ' ')
				i--;
			strncpy(saux, s + i + 1, ii - i);
			push(atof(saux));
			memset(saux, 0, strlen(saux));
		}
		else if (s[i] != ' ') {
			if (s[i] == '*') {
				value = v[k] * v[k - 1];
				pop();
				pop();
				push(value);
			}
			else if (s[i] == '/') {
				value = v[k] / v[k - 1];
				pop();
				pop();
				push(value);
			}
			else if (s[i] == '+') {
				value = v[k] + v[k - 1];
				pop();
				pop();
				push(value);
			}
			else if (s[i] == '-') {
				value = v[k] - v[k - 1];
				pop();
				pop();
				push(value);
			}
			else if (s[i] == '^') {
				value = pow((double)v[k], (double)v[k - 1]);
				pop();
				pop();
				push(value);
			}
		}
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return value;
}


int main() {
	char sir[50];
	printf("Introduceti expresia prefixata:\n");
	gets(sir);
	printf("Rezultatul expresiei %s este %.3f", sir, prefix(sir));
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	return 0;
}

void push(float n) {
	if (k == MAX - 1)
		printf("\n-----------------\nOVERFLOW!!!\tOVERFLOW!!!\tOVERFLOW!!!\n-----------------\n");
	else {
		k++;
		printf("\nInserted: %.2f", n);
		v[k] = n;
	}
}

void pop() {
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\nPopped: %.2f", v[k]);
		v[k] = '-1';
		k--;
	}

}

void show() {
	int i;
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\n\nStack:");
		for (i = k; i >= 0; i--)
			printf("\n%.2f", v[i]);
		printf("\n");
	}
}