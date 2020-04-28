#include "zolw.h"
#include "swiat.h"

Zolw::Zolw(int sila, int inicjatywa, char znak){
	this->znak = znak;
	this->inicjatywa = inicjatywa;
	this->sila = sila;
}
void Zolw::akcja(){
	int f = 0;
	do {
		f = rand() %16;
	} while (!swiat->sprawdzRuch(f, pol_x, pol_y));
	int nowyx = pol_x;
	int nowyy = pol_y;
	
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
	case 4:
		nowyx = pol_x;
		break;
	case 5:
		nowyx = pol_x;
		break;
	case 6:
		nowyy = pol_y;
		break;
	case 7:
		nowyy = pol_y;
		break;
	case 8:
		nowyx = pol_x;
		break;
	case 9:
		nowyx = pol_x;
		break;
	case 10:
		nowyy = pol_y;
		break;
	case 11:
		nowyy = pol_y;
		break;
	case 12:
		nowyx = pol_x;
		break;
	case 13:
		nowyx = pol_x;
		break;
	case 14:
		nowyy = pol_y;
		break;
	case 15:
		nowyy = pol_y;
		break;
	}

	Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);
	if (kolizja1 == NULL ){
		swiat->przesun(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (nowyy == pol_y&& nowyx == pol_x){
	
	}
	else if (kolizja1->zwrocZnak() == 'g'){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (kolizja1->zwrocZnak() == 'j'){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
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
}
void Zolw::kolizja(int x, int y, int x2, int y2){
	Organizm *f = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
	if (l->zwrocSile() <= f->zwrocSile() && f->zwrocSile()<5 && l->zwrocZnak() =='Z'){
		cout << "Zolw odgania przeciwnika"<< "\n";
	}
	else if (f->zwrocSile()>= l->zwrocSile() && f->zwrocZnak() == 'Z'){
		f->swiat->usunto(x2, y2, x, y);
		if (l->zwrocSile() == 0){
			cout << f->zwrocZnak() << "-zjada:" << l->zwrocZnak() << "\n";
		}
		else{
			cout << f->zwrocZnak() << "-wygrywa walke z:" << l->zwrocZnak() << "\n";
		}
	}
	else {
		f->swiat->usunObiekt(x, y);
		cout << "Zolw przegrywa walke z: " << l->zwrocZnak() << "\n";
	}
}