#ifndef __Visitable_H__
#define __Visitable_H__

#include <string>
#include "../Control/Visiteur.h"

class Visitable{
public:
	virtual void accept(Visiteur& v) = 0;
};
#endif /* __Visitable_H__ */

