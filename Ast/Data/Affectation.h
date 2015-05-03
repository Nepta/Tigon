#ifndef __Affectation_H__
#define __Affectation_H__

#include <string>
#include "Visitable.h"

class Affectation : public Visitable{
	std::string variableName_;
	Visitable* expression_;

public:
	Affectation(std::string variableName, Visitable* expression) :
		variableName_(variableName), expression_(expression){
	}
	
	std::string variableName(){
		return variableName_;
	}
	
	Visitable* expression(){
		return expression_;
	}
	
	virtual void accept(Visiteur& v){
		v.visite(*this);
	}
};

#endif /* __Affectation_H__ */

