#ifndef _KSIAZKA_H_
#define _KSIAZKA_H_

#include "artykul.h"

class Ksiazka: public Artykul {
public:
	Ksiazka();
	
	Ksiazka(const string& tytul,
			const string& autor,
			const string& wydawca,
			int rokWydania,
			const string& ISBN);	

	string info() const;
	string id() const;

private:
	string tytul_;
	string autor_;
	string wydawca_;
	int rokWydania_;
	string ISBN_;
};

#endif