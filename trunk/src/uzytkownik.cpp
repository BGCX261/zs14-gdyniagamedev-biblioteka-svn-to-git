#include "uzytkownik.h"
#include "egzemplarz.h"
#include <string>

int	Uzytkownik::licznikUzytkownikow_ = 0;

Uzytkownik::Uzytkownik(const string& imie,
	const string& nazwisko,
	const string& adres):
imie_(imie), nazwisko_(nazwisko), adres_(adres)
{
		id_ = licznikUzytkownikow_++;
}

int Uzytkownik::id() const {
	return id_;
}

// ta f-cja powinna byc wolana tylko z Uzytkownik::wypozycz(Egzemplarz*)
// zeby zapewnic zgodnosc danych
void Uzytkownik::wypozycz(Egzemplarz* e){
	historia_.push_back( e->wypozycz(this) );
}
