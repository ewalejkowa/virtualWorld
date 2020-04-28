#ifndef _ORGANIZM_H
#define _ORGANIZM_H
#define EXTERNC
#include <iostream>


using namespace std;
class Swiat;
class Organizm{			
protected:	
	int sila;
	int pol_x;
	int pol_y;
	char znak;
	bool flaga = false;
	
public:
	int wiek = 0;
	int inicjatywa;
	Organizm( int sila=0 , int inicjatywa=0 ,char znak ='o');
	Swiat *swiat;	
	void wczytajgre(Swiat *g);
	virtual void akcja(){};
	virtual void kolizja(int x, int y, int x2, int y2) ;
	 void rysowanie();
	 void ustaw(int a, int b);
	 int zwrocSile();
	 char zwrocZnak();
	 int zwiekszSile();
	 void rozmnazanie(int x, int y, int x2, int y2);
	 int zwrocPolozenie();
	 void oflaguj();
	 bool zwrocFlage();
	 void zdejmij();
	 void dodaj();
	 int zwrocWiek();
};
#endif

