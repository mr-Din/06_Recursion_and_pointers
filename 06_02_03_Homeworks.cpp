#include "Header.h"

/*Задание 3. Используя два указателя на массивы целых чисел, скопировать
один массив в другой так, чтобы во втором массиве элементы находились
в обратном порядке.
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
	// указатель на конец массива
	int* arr_end = arr + n - 1;
	
	// Второй массив 
	int* arr2 = new int[n];
	
	cout << "До копирования:\n";
	ShowArr(arr, n);
	ShowArr(arr2, n);
	
	// Копирование массива arr в arr2 в обратном порядке
	for (int i = 0; i < n; i++)
	{
		*(arr2+i) = *arr_end;
		arr_end--;
	}
	cout << "После копирования:\n";
	ShowArr(arr, n);
	ShowArr(arr2, n);
	
	return 0;
}

