#ifndef __Subtraction_H__
#define __Subtraction_H__

#include "Operator.h"

class Subtraction : public Operator, public Visitable{
public:
	Subtraction(Visitable *left, Visitable *right) : Operator(left,right) {}

	std::string accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Subtraction_H__ */

