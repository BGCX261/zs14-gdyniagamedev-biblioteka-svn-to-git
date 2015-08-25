#include <iostream>
#include <vector>
#include <string>
using namespace std;

class ksiazki{
public:
	string tytul;
	int rok_wydania;
	int wypozyczona;
	void dodaj_ksiazke();
	void wypozycz_ksiazke();
	void oddaj_ksiazke();
};

void ksiazki::dodaj_ksiazke(){
	ksiazki* biblioteka;
	biblioteka = new ksiazki;

	cout<<"obiekt utworzony!"<<endl;
	cin.get();
	cin.get();
	delete biblioteka;
	cout<<"obiekt zniszczony!"<<endl;
	cin.get();
	cin.get();
} 

vector <class ksiazki> biblioteka;
void main(){
	int a;
	cout<<"                                 BIBLIOTEKARZ 2011"<<endl;
	cout<<"1 dodaj ksiazke"<<endl;
	cout<<"2 wypozycz ksiazke"<<endl;
	cout<<"3 oddaj ksiazke"<<endl;
	cin>>a;
	switch(a){
	case 1:
		break;
	case 2:
		break;
	case 3:
		break;
	}
}