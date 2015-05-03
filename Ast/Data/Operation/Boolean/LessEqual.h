#ifndef __LessEqual_H__
#define __LessEqual_H__

#include "../Operator.h"

class LessEqual : public Operator, public Visitable{
public:
	LessEqual(Visitable *left, Visitable *right) : Operator(left,right) {}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __LessEqual_H__ */

