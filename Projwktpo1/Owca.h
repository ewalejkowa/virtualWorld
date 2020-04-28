#ifndef _OWCA_H
#define _OWCA_H
#include <iostream>
#include "zwierze.h"

using namespace std;

class Owca : public Zwierze{
public:
	Owca( int sila=4, int inicjatywa=4,char znak = 'O');
};
#endif