#ifndef __Greater_H__
#define __Greater_H__

#include "../Operator.h"

class Greater : public Operator, public Visitable{
public:
	Greater(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Greater_H__ */

