#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"
#include <unordered_map>
#include "Int.h"
#include <iostream>

class VariableList{
	std::unordered_map<std::string, Visitable*> variableList_;

public:
	Visitable* getValue(std::string name){
		return variableList_[name];
	}
	
	void addValue(std::string name, Visitable *value){
		int oldValue = 0;
		try{
			oldValue = ((Int*)variableList_.at(name))->value();
		}catch(std::exception& e){}
		std::cerr << name << ": " << oldValue << " -> " << ((Int*)value)->value() << std::endl;
		variableList_[name] = value;
	}
};

#endif /* __Variable_H__ */

