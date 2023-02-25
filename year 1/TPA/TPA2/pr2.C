#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

void push(char n);
void pop();
void show();
int priority(char c);

char v[MAX];
char infix[MAX], fp[MAX];
int k = -1;

int main() {
	int i, j = 0;
	printf("Introduceti expresia: ");
	gets(infix);
	for (i = 0; i < strlen(infix); i++)
	{
		if (infix[i] == '(')
			push(infix[i]);
		else if (infix[i] == ')') {

			while (v[k] != '(')
			{
				fp[j++] = v[k];
				pop();
			}
			pop();
		}
		else if (infix[i] == '+' || infix[i] == '-' || infix[i] == '*' || infix[i] == '/')
		{
			while (priority(v[k]) >= priority(infix[i]))
			{
				fp[j++] = v[k];
				pop();
			}
			push(infix[i]);
		}
		else
			fp[j++] = infix[i];
	}
	while (k != -1)
	{
		fp[j++] = v[k];
		pop();
	}
	printf("\n~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	puts(fp);
	printf("~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
	system("pause");
	return 0;
}





int priority(char c) 
{
	if (c == '(' || c == ')')
		return 0;
	else if (c == '+' || c == '-')
		return 1;
	else if (c == '*' || c == '/')
		return 2;
}

void push(char n) {
	if (k == MAX - 1)
		printf("\n-----------------\nOVERFLOW!!!\tOVERFLOW!!!\tOVERFLOW!!!\n-----------------\n");
	else {
		k++;
		printf("\nInserted: %c", n);
		v[k] = n;
	}
}

void pop() {
	if (k < 0)
		printf("\n-----------------\nUNDERFLOW!!!\tUNDERFLOW!!!\tUNDERFLOW!!!\n-----------------\n");
	else {
		printf("\nPopped: %c", v[k]);
		v[k] = '#';
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
			printf("\n%c", v[i]);
		printf("\n");
	}

}
