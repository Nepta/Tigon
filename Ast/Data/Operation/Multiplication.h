#ifndef __Multiplication_H__
#define __Multiplication_H__

#include "Operator.h"

class Multiplication : public Operator, public Visitable{
public:
	Multiplication(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Multiplication_H__ */

