#ifndef __GreaterEqual_H__
#define __GreaterEqual_H__

#include "../Operator.h"

class GreaterEqual : public Operator, public Visitable{
public:
	GreaterEqual(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __GreaterEqual_H__ */

