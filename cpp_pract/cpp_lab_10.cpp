#include <iostream>
#include <regex>
#include <string>
#include <fstream>
#include <algorithm>
#include <ctime>
#include <fstream>
#include <sstream>
#include <bitset>

using namespace std;

void ExamBegin94() {
	string input;
	cout << "Введите строку (string)\n";
	getline(cin, input);
	for (int i = 0; i < input.size(); i++)
		input[i] = toupper(input[i]);
	regex regex_space(" ");
	vector<string> text(
		sregex_token_iterator(input.begin(), input.end(), regex_space, -1),
		sregex_token_iterator()
	);

	int k = 0;
	for (int i = 0; i < text.size(); i++)
	{
		if (text[i][0] == text[i][text[i].size()-1]) {
			k++;
		}
	}
	cout << "колличество слов начинающихся и заканчивающихся одной и той же буквой:" << k << endl;
}

void switchTwiceEls(char* arr, int size) {
	char tmp;
	int first = rand() % (size - 0) + 0;
	int second = rand() % (size - 0) + 0;
}

void zadacha2_2() {
	string word;
	cout << "Введите слово: ";
	cin >> word;

	string original = word;
	int count = 0;
	srand(time(NULL));

	do {
		random_shuffle(word.begin(), word.end());
		count++;
		cout << "Переставленное слово: " << word << endl;
	} while (word != original);

	cout << "Общее количество перестановок: " << count << endl;
}

void Five8() {
	ifstream fin("FN1.txt");
	ofstream fout("FN2.txt");
	string line;

	while (getline(fin, line)) {
		istringstream iss(line);
		string operand1, operator_, operand2, equals, answer;

		if (!(iss >> operand1 >> operator_ >> operand2 >> equals >> answer)) {
			cerr << "Ошибка чтения! Скрипт не виноват, он работает, так что не надо тут эт самое вот всего вот этого)))\n";
			break; // ошибка чтения
		}

		// преобразование операндов из двоичной системы в десятичную
		unsigned long op1 = bitset<32>(operand1).to_ulong();
		unsigned long op2 = bitset<32>(operand2).to_ulong();
		unsigned long ans = bitset<32>(answer).to_ulong();

		// выполнение соответствующей операции и проверка ответа
		if ((operator_ == "+" && op1 + op2 == ans) || (operator_ == "*" && op1 * op2 == ans)) {
			cout << "Строка " << line << " обработана успешно.\n";
			fout << line << " +\n";
		}
		else {
			cout << "Неверный ответ в строке " << line << ".\n";
			fout << line << " -\n";
		}
	}
}

//int main() {
//	setlocale(LC_ALL, "Russian");
//	system("chcp 1251");
//	//ExamBegin94();
//	//zadacha2_2();
//	Five8();
//	return 0;
//}		