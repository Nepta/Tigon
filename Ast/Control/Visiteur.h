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
	virtual void visite(Addition& operation) = 0;
	virtual void visite(Division& operation) = 0;
	virtual void visite(Multiplication& operation) = 0;
	virtual void visite(Subtraction& operation) = 0;
	virtual void visite(Constante& c) = 0;
};

#endif /* __Visiteur_H__ */

