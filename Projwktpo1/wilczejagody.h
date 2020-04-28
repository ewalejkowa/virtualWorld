#ifndef _WILCZEJAGODY_H
#define _WILCZEJAGODY_H
#include <iostream>
#include "roslina.h"

using namespace std;

class WilczeJagody : public Roslina{
	
public:
	WilczeJagody(char znak = 'j', int sila = 99);
	void  kolizja(int x, int y, int x2, int y2);
};
#endif