#include "ksiazka.h"
#include <sstream>

using namespace std;

Ksiazka::Ksiazka():
	//tytul_(""),autor_(""),wydawca_(""), stringi zainicjalizuja sie same! - nie trzeba ich inicjalizowac jawnie
			 rokWydania_(1950)/*,ISBN_("")*/{} 

Ksiazka::Ksiazka(const string& tytul,
		const string& autor,
		const string& wydawca,
		int rokWydania,
		const string& ISBN):
		 tytul_(tytul),autor_(autor),wydawca_(wydawca),
			 rokWydania_(rokWydania),ISBN_(ISBN){}

string Ksiazka::info() const{
	stringstream ss;
	ss << "Autor: " << autor_ << endl
				<< "Tytul: " << tytul_ << endl
				<< "Wyd.: " << wydawca_ << ", "
				<< rokWydania_ << endl
				<< "ISBN: " << ISBN_ << endl;
	return ss.str();	
}

string Ksiazka::id() const{
	return ISBN_;
}