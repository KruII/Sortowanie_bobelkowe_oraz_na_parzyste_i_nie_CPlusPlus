#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> parzyste;
vector<int> nieparzyste;
void sortowanie_danych(){
	int liczba = 0;
	int liczbapobran = 0;
	cout << "Ile danych pobraæ: ";
	cin >> liczbapobran;
	for (int i = 0; i < liczbapobran; i++){
		cout << "Podaj dane: ";
		cin >> liczba;
		if (liczba % 2 == 0) {
			parzyste.push_back(liczba);
		}
		else{
			nieparzyste.push_back(liczba);
		}
	}

}
void sortowanie_babelkowe(int parzystetab[], int iloscmiejscwtablicy)
{
	for (int i = 0; i < iloscmiejscwtablicy; i++)
		for (int j = 1; j < iloscmiejscwtablicy - i; j++)
			if (parzystetab[j - 1] > parzystetab[j])
				swap(parzystetab[j - 1], parzystetab[j]);
}
void wyprowadz_parzyste(int parzystetab[], int iloscmiejscwtablicy) {
	iloscmiejscwtablicy = parzyste.size();
	parzystetab = new int[iloscmiejscwtablicy];
	for (int i = 0; i < parzyste.size(); i++){
		int t = parzyste[i];
		parzystetab[i] = t;
	}
	sortowanie_babelkowe(parzystetab, iloscmiejscwtablicy);
	cout << "Parzyste:" << endl;
	for (int i = 0; i < iloscmiejscwtablicy; i++)
		cout << parzystetab[i] << " ";
}
void wyprowadz_nieparzyste() {
	sort(nieparzyste.begin(), nieparzyste.end());
	reverse(nieparzyste.begin(), nieparzyste.end());
	cout << "\nNieparzyste:" << endl;
	for (int i = 0; i < nieparzyste.size(); i++)
		cout << nieparzyste[i] << " ";
}

int main()
{
	int* parzystetab, iloscmiejscwtablicy;

	setlocale(LC_CTYPE, "Polish");
	sortowanie_danych();
	wyprowadz_parzyste(parzystetab, iloscmiejscwtablicy);
	wyprowadz_nieparzyste();
}

