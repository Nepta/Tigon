#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"

class Variable : public Constante{
	Constante *value_;

public:
	Variable(Constante *value) : value_(value){}
	
	Constante* value(){
		return value_->value();
	}
	
	void value(Constante *value){
		delete value_;
		value_ = value;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Variable_H__ */

