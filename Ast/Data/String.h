#ifndef __String_H__
#define __String_H__

class String : public Constante{
	std::string value_;

public:
	String(std::string value) : value_(value){}

	std::string value(){
		return value_;
	}
	
	void accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __String_H__ */

