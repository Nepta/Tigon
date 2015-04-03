#ifndef __Constante_H__
#define __Constante_H__

#include "Expression.h"

class Constante : public Expression{
	int value_;

public:
	Constante(int value) : value_(value){}
	
};

#endif /* __Constante_H__ */

