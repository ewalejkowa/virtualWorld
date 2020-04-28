#ifndef _GUARANA_H
#define _GUARANA_H

#include "roslina.h"



class Guarana : public Roslina{
	
public:
Guarana(char znak = 'g');
void kolizja(int x, int y, int x2, int y2);
};
#endif