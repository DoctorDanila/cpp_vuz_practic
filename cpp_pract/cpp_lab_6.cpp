#include <iostream>
#include <vector>
#include "Lab6Module.h"

using namespace std;

//int main() {
//	setlocale(LC_ALL, "Russian");
//	/*int N;
//	vector<Fraction> fractions;
//	vector<char> actions;
//	cout << "Сколько хотите ввести дробей?"; cin >> N;
//	for (int i = 1; i <= N; i++)
//	{
//		int a, b;
//		cout << "Дробь #" << i << " числитель:"; cin >> a;
//		cout << "Дробь #" << i << " знаменатель:"; cin >> b;
//		Fraction tmp(a,b);
//		fractions.push_back(tmp);
//	}
//	for (int i = 0; i < N-1; i++)
//	{
//		char action;
//		cout << "Введите действие между дробями " << i+1 << " и " <<i+2 << " / * + -\n";
//		cin >> action;
//		actions.push_back(action);
//	}
//	Fraction answer;
//	for (int i = 0; i < N-1; i++)
//	{
//		if (i == 0)
//			switch (actions[i])
//			{
//			case '/' :
//				answer = fractions[i] / fractions[i + 1];
//				break;
//			case '*' :
//				answer = fractions[i] * fractions[i + 1];
//				break;
//			case '+' :
//				answer = fractions[i] + fractions[i + 1];
//				break;
//			case '-' :
//				answer = fractions[i] - fractions[i + 1];
//				break;
//			}
//		else
//			switch (actions[i])
//			{
//			case '/':
//				answer = answer / fractions[i + 1];
//				break;
//			case '*':
//				answer = answer * fractions[i + 1];
//				break;
//			case '+':
//				answer = answer + fractions[i + 1];
//				break;
//			case '-':
//				answer = answer - fractions[i + 1];
//				break;
//			}
//	}
//	for (int i = 0; i < N-1; i++)
//	{
//		cout << fractions[i].getNumerator() << "/" << fractions[i].getDenominator();
//		cout << " " << actions[i] << " ";
//		cout << fractions[i+1].getNumerator() << "/" << fractions[i+1].getDenominator();
//		cout << endl;
//	}*/
//	int a, b, c, d, k, m;
//	cout << "a:"; cin >> a;
//	cout << "b:"; cin >> b;
//	cout << "c:"; cin >> c;
//	cout << "d:"; cin >> d;
//	cout << "k:"; cin >> k;
//	cout << "m:"; cin >> m;
//	Fraction f1(a,b);
//	Fraction f2(c,d);
//	Fraction f3(k,m);
//	cout << f1.getNumerator() << "/" << f1.getDenominator();
//	cout << " : ";
//	cout << f2.getNumerator() << "/" << f2.getDenominator();
//	cout << " : ";
//	cout << f3.getNumerator() << "/" << f3.getDenominator();
//	cout << endl;
//	Fraction answer = f1 / f2 / f3;
//	answer.reductionThis();
//	cout << answer;
//}