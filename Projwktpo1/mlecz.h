#ifndef _MLECZ_H
#define _MLECZ_H
#include <iostream>
#include "roslina.h"

using namespace std;

class Mlecz : public Roslina{
	
public:
Mlecz(char znak = 'm');
void akcja();
};
#endif