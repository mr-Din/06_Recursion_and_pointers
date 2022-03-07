#include "Header.h"


/*
Задание 4. Написать рекурсивную функцию нахождения степени числа.

Задание 5. Написать рекурсивную функцию, которая выводит N звезд в ряд,
число N задает пользователь. Проиллюстрируйте работу функции примером.

Задание 6. Написать рекурсивную функцию, которая вычисляет сумму всех
чисел в диапазоне от a до b. Пользователь вводит a и b. Проиллюстрируйте
работу функции примером.
*/

int Degree(int number, int degree) {
	if (degree == 1) {
		return number;
	}
	if (degree == 0) {
		return 1;
	}
	number *= Degree(number, --degree);

}

void ShowStar(int stars) {
	if (stars == 0) {
		return;
	}
	cout << "* "s;
	ShowStar(--stars);
}

int SumOfNumberInRange(int a, int b) {
	if (a > b) {
		cout << "Некорректные данные!\n";
		return 0;
	}
	int res = a;
	if (a == b) {
		return res;
	}
	res += SumOfNumberInRange(++a, b);
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	cout << Degree(8, 7) << endl; //2097152
	cout << "Введите число и степень: ";
	int number, degree; cin >> number >> degree;
	cout << number << " в степени " << degree << " = " << Degree(number, degree) << endl;
	
	cout << "\nВведите количество звёзд на вывод: ";
	int count_stars; cin >> count_stars;
	ShowStar(count_stars);

	cout << "\n\nВведите 2 числа: ";
	int a, b; cin >> a >> b;
	cout << "Сумма чисел в диапазоне от " << a << " до " << b << " = " << SumOfNumberInRange(a, b) << endl;
	return 0;
}

