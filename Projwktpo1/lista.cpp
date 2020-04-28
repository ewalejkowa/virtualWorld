#include "lista.h"
#include <iostream>


Lista::Lista(){
	ilosc = 0;
	Pierwszy = NULL;
}

void Lista::dodaj(Organizm *o){
	if (ilosc == 0){
		Pierwszy = new PoleListy;
		Pierwszy->nast = NULL;
		Pierwszy->poprz = NULL;
		Pierwszy->o = o;
	}

	else {
		//dodajemy na poczatku listy
		if (o->inicjatywa > Pierwszy->o->inicjatywa){
			PoleListy * nowe = new PoleListy();
			nowe->o = o;
			nowe->poprz = NULL;
			nowe->nast = Pierwszy;
			Pierwszy->poprz = nowe;
			
			//Pierwszy->o = nowe->o;
			Pierwszy = nowe;
			//Pierwszy->o = nowe->nast->o;
			
		}
		else {
			PoleListy *i = Pierwszy;
			while (i->o->inicjatywa >= o->inicjatywa && i->nast != NULL){
				i = i->nast;
			}
			PoleListy * nowe = new PoleListy();
			nowe->o = o;

			// dodajemy na koncu listy
			if (i->nast == NULL && i->o->inicjatywa > o->inicjatywa){
				nowe->poprz = i;
				i->nast = nowe;
				nowe->nast = NULL;
			}
			// dodajemy w srodku listy
			else if (i->o->inicjatywa == o->inicjatywa && i->o->zwrocWiek() <= o->zwrocWiek()){
				
				nowe->poprz = i;
				i->nast = nowe;
				nowe->nast = NULL;
				
			}
			else {
				nowe->poprz = i->poprz;
				nowe->nast = i;
				i->poprz->nast = nowe;
				i->poprz = nowe;
			}
		}

	}
	ilosc++;

}

void Lista::wyswietl(){
	PoleListy *j = Pierwszy;
	while (j != NULL){
		printf("%d -> ", j->o->inicjatywa);
		j = j->nast;
	}
}

 Organizm *Lista::pobierzZ(int ktory){
	int i = 0;
	PoleListy *a = Pierwszy;

	while (i < ktory && i < ilosc){
		a = a->nast;
		i++;
	}
			return a->o;
		
}
int Lista::zwrocPol(int ktory){
	int i = 0;
	PoleListy *a = Pierwszy;

	while (i < ktory && i < ilosc){
		a = a->nast;
		i++;
	}
	return a->o->zwrocPolozenie();
}


void Lista::usun(Organizm *o){

		int i = 0;
		// znalezienie usuwanego elementu
		PoleListy *a = Pierwszy;
		while (a->o != o && i<ilosc){
			a = a->nast;
			i++;
		}

		// nie ma takiego elementu na liscie
		if (a == NULL)
			return;

		// usuwany element jest na poczatku listy
		if (a == Pierwszy){
			a->nast->poprz = NULL;
			Pierwszy = a->nast;
			delete a;
			ilosc--;
		}
		// element jest ostatnim na liscie
		else if (a->nast == NULL){
			a->poprz->nast = NULL;
			delete a;
			ilosc--;
		}
		// element jest w srodku
		else{
			a->poprz->nast = a->nast;
			a->nast->poprz = a->poprz;

			delete a;
			ilosc--;
		}
	}

int Lista::zwrocIlosc(){
	return ilosc;
}
