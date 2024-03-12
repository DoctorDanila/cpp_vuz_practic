#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

void lab13_File13() {
    ifstream inputFile("lab13_File13_input.bin", ios::binary); // �������� ����
    ofstream positiveFile("lab13_File13_positive.bin", ios::binary); // ���� ��� ������������� �����
    ofstream negativeFile("lab13_File13_negative.bin", ios::binary); // ���� ��� ������������� �����

    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� �������� ����." << endl;
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

    // ������ ������������� ����� � �������� �������
    if (!positiveNumbers.empty()) {
        reverse(positiveNumbers.begin(), positiveNumbers.end());
        for (int num : positiveNumbers) {
            positiveFile.write(reinterpret_cast<char*>(&num), sizeof(int));
        }
    }

    // ������ ������������� ����� � �������� �������
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
    ifstream inputFile("lab13_File36_input.bin", ios::binary); // �������� �������� ����
    ofstream tempFile("lab13_File36_temp.bin", ios::binary); // ��������� ����

    if (!inputFile.is_open()) {
        cerr << "�� ������� ������� �������� ����." << endl;
        return;
    }

    // ������ ��������� ����� � ������ � ��������� ����
    int number;
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        tempFile.write(reinterpret_cast<char*>(&number), sizeof(int));
    }

    // ����������� � ������ ��������� �����
    inputFile.clear(); // ����� ����� EOF
    inputFile.seekg(0, ios::beg); // ����������� � ������ �����

    // ��������� ������ ��������� ����� � ������ � ��������� ����
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        tempFile.write(reinterpret_cast<char*>(&number), sizeof(int));
    }

    inputFile.close();
    tempFile.close();

    // �������� ��������� ����� � �������������� ���������� �����
    remove("lab13_File36_input.bin");
    rename("lab13_File36_temp.bin", "lab13_File36_input.bin");
}

void lab13_File55() {
    string archiveName = "lab13_File55_S0"; // ��� ������ �����-������
    int N = 4; // ���������� �������� ������
    vector<string> fileNames = { "lab13_File55_S1", "lab13_File55_S2", "lab13_File55_S3", "lab13_File55_S4" }; // ����� �������� ������

    ofstream archiveFile(archiveName, ios::binary); // ����� ����-�����

    if (!archiveFile.is_open()) {
        cerr << "�� ������� ������� ����-����� ��� ������." << endl;
        return;
    }

    for (const auto& fileName : fileNames) {
        ifstream inputFile(fileName, ios::binary); // �������� ����

        if (!inputFile.is_open()) {
            cerr << "�� ������� ������� ���� " << fileName << " ��� ������." << endl;
            continue; // ���������� ���� ����, ���� �� �� ����� ���� ������
        }

        // ������� ���������� ��������� � �����
        inputFile.seekg(0, ios::end);
        streamsize size = inputFile.tellg();
        int count = size / sizeof(int);
        inputFile.seekg(0, ios::beg);

        // ���������� ���������� ��������� � ����-�����
        archiveFile.write(reinterpret_cast<char*>(&count), sizeof(int));

        // ���������� ��� �������� �� ��������� ����� � ����-�����
        int number;
        while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
            archiveFile.write(reinterpret_cast<char*>(&number), sizeof(int));
        }

        inputFile.close();
    }

    archiveFile.close();
}

int evaluateExpression(const string& expression) {
    // ���������, �������� �� ��������� ������
    if (expression.find_first_not_of("0123456789") == string::npos) {
        return stoi(expression);
    }

    // ���������, �������� �� ��������� �������� M ��� m
    if (expression.front() == 'M' || expression.front() == 'm') {
        // ������� ������ � ��������� ���������
        string params = expression.substr(2, expression.size() - 3);
        replace(params.begin(), params.end(), ',', ' ');
        istringstream iss(params);
        vector<int> numbers;
        int number;
        while (iss >> number) {
            numbers.push_back(number);
        }

        // ��������� �������� ���������
        if (expression.front() == 'M') {
            return *max_element(numbers.begin(), numbers.end());
        }
        else {
            return *min_element(numbers.begin(), numbers.end());
        }
    }

    // ���� ��������� �� ����� � �� �������, ���������� 0 (������)
    return 0;
}

void lab13_Recur22() {
    string expression = "M(11,21,3)"; // ������ ���������
    cout << "�������� ���������: " << evaluateExpression(expression) << endl;
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
