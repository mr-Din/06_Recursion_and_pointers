#include "Header.h"

/*Задание 2. Используя указатель на массив целых чисел, изменить порядок
следования элементов массива на противоположный.
Использовать в программе арифметику указателей для продвижения по массиву,
а также оператор разыменования.*/


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
	ShowArr(arr, n);
	// указатель на начало и конец массива
	int* arr_start = arr;
	int* arr_end = arr + n - 1;
	// Развернём массив
	for (int i = 0; i < n/2; i++)
	{
		int tmp = *arr_start;
		*arr_start = *arr_end;
		*arr_end = tmp;
		arr_start++;
		arr_end--;
	}
	ShowArr(arr, n);
	
	return 0;
}

