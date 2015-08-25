#ifndef _ARTYKUL_H_
#define _ARTYKUL_H_

#include <string>
#include <iostream>
using namespace std;

class Artykul{
public:
	virtual ~Artykul() = 0;
	virtual string info() const = 0;
	virtual string id() const = 0;
};



#endif