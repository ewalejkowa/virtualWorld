
#include <iostream>
#include "swiat.h"
#include<fstream>
#include<sstream>
#define ILOSC_ORGANIZMOW 28

using namespace std;

void Swiat::rysujSwiat(){
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j){
			if (organizmy[i][j] == NULL){
				cout << '_' << ' ';
			}
			else{
				organizmy[i][j]->rysowanie();
			}
		}
		cout << "\n";
	}

}
Swiat::Swiat( int s){
	this->size = s;

	organizmy = new Organizm**[s];
	for (int i = 0; i < s; i++){
		organizmy[i] = new Organizm*[s];
		for (int j = 0; j < s; j++){
			organizmy[i][j] = NULL;
		}
	}	
	dodajOrganizmy();
		
}
void Swiat::wykonajTure(){
	
	for (int i = 0; i < lista.zwrocIlosc() ; i++){
		if (lista.pobierzZ(i)->zwrocFlage() == false){
			lista.pobierzZ(i)->akcja();
			lista.pobierzZ(i)->oflaguj();
			lista.pobierzZ(i)->dodaj();

		}
	}
	for (int i = 0; i < lista.zwrocIlosc(); i++){
		lista.pobierzZ(i)->zdejmij();

	}

	//system("cls");
	rysujSwiat();

}
void Swiat::dodajOrganizmy(){
	for (int i = 0; i < ILOSC_ORGANIZMOW && i < size*size; i++){
		int f, g;
		do {
			f = rand() % size;
			g = rand() % size;
		} while (organizmy[f][g] != NULL);
		
		int numerOrganizmu = rand() % 9;
		switch (numerOrganizmu){
		case 0: organizmy[f][g] = new Wilk();  lista.dodaj(organizmy[f][g]);break;
		case 1: organizmy[f][g] = new Owca(); lista.dodaj(organizmy[f][g]); break;
		case 2: organizmy[f][g] = new Antylopa(); lista.dodaj(organizmy[f][g]); break;
		case 3: organizmy[f][g] = new Lis(); lista.dodaj(organizmy[f][g]); break;
		case 4: organizmy[f][g] = new Zolw();  lista.dodaj(organizmy[f][g]); break;
		case 5: organizmy[f][g] = new Guarana();   lista.dodaj(organizmy[f][g]); break;
		case 6: organizmy[f][g] = new Mlecz();   lista.dodaj(organizmy[f][g]); break;
		case 7: organizmy[f][g] = new Trawa();  lista.dodaj(organizmy[f][g]); break;
		case 8: organizmy[f][g] = new WilczeJagody(); lista.dodaj(organizmy[f][g]); break;
		default: organizmy[f][g] = new Organizm();
		}
		organizmy[f][g]->wczytajgre(this);
		organizmy[f][g]->ustaw(g,f);
	}
	int c, k;
	do {
		c = rand() % size;
		k = rand() % size;
	} while (organizmy[c][k] != NULL);
	organizmy[c][k] = new Czlowiek();
	organizmy[c][k]->wczytajgre(this);
	organizmy[c][k]->ustaw(k, c);
	lista.dodaj(organizmy[c][k]); 

}

bool Swiat::sprawdzRuch(int kierunek, int x, int y){
	switch (kierunek){
	case 0:
		if (y-1 >= 0) return true;//g
		break;
	case 1:
		if (y +1< size) return true;//d
		break;
	case 2:
		if (x +1 < size) return true;//p
		break;
	case 3:
		if (x-1  >= 0) return true;//l
		break;
default:
	return true;
	break;
	}
	
	return false;
}
Organizm* Swiat::zwrocOrganizm(int x, int y){
	return organizmy[y][x];
}
void Swiat::przesun(int x, int y, int nowyx, int nowyy){
	organizmy[nowyy][nowyx] = organizmy[y][x];
	lista.dodaj(organizmy[nowyy][nowyx]);
	lista.usun(organizmy[y][x]);
	
	organizmy[y][x] = NULL;
	
}
bool Swiat::CzlowiekRuch(int kierunek, int x, int y){
	if (kierunek == 0x48){// dol
		if (y + 1 < size){
			return true;
		}
		
	}
	else if (kierunek == 0x50){
		// gora
		if (y -1> 0){
			return true;
		}
		
	}
	else if (kierunek == 0x4b){
		// lewo
		if (x -1> 0){
			return true;
		}
		
	}
	else if (kierunek == 0x4d){
		// prawo
		if (x + 1 < size){
			return true;
		}
	
	}

	return false;
}
void Swiat::usunto(int x, int y, int x2, int y2){
	usunObiekt(x2,y2);
	przesun(x, y, x2, y2);
}
void Swiat::usunObiekt(int x, int y){
	lista.usun(organizmy[y][x]);
	organizmy[y][x] = NULL;
}
void Swiat::dodajOrganizm(Organizm* l , char znak,int potx, int poty )
{
	switch (znak){
	case 'W': organizmy[poty][potx] = new Wilk();  lista.dodaj(organizmy[poty][potx]); break;
	case 'A': organizmy[poty][potx] = new Antylopa();  lista.dodaj(organizmy[poty][potx]); break;
	case 'O': organizmy[poty][potx] = new Owca();  lista.dodaj(organizmy[poty][potx]); break;
	case 'L': organizmy[poty][potx] = new Lis();  lista.dodaj(organizmy[poty][potx]); break;
	case 'Z': organizmy[poty][potx] = new Zolw();  lista.dodaj(organizmy[poty][potx]); break;
	case 't': organizmy[poty][potx] = new Trawa();  lista.dodaj(organizmy[poty][potx]); break;
	case 'm': organizmy[poty][potx] = new Mlecz();  lista.dodaj(organizmy[poty][potx]); break;
	case 'g': organizmy[poty][potx] = new Guarana();  lista.dodaj(organizmy[poty][potx]); break;
	case 'j': organizmy[poty][potx] = new WilczeJagody();  lista.dodaj(organizmy[poty][potx]); break;

	}
	organizmy[poty][potx]->wczytajgre(this);
	organizmy[poty][potx]->ustaw(potx, poty);
	organizmy[poty][potx]->oflaguj();
}

void Swiat::zapiszDoPliku(){
	std::string filename = "plansza.txt";
	std::fstream file;
	file.open(filename.c_str(), std::ios::out);	
	if (file.good() == true){	
			char t;
			int y;
			int l = 0;
			for (int i = 0; i < lista.zwrocIlosc(); i++){
				std::string line;
				std::stringstream s;

				t=lista.pobierzZ(i)->zwrocZnak();
				s << t;
				file << s.str();
				y = lista.pobierzZ(i)->zwrocPolozenie();
					file << s.str();
		
			}
	}	
	file.close();
}
void Swiat::wczytajZPliku(){
	
	std::string filename = "plansza.txt";
		std::fstream file;
		file.open(filename.c_str(), std::ios::in | std::ios::out);
		int l = 0;
		if (file.good() == true)
		{
			std::string line;
			while (l < size  &&  getline(file, line)){

				l++;
			}

			file.close();
		}
}
