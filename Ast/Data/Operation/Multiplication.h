#ifndef __Multiplication_H__
#define __Multiplication_H__

#include "Operator.h"

class Multiplication : public Operator{
public:
	Multiplication(Visitable *left, Visitable *right) : Operator(left,right) {}
};

#endif /* __Multiplication_H__ */

