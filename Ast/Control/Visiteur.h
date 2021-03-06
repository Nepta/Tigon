#ifndef __Visiteur_H__
#define __Visiteur_H__

#include <string>

class Addition;
class Division;
class Multiplication;
class Subtraction;
class ReadVariable;
class Print;
class Int;
class String;
class Affectation;
class If;
class While;
class VariableList;
class Equal;
class NotEqual;
class Less;
class LessEqual;
class Greater;
class GreaterEqual;
class Sequence;

class Visiteur{
protected:
	VariableList& variableList_;

public:
	Visiteur(VariableList& variableList) : variableList_(variableList){}
	virtual void visite(Addition& operation) = 0;
	virtual void visite(Division& operation) = 0;
	virtual void visite(Multiplication& operation) = 0;
	virtual void visite(Subtraction& operation) = 0;

	virtual void visite(Equal& operation) = 0;
	virtual void visite(NotEqual& operation) = 0;
	virtual void visite(Less& operation) = 0;
	virtual void visite(LessEqual& operation) = 0;
	virtual void visite(Greater& operation) = 0;
	virtual void visite(GreaterEqual& operation) = 0;
	virtual void visite(Sequence& operation) = 0;
	
	virtual void visite(Int& c) = 0;
	virtual void visite(String& c) = 0;
	virtual void visite(Affectation& a) = 0;
	virtual void visite(ReadVariable& v) = 0;
	virtual void visite(Print& expression) = 0;
	
	virtual void visite(If& i) = 0;
	virtual void visite(While& w) = 0;
};

#endif /* __Visiteur_H__ */

