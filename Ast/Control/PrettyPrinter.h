#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <ostream>

class PrettyPrinter : public Visiteur{
	std::ostream ostr;
	
public:
	Expression* visite(Addition& operation){
		return operation.left().accept(*this) + " + " + operation.right().accept(*this);
	}

	Expression* visite(Division& operation){
		return operation.left().accept(*this) + " ÷ " + operation.right().accept(*this);
	}

	Expression* visite(Multiplication& operation){
		return operation.left().accept(*this) + " × " + operation.right().accept(*this);
	}

	Expression* visite(Subtraction& operation){
		return operation.left().accept(*this) + " - " + operation.right().accept(*this);
	}
	
	int visite(Constante& c){
		return c.value();
	}
};

#endif /* __PrettyPrinter_H__ */

