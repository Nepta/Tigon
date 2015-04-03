#ifndef __Multiplication_H__
#define __Multiplication_H__

#include "Operator.h"

class Multiplication : public Operator{
public:
	Multiplication(Expression *left, Expression *right) : LeftRightOperation(left,right) {}
};

#endif /* __Multiplication_H__ */

