#ifndef __Interpreter_H__
#define __Interpreter_H__

#include "../Data/Constante.h"
#include "DivisionByZeroException.h"
#include <iostream>

class Interpreter : public Visiteur{
	Visitable& ast_;
	int var_;

private:
	void push(int var){
		var_ = var;
	}
	
	int pullVar(){
		return var_;
	}
	
public:
	Interpreter(Visitable& v) : ast_(v){}
	
	void visite(Addition& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		push(left+right);
	}

	void visite(Division& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		if(right == 0){
			throw DivisionByZeroException();
		}
		push(left/right);
	}

	void visite(Multiplication& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		push(left*right);
	}

	void visite(Subtraction& operation){
		operation.left()->accept(*this);
		int left = pullVar();
		operation.right()->accept(*this);
		int right = pullVar();
		push(left-right);
	}
	
	void visite(Constante& c){
		push(c.value());
	}
	friend
	std::ostream& operator<<(std::ostream& ostr, Interpreter& i);
};

inline
std::ostream& operator<<(std::ostream& ostr, Interpreter& i){
	try{
		i.ast_.accept(i);
		ostr << std::to_string(i.pullVar());
	}catch(DivisionByZeroException& e){
		ostr << std::string(e.what());
	}
	return ostr;
}

#endif /* __Interpreter_H__ */

