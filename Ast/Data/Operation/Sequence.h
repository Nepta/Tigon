#ifndef __Sequence_H__
#define __Sequence_H__

#include "Operator.h"

class Sequence : public Operator, public Visitable{
public:
	Sequence(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Sequence_H__ */

