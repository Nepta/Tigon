#ifndef __Operator_H__
#define __Operator_H__

#include "../Visitable.h"

class Operator : public Visitable{
	Visitable *left_;
	Visitable *right_;

public:
	Operator(Visitable *left, Visitable *right) : left_(left), right_(right){}
	
	virtual Visitable* left(){
		return left_;
	}
	
	virtual Visitable* right(){
		return right_;
	}
};

#endif /* __Operator_H__ */

