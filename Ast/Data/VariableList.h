#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"
#include "Constante.h"
#include <unordered_map>

class VariableList : Visitable{
	std::unordered_map<std::string, Constante*> variableList_;

public:
	Constante* getValue(std::string name){
		return variableList_[name];
	}
	
	void addValue(std::string name, Constante *value){
		variableList_[name] = value;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Variable_H__ */

