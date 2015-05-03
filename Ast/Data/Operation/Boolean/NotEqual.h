#ifndef __NotEqual_H__
#define __NotEqual_H__

#include "../Operator.h"

class NotEqual : public Operator, public Visitable{
public:
	NotEqual(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __NotEqual_H__ */

