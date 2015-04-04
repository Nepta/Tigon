#ifndef __If_H__
#define __If_H__

#include "../Visitable.h"

class If : public Visitable{
	Visitable *condition_;
	Visitable *expression_;

public:
	If(Visitable *condition, Visitable *expression) : condition_(condition), expression_(expression){}
	
	Visitable* condition(){
		return condition_;
	}
	
	Visitable* expression(){
		return expression_;
	}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __If_H__ */

