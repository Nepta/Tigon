#ifndef __PrettyPrinter_H__
#define __PrettyPrinter_H__

#include <iostream>
#include <sstream>
#include <string>

#include "../Data/Operation/ReadVariable.h"
#include "../Data/Operation/Boolean/Equal.h"
#include "../Data/Int.h"
#include "../Data/String.h"
#include "../Data/Affectation.h"
#include "../Data/VariableList.h"
#include "../Data/Block/If.h"
#include "../Data/Block/While.h"

class PrettyPrinter : public Visiteur{
	std::stringstream s_;

public:
	PrettyPrinter(VariableList& v) : Visiteur(v){}

	void visite(Addition& operation){
		s_ << " (";
		operation.left()->accept(*this);
		s_ << " + ";
		operation.right()->accept(*this);
		s_ << ") ";
	}

	void visite(Division& operation){
		s_ << " (";
		operation.left()->accept(*this);
		s_ << " ÷ ";
		operation.right()->accept(*this);
		s_ << ") ";
	}

	void visite(Multiplication& operation){
		s_ << " (";
		operation.left()->accept(*this);
		s_ << " × ";
		operation.right()->accept(*this);
		s_ << ") ";
	}

	void visite(Subtraction& operation){
		s_ << " (";
		operation.left()->accept(*this);
		s_ << " - ";
		operation.right()->accept(*this);
		s_ << ") ";
	}
	
	void visite(Affectation& a){
		std::string variableName = a.variableName();
		s_ << variableName;
		s_ << " := ";
		a.expression()->accept(*this);
	}
	
	void visite(ReadVariable& v){
		s_<< v.variableName();
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
		i.trueExpression()->accept(*this);
		s_ << " else ";
		i.falseExpression()->accept(*this);
		s_ << " end";
	}

	void visite(While& w){
		s_ << "while ";
		w.condition()->accept(*this);
		s_ << " do ";
		w.expression()->accept(*this);
		s_ << " end";
	}

	void visite(Equal& operation){
		s_ << " (";
		operation.left()->accept(*this);
		s_ << " = ";
		operation.right()->accept(*this);
		s_ << ") ";
	}

	friend
	std::ostream& operator<<(std::ostream& ostr, PrettyPrinter& v);	
};

inline
std::ostream& operator<<(std::ostream& ostr, PrettyPrinter& v){
	ostr << v.s_.str();
	return ostr;
}
#endif /* __PrettyPrinter_H__ */

