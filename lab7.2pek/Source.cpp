#include <iostream>
#include <iomanip>
#include <time.h>
#include <Windows.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
void Sort(int** a, const int n, int i = 0, int j = 0) {
	if (i == n - 1) {
		return;  // дійшли до останнього рядка
	}

	if (j == n - i - 1) {
		// Коли дійшли до кінця поточного рядка, переходимо до наступного рядка
		Sort(a, n, i + 1, 0);
		return;
	}

	if (a[j][j] > a[j + 1][j + 1]) {
		// Міняємо місцями елементи
		int temp = a[j][j];
		a[j][j] = a[j + 1][j + 1];
		a[j + 1][j + 1] = temp;
	}

	// Переходимо до наступного стовпця
	Sort(a, n, i, j + 1);
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	srand((unsigned)time(NULL));
	int N;
	cout << "n = "; cin >> N;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = 7, High = 65;
	CreateRows(a, N, Low, High, 0);

	cout << "Початковий масив:" << endl;
	PrintRows(a, N, 0);

	Sort(a, N);

	cout << "Відсортований масив:" << endl;
	PrintRows(a, N, 0);
	
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}