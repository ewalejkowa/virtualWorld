#include "antylopa.h"
#include "organizm.h"
#include "swiat.h"

Antylopa::Antylopa(int sila, int inicjatywa, char znak){
	this->znak = znak;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
}
void Antylopa::akcja(){
	int f = 0;
	do {
		f = rand() % 4;
	} while (!this->sprawdzRuch(f, pol_x, pol_y));
	int nowyx = pol_x;
	int nowyy = pol_y;
	switch (f)
	{
	case 0:
		nowyy = pol_y - 2;

		break;
	case 1:
		nowyy = pol_y + 2;
		break;
	case 2:
		nowyx = pol_x + 2;
		break;
	case 3:
		nowyx = pol_x - 2;
		break;
	}
	Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);
	if (kolizja1 == NULL ){
		swiat->przesun(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (kolizja1->zwrocZnak() == 'Z' && this->zwrocSile() <5){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
		cout << "Antylopa zostaje odgoniona" << "\n";
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
	else  {
		this->kolizja(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	flaga = true;
	wiek++;
}
bool Antylopa::sprawdzRuch(int kierunek, int x, int y){
		switch (kierunek){
		case 0:
			if (y - 2 >= 0) return true;//g
			break;
		case 1:
			if (y + 2< 20) return true;//d
			break;
		case 2:
			if (x + 2 < 20) return true;//p
			break;
		case 3:
			if (x - 2 >= 0) return true;//l
			break;
		}
		return false;
}
void Antylopa::kolizja(int x, int y, int x2, int y2){
	Organizm *f = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
	
	int b = 0;
	b = rand() % 1;
	switch (b){
	case 0:
		if (f->zwrocSile() >= l->zwrocSile()){
			f->swiat->usunto(x, y, x2, y2);
			if (l->zwrocSile() == 0){
				cout << f->zwrocZnak() << "-zjada:" << l->zwrocZnak() << "\n";
			}
			else{
				cout << f->zwrocZnak() << "-wygrywa walke z:" << l->zwrocZnak() << "\n";
			}
		}

		else {
			f->swiat->usunObiekt(x, y);
			cout << "Antylopa przegrywa walke z :" << l->zwrocZnak()<< "\n";
		}
		
		break;
	case 1:
		cout << "Antylopa Ucieka" << "\n";
		f->akcja();
		break;
	}


}