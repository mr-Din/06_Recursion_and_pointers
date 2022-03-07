#include "Header.h"

/*
Задание 8. Используя указатель на массив целых чисел, посчитать сумму элементов
массива. Использовать в программе арифметику указателей для продвижения по массиву,
а также оператор разыменования.
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
	cout << "Введите размер массива: ";
	int n; cin >> n;
	int* arr = ArrOneDim(n);
	// ещё один указатель на массив
	int* pa = arr;
	ShowArr(arr, n);
	int sum = 0;
	int sum2 = 0;
	for (int i = 0; i < n; i++)
	{
		// способ 1
		sum += *(arr + i);
		// способ 2 (сдвиг самого указателя)
		sum2 += *(pa++);

	}
	cout << "Сумма элементов массива = " << sum << endl;
	cout << "Сумма элементов массива = " << sum2 << endl;
	ShowArr(arr, n);
	return 0;
}

