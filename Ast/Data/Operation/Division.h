#ifndef __Division_H__
#define __Division_H__

#include "Operator.h"

class Division : public Operator{
public:
	Division(Expression *left, Expression *right) : LeftRightOperation(left,right) {}
};

#endif /* __Division_H__ */

