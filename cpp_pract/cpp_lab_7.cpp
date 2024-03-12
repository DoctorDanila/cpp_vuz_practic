#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <map>

using namespace std;

bool is_progressive(double* mas, int N) {
    double del = 0;
    int i = N, j, flag = 1;
    del = mas[1] / mas[0];
    for (j = 0; j < (i - 1); j++) {
        if ((mas[j + 1] / mas[j]) != del) {
            flag = 0;
            return false;
        }
    }
    return true;
}

void Array25() {
    int N;
    cout << "N:"; cin >> N;
    double mas[100] = { 0 };
    for (int i = 0;i < N; i++)
    {
        cout << i + 1  << " из " << N << ":"; cin >> mas[i];
    } 
    is_progressive(mas, N) ? cout << "Это прогрессия\n", cout << "Знаменатель q = " << mas[1] / mas[0] << endl : cout << "Это не прогрессия\n";
}

void insertNumber(int*& array, int& currentSize, int index, int number)
{
    int* newArray = new int[++currentSize]; // создаем новый массив
    for (int i = 0; i < index; ++i) // копипастим массив элементы до index
        newArray[i] = array[i];
    newArray[index] = number;
    for (int i = index; i < currentSize - 1; ++i) // копипастим массив после index
        newArray[i + 1] = array[i];
    delete[]array; // чистим прошлый массив
    array = newArray;
}

void Array102() {
    int N, K;
    cout << "N:"; cin >> N;
    cout << "Введите K(от 1 до N):"; cin >> K;
    if (!(K > 1 && K < N)) { cout << "Перезапустите программу и введите правильные значения."; return; }
    int* arr;
    arr = new int[N+1];
    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 500 + 1;
        cout << arr[i] << " "; 
    }
    cout << endl;
    insertNumber(arr, N, K, 0);
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void TheMassiv16() {
    int N;
    cout << "N:"; cin >> N;
    int* arr;
    arr = new int[N + 1];

    for (int i = 0; i < N; i++) {
        arr[i] = rand() % 20 + 1;
        cout << arr[i] << " ";
    }
    cout << endl;

    map<int, int> table; // pair key->value
    for (int i = 0; i < N; i++) {
        if (table.count(arr[i])) {
            table[arr[i]] += 1;
        }
        else {
            table[arr[i]] = 1;
        }
    }
    int maxk = INT_MIN;
    for (const auto& element : table)
    {
        if (element.first > maxk)
            maxk = element.first;
    }

    cout << "Максимальный элемент: " << maxk << " повторился " << table[maxk] << " раз \n";

}

void z2() {
    int k;
    vector <int> vec;
    string line;

    cout << "Введите k: ";
    cin >> k;

    ifstream in("specialniifailsochenvaznimychislami.txt");
    if (in.is_open()) {
        while (getline(in, line)) {
            vec.push_back(stoi(line));
        }
    }

    cout << "Изначальный массив: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
        if (vec[i] > k) {
            vec.erase(vec.begin() + i);
            i--;
        }
    }

    cout << "\nМассив без элементов, превышающих k: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
}

//int main() {
//	setlocale(LC_ALL, "Russian");
//    //Array25();
//    //Array102();
//    //TheMassiv16();
//    z2();
//	return 0;
//}