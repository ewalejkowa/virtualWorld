#include "Czlowiek.h"
#include "swiat.h"


Czlowiek::Czlowiek(int sila, int inicjatwa, char znak){
	this->znak = znak;
	this->inicjatywa = inicjatywa;
	this->sila = sila;
}
void Czlowiek::akcja(){
	
		char v;
		if (licznik == 0){
			cout << "Czy chcesz aktywowac specjalna umiejetnosc? t/n" << "\n";
			v = getchar();
			if (v == 't'){
				licznik = 10;
			}
			else;
		}
		if (licznik >= 5 && licznik >=7){
			sp();
		}
		else if (licznik >= 5 && licznik <= 7){
			
			int nowy = rand() % 1;
			switch (nowy){
			case 0:
				sp();
				break;

			case 1:
				zmniejsz();
					
				break;
			}
		}
		 if (licznik < 5 ){
			cout << "Podaj kierunek ruchu czlowieka" << "\n";
			int nowyx = pol_x;
			int nowyy = pol_y;
			int kierunek = 0;
			do {
				kierunek = getch();
			} while (!swiat->CzlowiekRuch(kierunek, pol_x, pol_y));
			switch (kierunek){

			case 0x50: // gora
				nowyy = pol_y + 1;
				break;
			case 0x48: // dol
				nowyy = pol_y - 1;
				break;
			case 0x4d: // prawo
				nowyx = pol_x + 1;
				break;
			case 0x4b: // lewo
				nowyx = pol_x - 1;
				break;
			}
			Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);


			if (kolizja1 == NULL){
				swiat->przesun(pol_x, pol_y, nowyx, nowyy);
				pol_x = nowyx;
				pol_y = nowyy;

			}
			else if (kolizja1->zwrocZnak() == 'j'){
				kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
			}
			else if (kolizja1->zwrocZnak() == 'g'){
				kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
				pol_x = nowyx;
				pol_y = nowyy;
			}
			else {
				this->kolizja(pol_x, pol_y, nowyx, nowyy);
				pol_x = nowyx;
				pol_y = nowyy;
			}
			if (licznik > 0){
				zmniejsz();
			}
		}
	//
		 flaga = true;
		 wiek++;
}
void Czlowiek::kolizja(int x, int y, int x2, int y2){
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
		f->swiat->usunObiekt(x, y);
		cout << f->zwrocZnak() << "-przegrywa walke z: " << l->zwrocZnak() << "\n";
	}
}
void Czlowiek::zmniejsz(){
	licznik--;
}
void Czlowiek::sp(){
	cout << "Podaj kierunek ruchu czlowieka" << "\n";
	cout << "speck";
	int nowyx = pol_x;
	int nowyy = pol_y;
	int kierunek = 0;
	do {
		kierunek = getch();
	} while (!sprawdzRuchcz(kierunek, pol_x, pol_y));
	switch (kierunek){

	case 0x50: // gora
		nowyy = pol_y + 2;
		break;
	case 0x48: // dol
		nowyy = pol_y - 2;
		break;
	case 0x4d: // prawo
		nowyx = pol_x + 2;
		break;
	case 0x4b: // lewo
		nowyx = pol_x - 2;
		break;
	}
	Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);
	if (kolizja1 == NULL){
		swiat->przesun(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (kolizja1->zwrocZnak() == 'g'){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;
	}
	else if (kolizja1->zwrocZnak() == 'j'){
		kolizja1->kolizja(pol_x, pol_y, nowyx, nowyy);
	}
	else  {
		this->kolizja(pol_x, pol_y, nowyx, nowyy);
		pol_x = nowyx;
		pol_y = nowyy;

	}
	zmniejsz();
	flaga = true;
	wiek++;
}

bool Czlowiek::sprawdzRuchcz(int kierunek, int x, int y){
	if (kierunek == 0x48){// dol
		if (y + 4 < 20){
			return true;
		}

	}
	else if (kierunek == 0x50){
		// gora
		if (y - 4>= 0){
			return true;
		}

	}
	else if (kierunek == 0x4b){
		// lewo
		if (x - 4>= 0){
			return true;
		}

	}
	else if (kierunek == 0x4d){
		// prawo
		if (x + 4 < 20){
			return true;
		}

	}

	return false;
}