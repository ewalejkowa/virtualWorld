#ifndef _SWIAT_H
#define _SWIAT_H

#include<time.h>
#include "trawa.h"
#include<stdio.h>
#include"conio2.h"
#include <windows.h>
#include "mlecz.h"
#include "guarana.h"
#include "wilczejagody.h"
#include "wilk.h"
#include "Owca.h"
#include "lis.h"
#include "zolw.h"
#include "antylopa.h"
#include "organizm.h"
#include "Czlowiek.h"
#include "lista.h"

 class Swiat{
	 int size;
	Organizm ***organizmy; 
 public:
Lista lista; 	
	 Swiat( int size = 20);
	 void wykonajTure();
	 void rysujSwiat();
	 void dodajOrganizmy();
	 bool sprawdzRuch(int kierunek, int x,int y);
	Organizm* zwrocOrganizm(int x, int y);
	void przesun(int nowyx, int nowyy, int x, int y);
	bool Swiat::CzlowiekRuch(int kierunek, int x, int y);
	void usunto(int x,int  y,int  x2,int  y2);
	void usunObiekt(int x, int y);
	void dodajOrganizm(Organizm* l, char znak, int potx, int poty);
	void zapiszDoPliku();
	void wczytajZPliku();
};
#endif

