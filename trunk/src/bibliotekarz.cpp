#include "biblioteka.h"
#include "uzytkownik.h"
#include "artykul.h"
#include "ksiazka.h"
#include "egzemplarz.h"
#include <iostream>
using namespace std;

int main(){
	// "dane\\dvd.txt" razem ze zmianami w biblioteka.cpp, dvd.h i dvd.cpp to zadanie nr 5
	Biblioteka mojaBiblioteka( "dane\\ksiazki.txt", "dane\\dvd.txt", "dane\\uzytkownicy.txt" );
	mojaBiblioteka.wyswietlZbior();

	// zadanie 2
	mojaBiblioteka.dodajEgzemplarz( new Ksiazka( "Lato w dolinie Muminkow",
												"Tove Jansson",
												"Znak",
												2011,
												"02938402394" ),
												"LatMum-01" );
	cout << endl
		<< "zadanie nr 2"
		<< endl;
	mojaBiblioteka.wyswietlZbior();


	// zadanie nr 3
	mojaBiblioteka.dodajUzytkownika( new Uzytkownik( "Krzysiek", "Szymañski", "ul. Kameliowa, Gdynia" ) );
	mojaBiblioteka.wypozycz(0, "LatMum-01");
	cout << endl
		<< "zadanie nr 3"
		<< endl;
	mojaBiblioteka.wyswietlZbior();

	// zadanie nr 4
	mojaBiblioteka.oddaj( "LatMum-01" );
	cout << endl
		<< "zadanie nr 4"
		<< endl;
	mojaBiblioteka.wyswietlZbior();
}

