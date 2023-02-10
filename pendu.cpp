#include "pendu.h"

using namespace std;

Pendu::Pendu(int vie, string mot) {
	_vie = vie;
	_vieTotal = vie;
	_mot[1] = mot;
	_mot[0] = "";
	_mot[2] = "";
	_score = 0;

	for (int i = 0; i < _mot[1].size(); i++) {
		_mot[0].append("_");
	}

}

void Pendu::setMot(std::string mot, int index) {
	_mot[index] = mot;
}


string Pendu::getMot(int index) const {
	return _mot[index];
}

int Pendu::getScore() const {
	return _score;
}

int Pendu::getVie(bool mode) const{
	if (mode) {
		return _vie;
	}
	else {
		return _vieTotal;
	}
}

void Pendu::setScore() {
	_score++;
}

void Pendu::setVie() {
	_vie--;
}

void Pendu::guess(char guess) {

	int pos = 0;
	 Pendu::setScore();

	string affiche = Pendu::getMot(2);
	affiche += guess; // https://stackoverflow.com/questions/1472048/how-to-append-a-char-to-a-stdstring
	Pendu::setMot(affiche, 2);


	affiche = Pendu::getMot(0);
	string mot = Pendu::getMot(1);
	bool vie = 0;
	for (int i = 0; i < mot.size(); i++) {
		if (mot[i] == guess) {
			 affiche[i] = guess;
			 vie = 1;
		}
	}

	if (!vie) {
		Pendu::setVie();
	}

	Pendu::setMot(affiche, 0);
}

bool Pendu::getVictoire() const {
	bool victoire;

	victoire = (Pendu::getMot(0) == Pendu::getMot(1));

	return victoire;
}