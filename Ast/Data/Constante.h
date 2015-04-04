#ifndef __Constante_H__
#define __Constante_H__

#include "Visitable.h"

class Constante : public Visitable{
	int value_;

public:
	Constante(int value) : value_(value){}
	
	int value(){
		return value_;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Constante_H__ */

