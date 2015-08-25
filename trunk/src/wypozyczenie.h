#ifndef _WYPOZYCZENIE_H_
#define _WYPOZYCZENIE_H_

#include <string>
using namespace std;

class Uzytkownik;
class Egzemplarz;

class Wypozyczenie{
public:
	Wypozyczenie(Uzytkownik*, Egzemplarz*, const string&);
	void zamknij(const string&);

private:
	Uzytkownik*				uzytkownik_;
	Egzemplarz*				egzemplarz_;
	string					wypozyczono_;
	string					oddano_;
};

#endif