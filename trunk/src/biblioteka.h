#ifndef _BIBLIOTEKA_H_
#define _BIBLIOTEKA_H_

#include <list>
#include <map>
#include <string>
using namespace std;

class Egzemplarz;
class Uzytkownik;
class Artykul;

class Biblioteka{
public:
	Biblioteka(const string&, const string&, const string&);
	~Biblioteka();
	
	void dodajEgzemplarz(Artykul*, const string&);
	void dodajUzytkownika(Uzytkownik*);
	
	bool wypozycz(const int&, const string&);
	bool oddaj(const string&);

	void wyswietlZbior();

private:
	map<string, Artykul*> artykuly_;
	list<Egzemplarz*> egzemplarze_;
	list<Uzytkownik*> uzytkownicy_;
};

#endif