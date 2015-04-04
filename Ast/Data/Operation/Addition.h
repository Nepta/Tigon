#ifndef __Addition_H__
#define __Addition_H__

#include "Operator.h"

class Addition : public Operator, public Visitable{
public:
	Addition(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Addition_H__ */

