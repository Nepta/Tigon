#ifndef __Division_H__
#define __Division_H__

#include "Operator.h"

class Division : public Operator, public Visitable{
public:
	Division(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	std::string accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Division_H__ */

