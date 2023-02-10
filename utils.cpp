#include "utils.h"
#include <string>
#include <iostream>
#include <locale>
#include <algorithm>
#include <conio.h>
#include <iomanip>

using namespace std;
char maininput = 'a';

void msg(string inputmsg, int mode)
{
	switch (mode) {
	case 1:
		cout << setw(5) << "" << inputmsg;
		break;
	default:
		cout << setw(5) << "" << inputmsg << "\r\n";
		break;
	}
}

void pcontinue() {
	msg("Insérer Q pour quitter, et n'impote quels symbole pour continuer.", 1);
	maininput = _getche();
	msg("\r\n");
}

void strlower(std::string &input) {
	for (int i = 0; i < input.size(); i++) {
		input[i] = tolower(input[i]);
	}
}

void wininit() {
	std::setlocale(LC_ALL, "fr_CA");
	system("chcp 1252");
	system("cls");
}

// replace symbol in a string.
string replacesymbol(string inout, char replaceOrigin, char replaceString) {
	replace(inout.begin(), inout.end(), replaceOrigin, replaceString);
	return inout;
}

int numEdit(int min, int max) {
	int vtmp = min - 1;

	while (vtmp < min || vtmp > max) {
		msg("ins\351rer une valuer num\351rique qui est incluse entre " + to_string(min) + " et " + to_string(max) + ": ", 1);
		cin >> vtmp;
		// solution trouver https://www.sololearn.com/discuss/473034/how-to-fix-infinite-loop-when-user-enters-char-into-int-data-type
		if (cin.fail())
		{
			cin.clear(); cin.ignore(512, '\n');
			msg("\r\nN'est pas un nombre!");
			vtmp = -1;
		}
	}
	return vtmp;
}