#ifndef __Int_H__
#define __Int_H__

#include "Constante.h"

class Int : public Constante{
	int value_;

public:
	Int(int value) : value_(value){}
	
	int value(){
		return value_;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Int_H__ */

