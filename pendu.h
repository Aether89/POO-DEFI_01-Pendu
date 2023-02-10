#pragma once
#include <string>

class Pendu {

private:

	std::string _mot[3];
	int _vie;
	int _vieTotal;
	int _score;
public:
	
	Pendu(int vie, std::string mot);
	std::string getMot(int index = 1) const;
	int getVie(bool mode = 0) const;
	void guess(char guess);
	void setVie();
	void setMot(std::string mot, int index = 0);
	void setScore();
	int getScore() const;
	bool getVictoire() const;
};

void ui();