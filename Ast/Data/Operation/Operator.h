#ifndef __Operator_H__
#define __Operator_H__

#include "../Visitable.h"

class Operator : public Visitable{
	Expression *left_;
	Expression *right_;

public:
	Operator(Expression *left, Expression *right) : left_(left), right_(right){}
	
	virtual Expression* left(){
		return left_;
	}
	
	virtual Expression* right(){
		return right_;
	}
};

#endif /* __Operator_H__ */

