#include "wilczejagody.h"
#include "swiat.h"

WilczeJagody::WilczeJagody(char znak, int sila){
	this->znak = znak;
	this->sila = sila;
}
void WilczeJagody::kolizja(int x, int y, int x2, int y2){
	Organizm *f = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
	cout << f->zwrocZnak() << "-zjada:" << l->zwrocZnak() << " I umiera"<< "\n";
	f->swiat->usunObiekt(x, y);
	l->swiat->usunObiekt(x2, y2);			
}