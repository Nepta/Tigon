#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <sstream>
#include <string>

#include "../Data/Constante.h"

class PrettyPrinter : public Visiteur{
	Visitable* ast_;
	std::ostringstream s;
public:
	PrettyPrinter(Visitable* v) : ast_(v){}

	void visite(Addition& operation){
		operation.left()->accept(*this);
		s << " + ";
		operation.right()->accept(*this);
	}

	void visite(Division& operation){
		operation.left()->accept(*this);
		s << " ÷ ";
		operation.right()->accept(*this);
	}

	void visite(Multiplication& operation){
		operation.left()->accept(*this);
		s << " × ";
		operation.right()->accept(*this);
	}

	void visite(Subtraction& operation){
		operation.left()->accept(*this);
		s << " - ";
		operation.right()->accept(*this);
	}
	
	void visite(Constante& c){
		s << std::to_string(c.value());
	}

	std::string toString(){
		ast_->accept(*this);
		return s.str();
	}
};

#endif /* __PrettyPrinter_H__ */

