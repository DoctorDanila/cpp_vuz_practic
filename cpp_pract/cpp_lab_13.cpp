#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void lab13_File13() {
    ifstream inputFile("lab13_File13_input.bin", ios::binary); // Исходный файл
    ofstream positiveFile("lab13_File13_positive.bin", ios::binary); // Файл для положительных чисел
    ofstream negativeFile("lab13_File13_negative.bin", ios::binary); // Файл для отрицательных чисел

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть исходный файл." << endl;
        return;
    }

    vector<int> positiveNumbers;
    vector<int> negativeNumbers;

    int number;
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number > 0) {
            positiveNumbers.push_back(number);
        }
        else if (number < 0) {
            negativeNumbers.push_back(number);
        }
    }

    // Запись положительных чисел в обратном порядке
    if (!positiveNumbers.empty()) {
        reverse(positiveNumbers.begin(), positiveNumbers.end());
        for (int num : positiveNumbers) {
            positiveFile.write(reinterpret_cast<char*>(&num), sizeof(int));
        }
    }

    // Запись отрицательных чисел в обратном порядке
    if (!negativeNumbers.empty()) {
        reverse(negativeNumbers.begin(), negativeNumbers.end());
        for (int num : negativeNumbers) {
            negativeFile.write(reinterpret_cast<char*>(&num), sizeof(int));
        }
    }

    inputFile.close();
    positiveFile.close();
    negativeFile.close();
}

void lab13_File36() {
    ifstream inputFile("lab13_File36_input.bin", ios::binary); // Исходный двоичный файл
    ofstream tempFile("lab13_File36_temp.bin", ios::binary); // Временный файл

    if (!inputFile.is_open()) {
        cerr << "Не удалось открыть исходный файл." << endl;
        return;
    }

    // Чтение исходного файла и запись в временный файл
    int number;
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        tempFile.write(reinterpret_cast<char*>(&number), sizeof(int));
    }

    // Возвращение к началу исходного файла
    inputFile.clear(); // Сброс флага EOF
    inputFile.seekg(0, ios::beg); // Возвращение к началу файла

    // Повторное чтение исходного файла и запись в временный файл
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        tempFile.write(reinterpret_cast<char*>(&number), sizeof(int));
    }

    inputFile.close();
    tempFile.close();

    // Удаление исходного файла и переименование временного файла
    remove("lab13_File36_input.bin");
    rename("lab13_File36_temp.bin", "lab13_File36_input.bin");
}

void lab13_File55() {
    string archiveName = "lab13_File55_S0"; // Имя нового файла-архива
    int N = 4; // Количество исходных файлов
    vector<string> fileNames = { "lab13_File55_S1", "lab13_File55_S2", "lab13_File55_S3", "lab13_File55_S4" }; // Имена исходных файлов

    ofstream archiveFile(archiveName, ios::binary); // Новый файл-архив

    if (!archiveFile.is_open()) {
        cerr << "Не удалось открыть файл-архив для записи." << endl;
        return;
    }

    for (const auto& fileName : fileNames) {
        ifstream inputFile(fileName, ios::binary); // Исходный файл

        if (!inputFile.is_open()) {
            cerr << "Не удалось открыть файл " << fileName << " для чтения." << endl;
            continue; // Пропустить этот файл, если он не может быть открыт
        }

        // Считаем количество элементов в файле
        inputFile.seekg(0, ios::end);
        streamsize size = inputFile.tellg();
        int count = size / sizeof(int);
        inputFile.seekg(0, ios::beg);

        // Записываем количество элементов в файл-архив
        archiveFile.write(reinterpret_cast<char*>(&count), sizeof(int));

        // Записываем все элементы из исходного файла в файл-архив
        int number;
        while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            archiveFile.write(reinterpret_cast<char*>(&number), sizeof(int));
        }

        inputFile.close();
    }

    archiveFile.close();
}

int evaluateExpression(const string& expression) {
    // Проверяем, является ли выражение числом
    if (expression.find_first_not_of("0123456789") == string::npos) {
        return stoi(expression);
    }

    // Проверяем, является ли выражение функцией M или m
    if (expression.front() == 'M' || expression.front() == 'm') {
        // Удаляем скобки и разделяем параметры
        string params = expression.substr(2, expression.size() - 3);
        replace(params.begin(), params.end(), ',', ' ');
        istringstream iss(params);
        vector<int> numbers;
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }

        // Вычисляем значение выражения
        if (expression.front() == 'M') {
            return *max_element(numbers.begin(), numbers.end());
        }
        else {
            return *min_element(numbers.begin(), numbers.end());
        }
    }

    // Если выражение не число и не функция, возвращаем 0 (ошибка)
    return 0;
}

void lab13_Recur22() {
    string expression = "M(11,21,3)"; // Пример выражения
    cout << "Значение выражения: " << evaluateExpression(expression) << endl;
}

//int main() {
//    setlocale(LC_ALL, "Russian");
//    system("chcp 1251");
//    /*lab13_File13();
//    lab13_File36();
//    lab13_File55();*/
//    lab13_Recur22();
//    return  0;
//}
