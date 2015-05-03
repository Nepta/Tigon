#ifndef __Less_H__
#define __Less_H__

#include "../Operator.h"

class Less : public Operator, public Visitable{
public:
	Less(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Less_H__ */

