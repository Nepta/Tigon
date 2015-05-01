#ifndef __Visiteur_H__
#define __Visiteur_H__

#include <string>

class Addition;
class Division;
class Multiplication;
class Subtraction;
class Int;
class String;
class If;
class While;
class VariableList;

class Visiteur{
public:
	virtual void visite(Addition& operation) = 0;
	virtual void visite(Division& operation) = 0;
	virtual void visite(Multiplication& operation) = 0;
	virtual void visite(Subtraction& operation) = 0;
	virtual void visite(Int& c) = 0;
	virtual void visite(String& c) = 0;
	virtual void visite(If& i) = 0;
	virtual void visite(VariableList& i) = 0;
	virtual void visite(While& w) = 0;
};

#endif /* __Visiteur_H__ */

