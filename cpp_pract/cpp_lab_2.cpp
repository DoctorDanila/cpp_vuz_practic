#include <iostream>
#include <vector>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

//while
//int Count(int a)
//{
//	int count = 0;
//	while (a > 0) {
//		count++;
//		a /= 10;
//	}
//	return count;
//}
//
//void while17() {
//	vector<int> ranks;
//	int num;
//	cout << "������� �����: "; cin >> num;
//	int num_ranks = Count(num);
//	for (int i = 0; i < num_ranks; i++) {
//		ranks.push_back(num%10);
//		num /= 10;
//	}
//	for (int i = ranks.size()-1; i >= 0; i--) {
//		cout << ranks[i] << " ";
//	}
//	cout << endl;
//}
/*
void while18() {
	vector<int> ranks;
	int num, sum = 0;
	cout << "������� �����: "; cin >> num;
	int num_ranks = Count(num);
	for (int i = 0; i < num_ranks; i++) {
		ranks.push_back(num % 10);
		num /= 10;
	}
	for (int i = ranks.size() - 1; i >= 0; i--) {
		sum += ranks[i];
	}
	cout << "Count: " << num_ranks << " Sum: " << sum << endl;
}

void while19() {
	vector<int> ranks;
	int num;
	cout << "������� �����: "; cin >> num;
	int num_ranks = Count(num);
	for (int i = 0; i < num_ranks; i++) {
		ranks.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < ranks.size(); i++) {
		cout << ranks[i];
	}
	cout << endl;
}

void while20() {
	vector<int> ranks;
	int num;
	bool jk;
	cout << "������� �����: "; cin >> num;
	int num_ranks = Count(num);
	for (int i = 0; i < num_ranks; i++) {
		ranks.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < ranks.size(); i++) {
		if (ranks[i] == 2) { jk = true; break; }
		else jk = false;
	}
	if (jk) cout << "true\n";
	else cout << "false\n";
}

void while21() {
	vector<int> ranks;
	int num;
	bool jk;
	cout << "������� �����: "; cin >> num;
	int num_ranks = Count(num);
	for (int i = 0; i < num_ranks; i++) {
		ranks.push_back(num % 10);
		num /= 10;
	}
	for (int i = 0; i < ranks.size(); i++) {
		if (ranks[i]%2 == 0) { jk = true; break; }
		else jk = false;
	}
	if (jk) cout << "true\n";
	else cout << "false\n";
}*/

//series
void series4() {
	int N, tmp, sum = 0, mult = 1;
	vector<double> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{ 
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		sum += collN[i];
		mult *= collN[i];
	}
	cout << "sum: " << sum << " mult: " << mult << endl;
}

void series5() {
	int N, sum = 0;
	double tmp;
	vector<double> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		cout << static_cast<int>(collN[i]) << " ";
		sum += collN[i];
	}
	cout << "sum: " << sum << "\n";
}

void series6() {
	int N;
	double tmp, mult = 1;
	vector<double> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		cout << collN[i] - (int)collN[i] << " ";
		mult *= collN[i] - (int)collN[i];
	}
	cout << "mult: " << mult << "\n";
}

void series7() {
	int N;
	double tmp, sum = 0;
	vector<double> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		cout << round(collN[i]) << " ";
		sum += round(collN[i]);
	}
	cout << "sum: " << sum << "\n";
}

void series8() {
	int N, tmp, K = 0;
	vector<int> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] % 2 == 0) {
			cout << collN[i] << " ";
			K++;
		}
	}
	cout << "K: " << K << "\n";
}

void series9() {
	int N, tmp, K = 0;
	vector<int> collN;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] % 2 != 0) {
			cout << i+1 << " ";
			K++;
		}
	}
	cout << "K: " << K << "\n";
}

void series10() {
	int N, tmp;
	vector<int> collN;
	bool jk = false;
	cout << "������� ����������� �������:"; cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] > 0) {
			jk = true;
			break;
		}
	}
	if (jk) cout << "True\n";
	else cout << "False\n";
}

void series11() {
	int N, K, tmp;
	vector<int> collN;
	bool jk = false;
	cout << "������� ����������� �������:"; cin >> N;
	cout << "������� ����� ��� ��������:"; cin >> K;
	for (int i = 0; i < N; i++)
	{
		cin >> tmp;
		collN.push_back(tmp);
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] < K) {
			jk = true;
			break;
		}
	}
	if (jk) cout << "True\n";
	else cout << "False\n";
}

void series12() {
	int tmp, count = 0;
	vector<int> collN;
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp != 0)
			collN.push_back(tmp);
		else break;
	}
	for (int i = 0; i < collN.size(); i++)
	{	
		count++;
	}
	cout << "count: " << count << endl;
}

void series13() {
	int tmp, sum = 0;
	vector<int> collN;
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp != 0)
			collN.push_back(tmp);
		else break;
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] % 2 == 0 && collN[i] > 0) sum += collN[i];
	}
	cout << "sum: " << sum << endl;
}

void series14() {
	int tmp, count = 0, K;
	vector<int> collN;
	cout << "������� ����� ��� ��������:"; cin >> K;
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp != 0)
			collN.push_back(tmp);
		else break;
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] < K) count++;
	}
	cout << "count: " << count << endl;
}

void series15() {
	int tmp, count = 0, K;
	vector<int> collN;
	bool jk = true;
	cout << "������� ����� ��� ��������:"; cin >> K;
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp != 0)
			collN.push_back(tmp);
		else break;
	}
	for (int i = 0; i < collN.size(); i++)
	{
		if (collN[i] > K) { jk = false; cout << "����� #" << i + 1 << endl; break; }
	}
	if (jk) cout << 0 << endl;
}

void series16() {
	int tmp, count = 0, K;
	vector<int> collN;
	bool jk = true;
	cout << "������� ����� ��� ��������:"; cin >> K;
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp != 0)
			collN.push_back(tmp);
		else break;
	}
	for (int i = collN.size() - 1; i >= 0; i--)
	{
		if (collN[i] > K) { jk = false; cout << "����� #" << i + 1 << endl; break; }
	}
	if (jk) cout << 0 << endl;
}

//z3
void z31() {
	int o=0, r=0;
	bool b;
	for (int i = 0; i < 20; i++)
	{
		b = rand() % 2;
		if (b) { cout << "��� "; o++; }
		else { cout << "����� "; r++; }
	}
	cout << "\n��� �����: " << o << " ���, � ����� ������: " << r << " ���\n";
}

void z32() {
	int b;
	for (int i = 0; i < 20; i++)
	{
		b = 1 + rand() % 20;
		for (int j = 0; j < b; j++)
		{
			cout << "*";
		}
		cout << endl;
	}
	cout << "\n";
}

void z33() {
	int b, tmp, count = 0;
	b = 1 + rand() % 100;
	cout << "� ������� �����) ������))\n";
	while (0 == 0)
	{
		cin >> tmp;
		if (tmp > b) cout << "�� ����, ��� �����! ���� ������)\n";
		else if (tmp < b) cout << "�� �� ��, �������� �����! ���� ��������)\n";
		else {
			cout << "�� ��, ������) �� ������� " << count << " ���\n";
			break;
		}
		count++;
	}
}

void z34() {
	vector<string> els = {"������", "�������", "������"};
	string compChoose, usrChoose;
	int tmp;
	compChoose = els[rand() % els.size()];
	cout << "� �������!\n������ �� ����� 0 - ������ 1 - ������� 2 - ������\n";
	cin >> tmp;
	usrChoose = els[tmp];
	if (usrChoose == "������" && compChoose=="�������") {
		cout << "�� ������� :(\n";
		return;
	}
	if (usrChoose == "�������" && compChoose == "������") {
		cout << "��������, �� �������� :)\n";
		return;
	}
	if (usrChoose == "������" && compChoose == "������") {
		cout << "��������, �� �������� :)\n";
		return;
	}
	if (usrChoose == "������" && compChoose == "������") {
		cout << "�� �������, �� � ����� �� ���? :(\n";
		return;
	}
	if (usrChoose == "�������" && compChoose == "������") {
		cout << "������, �� ����� ������� :(\n";
		return;
	}
	if (usrChoose == "������" && compChoose == "�������") {
		cout << "��������, �� ��������, � � ������� :)\n";
		return;
	}
}

//TheTwo
/*
���� ����������� ����� n � k. ����� �������� ���������: 1k+2k+3k+...+n
k ��������� ������� � ���� ������������� �����.
*/
void TheTwo12() {
	int n, k;
	float answ = 0;
	cout << "n:"; cin >> n;
	cout << "k:"; cin >> k;
	for (int i = 1; i <= n; i++)
	{
		float tmp = i;
		for (int j = 0; j < k;j++) {
			tmp*=i;
		}
		answ += tmp;
	}
	cout << answ << endl;
}

/*
��� ������������ ����� N, ����������� �� �����, ��� 8 �������� ����, ��������,
�������� �� ��� ������������������ ���� ��� ��������� ������ ������ �������������� �������������������.
*/
void TheTwo24() {
	int N;
	bool is_narost = true;
	cout << "������� 8-������� N:"; cin >> N;
	for (int i = 7; i > 0 ; i--)
	{
		int tmpR = N % 10;
		N /= 10;
		int tmpL = N % 10;

		if (tmpR < tmpL) {
			is_narost = false;
			break;
		}

	}
	if (is_narost) cout << "�����������!\n";
	else cout << "�� �����������\n";
}
//
//double factorial(double i)
//{
//	if (i == 0) return 1;
//	else return i * factorial(i - 1);
//}
//
//
//void z62() {
//	int n;
//	long double x, answ = 0;
//	bool toggle = false;
//	cout << "x:"; cin >> x;
//	cout << "n:"; cin >> n;
//	for (int i = 0; i < n; i++)
//	{
//		if (toggle) answ -= pow(x, (2 * i + 1)) / factorial(2 * i + 1);
//		if (!toggle) answ += pow(x, (2 * i + 1)) / factorial(2 * i + 1);
//		cout << "Debug: " << answ << "=" << x << "^(" << (2 * i + 1) << "/" << factorial(2 * i + 1) << ") itter: " << i+1 << endl;
//		toggle = !toggle;
//	}
//	cout << "answ = " << answ << "\n" << "f(x) = sin(x) => " << sin(x) << endl;
//}

//void call_listener() {
//	cout << "������������ ������ #2\n";
//	/*cout << "while17()\n";
//	while17();
//	cout << "while18()\n";
//	while18();
//	cout << "while19()\n";
//	while19();
//	cout << "while20()\n";
//	while20();
//	cout << "while21()\n";
//	while21();*/
//
//	/*cout << "series4()\n";
//	series4();
//	cout << "series5()\n";
//	series5();
//	cout << "series6()\n";
//	series6();
//	cout << "series7()\n";
//	series7();
//	cout << "series8()\n";
//	series8();
//	cout << "series9()\n";
//	series9();
//	cout << "series10()\n";
//	series10();*/
//	/*cout << "series11()\n";
//	series11();*/
//	/*cout << "series12()\n";
//	series12();
//	cout << "series13()\n";
//	series13();
//	cout << "series14()\n";
//	series14();
//	cout << "series15()\n";
//	series15();
//	cout << "series16()\n";
//	series16();*/
//
//	/*cout << "������ 3 1\n";
//	z31();
//	cout << "������ 3 2\n";
//	z32();
//	cout << "������ 3 3\n";
//	z33();*/
//	/*cout << "������ 3 4\n";
//	z34();*/
//
//
//}

//int main() {
//	srand((unsigned int)time(NULL));
//	setlocale(LC_ALL, "Russian");
//	//call_listener();
//	TheTwo24();
//	return 0;
//}