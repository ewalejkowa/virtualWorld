#ifndef _ANTYLOPA_H
#define _ANTYLOPA_H
#include <iostream>
#include "zwierze.h"
#include "conio2.h"

using namespace std;

class Antylopa : public Zwierze{
	
public:
	Antylopa(int sila = 4, int inicjatywa = 4, char znak = 'A');
	void  kolizja(int x, int y, int x2, int y2);
	void akcja();
	bool sprawdzRuch(int kierunek, int x,int y);
};
#endif
