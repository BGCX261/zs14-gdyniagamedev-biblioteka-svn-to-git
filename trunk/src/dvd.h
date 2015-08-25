#ifndef _DVD_H_
#define _DVD_H_

#include "artykul.h"
#include <vector>

class Dvd: public Artykul {
public:
	Dvd();
	
	Dvd( const string& tytul,
		const string& rezyser,
		const vector<string>& obsada,
		const string& wytwornia,
		const int& rokProdukcji,
		const int& czasTrwaniaMin );	

	string info() const;
	string id() const;

private:
	string tytul_;
	string rezyser_;
	vector<string> obsada_;
	string wytwornia_;
	int rokProdukcji_;
	int czasTrwaniaMin_;
};

#endif