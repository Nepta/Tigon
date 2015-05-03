#ifndef __Equal_H__
#define __Equal_H__

#include "../Operator.h"

class Equal : public Operator, public Visitable{
public:
	Equal(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Equal_H__ */

