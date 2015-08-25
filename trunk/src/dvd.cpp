#include "dvd.h"
#include <sstream>

using namespace std;

Dvd::Dvd():
rokProdukcji_(1950), czasTrwaniaMin_(0){}

Dvd::Dvd( const string& tytul,
		const string& rezyser,
		const vector<string>& obsada,
		const string& wytwornia,
		const int& rokProdukcji,
		const int& czasTrwaniaMin ):
tytul_( tytul ),
rezyser_( rezyser ),
obsada_( obsada ),
wytwornia_( wytwornia ),
rokProdukcji_( rokProdukcji ),
czasTrwaniaMin_( czasTrwaniaMin_ ){} 

string Dvd::info() const{
	stringstream ss;
	string obsadaRazem;
	for (int i = 0; i != obsada_.size(); ++i ){
		obsadaRazem += obsada_[i] + ", ";
	}
	obsadaRazem.resize( obsadaRazem.size() - 2 );//ucinamy ostatnie ", "
	ss << "Tytul: " << tytul_ << endl
				<< "Rezyser: " << rezyser_ << endl
				<< "Produkcja: " << wytwornia_ << ", "
				<< rokProdukcji_ << endl
				<< "Obsada: " << obsadaRazem << endl
				<< "ID: " << id() << endl;
	return ss.str();	
}

string Dvd::id() const{
	return tytul_.substr(0,5) + rezyser_.substr(0,3);
}