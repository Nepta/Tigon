#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <string>

#include "../Data/Constante.h"

class PrettyPrinter : public Visiteur{
	
public:
	std::string visite(Addition& operation){
		return operation.left()->accept(*this) + " + " + operation.right()->accept(*this);
	}

	std::string visite(Division& operation){
		return operation.left()->accept(*this) + " ÷ " + operation.right()->accept(*this);
	}

	std::string visite(Multiplication& operation){
		return operation.left()->accept(*this) + " × " + operation.right()->accept(*this);
	}

	std::string visite(Subtraction& operation){
		return operation.left()->accept(*this) + " - " + operation.right()->accept(*this);
	}
	
	std::string visite(Constante& c){
		return std::to_string(c.value());
	}
};

#endif /* __PrettyPrinter_H__ */

