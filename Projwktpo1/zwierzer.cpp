#include "zwierze.h"
#include "conio2.h"
#include "swiat.h"


void Zwierze::akcja(){
	int f = 0;
	do {
		f = rand() % 4;
	} while (!swiat->sprawdzRuch(f, pol_x, pol_y));
	int nowyx=pol_x;
	int nowyy=pol_y;
	switch (f)
	{
	case 0:
		nowyy = pol_y - 1;
	
		break;
	case 1:
		nowyy = pol_y + 1;
		break;
	case 2:
		nowyx = pol_x + 1;
		break;
	case 3:
		nowyx = pol_x - 1;
		break;
	}
	Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);
	Organizm *source = swiat->zwrocOrganizm(pol_x, pol_y);
	if (kolizja1 == NULL ){
		swiat->przesun(pol_x, pol_y,nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;	
	}
	else if (kolizja1->zwrocZnak() == 'Z' && this->zwrocSile() <5){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
	}
	else if (kolizja1->zwrocZnak() == 'j' ){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
	}
	else if (kolizja1->zwrocZnak() == 'g'){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (kolizja1->zwrocZnak() == this->zwrocZnak())
	{	
		rozmnazanie(pol_x, pol_y, nowyx, nowyy);	

	}
	else {
		this->kolizja(pol_x, pol_y, nowyx, nowyy);
	    pol_x = nowyx;
	    pol_y = nowyy;
	}
	flaga = true;
	wiek++;
}

	