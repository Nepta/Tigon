#ifndef __Print_H__
#define __Print_H__

#include <string>

class Print : public Visitable{
	std::string variableName_;
	
public:
	Print(std::string variableName) : variableName_(variableName){}
	
	std::string variableName(){
		return variableName_;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Print_H__ */

