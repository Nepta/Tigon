#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"
#include <unordered_map>

class VariableList{
	std::unordered_map<std::string, Visitable*> variableList_;

public:
	Visitable* getValue(std::string name){
		return variableList_[name];
	}
	
	void addValue(std::string name, Visitable *value){
		variableList_[name] = value;
	}
};

#endif /* __Variable_H__ */

