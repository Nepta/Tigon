#ifndef __Visiteur_H__
#define __Visiteur_H__

class Visitable;

class Visiteur{
public:
	virtual Expression* visite(Visitable&) = 0;
	virtual int visite(Visitable&) = 0;
};

#endif /* __Visiteur_H__ */

