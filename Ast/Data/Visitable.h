#ifndef __Visitable_H__
#define __Visitable_H__

#include "../Control/Visiteur.h"

class Visitable{
public:
	virtual Expression* accept(Visiteur& v){
		return v.visite(*this);
	}
	
	virtual int accept(Visiteur& v){
		return v.visite(*this);
	}
};

#endif /* __Visitable_H__ */

