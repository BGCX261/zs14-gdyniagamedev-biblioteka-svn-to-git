#ifndef _EGZEMPLARZ_H_
#define _EGZEMPLARZ_H_

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Artykul;
class Wypozyczenie;
class Uzytkownik;

class Egzemplarz{
public:
	Egzemplarz(Artykul*, const string&);
	bool jestWypozyczony() const { return wypozyczony_; }
	Wypozyczenie* wypozycz(Uzytkownik*);
	void odstawNaPolke();
	string sygnatura() const	{ return sygnatura_; }

	friend ostream& operator << (ostream& os, const Egzemplarz&);

private:
	Artykul*				artykul_;
	string					sygnatura_;
	bool					wypozyczony_;
	vector<Wypozyczenie*>	historia_;
};

#endif