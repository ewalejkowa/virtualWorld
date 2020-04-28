#include <iostream>
#include "organizm.h"
#include "conio2.h"
#include "swiat.h"
using namespace std;


Organizm:: Organizm ( int  sila, int  inicjatywa, char  znak){
	//this->pol_x = pol_x;
	//this->pol_y = pol_y;
	pol_x = rand() % 18 + 1;
	pol_y = rand() % 18 + 1;
	this->pol_x = pol_x;
	this->pol_y = pol_y;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->znak = znak;
}
void Organizm::rysowanie(){
	cout << znak <<' ';
	
}
void Organizm::wczytajgre(Swiat *g){
	swiat = g;
}
void Organizm::ustaw(int a , int b){
	pol_x = a;
	pol_y = b;
}
void Organizm::kolizja(int x, int y,int x2, int y2){
	Organizm *f = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
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
		f->swiat->usunObiekt(x,y);
		cout << f->zwrocZnak() << "-przegrywa walke z: " << l->zwrocZnak()<< "\n";
	}
}
int Organizm::zwrocSile(){
	return sila;
}
char Organizm::zwrocZnak()
{ return znak;
}
int Organizm::zwiekszSile(){
	return sila = sila + 3;
}
void Organizm::rozmnazanie(int x, int y, int x2, int y2){
	Organizm *h = swiat->zwrocOrganizm(x, y);
	Organizm *l = swiat->zwrocOrganizm(x2, y2);
	int potx, poty, potx1, poty1;
	potx = x ;
	poty = y ;
	int f = 0;
	do {
		f = rand() % 4;
	} while (!swiat->sprawdzRuch(f,potx , poty));
	 potx1 = potx;
	 poty1 = poty;
	switch (f)
	{
	case 0:
		poty1 = poty-1;

		break;
	case 1:
		poty1 = poty+1;
		break;
	case 2:
		potx1 = potx+1;
		break;
	case 3:
		potx1 = potx-1;
		break;
	}
	char t = l->zwrocZnak();
	Organizm *kolizja1 = swiat->zwrocOrganizm(potx1, poty1);
	if (kolizja1 == NULL){
		swiat->dodajOrganizm(kolizja1, t, potx1,poty1);
		potx = potx1;
		poty = poty1;
		cout << t << " rozmnozyl sie" << "\n";
	}
	
	else {
	if (swiat->zwrocOrganizm(potx + 1, poty) != NULL&& swiat->zwrocOrganizm(potx, poty + 1) != NULL&&swiat->zwrocOrganizm(potx - 1, poty) != NULL&&swiat->zwrocOrganizm(potx, poty - 1) != NULL){
		cout << "Brak miejsca" << "\n";
	}
	else  rozmnazanie(x, y, x2, y2);
	}
	
}
int Organizm::zwrocPolozenie(){
	return pol_x, pol_y;
}
void Organizm::oflaguj(){
	 flaga = true;

}
void Organizm::zdejmij(){
	flaga = false;
}
bool Organizm::zwrocFlage(){
	return flaga;
}
void Organizm::dodaj(){
	wiek++;
}
int Organizm::zwrocWiek(){
	return wiek;
}