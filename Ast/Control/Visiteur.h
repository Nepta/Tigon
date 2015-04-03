#ifndef __Visiteur_H__
#define __Visiteur_H__

class Visitable;
#include "../Data/Constante.h"

class Visiteur{
public:
	virtual Visitable* visite(Visitable&) = 0;
	virtual int visite(Constante&) = 0;
};

#endif /* __Visiteur_H__ */

