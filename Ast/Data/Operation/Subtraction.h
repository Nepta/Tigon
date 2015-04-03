#ifndef __Subtraction_H__
#define __Subtraction_H__

#include "Operator.h"

class Subtraction : public Operator{
public:
	Subtraction(Visitable *left, Visitable *right) : Operator(left,right) {}
};

#endif /* __Subtraction_H__ */

