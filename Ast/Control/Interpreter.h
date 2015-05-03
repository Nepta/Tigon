#ifndef __Interpreter_H__
#define __Interpreter_H__

#include "../Data/Int.h"
#include "../Data/String.h"
#include "../Data/Operation/Addition.h"
#include "../Data/Operation/Subtraction.h"
#include "../Data/Operation/Multiplication.h"
#include "../Data/Operation/Division.h"
#include "../Data/Affectation.h"
#include "../Data/Block/If.h"
#include "../Data/Block/While.h"
#include "DivisionByZeroException.h"
#include <iostream>
#include "../Data/VariableList.h"

class Interpreter : public Visiteur{
	int var_;

private:
	void pushVar(int var){
		var_ = var;
	}
	
	int pullVar(){
		return var_;
	}
	
public:
	Interpreter(VariableList& v) : Visiteur(v){}
	
	void visite(Addition& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left+right);
	}

	void visite(Division& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		if(right == 0){
			throw DivisionByZeroException();
		}
		pushVar(left/right);
	}

	void visite(Multiplication& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left*right);
	}

	void visite(Subtraction& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left-right);
	}

	void visite(Affectation& a){
		a.expression()->accept(*this);
		std::string variableName = a.variableName();
		int value = pullVar();
//		variableList_.addValue(variableName,value);
		pushVar(value);
	}
	
	void visite(Int& c){
		pushVar(c.value());
	}
	
	void visite(String& s){
		pushVar(9); //FIXME
	}
	
	void visite(If& i){
		i.condition()->accept(*this);
		int condition = pullVar();
		if(condition != 0){
			i.trueExpression()->accept(*this);
		}else{
			i.falseExpression()->accept(*this);
		}
	}
	
	void visite(While& w){
		w.condition()->accept(*this);
		int condition = pullVar();
		if(condition != 0){
			w.expression()->accept(*this);
		}
	}
	
	int peakVar(){
//		ast_.accept(*this);
//		return var_;
		return 42;
	}
	
	friend
	std::ostream& operator<<(std::ostream& ostr, Interpreter& i);
};

inline
std::ostream& operator<<(std::ostream& ostr, Interpreter& i){
	ostr << std::to_string(i.pullVar());
	return ostr;
}

#endif /* __Interpreter_H__ */

