#include "biblioteka.h"
#include "artykul.h"
#include "ksiazka.h"
#include "uzytkownik.h"
#include "egzemplarz.h"
#include "dvd.h"
#include <iostream>
#include <fstream>

using namespace std;

Biblioteka::Biblioteka(const string& plikKsiazki,
	const string& plikFilmy,
	const string& plikUzytkownicy){
	
	ifstream ifs(plikKsiazki.c_str());	
	string strIleKsiazek;
	int ileKsiazek;
	getline(ifs, strIleKsiazek);
	ileKsiazek = strtol(strIleKsiazek.c_str(), NULL, 10);
	
	string tytul, autor, wydawca, strRokWydania, ISBN, syg;
	int rokWydania;
			
	for ( int i = 0; i != ileKsiazek; ++i ){
		getline(ifs, tytul);
		getline(ifs, autor);
		getline(ifs, wydawca);
		getline(ifs, strRokWydania);
		rokWydania = strtol(strRokWydania.c_str(), NULL, 10);
		getline(ifs, ISBN);
		getline(ifs, syg);
		// tu wyciek pamieci, jesli Ksiazka juz istnieje!
		// jak to rozwiazac?
		dodajEgzemplarz( new Ksiazka( tytul, autor, wydawca, rokWydania, ISBN ),
			syg );
	}	
	ifs.close();

	ifs.open( plikFilmy.c_str() );
	string strIleFilmow;
	int ileFilmow;
	getline(ifs, strIleFilmow);
	ileFilmow = strtol(strIleFilmow.c_str(), NULL, 10);

	string rezyser, wytwornia, strTemp, sygnatura;
	vector<string> obsada;
	int iluAktorow, rokProdukcji, czasTrwaniaMin;

	for ( int i = 0; i != ileFilmow; ++i ){
		getline(ifs, tytul);
		getline(ifs, rezyser);
		getline(ifs, strTemp);
		iluAktorow = strtol(strTemp.c_str(), NULL, 10);
		obsada.resize( iluAktorow );
		for (int i = 0; i != iluAktorow; ++i ){
			getline(ifs, obsada[i]);
		}
		getline(ifs, wytwornia);
		getline(ifs, strTemp);
		rokProdukcji = strtol(strTemp.c_str(), NULL, 10);
		getline(ifs, strTemp);
		czasTrwaniaMin = strtol(strTemp.c_str(), NULL, 10);
		getline(ifs, syg);
		dodajEgzemplarz( new Dvd( tytul, rezyser, obsada, wytwornia, rokProdukcji, czasTrwaniaMin ),
			syg );
	}
	ifs.close();

	ifs.open( plikUzytkownicy.c_str() );
	string strIleUzytkownikow;
	int ileUzytkownikow;
	getline(ifs, strIleUzytkownikow);
	ileUzytkownikow = strtol(strIleUzytkownikow.c_str(), NULL, 10);

	string imie, nazwisko, adres;

	for ( int i = 0; i != ileUzytkownikow; ++i ){
		getline(ifs, imie);
		getline(ifs, nazwisko);
		getline(ifs, adres);
		dodajUzytkownika( new Uzytkownik( imie, nazwisko, adres ) );
	}
}

void Biblioteka::wyswietlZbior(){
	cout << "---------------------------------------------" << endl;
	for ( list<Egzemplarz*>::iterator it = egzemplarze_.begin();
		it != egzemplarze_.end();
		++it ){
			// uzupelnic
		cout << **it << endl;
	}
	cout << "---------------------------------------------" << endl;
}

Biblioteka::~Biblioteka(){
	for ( list<Egzemplarz*>::iterator it = egzemplarze_.begin();
		it != egzemplarze_.end();
		++it ){
			delete *it;
	}

	for ( map<string, Artykul*>::iterator it = artykuly_.begin();
		it != artykuly_.end();
		++it ){
			delete it->second;
	}

	for ( list<Uzytkownik*>::iterator it = uzytkownicy_.begin();
		it != uzytkownicy_.end();
		++it ){
			delete *it;
	}
}

void Biblioteka::dodajEgzemplarz(Artykul* a, const string& syg){
	list<Egzemplarz*>::iterator itEgz = egzemplarze_.begin();
	for ( ; itEgz != egzemplarze_.end(); ++itEgz ){
			if ( (*itEgz)->sygnatura() == syg ){
				// egzemplarz o takiej sygnaturze juz istnieje - nie mozna dodac
				return;
			}
	}

	artykuly_[ a->id() ] = a;
	egzemplarze_.push_back( new Egzemplarz( a, syg ) );
}

void Biblioteka::dodajUzytkownika(Uzytkownik* u){
	uzytkownicy_.push_back( u );
}
	
bool Biblioteka::wypozycz(const int& idUzytkownika, const string& syg){
	list<Uzytkownik*>::iterator itUzyt = uzytkownicy_.begin();
	for ( ; itUzyt != uzytkownicy_.end(); ++itUzyt ){
			if ( (*itUzyt)->id() == idUzytkownika ){
				break;
			}
	}
	if ( itUzyt == uzytkownicy_.end() ){
		// nie ma uzytkownika o takim id
		return false;
	}

	list<Egzemplarz*>::iterator itEgz = egzemplarze_.begin();
	for ( ; itEgz != egzemplarze_.end(); ++itEgz ){
			if ( (*itEgz)->sygnatura() == syg ){
				break;
			}
	}
	if ( itEgz == egzemplarze_.end() ){
		// nie ma egzemplarza o takiej sygnaturze
		return false;
	}

	(*itUzyt)->wypozycz( *itEgz );
	return true;
}

bool Biblioteka::oddaj(const string& syg){
	list<Egzemplarz*>::iterator itEgz = egzemplarze_.begin();
	for ( ; itEgz != egzemplarze_.end(); ++itEgz ){
			if ( (*itEgz)->sygnatura() == syg ){
				break;
			}
	}
	if ( itEgz == egzemplarze_.end() ){
		// nie ma egzemplarza o takiej sygnaturze
		return false;
	}

	(*itEgz)->odstawNaPolke();
	return true;
}
