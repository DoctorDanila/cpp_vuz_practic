#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

double fib(double n)
{
    if (n <= 1)
        return n;
    return fib(n - 1) + fib(n - 2);
}

void TextFile2() {
	ofstream fout("b.tst");
	if (!fout) return;
	int a, b;
	cout << "от:"; cin >> a;
	cout << "до:"; cin >> b;
	for (int i = a; i <= b; i++) {
		fout << fib(i) << endl;
	}
}

/*
Дан текстовый файл с именем d.txt, в первой строке которого записано единственное
число N, а во второй строке последовательность из N целых чисел, разделенных пробелами.
Требуется определить, правда ли, что в данной последовательности все числа состоят из одинакового количества цифр. Обязательно использовать логическую переменную и НЕ использовать
оператор ветвления в теле цикла. Массивы использовать запрещается, а файл для чтения открывать только один раз.
*/

int Count(int a)
{
	int count = 0;
	do {
		count++;
		a /= 10;
	} while (a);
	return count;
}


void TextFile19() {
	ifstream fin("d.txt");
	string buf;
	getline(fin, buf);
	int N = stoi(buf), numLen = 2;
	getline(fin, buf, ' ');
	numLen = Count(stoi(buf));
	for (int i = 0; i < N; i++)
	{
		getline(fin, buf, ' ');
		bool is_bigest = Count(stoi(buf)) == numLen && numLen != 0;
		numLen = is_bigest ? Count(stoi(buf)) : 0;
	}
	bool an = numLen != 0;
	an ? cout << "Все равны\n" : cout << "Не все равны\n";
}
/*
Текущее показание электронных часов m (0 ≤ m ≤ 23) n минут (0 ≤ n ≤ 59) k секунд (0 ≤ k ≤
59). Какое время будут показывать часы через p часов (0 ≤ p ≤ 100) q минут (0 ≤ q ≤
59) r секунд (0 ≤ r ≤ 59)? Разработать разные варианты тестов и заполнить таблицу тестирования программы
*/
void TextTask2(int* timeNow, int* timeLeft) {
	int h = timeNow[0] + timeLeft[0];
	int m = timeNow[1] + timeLeft[1];
	int s = timeNow[2] + timeLeft[2];
	if (s >= 60) { 
		m += 1*(s/60); 
		s -= 60*(s/60); 
	}
	if (m >= 60) { 
		h += 1*(m/60); 
		m -= 60*(m/60); 
	}
	if (h >= 24) { 
		h = 0; 
		cout << "За границами"; 
	}
	timeNow[0] = h; timeNow[1] = m; timeNow[2] = s;
	cout << "\t\t" << timeNow[0] << ":" << timeNow[1] << ":" << timeNow[2] << endl;
}

bool TextTask2(int* timeNow, int* timeLeft, int*holdenResult) {
	int h = timeNow[0] + timeLeft[0];
	int m = timeNow[1] + timeLeft[1];
	int s = timeNow[2] + timeLeft[2];
	if (s >= 60) {
		m += 1 * (s / 60);
		s -= 60 * (s / 60);
	}
	if (m >= 60) {
		h += 1 * (m / 60);
		m -= 60 * (m / 60);
	}
	if (h >= 24) {
		h = 0;
	}
	timeNow[0] = h; timeNow[1] = m; timeNow[2] = s;
	if (timeNow[0] == holdenResult[0] &&
		timeNow[1] == holdenResult[1] &&
		timeNow[2] == holdenResult[2]) {
		cout << "holden val: " << holdenResult[0] << ":" << holdenResult[1] << ":" << holdenResult[2] << "; this val: " << timeNow[0] << ":" << timeNow[1] << ":" << timeNow[2] << "; => ";
		cout << "true\n";
		return true;
	}
	cout << "holden val: " << holdenResult[0] << ":" << holdenResult[1] << ":" << holdenResult[2] << "; this val: " << timeNow[0] << ":" << timeNow[1] << ":" << timeNow[2] << "; => ";
	cout << "false\n";
	return false;
}

class TestTextTask2 {
	int timesNow[10][3] =
	{
		{12,34,33},
		{12,23,34},
		{23,34,24},
		{11,13,15},
		{9,35,3},
		{19,24,56},
		{7,45,37},
		{23,37,24},
		{6,25,46},
		{24,60,60}
	};
	int timesLeft[10][3] =
	{
		{1,3,3},
		{2,3,4},
		{3,4,4},
		{1,3,5},
		{9,5,3},
		{1,4,6},
		{7,4,7},
		{2,7,4},
		{6,2,6},
		{1,1,1}
	};
	//напиши здесь результаты посчитанные руками
	int timesHolden[10][3] =
	{
		{13,37,36},
		{14,26,38},
		{0,38,28},
		{12,16,20},
		{18,40,6},
		{20,29,2},
		{14,49,44},
		{0,44,28},
		{12,27,52},
		{0,2,1}
	};
public:
	TestTextTask2() {
		for (int i = 0; i < 10; i++)
		{
			int timeNow[] = { timesNow[i][0], timesNow[i][1], timesNow[i][2] };
			int timeLeft[] = { timesLeft[i][0], timesLeft[i][1], timesLeft[i][2] };
			int timeHolden[] = { timesHolden[i][0], timesHolden[i][1], timesHolden[i][2] };
			cout << "Test no." << i + 1 << " => ";
			TextTask2(timeNow, timeLeft, timeHolden);
		}
	}

};

//int main() {
//	setlocale(LC_ALL, "Russian");
//
//	//TextFile2();
//	//TextFile19();
//
//	int timeNow[3] = {21, 23, 20};
//	int timeLeft[3] = {1, 36, 40};
//	TextTask2(timeNow, timeLeft);
//	TestTextTask2();
//	return 0;
//}