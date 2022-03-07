#include "Header.h"

/*
Задание 7: Написать примитивный калькулятор, пользуясь только указателями.
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

	char ex=' ';
	do
	{
		cout << "Введите: \"число 1\" \"операция\" \"число 2\":" << endl;
		double a, b;
		double* pa = &a;
		double* pb = &b;
		char oper;
		bool correct = true;
		cin >> *pa >> oper >> *pb;
		switch (oper)
		{
		case '+':
			cout << *pa + *pb << endl;
			break;
		case '-':
			cout << *pa - *pb << endl;
			break;
		case '*':
			cout << *pa * *pb << endl;
			break;
		case '/':
			if (*pb == 0) {
				cout << "На ноль делить нельзя!\n";
				break;
			}
			cout << *pa / *pb << endl;
			break;
		default:
			cout << "Операция не корректна!\n";
			cin.clear();
			cin.ignore(32767, '\n');
			correct = false;
			break;
		}
		if (correct) {
			cout << "Введите что-угодно для продолжения, N для выхода: ";
			cin >> ex;
			if (ex != 'N' && ex != 'n') {
				cin.ignore(32767, '\n');
			}
		}
			
	} while (ex!='N' && ex != 'n');
	

	return 0;
}

