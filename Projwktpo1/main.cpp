#include <iostream>
#include "swiat.h"
#include<stdio.h>
#include"conio2.h"
#include <cstdlib>

using namespace std;

int main(){
	Swiat t;

	int zn = 0;
	int c = 0;
	t.rysujSwiat();
	
	cout << "Wcisnij s by rozpoczac ture:";
	c = getchar();
	if (c == 's'){
		system("cls");
		do{
			t.rysujSwiat();
			t.wykonajTure();
			cout << "\n";
			cout << "\n";
			cout << "Rozpocznij nowa ture, wcisnij q zeby zakonczyc lub f, zeby zapisac stan do pliku";
			c= getchar();
			if (c == 'q'){
				break;
			}
			else if (c == 'f'){
				t.zapiszDoPliku();
				break;
			}
			system("cls");
		} while (zn != true);
	}
	return 0;
}
