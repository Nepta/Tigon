#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <sstream>
#include <string>

#include "../Data/Int.h"
#include "../Data/String.h"
#include "../Data/Block/If.h"

class PrettyPrinter : public Visiteur{
	Visitable& ast_;
	std::stringstream s_;
public:
	PrettyPrinter(Visitable& v) : ast_(v){}

	void visite(Addition& operation){
		operation.left()->accept(*this);
		s_ << " + ";
		operation.right()->accept(*this);
	}

	void visite(Division& operation){
		operation.left()->accept(*this);
		s_ << " ÷ ";
		operation.right()->accept(*this);
	}

	void visite(Multiplication& operation){
		operation.left()->accept(*this);
		s_ << " × ";
		operation.right()->accept(*this);
	}

	void visite(Subtraction& operation){
		operation.left()->accept(*this);
		s_ << " - ";
		operation.right()->accept(*this);
	}
	
	void visite(Int& c){
		s_ << std::to_string(c.value());
	}

	void visite(String& s){
		s_ << s.value();
	}
	
	void visite(If& i){
		s_ << "if ";
		i.condition()->accept(*this);
		s_ << " then ";
		i.expression()->accept(*this);
		s_ << " end";
	}

	friend
	std::ostream& operator<<(std::ostream& ostr, PrettyPrinter& v);	
};

inline
std::ostream& operator<<(std::ostream& ostr, PrettyPrinter& v){
	v.s_.str(std::string());
	v.ast_.accept(v);
	ostr << v.s_.str();
	return ostr;
}
#endif /* __PrettyPrinter_H__ */

