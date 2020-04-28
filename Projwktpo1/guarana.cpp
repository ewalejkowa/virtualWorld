#include "guarana.h"
#include "swiat.h"

Guarana::Guarana(char znak){
	this->znak = znak;
}
void Guarana::kolizja(int x, int y, int x2, int y2){
	Organizm *f = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
		f->zwiekszSile();
		cout << "Guarana zwieksza sile: " << f->zwrocZnak() << "  trzykrotnie" << "\n";
		f->swiat->usunto(x, y, x2, y2);
}