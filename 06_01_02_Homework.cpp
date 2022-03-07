#include "Header.h"

/*Задание 2: Написать игру «Быки и коровы». Программа "загадывает" четырёхзначное число
и играющий должен угадать его. После ввода пользователем числа программа сообщает,
сколько цифр числа угадано (быки) и сколько цифр угадано и стоит на нужном месте (коровы).
После отгадывания числа на экран необходимо вывести количество сделанных пользователем
попыток. В программе необходимо использовать рекурсию.*/

// Функция генерации вектора из 4х разных цифр
vector<int> GetVectorFourDigits() {
	// вектор цифр от 1 до 9
	vector<int> digits;
	for (int i = 0; i < 10; ++i) {
		digits.push_back(i);
	}
	random_device rd;
	mt19937 g(rd());
	// перемешиваем вектор
	shuffle(digits.begin(), digits.end(), g);
	// оставляем первые 4 элемента
	digits.resize(4);
	return digits;
}

// Функция генерации 4х значного числа
int GetFourDigitNumber() {
	int res = 0;
	vector<int> digits;
	do
	{
		digits = GetVectorFourDigits();

	} while (digits.at(0)==0);

    int digit_count = 1000;
    for (int i : digits) {
        res += digit_count * i;
        digit_count /= 10;
    }

    return res; // число
}

// Функция конвертирует число в вектор цифр
vector<int> SplitIntoDigits(int number) {
	vector<int> res;

	for (int i = 0; i < 4; ++i) {
		res.push_back(number % 10);
		number /= 10;
	}
	reverse(res.begin(), res.end());
	return res;
}

ostream& operator << (ostream& out, vector<int> v){
	for (int i : v) {
		out << i;
	}
	return out;
}

// Функция определения количества коров и быков
pair <int, int> ChekNumber(vector<int>& secret_num, vector<int>& input_num) {
	// быки и коровы
	int bull = 0;
	int cow = 0;
	for (int i = 0;i < secret_num.size();i++)
	{
		if (secret_num[i] == input_num[i])
			cow++;
	}
	for (int i = 0;i < 4;i++)
	{
		for (int j = 0;j < 4;j++)
		{
			if (secret_num[i] == input_num[j] && i != j)
				bull++;
		}
	}
	return { cow, bull };
}

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

	auto secret_number = GetVectorFourDigits();

	int user_number = 0;
	int try_count = 0;
	pair <int, int> cow_bull;
	//cin >> user_number;
	//cout << SplitIntoDigits(user_number) << endl;
	do
	{
		do
		{
			cout << "Введите 4х-значное число: ";
			cin >> user_number;
			if (user_number > 9999 || user_number < 100) {
				cout << "Некорректное значение! Повторите ввод!\n";
			}
			
		} while (user_number > 9999 || user_number < 100);

		vector<int> user_num_vector = SplitIntoDigits(user_number);;
		cow_bull = ChekNumber(secret_number, user_num_vector);
		++try_count;
		cout << "Коров: " << cow_bull.first << endl << "Быков: " << cow_bull.second << endl;
	} while (cow_bull.first != 4);
	cout << "Вы угадали! Попыток: " << try_count << endl;
	cout << "Загаданное число: " << secret_number << endl;

	return 0;
}

