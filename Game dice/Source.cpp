// ������������ ������ ������� �++
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
			cout << "��� ������ 6. ������ �� ������ ����� ��� ���? ����� -> ";
			bool choice;
			cin >> choice;
			if (choice) {
				points = rand() % 6 + 1;
				if (points % 2) {
					scorePlayer += points;
					cout << "��� ������ " << points << "\n";
					cout << "�����: " << scorePlayer << "\n";
				}
				else {
					scorePlayer -= points;
					cout << "��� ������ " << points << "\n";
					cout << "�����: " << scorePlayer << "\n";
				}
			}
		}
		else {
			scoreComp += points;
			if (first) {
				cout << "���������� ������ 6. �� ����� ������ ��������.\n";
				points = rand() % 6 + 1;
				if (points % 2)
					scoreComp += points;

				else
					scoreComp -= points;
				

			}
			else {
				cout << "���������� ������ 6. �� ����� �� ������\n";
			}
		}
	}
	else
		if (comp) {
			scoreComp += points;
			cout << "���������� ������ " << points << "\n";
			cout << "���������: " << scoreComp << "\n";
		}
		else {
			scorePlayer += points;
			cout << "��� ������ " << points << "\n";
			cout << "�����: " << scorePlayer << "\n";
		}
}


int main() {
	setlocale(LC_ALL, "Russian");
	srand(time(NULL));

	cout << "����� ������� � ����!\n";
	if (first()) {
		cout << "�������� �����\n����� ������� ����� -> ";
		roll();

	}
	else
		cout << "�������� ���������\n��������� ������� ����� -> ";
	do {
		if (scorePlayer < 50)
			roll(true);
		if (scoreComp < 50)
			roll();

	} while (scorePlayer < 50 && scoreComp < 50);
	if (scorePlayer >= 50)
		cout << "�� ��������";
	else
		cout << "������� ���������";

	return 0;
}