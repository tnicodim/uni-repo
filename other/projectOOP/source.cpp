#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Persoana {
public:
	int varsta;
	string nume;
};
class Student :public Persoana {
public:
	int an;
	string matricol;
	string facultate;
	Student(int, string, int, string, string);
	void afisare();
};
class Angajat :public Persoana {
public:
	int salariu;
	string companie;
	Angajat(int, string, int, string);
	void afisare();
};

Student::Student(int v, string n, int a, string m, string f) {
	varsta = v;
	nume = n;
	an = a;
	matricol = m;
	facultate = f;
}
Angajat::Angajat(int v, string n, int s, string c) {
	varsta = v;
	nume = n;
	salariu = s;
	companie = c;
}

void Student::afisare() {
	cout << "\nNume: " << nume << "\nVarsta: " << varsta << "\nFacultate: " << facultate << "\nAn: " << an << "\nMatricol: " << matricol << "\n\n";
}
void Angajat::afisare() {
	cout << "\nNume: " << nume << "\nVarsta: " << varsta << "\nCompanie: " << companie << "\nSalariu: " << salariu << "\n\n";
}

vector<Student> studentList;
vector<Angajat> angajatList;


int validareMatricol(string matricol) {
	int i;
	char letter;
	if (matricol.size() != 7)
		return 1;
	for (i = 0; i < 2; i++) {
		letter = matricol[i];
		if (!(letter >= 'A' && letter <= 'Z'))
			return 2;
	}
	for (i = 2; i < 7; i++) {
		letter = matricol[i];
		if (!(letter >= '0' && letter <= '9'))
			return 2;
	}
	return 0;
}

void readFromFile() {
	ifstream fis;
	fis.open("studenti.txt");
	if (fis.is_open()) {
		while (fis) {
			string name, facultate, matricol, myline;
			int varsta, an;
			stringstream stringnum1, stringnum2;
			getline(fis, name);
			if (name == "") {
				fis.close();
				break;
			}
			getline(fis, myline);
			stringnum1 << myline;
			stringnum1 >> varsta;
			getline(fis, facultate);
			getline(fis, myline);
			stringnum2 << myline;
			stringnum2 >> an;
			getline(fis, matricol);
			Student a(varsta, name, an, matricol, facultate);
			studentList.push_back(a);
		}
	}
	else {
		cout << "Couldn't open file\n";
	}
	fis.open("angajati.txt");
	if (fis.is_open()) {
		while (fis) {
			string name, companie, myline;
			int varsta, salariu;
			stringstream stringnum1, stringnum2;
			getline(fis, name);
			if (name == "") {
				fis.close();
				break;
			}
			getline(fis, myline);
			stringnum1 << myline;
			stringnum1 >> varsta;
			getline(fis, companie);
			getline(fis, myline);
			stringnum2 << myline;
			stringnum2 >> salariu;
			Angajat m(varsta, name, salariu, companie);
			angajatList.push_back(m);
		}
	}
	else {
		cout << "Couldn't open file\n";
	}
}

void saveToFile() {
	ofstream fis;
	fis.open("studenti.txt", std::ofstream::out | std::ofstream::trunc);
	if (fis.is_open())
	{
		for (auto student : studentList) {
			fis << student.nume << endl << student.varsta << endl << student.facultate << endl << student.an << endl << student.matricol << endl;
		}
		fis.close();
	}
	else {
		cout << "\nNu s-a putut deschide fisierul studenti.txt";
		system("pause");
	}
	fis.open("angajati.txt", std::ofstream::out | std::ofstream::trunc);
	if (fis.is_open())
	{
		for (auto angajat : angajatList) {
			fis << angajat.nume << endl << angajat.varsta << endl << angajat.companie << endl << angajat.salariu << endl;
		}
		fis.close();
	}
	else {
		cout << "\nNu s-a putut deschide fisierul angajati.txt";
		system("pause");
	}
}

int main() {
	cin.exceptions(std::istream::failbit);
	readFromFile();
	while (1) {
		int opt, opt2;
		cout << "\n------------------------------------------------\n1. Adaugare persoana\n2. Afisare studenti\n3. Afisare angajati\n4. Afisare persoane\n5. Cautare persoana\n6. Stergere persoane\n0. Exit\n------------------------------------------------\nAlegeti optiunea: ";
		cin >> opt;
		switch (opt) {
		case 1:
			do {
				cout << "\n------------------------\n1. Adaugare student\n2. Adaugare angajat\n0. Back\n------------------------\nAlegeti optiunea: ";
				cin >> opt2;
				switch (opt2) {
				case 1:
				{
					bool aux = true;
					string nume, matricol, facultate;
					int varsta, an;
					cout << "Nume: ";
					getline(cin, nume);
					getline(cin, nume);
				do {
					try {
						cout << "Varsta: ";
						cin >> varsta;
						aux = true;
					}
					catch (std::ios_base::failure& fail) {
						aux = false;
						cout << "Varsta gresita, reintroduceti:" << endl;
						cin.clear();
						string tmp;
						getline(cin, tmp);
					}
				} while (aux == false);
				do {
					try {
						cout << "An: ";
						cin >> an;
						aux = true;
					}
					catch (std::ios_base::failure& fail) {
						aux = false;
						cout << "An gresit, reintroduceti:" << endl;
						cin.clear();
						string tmp;
						getline(cin, tmp);
					}
				} while (aux == false);
					cout << "Facultate: ";
					getline(cin, facultate);
					getline(cin, facultate);
					do
					{
						try{
						cout << "Matricol: ";
						getline(cin, matricol);
						int temp = validareMatricol(matricol);
						if (temp != 0)
							throw temp;
						aux = true;
						}
						catch (int err) {
							if (err == 1)
								printf("\nWrong size! Try again!\n");
							if (err == 2)
								printf("\nWrong format (XX12345)! Try again!\n");
							aux = false;
						}
					} while (aux == false);
					Student a(varsta, nume, an, matricol, facultate);
					studentList.push_back(a);
					saveToFile();
					break;
				}
				case 2:
				{
					bool aux = true;
					string nume, companie;
					int varsta, salariu;
					cout << "Nume: ";
					getline(cin, nume);
					getline(cin, nume);
					do {
						try {
							cout << "Varsta: ";
							cin >> varsta;
							aux = true;
						}
						catch (std::ios_base::failure& fail) {
							aux = false;
							cout << "Varsta gresita, reintroduceti:" << endl;
							cin.clear();
							string tmp;
							getline(cin, tmp);
						}
					} while (aux == false);
					cout << "Companie: ";
					getline(cin, companie);
					getline(cin, companie);
					do {
						try {
							cout << "Salariu: ";
							cin >> salariu;
							aux = true;
						}
						catch (std::ios_base::failure& fail) {
							aux = false;
							cout << "Salariu gresit, reintroduceti:" << endl;
							cin.clear();
							string tmp;
							getline(cin, tmp);
						}
					} while (aux == false);
					Angajat m(varsta, nume, salariu, companie);
					angajatList.push_back(m);
					saveToFile();
				break;
				}
				case 0:
					break;
				default:
					cout << "\nOptiune invalida!";
					break;
				}
			} while (opt2 != 0);
			break;
		case 2: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nStudenti\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto student : studentList) {
				student.afisare();
			}
			break;
		}
		case 3: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nAngajati\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto angajat : angajatList) {
				angajat.afisare();
			}
			break;
		}
		case 4:
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nStudenti\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto student : studentList) {
				student.afisare();
			}
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nAngajati\n~~~~~~~~~~~~~~~~~~~~~\n ";
			for (auto angajat : angajatList) {
				angajat.afisare();
			}
			break;
		case 5: {
			string numeCautat;
			int flag = 0;
			cout << "Nume cautat: ";
			getline(cin, numeCautat);
			getline(cin, numeCautat);
			for (auto student : studentList) {
				if (student.nume == numeCautat) {
					printf("\nStudent found!\n");
					student.afisare();
					flag++;
				}
			}
			for (auto angajat : angajatList) {
				if (angajat.nume == numeCautat) {
					printf("\nAngajat found!\n");
					angajat.afisare();
					flag++;
				}
			}
			if (!flag)
				printf("\nNo person found!\n");
			break;
		}
		case 6:
		{
			int counter = 0;
			int flag = 0;
			string numeCautat;
			cout << "Nume cautat: ";
			getline(cin, numeCautat);
			getline(cin, numeCautat);
			for (auto student : studentList) {
				if (student.nume == numeCautat) {
					student.afisare();
					printf("\nStudent deleted!\n");
					studentList.erase(studentList.begin() + counter);
					saveToFile();
					flag = 1;
				}
				counter++;
			}
			counter = 0;
			for (auto angajat : angajatList) {
				if (angajat.nume == numeCautat) {
					angajat.afisare();
					printf("\nAngajat deleted!\n");
					angajatList.erase(angajatList.begin() + counter);
					saveToFile();
					flag = 1;
				}
				counter++;
				if (!flag)
					printf("\nNo person found!\n");
				break;
			}
		}
		break;
		case 0:
			exit(0);
		default:
			cout << "\nOptiune invalida!";
			break;
		}
	}
	return 0;
}