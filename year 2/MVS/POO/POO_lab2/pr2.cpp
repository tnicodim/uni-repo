#include<iostream>
#include<conio.h>
#include <string>

using namespace std;

class Student{
	string *nume, *pren;
	int *grupa, *cod_postal;
public:
	Student(string n, string p, int g, int c);//Constructor
	~Student();//Destructor
	void afisare_date();
};
//constructor
Student::Student(string n, string p, int g, int c)
{
	nume = new string;
	pren = new string;
	grupa = new int;
	cod_postal = new int;
	*nume = n;
	*pren = p;
	*grupa = g;
	*cod_postal = c;
	cout << "Constructor: Succes!\n";
}
//funcție pentru afișarea datelor
void Student::afisare_date()
{
	cout << "Nume :" << *nume << endl;
	cout << "Prenume:" << *pren << endl;
	cout << "Grupa:" << *grupa << endl;
	cout << "Cod postal :" << *cod_postal;
}
//destructor
Student :: ~Student()
{
	delete nume;
	delete pren;
	delete grupa;
	delete cod_postal;
	cout << "\nDestructor: Eliberare memorie! ";
}


void main()
{
	string nume, pren;
	int grupa, cod_postal;
	cout << "Nume:";
	getline(cin, nume);
	cout << "Prenume:";
	getline(cin, pren);
	cout << "Grupa:";
	cin >> grupa;
	cout << "Cod postal: ";
	cin >> cod_postal;
	//crearea unui obiect de tip Student
	Student s(nume, pren, grupa, cod_postal);
	//afișarea informațiilor
	s.afisare_date();
	_getch();
	s.~Student(); //apelare explicită
	_getch();
}