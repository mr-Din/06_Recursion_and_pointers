#include "Header.h"

/*Задание 1. Используя два указателя на массив целых чисел, скопировать
один массив в другой.
Использовать в программе арифметику указателей для продвижения по массиву,
а также оператор разыменования.*/


// вывод вектора
ostream& operator << (ostream& out, vector<int> v) {
	for (int i : v) {
		out << i;
	}
	return out;
}



// 2-мерный массив - квадратная мартица
int** ArrTwoDim(int size, int element) {
	int** arr = new int* [size];
	for (int i = 0; i < size; ++i) {
		arr[i] = new int[size];
	}

	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			arr[i][j] = element;
		}
	}
	return arr;
}

// Одномерный массив
int* ArrOneDim(int size) {
	int* arr = new int[size];
	for (int i = 0; i < size; ++i) {
		arr[i] = rand() % (100 - (-100)) - 100;
	}
	return arr;
}

void ShowArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		cout << *arr << " ";
		arr++;
	}
	cout << endl;
}

void Show(int** arr, int size) {
	for (int i = 0; i < size; ++i) {
		for (int j = 0; j < size; ++j) {
			cout << setfill(' ') << setw(2) << arr[i][j]<<" ";
		}
		cout << endl;
	}
	cout << endl;
}




int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	cout << "Введите размер массива: ";
	int n; cin >> n;

	int* arr_1 = ArrOneDim(n);	// заполненный массив
	int* arr_2 = new int[n];	// незаполненный массив
	cout << "Массив №1: \n";
	ShowArr(arr_1, n);
	cout << "Массив №2: \n";
	ShowArr(arr_2, n);
	// Копирование данных одного массива в другой через указатели

	for (int i = 0; i < n; i++)
	{
		*(arr_2+i) = *(arr_1+i);
	}
	cout << "=================================\n";
	cout << "Массив №2 с данными из массива №1: \n";
	ShowArr(arr_2, n);

	// При копировании (а не присваивании указателя) массива ошибки не будет
	delete[] arr_1;
	delete[] arr_2;

	
	return 0;
}

