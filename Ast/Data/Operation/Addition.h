#ifndef __Addition_H__
#define __Addition_H__

#include "Operator.h"

class Addition : public Operator{
public:
	Addition(Visitable *left, Visitable *right) : Operator(left,right) {}
};

#endif /* __Addition_H__ */

