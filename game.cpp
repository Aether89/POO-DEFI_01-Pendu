#include "utils.h"
#include "pendu.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include "game.h"
#include <conio.h>

using namespace std;

string randomMot(int difficulte) {

	ifstream fichier;
	string flux = "";
	int ligneTotal[] = {0,0};
	int ligne = 0;
	int difficulteSkip = 0;

	fichier.open("mots.txt");
	if (fichier.is_open()) {
		while (getline(fichier, flux)) {
			
			if (flux == "=====") difficulteSkip++;
			if (difficulteSkip == difficulte) ligneTotal[0]++;
			if (difficulteSkip < difficulte) ligneTotal[1]++;

		}
	}
	else {
		msg("Le Fichier est innacessible");
		pcontinue();
	}

	fichier.close();
	fichier.clear();

	srand(time(NULL));
	ligne = (rand() % ligneTotal[0] + 1) + ligneTotal[1];
	ligneTotal[0] = 0;

	fichier.open("mots.txt");
	if (fichier.is_open()) {
		while (ligneTotal[0] != ligne && getline(fichier, flux)) {
			ligneTotal[0]++;
		}
	}
	else {
		msg("Le Fichier est innacessible");
		pcontinue();
	}
	fichier.close();

	strlower(flux);
	return flux;
}

int difficulte()
{
	int difficulte = 0;
	msg("Choisiser une difficulté");
	msg("1]- Novice");
	msg("2]- Apprentit");
	msg("3]- Adep");
	msg("4]- Expert");
	msg("5]- Maître");

	difficulte = numEdit(1,5);
	return (difficulte - 1);
}

void ui(Pendu game) {
	system("cls");
	cout << setw(5) << "" << setw(2) << game.getVie(1) << setw(1) << "\\" << setw(2) << game.getVie() << setw(5) << "" << "Score: " << game.getScore() << "\r\n" <<
		setw(5) << "" << game.getMot(0) <<
		setw(5) << "" << game.getMot(2) << endl;
}

void game() {
	wininit();

	msg("Insérer le nombre de vie que vous avez.");
	int vie = numEdit(3,10);
	Pendu game(vie, randomMot(difficulte()));
	
	char guess = '\0';
	ui(game);

	while (game.getVie(1) > 0 && game.getMot(0) != game.getMot(1)) {
		msg("Choisisez une lettre: ", 1);
		cin >> guess;
		game.guess(tolower(guess));
		ui(game);
	}

	if (game.getVictoire()) {
		msg("Félicitations vous avez Gagné!!!");
	}
	else {
		msg("Le mot était " + game.getMot());
	}

	pcontinue();


}