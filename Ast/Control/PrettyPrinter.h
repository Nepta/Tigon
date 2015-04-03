#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <ostream>

class PrettyPrinter : public Visiteur{
	std::ostream ostr;
	
public:
	Visitable* visite(Addition& operation){
		return operation.left().accept(*this) + " + " + operation.right().accept(*this);
	}

	Visitable* visite(Division& operation){
		return operation.left().accept(*this) + " ÷ " + operation.right().accept(*this);
	}

	Visitable* visite(Multiplication& operation){
		return operation.left().accept(*this) + " × " + operation.right().accept(*this);
	}

	Visitable* visite(Subtraction& operation){
		return operation.left().accept(*this) + " - " + operation.right().accept(*this);
	}
	
	int visite(Constante& c){
		return c.value();
	}
};

#endif /* __PrettyPrinter_H__ */

