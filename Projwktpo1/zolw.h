#ifndef _ZOLW_H
#define _ZOLW_H
#include <iostream>
#include "zwierze.h"

using namespace std;

class Zolw : public Zwierze{	
public:
	Zolw(int sila = 2, int inicjatywa = 1, char znak = 'Z');
	void akcja();
	void kolizja(int x, int y, int x2, int y2);
};
#endif