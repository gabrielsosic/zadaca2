#include <iostream>
#include <string>
#include <fstream>
#include<ctime>
#include "game_of_life.h"
using namespace std;

int main() {
	game_of_life the_game;
	srand(time(nullptr));
	
	bool dalje;
	do {
		the_game.iscrtaj();
		the_game.sljedeca_generacija();
		
		cout << "Dalje (1/0): ";
		cin >> dalje;
	} while (dalje);

	return 0;
}