#include "Header.h"

/*
Задание 4:
Используя указатели и оператор разыменования, определить наибольшее из двух чисел.
Задание 5:
Используя указатели и оператор разыменования, определить знак числа, введённого с
клавиатуры.
Задание 6:
Используя указатели и оператор разыменования, обменять местами значения двух
переменных.
*/


// Одномерный массив
int* ArrOneDim(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		//arr[i] = rand() % (100 - (-100)) - 100;
		arr[i] = rand() % 100;
	}
	return arr;
}

void ShowArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		/*cout << *arr << " ";
		arr++;*/
		cout << "[" << i << "]=" << arr[i] << " ";
	}
	cout << endl;
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));

	// Задание №4
	cout << "Введите 2 числа: ";
	int a, b; cin >> a >> b;
	int* pa = &a;
	int* pb = &b;
	(*pa > *pb) ? (cout << *pa << ">" << *pb << endl) : (cout << *pa << "<=" << *pb << endl);
	

	// Задание №5
	cout << "Введите число: ";
	int c; cin >> c;
	int* pc = &c;
	(*pc < 0) ? (cout << *pc << " отрицательное число" << endl)
		: (cout << *pc << " положительное число" << endl);

	// Задание №6
	cout << "Введите 2 числа: ";
	int d, e; cin >> d >> e;
	int* pd = &d;
	int* pe = &e;
	cout << "d = " << *pd << "; e = " << *pe << endl;
	int* tmp = pd;
	pd = pe;
	pe = tmp;
	cout << "d = " << *pd << "; e = " << *pe << endl;

	return 0;
}

