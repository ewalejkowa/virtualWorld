#include <iostream>
#include "roslina.h"
#include "swiat.h"
#define PRAWDOPODOBIENSTWO 60

using namespace std;
void Roslina::akcja(){

	int c = rand() % PRAWDOPODOBIENSTWO;
	switch (c){
	case 0:
		int f = 0;
		do {
			f = rand() % 4;
		} while (!swiat->sprawdzRuch(f, pol_x, pol_y));
		int nowyx = pol_x;
		int nowyy = pol_y;
		switch (f)
		{
		case 0:
			nowyy = pol_y-1;

			break;
		case 1:
			nowyy = pol_y+1;
			break;
		case 2:
			nowyx = pol_x+1;
			break;
		case 3:
			nowyx = pol_x-1;
			break;
		}
		char t = this->zwrocZnak();
		Organizm *kolizja1 = swiat->zwrocOrganizm(nowyx, nowyy);
		if (kolizja1 == NULL){
			swiat->dodajOrganizm(kolizja1, t, nowyy, nowyx);
			cout << t << "-zasial nowa rosline" << "\n";
		}

		break;

	}
	flaga = true;
}