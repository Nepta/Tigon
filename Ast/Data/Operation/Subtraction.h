#ifndef __Subtraction_H__
#define __Subtraction_H__

#include "Operator.h"

class Subtraction : public Operator, public Visitable{
public:
	Subtraction(Visitable *left, Visitable *right) : Operator(left,right) {}

	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Subtraction_H__ */

