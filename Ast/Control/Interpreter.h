#ifndef __Interpreter_H__
#define __Interpreter_H__

#include "../Data/Int.h"
#include "../Data/String.h"
#include "../Data/Operation/Addition.h"
#include "../Data/Operation/Subtraction.h"
#include "../Data/Operation/Multiplication.h"
#include "../Data/Operation/Division.h"
#include "../Data/Operation/Sequence.h"
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
		variableList_.addValue(variableName,new Int(value));
		pushVar(value);
	}
	
	void visite(ReadVariable& v){
		std::string variableName = v.variableName();
		Visitable* variable = variableList_.getValue(variableName);
		if(variable != nullptr){
			Int* variableAsInt = dynamic_cast<Int*>(variable);
			pushVar(variableAsInt->value());
		}else{
			pushVar(0); //FIXME?
		}
	}
	
	void visite(Int& c){
		pushVar(c.value());
	}
	
	void visite(String& s){
		pushVar(42); //FIXME
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
		variableList_++;
		w.condition()->accept(*this);
		int condition = pullVar();
		while(condition != 0){
			w.expression()->accept(*this);
			pullVar();
			w.condition()->accept(*this);
			condition = pullVar();
			std::string pause;
			std::cin >> pause;
		}
		variableList_--;
	}
	
	void visite(Equal& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left = right);
	}
	
	void visite(NotEqual& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left != right);
	}
	
	void visite(Less& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left < right);
	}
	
	void visite(LessEqual& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left <= right);
	}
	
	void visite(Greater& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left > right);
	}
	
	void visite(GreaterEqual& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		pushVar(left >= right);
	}
	
	void visite(Sequence& operation){
		operation.left()->accept(*this);
		operation.right()->accept(*this);
	}
	
	int peakVar(){
		return var_;
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

