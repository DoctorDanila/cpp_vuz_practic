#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

int* fillArray(int* arr, int N, int mini = 1, int maxi = 500) {
	
	for (int i = 0; i < N; i++) {
		arr[i] = rand() % (maxi - mini + 1) + mini;
	}
	return arr;
}

void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int max_idx = i;
        for (int j = i + 1; j < n; j++)
            if (arr[j] > arr[max_idx])
                max_idx = j;
        swap(&arr[max_idx], &arr[i]);
        ofstream file("superpuperprotocol.txt", ios_base::app);
        for (int k = 0; k <= i; k++)
        {
            cout << arr[k] << " ";
            file << arr[k] << " ";
        }
        cout << "| ";
        file << "| ";
        for (int k = i + 1; k < n; k++) {
            cout << arr[k] << ' ';
            file << arr[k] << ' ';
        }
        file << "\n";
        cout << "\n";
    }
}

void sort8() {
	int N;
    cout << "N:"; cin >> N;
	int* arr;
	arr = new int[N];
    fillArray(arr,N);
    selectionSort(arr, N);
    for (int i = 0; i < N; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int binarySearch(const vector<int>& vec, int x) {
    int left = 0, right = vec.size() - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (vec[mid] == x) {
            if (mid == 0 || vec[mid - 1] != x)
                return mid;
            else
                right = mid - 1;
        }
        else if (vec[mid] < x)
            left = mid + 1;
        else
            right = mid - 1;
    }
    return -1;
}



void sort14() {
    int x;
    cout << "Введите число X: ";
    cin >> x;

    ifstream file("supermeganumbers.txt");
    vector<int> numbers((istream_iterator<int>(file)), istream_iterator<int>());
    file.close();

    int index = binarySearch(numbers, x);
    if (index != -1)
        cout << "Самое левое вхождение числа " << x << " находится на позиции " << index << endl;
    else
        cout << "Число " << x << " не найдено." << endl;
}

//int main() {
//    setlocale(LC_ALL, "Russian");
//    system("chcp 1251");
//    while (0==0)
//    {
//        //sort8();
//        sort14();
//    }
//	return 0;
//}