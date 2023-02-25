#include <iostream>
#include <conio.h>
using namespace std;
//functie care va returna o valoarea negativa
int negativ(int& i)
{
	i = -i;
	return i;
}
int main()
{
	int valoare;
	cout << "Dati valoarea: ";
	cin >> valoare;
	cout << "Valoarea negativa este: " << negativ(valoare);
	_getch();
	return 0;
}