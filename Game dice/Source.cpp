// Персональный шаблон проекта С++
#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;
int scorePlayer = 0, scoreComp = 0;
bool first() {
	return rand() % 2;
}
void roll(bool comp = false) {
	int points = rand() % 6 + 1;
	if (points == 6) {
		if (!comp) {
			scorePlayer += points;
			cout << "Вам выпало 6. Хотите ли кинуть кубик еще раз? Ответ -> ";
			bool choice;
			cin >> choice;
			if (choice) {
				points = rand() % 6 + 1;
				if (points % 2) {
					scorePlayer += points;
					cout << "Вам выпало " << points << "\n";
					cout << "Игрок: " << scorePlayer << "\n";
				}
				else {
					scorePlayer -= points;
					cout << "Вам выпало " << points << "\n";
					cout << "Игрок: " << scorePlayer << "\n";
				}
			}
		}
		else {
			scoreComp += points;
			if (first) {
				cout << "Компьютеру выпало 6. Он решил кинуть повторно.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComp += points;

				else
					scoreComp -= points;
				

			}
			else {
				cout << "Компьютеру выпало 6. Он решил не кидать\n";
			}
		}
	}
	else
		if (comp) {
			scoreComp += points;
			cout << "Компьютеру выпало " << points << "\n";
			cout << "Компьютер: " << scoreComp << "\n";
		}
		else {
			scorePlayer += points;
			cout << "Вам выпало " << points << "\n";
			cout << "Игрок: " << scorePlayer << "\n";
		}
}


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "Давай сыграем в игру!\n";
	if (first()) {
		cout << "Начинает игрок\nИгрок бросает кубик -> ";
		roll();

	}
	else
		cout << "Начинает компьютер\nКомпьютер бросает кубик -> ";
	do {
		if (scorePlayer < 50)
			roll(true);
		if (scoreComp < 50)
			roll();

	} while (scorePlayer < 50 && scoreComp < 50);
	if (scorePlayer >= 50)
		cout << "Вы победили";
	else
		cout << "Победил компьютер";

	return 0;
}