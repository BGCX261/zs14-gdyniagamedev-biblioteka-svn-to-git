#include "egzemplarz.h"
#include "artykul.h"
#include "wypozyczenie.h"
#include <ctime>

Egzemplarz::Egzemplarz(Artykul* art, const string& syg):
	artykul_(art), sygnatura_(syg), wypozyczony_( false )
	{}

Wypozyczenie* Egzemplarz::wypozycz(Uzytkownik* u){	
	wypozyczony_ = true;
	time_t dataWypozyczenia;
	time ( &dataWypozyczenia );
	historia_.push_back( new Wypozyczenie( u, this, ctime( &dataWypozyczenia ) ) );
	return historia_.back();
}

void Egzemplarz::odstawNaPolke(){	
	wypozyczony_ = false;
	time_t dataOddania;
	time ( &dataOddania );
	historia_.back()->zamknij( ctime( &dataOddania ) );
}

ostream& operator << (ostream& os, const Egzemplarz& e){
		 
	return os << e.artykul_->info() << endl
				<< "Sygnatura: " << e.sygnatura() << endl
				<< ( e.jestWypozyczony() ? "wypozyczony" : "w bibliotece" )
				<< endl;
}