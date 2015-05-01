#ifndef __If_H__
#define __If_H__

#include "../Visitable.h"

class If : public Visitable{
	Visitable* condition_;
	Visitable* trueExpression_;
	Visitable* falseExpression_;

public:
	If(Visitable* condition, Visitable* trueExpression, Visitable* falseExpression) :
		condition_(condition), trueExpression_(trueExpression_), falseExpression_(falseExpression){}
	
	Visitable* condition(){
		return condition_;
	}
	
	Visitable* trueExpression(){
		return trueExpression_;
	}
	
	Visitable* falseExpression(){
		return falseExpression_;
	}
	
	void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __If_H__ */

