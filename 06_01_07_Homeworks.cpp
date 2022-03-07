#include "Header.h"

/*Задание 7. Напишите рекурсивную функцию, которая принимает одномерный
массив из 100 целых чисел, заполненных случайным образом, и находит позицию,
с которой начинается последовательность из 10 чисел, сумма которых минимальна.*/


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
		//arr[i] = rand() % (100 - (-100)) - 100;
		arr[i] = rand() % 100;
	}
	return arr;
}

void ShowArr(int* arr, int size) {
	for (int i = 0; i < size; ++i) {
		/*cout << *arr << " ";
		arr++;*/
		cout << "[" << i << "] = " << arr[i] << endl;
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

int GetPos(int* arr, int n, int& pos) {
	int s = 0;
	for (int i = n; i < n + 10; ++i) s += arr[i];
	cout << "Позиция: " << n << "; Сумма: " << s << endl;
	if (100 - n == 10)
	{
		pos = n;
		return s;
	}
	else
	{
		int s1 = GetPos(arr, n + 1, pos);
		if (s <= s1)
		{
			pos = n;
			return s;
		}
		else return s1;
	}
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	//cout << "Введите размер массива: ";
	int n = 100;

	int* arr = ArrOneDim(n);	// заполненный массив
	ShowArr(arr, n);
	int p = 0;
	int sum = GetPos(arr, 0, p);
	cout << "Минимальная сумма: ";
	cout << sum << "\nПозиция: " << p << endl;
	

	
	return 0;
}

