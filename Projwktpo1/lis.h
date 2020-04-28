#ifndef _LIS_H
#define _LIS_H
#include <iostream>
#include "zwierze.h"

using namespace std;

class Lis : public Zwierze{
	
public:
	Lis(int sila = 3, int inicjatywa = 7, char znak = 'L');
	void akcja();
};
#endif