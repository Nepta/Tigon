#ifndef __Addition_H__
#define __Addition_H__

#include "Operator.h"

class Addition : public Operator{
public:
	Addition(Expression *left, Expression *right) : LeftRightOperation(left,right) {}
};

#endif /* __Addition_H__ */

