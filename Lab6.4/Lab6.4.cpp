// Lab6.4.cpp
// Опрацювання та впорядкування одновимірних динамічних масивів
// Михайлов Олександр
// Варіант 24

#include <iostream>
#include <Windows.h>
#include <cmath>
#include <time.h>

using namespace std;

void CreateIter(int mas[], const int n, const int Min, const int Max) {
	for (int i = 0; i < n; i++) {
		mas[i] = Min + rand() % (Max - Min + 1);
	}
}

void PrintIter(int mas[], const int n) {
	for (int i = 0; i < n; i++) {
		cout << mas[i] << "  ";
	}
	cout << endl;
}

int SumOddIter(int mas[], const int n) {
	int Sum = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 1) {
			Sum += mas[i];
		}
	}
	return Sum;
}

int FindIndexFirstNegIter(int mas[], const int n) {
	int indexfirstneg = 0;
	for (int i = 0; i < n; i++) {
		if (mas[i] < 0) {
			indexfirstneg = i;
			break;
		}
	}
	return indexfirstneg;
}

int FindIndexLastNegIter(int mas[], const int n) {
	int indexlastneg = 0;
	for (int i = n - 1; i > 0; i--) {
		if (mas[i] < 0) {
			indexlastneg = i;
			break;
		}
	}
	return indexlastneg;
}

int SumNegativeIter(int mas[], const int n) {
	int indexfirstneg = FindIndexFirstNegIter(mas, n);
	int indexlastneg = FindIndexLastNegIter(mas, n);
	int Sum = 0;
	for (int i = indexfirstneg; i < indexlastneg - 1; i++) {
		Sum += mas[i+1];
	}
	return Sum;
}

void PrintZeroIter(const int counter) {
	for (int i = 0; i < counter; i++) {
		cout << "0" << "  ";
	}
}

void SqueezedIter(int mas[], const int n) {
	int counter = 0;
	for (int i = 0; i < n; i++) {
		if (abs(mas[i]) > 1)
			cout << mas[i] << "  ";
		else {
			counter++;
			continue;
		}
	}
	PrintZeroIter(counter);
	cout << endl << endl;
}

void CreateRekurs(int mas[], const int n, const int Min, const int Max, int i)
{
	mas[i] = Min + rand() % (Max - Min + 1);
	if (i < n - 1)
		CreateRekurs(mas, n, Min, Max, i + 1);
}

void PrintRekurs(int mas[], const int n, int i)
{
	cout << mas[i] << "  ";
	if (i < n - 1)
		PrintRekurs(mas, n, i + 1);
	else
		cout << endl;
}

int SumOddRekurs(int mas[], const int n, int i) {
	int Sum = 0;
	if (i < n) {
		if (i % 2 == 1)
			return mas[i] + SumOddRekurs(mas, n, i + 1);
		else
			return SumOddRekurs(mas, n, i + 1);
	}
	else
		return 0;
}

int FindIndexFirstNegRekurs(int mas[], const int n, int i) {
	int indexfirstneg = 0;
	if (i < n) {
		if (mas[i] < 0) {
			indexfirstneg = i;
			return indexfirstneg;
		}
		return FindIndexFirstNegRekurs(mas, n, i + 1);
	}
}

int FindIndexLastNegRekurs(int mas[], const int n, int i) {
	int indexlastneg = 0;
	if (i > 0) {
		if (mas[i] < 0) {
			indexlastneg = i;
			return indexlastneg;
		}
		return FindIndexLastNegRekurs(mas, n, i - 1);
	}
}

int SumNegativeRekurs(int mas[], const int n, int i) {
	int indexfirstneg = FindIndexFirstNegRekurs(mas, n, 0);
	int indexlastneg = FindIndexLastNegRekurs(mas, n, n - 1);
	int Sum = 0;
	if (i < indexlastneg - 1)
		Sum = mas[i + 1] + SumNegativeRekurs(mas, n, i + 1);
	return Sum;
}

void PrintZeroRekurs(const int counter, int i) {
	if (i < counter) {
		cout << "0" << "  ";
		PrintZeroRekurs(counter, i + 1);
	}
}

void SqueezedRekurs(int mas[], const int n, int i) {
	int counter = 0;
	if (i < n) {
		if (abs(mas[i]) > 1)
			cout << mas[i] << "  ";
		else {
			counter++;
			SqueezedRekurs(mas, n, i + 1);
		}
	}
	PrintZeroRekurs(counter, 0);
	cout << endl << endl;
}

int main() 
{
	srand((unsigned)time(NULL));
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int Min, Max;
	int n;
	cout << "Введіть мінімальне можливе значення у масиві: "; cin >> Min;
	cout << "Введіть максимальне можливе значення у масиві: "; cin >> Max;
	cout << "Введіть кількість елементів масива: "; cin >> n;
	cout << endl;

	int* a = new int[n];

	// Ітераційний
	cout << "Ітераційний спосіб:" << endl;
	cout << "Масив: ";

	CreateIter(a, n, Min, Max);
	PrintIter(a, n);
	cout << "Сума елементів масиву з непарними номерами: " << SumOddIter(a, n) << endl; // 1.1
	cout << "Сума елементів масиву, розташованих між першим і останнім від’ємними елементами: " << SumNegativeIter(a, n) << endl; // 1.2
	cout << "Стиснутий масив: "; SqueezedIter(a, n); // 2

	// Рекурсивний
	cout << "Рекурсивний спосіб:" << endl;
	cout << "Масив: ";

	CreateRekurs(a, n, Min, Max, 0);
	PrintRekurs(a, n, 0);
	cout << "Сума елементів масиву з непарними номерами: " << SumOddRekurs(a, n, 0) << endl; // 1.1
	cout << "Сума елементів масиву, розташованих між першим і останнім від’ємними елементами: " << SumNegativeRekurs(a, n, FindIndexFirstNegRekurs(a, n, 0)) << endl << endl; // 1.2
	cout << "Стиснутий масив: "; SqueezedRekurs(a, n, 0); // 2

	cin.get();
	delete[]a;
	return 0;
}