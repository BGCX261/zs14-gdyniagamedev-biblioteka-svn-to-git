#include "wypozyczenie.h"

Wypozyczenie::Wypozyczenie(Uzytkownik* u, Egzemplarz* e, const string& data):
uzytkownik_( u ), egzemplarz_( e ), wypozyczono_( data ), oddano_(" - "){}

void Wypozyczenie::zamknij(const string& data){
	oddano_ = data;
}