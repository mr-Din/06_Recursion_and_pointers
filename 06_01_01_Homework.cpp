#include "Header.h"

/*Задание 1: Написать рекурсивную функцию нахождения
наибольшего общего делителя двух целых чисел. */

int GetGCD(int a, int b) {
	if (a > b) {
		if (b != 0) {
			return GetGCD(b, a % b);
		}
		else {
			return a;
		}
	}
	else {
		if (a != 0) {
			return GetGCD(a, b % a);
		}
		else {
			return b;
		}
	}
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	cout << GetGCD(3430, 1365) << endl;
	cout << GetGCD(1365, 3430) << endl;

	return 0;
}