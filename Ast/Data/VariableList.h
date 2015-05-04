#ifndef __Variable_H__
#define __Variable_H__

#include "Visitable.h"
#include <unordered_map>
#include <vector>

class VariableList{
	using VarArray = std::unordered_map<std::string, Visitable*>;
	using Scope = std::vector<VarArray>;
	Scope scopedVariableList_ = {std::unordered_map<std::string, Visitable*>()};
	int scopeDeep = 0;

public:
	Visitable* getValue(std::string name){
		for(auto variableList = scopedVariableList_.rbegin(); variableList != scopedVariableList_.rend(); variableList++){
			if(variableList->count(name) > 0){
				return (*variableList)[name];
			}
		}
		return nullptr;
	}
	
	void addValue(std::string name, Visitable *value){
		for(auto variableList = scopedVariableList_.rbegin(); variableList != scopedVariableList_.rend(); variableList++){
			if(variableList->count(name) > 0){
				(*variableList)[name] = value;
				return;
			}
		}
		scopedVariableList_[scopeDeep][name] = value;
	}
	
	void operator++(int){
		scopeDeep++;
		scopedVariableList_.push_back({std::unordered_map<std::string, Visitable*>()});
	}
	
	void operator--(int){
		scopeDeep--;
		scopedVariableList_.pop_back();
	}
};

#endif /* __Variable_H__ */

