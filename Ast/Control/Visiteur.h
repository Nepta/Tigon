#ifndef __Visiteur_H__
#define __Visiteur_H__

#include <string>

class Addition;
class Division;
class Multiplication;
class Subtraction;
class Constante;

class Visiteur{
public:
	virtual std::string visite(Addition& operation) = 0;
	virtual std::string visite(Division& operation) = 0;
	virtual std::string visite(Multiplication& operation) = 0;
	virtual std::string visite(Subtraction& operation) = 0;
	virtual std::string visite(Constante& c) = 0;
};

#endif /* __Visiteur_H__ */

