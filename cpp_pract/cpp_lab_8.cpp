#include <iostream>
#include <vector>

using namespace std;

int** CreateMatrix(int M, int N) {
	int** arr = new int* [M];
	for (int i = 0; i < M; i++)
		arr[i] = new int[N];
	return arr;
}

int** fillMatrix(int ** arr, int M, int N, int mini = 1, int maxi = 500) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			arr[i][j] = rand() % (maxi - mini + 1) + mini;
		}
	}
	return arr;
}

void printMatrix(int** arr, int M, int N) {
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	for (int j = 0; j < N; j++)
		cout << "----";
	cout << endl;
}

void Matrix24() {
	int N, M, max = 0;
	cout << "M:"; cin >> M;
	cout << "N:"; cin >> N;
	int **arr = CreateMatrix(M, N);
	arr = fillMatrix(arr, M, N);
	printMatrix(arr, M, N);

	cout << "Максимальные элементы по столбцам:\n";

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < M; i++)
			if (i == 0 || arr[i][j] > max) max = arr[i][j];
		cout << max << " ";
	}
}

bool checkCol(int ** arr, int M, int N) {
	for (int i = 0; i < M; i++)
	{
		if (arr[i][N] > 0) return false;
	}
	return true;
}

void switchCell(int ** arr, int M, int targetCell, int placeCell) {
	targetCell--;
	for (int i = 0; i < M; i++)
	{
		int tmp = arr[i][placeCell];
		arr[i][placeCell] = arr[i][targetCell];
		arr[i][targetCell] = tmp;
	}
}

void Matrix54() {
	int N, M;
	cout << "M:"; cin >> M;
	cout << "N:"; cin >> N;
	int** arr = CreateMatrix(M, N);
	arr = fillMatrix(arr, M, N, -500);
	printMatrix(arr, M, N);

	for (int i = 0; i < M; i++)
	{
		if (checkCol(arr, M, N)) {
			switchCell(arr, M, N, i);
			break;
		}
	}

	printMatrix(arr, M, N);
}

void transpose(int ** matrix, int M, int N)
{
	int t;
	for (int i = 0; i < M; ++i)
	{
		for (int j = i; j < N; ++j)
		{
			t = matrix[i][j];
			matrix[i][j] = matrix[j][i];
			matrix[j][i] = t;
		}
	}
}

void DArray8() {
	int N;
	cout << "N:"; cin >> N;
	int** arr = CreateMatrix(N, N);
	arr = fillMatrix(arr, N, N);
	printMatrix(arr, N, N);
	transpose(arr, N, N);
	printMatrix(arr, N, N);
}

void DArray11() {
	int N, M, max = INT_MIN, x=0, y=0;
	cout << "M:"; cin >> M;
	cout << "N:"; cin >> N;
	int** arr = CreateMatrix(M, N);
	arr = fillMatrix(arr, M, N, -500);
	printMatrix(arr, M, N);

	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (arr[i][j] > max) {
				max = arr[i][j]; 
				x = i+1; y = j+1;
			}
		}
	}
	cout << "Максимальный элемент: " << max << " был найден в ячейке " << x << ":" << y << endl;
}

//int main() {
//	setlocale(LC_ALL, "Russian");
//	//Matrix24();
//	//Matrix54();
//	//DArray8();
//	DArray11();
//	return 0;
//}
