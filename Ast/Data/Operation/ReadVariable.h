#ifndef __ReadVariable_H__
#define __ReadVariable_H__

#include <string>

class ReadVariable : public Visitable{
	std::string variableName_;

public:
	ReadVariable(std::string variableName) : variableName_(variableName){}
	
	std::string variableName(){
		return variableName_;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __ReadVariable_H__ */

