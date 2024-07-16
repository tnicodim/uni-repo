#include <fstream>
#include <iostream>
#include <conio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

class Media {
public:
	string name;
};
class Movie :public Media {
public:
	string mainactor;
	Movie(string, string);
};
class Series :public Media {
public:
	int seasons;
	Series(string, int);
	void afisare();
};

Movie::Movie(string n,string a){
	name = n;
	mainactor = a;
}
Series::Series(string n, int s){
	name = n;
	seasons = s;
}

void Series::afisare() {
	cout << "\nName: " << name << "\nSeasons: " << seasons << "\n\n";
}

vector<Movie> movieList;
vector<Series> seriesList;

bool compareMovies(const Movie& left, const Movie& right)
{
	return left.name < right.name;
}
bool compareSeries(const Series& left, const Series& right)
{
	return left.name < right.name;
}

ostream& operator<<(ostream& iesire, Movie st)
{
	iesire << "\nName: " << st.name << "\nMain Actor: " << st.mainactor << "\n\n";
	return iesire;
}


int main() {
	cin.exceptions(std::istream::failbit);
	while (1) {
		int opt, opt2;
		cout << "\n------------------------------------------------\n1. Add media\n2. Show movies in alphabetical order\n3. Show series in alphabetical order\n4. Search media\n0. Exit\n------------------------------------------------\nOption: ";
		cin >> opt;
		switch (opt) {
		case 1:
			do {
				cout << "\n------------------------\n1. Add movie\n2. Add series\n0. Back\n------------------------\nOption: ";
				cin >> opt2;
				switch (opt2) {
				case 1:
				{
					string name, mainactor;
					cout << "Name: ";
					getline(cin, name);
					getline(cin, name);
					cout << "Main Actor: ";
					getline(cin, mainactor);
					Movie a(name, mainactor);
					movieList.push_back(a);
					break;
				}
				case 2:
				{
					bool aux = true;
					string name;
					int seasons;
					cout << "Name: ";
					getline(cin, name);
					getline(cin, name);
					do {
						try {
							cout << "Seasons: ";
							cin >> seasons;
							aux = true;
						}
						catch (std::ios_base::failure& fail) {
							aux = false;
							cout << "Seasons should be a number!:" << endl;
							cin.clear();
							string tmp;
							getline(cin, tmp);
						}
					} while (aux == false);
					Series a(name, seasons);
					seriesList.push_back(a);
					break;
				}
				case 0:
					break;
				default:
					cout << "\Invalid Option";
					break;
				}
			} while (opt2 != 0);
			break;
		case 2: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nMovies\n~~~~~~~~~~~~~~~~~~~~~\n ";
			sort(movieList.begin(), movieList.end(), compareMovies);
			for (auto movie : movieList) {
				cout << movie;
			}
			break;
		}
		case 3: {
			cout << "\n~~~~~~~~~~~~~~~~~~~~~\nSeries\n~~~~~~~~~~~~~~~~~~~~~\n ";
			sort(seriesList.begin(), seriesList.end(), compareSeries);
			for (auto series : seriesList) {
				series.afisare();
			}
			break;
		}

		case 4: {
			ofstream ofs;
			ofs.open("search.txt", std::ofstream::out | std::ofstream::trunc);
			ofs.close();
			string nameSearch;
			cout << "Search by name: ";
			getline(cin, nameSearch);
			getline(cin, nameSearch);
			for (auto movie : movieList) {
				if (movie.name == nameSearch) {
					printf("\nMovie found!\n");
					cout << movie;
					ofstream fis;
					fis.open("search.txt", std::ios_base::app);
					if (fis.is_open())
					{
						
						fis << "MOVIE:\n" << "\nName: " << movie.name << "\nMain Actor: " << movie.mainactor << "\n\n";
						fis.close();
					}
					else {
						cout << "\nError opening search.txt";
						system("pause");
					}
				}
			}
			for (auto series : seriesList) {
				if (series.name == nameSearch) {
					printf("\nSeries found!\n");
					series.afisare();
					ofstream fis;
					fis.open("search.txt", std::ios_base::app);
					if (fis.is_open())
					{
						fis << "SERIES:\n" << "\nName: " << series.name << "\nSeasons: " << series.seasons << "\n\n";
						fis.close();
					}
					else {
						cout << "\nError opening search.txt";
						system("pause");
					}
				}
			}
			break;
		}
		case 0:
			exit(0);
		default:
			cout << "\nInvalid option!";
			break;
		}
	}
	return 0;
}