#include <stdio.h>
#include <stdlib.h>

#define MAX 20

void push(int n);
void pop();
void show();
void Manna_Pnueli(int n);

int v[MAX];
int starting_number;
int k = -1;

int main() {
	printf("Introduceti numarul pentru functia Manna Pnueli: ");
	scanf("%d", &starting_number);
	push(starting_number);
	Manna_Pnueli(starting_number);
	system("pause");
	return 0;
}







void push(int n){
	if (k == MAX - 1)
		printf("\n-----------------\nOVERFLOW!!!\tOVERFLOW!!!\tOVERFLOW!!!\n-----------------\n");
	else {
		k++;
		printf("\nInserted: %d", n);
		v[k]=n;
	}
}

void pop() {
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\nPopped: %d", v[k]);
		v[k] = -1;
		k--;
	}

}

void show(){ 
	int i;
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\n\nStack:");
		for (i = k; i >= 0; i--)
			printf("\n%d", v[i]);
		printf("\n");
	}

}

void Manna_Pnueli(int n)
{
	int i;
	while (1) {
		if (v[k] < 12) {
			n = n + 2;
			push(n);
			show();
		}
		else
		{
			pop();
			n--;
			if (k == -1) {
				printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\nRezultatul f(%d) este %d\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n", starting_number, n);
				break;
			}
			pop();
			push(n);
			show();
		}
	}

}
