#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"
#include "Constante.h"
#include <unordered_map>
#include "../Control/Interpreter.h"

class VariableList{
	std::unordered_map<std::string, Constante*> variableList_;

public:
	Constante* getValue(std::string name){
		return variableList_[name];
	}
	
	void addValue(std::string name, Constante *value){
		variableList_[name] = value;
	}
	
	void addValue(std::string name, Visitable *v){
		Interpreter i(*v);
		int value = i.peakVar();
		Constante* interpretedValue = new Int(value);
		variableList_[name] = interpretedValue;
	}
};

#endif /* __Variable_H__ */

