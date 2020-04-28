#ifndef _LISTA_H
#define _LISTA_H
#include "organizm.h"


struct PoleListy{
	PoleListy *nast, *poprz;
	Organizm *o;
};

class Lista{	
	PoleListy *Pierwszy;
	int ilosc;
public:	
	Lista();
	void dodaj(Organizm *o);
	void usun(Organizm *o);
	Organizm *pobierzZ(int ktory);
	void wyswietl();
	int zwrocIlosc();
	int Lista::zwrocPol(int ktory);
};
#endif