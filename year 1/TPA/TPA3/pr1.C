#include <stdio.h>
#include <stdlib.h>

#define MAX 50

void push(int n);
void pop();
void Init(int k);
int Succesor(int k);
int Valid(int k);
int Solution(int k);
void Print();
void Back(int n);

int v[MAX];
int m = 0;
int n = 4;
int k = -1;

int main() {
	Back(n);
	return 0;
}

void Back(int n) {
	int isS, isV;
	k = 0; 
	Init(k);
	while (k >= 0) { // cât timp stiva nu e vidă
		isS = 0; isV = 0;
		if (k < n) // nu face sens depăşirea nivelului n în stivă 
			do {
			isS = Succesor(k);
		if (isS) 
			isV = Valid(k);
	} while (isS && !isV); // ...există succesor dar nu este valid
	if (isS) //este succesor si este valid
		if (Solution(k)) // verifică candidatul la soluţie
			Print(k); // afişează soluţia
		else { // dacă nu este soluţie
		k++; 
		Init(k); // creşte vârful stivei şi iniţializează
		}
	else // nu există succesor pt. valoarea curentă din stivă
		k--; // -> se coboară o poziţie în stivă
	}
}

void Print(int k) {
	int i;
	printf("Solution %d : ", ++m);
	for (i = 0; i < n; i++)
		printf("%d ", v[i]);
	printf("\n");
}

int Solution(int k) {
	return (k == n-1);
}

int Valid(int k) {
	int i;
	for (i = 0; i < k; i++)
		if (v[i] == v[k])
			return 0;
	return 1;

}

int Succesor(int k) {
	if (v[k] < n) {
		v[k]++;
		return 1;
	}
	else
		return 0;
}

void Init(int k) {
	v[k] = 0;
}

void push(int n) {
	if (k == MAX - 1)
		printf("\n-----------------\nOVERFLOW!!!\tOVERFLOW!!!\tOVERFLOW!!!\n-----------------\n");
	else {
		k++;
		printf("\nInserted: %d", n);
		v[k] = n;
	}
}

void pop() {
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\nPopped: %d", v[k]);
		v[k] = '#';
		k--;
	}

}