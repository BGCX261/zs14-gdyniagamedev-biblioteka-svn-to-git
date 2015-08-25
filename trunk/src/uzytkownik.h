#ifndef _UZYTKOWNIK_H_
#define _UZYTKOWNIK_H_

#include <vector>

class Wypozyczenie;
class Egzemplarz;

using namespace std;

class Uzytkownik{
public:
	Uzytkownik(const string&, const string&, const string&);
	int id() const;
	void wypozycz(Egzemplarz*);
	
private:
	string					imie_;
	string					nazwisko_;
	string					adres_;
	vector<Wypozyczenie*>	historia_;
	int						id_;
	static int				licznikUzytkownikow_;
};

#endif