#ifndef _WILK_H
#define _WILK_H
#include <iostream>
#include "zwierze.h"

using namespace std;

class Wilk : public Zwierze{
public:
	//void akcja();
	Wilk(int sila = 9, int inicjatywa =5, char znak = 'W');
};
#endif