#ifndef _CZLOWIEK_H
#define _CZLOWIEK_H
#include <iostream>
#include "zwierze.h"

using namespace std;

class Czlowiek :public Zwierze{	
	int licznik=0;
public:
	Czlowiek(int sila = 5, int inicjatywa = 4, char  znak = 'C');
	void akcja();
	void kolizja(int x, int y, int x2, int y2);
	void zmniejsz();
	void sp();
	bool sprawdzRuchcz(int kierunek, int x, int y);
};
#endif