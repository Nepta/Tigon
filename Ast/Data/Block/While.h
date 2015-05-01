#ifndef __While_H__
#define __While_H__

#include "../Visitable.h"

class While : public Visitable{
	Visitable *condition_;
	Visitable *expression_;

public:
	While(Visitable *condition, Visitable *expression) : condition_(condition), expression_(expression){}
	
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

#endif /* __While_H__ */

