////8
//#include <iostream>
//
//using namespace std;
//
//void case1() {
//	int day_num;
//	cout << "������� ����� �� 1 �� 7: ";cin >> day_num;
//	switch (day_num)
//	{
//	case 1:
//		cout << "��������� ���� ������: �����������" << endl;
//		break;
//	case 2:
//		cout << "��������� ���� ������: �������" << endl;
//		break;
//	case 3:
//		cout << "��������� ���� ������: �����" << endl;
//		break;
//	case 4:
//		cout << "��������� ���� ������: �������" << endl;
//		break;
//	case 5:
//		cout << "��������� ���� ������: �������" << endl;
//		break;
//	case 6:
//		cout << "��������� ���� ������: �������" << endl;
//		break;
//	case 7:
//		cout << "��������� ���� ������: �����������" << endl;
//		break;
//	default:
//		cout << "� ������ �� �����. ����������, ���������� ������ ����� ������." << endl;
//		break;
//	}
//}
//
//void theOne8() {
//	float x, y;
//	cout << "������� �,� ���������� ��������������: "; cin >> x >> y;
//	
//	if ( (y <= pow((1.4*x),2)-1) && (y <= 5 && y >= 0) ) cout << "����������� (True)" << endl;
//	else cout << "�� ����������� (False)" << endl;
//}
//
//void theOne19() {
//	int op;
//	float L;
//	cout << "������� ������ ������� L: "; cin >> L;
//	cout << "�������� ������� ��������� ��� ������� L (1 - ��������, 2 - ��������, 3 - ����, 4 - ���������, 5 - ���������): "; cin >> op;
//	switch (op)
//	{
//	case 1:
//		cout << L / 10 << "�" << endl;
//		break;
//	case 2:
//		cout << L * 1000 << "�" << endl;
//		break;
//	case 3:
//		cout << L << "�" << endl;
//		break;
//	case 4:
//		cout << L / 1000 << "�" << endl;
//		break;
//	case 5:
//		cout << L / 100 << "�" << endl;
//		break;
//	default:
//		cout << "� �� ���� ����� �������. ����������, ���������� ������ ����� ������." << endl;
//		break;
//	}
//}
//
///*
//
//���� ������������ ����������� ����� N. ����������, ������ ��, ��� ������� �����
//����� �����, � ��� ������� �������� ����� ����� � �� ��������� � �������� �������. 
//� �������� ������ �������� ���������� ��������
//
//*/
//
//double degrees(double a, double b, double angle)
//{
//	angle *= 3.14 / 180;
//	return 0.5 * a * b * sin(angle);
//}
//
//void text1() {
//	double a, b, S, angle;
//	cout << "������ ����� ������ ������������: ";
//	cin >> a >> b;
//	cout << "������ ���� ����� ���������: ";
//	cin >> angle;
//	S = degrees(a, b, angle);
//	if (S <= 0) {
//		cout << "Treygolnik invalid\n";
//		return;
//	}
//	cout << "Sqare: " << S << endl;
//	//cout<<"����� "<<1/2*a*b*sin(angle) << endl;
//}
//
//void text2() {
//	int S;
//	float rasxod, tsena;
//	cout << "���������� �� ���� � ���� ������� (��)->"; cin >> S;
//	cout << "������ ������� (� �� 100 ��) ->"; cin >> rasxod; rasxod /= 100;
//	cout << "���� ����� ������� (���.) ->"; cin >> tsena;
//	cout << "������� �� ���� �������� � " << (rasxod*(S*2))*tsena;
//}
//
//
//void one41() {
//	int num;
//	cout << "������� 6-�� ������� �����: "; cin >> num;
//	int a, b, c, d, e, f;
//	a = num / 100000;
//	b = (num / 10000) % 10;
//	c = (num / 1000) % 10;
//	d = (num / 100) % 10;
//	e = (num / 10) % 10;
//	f = num % 10;
//	if (a == f && (b||c||d||e!=a||f) && (b!=c!=d!=e)) {
//		cout << "True" << endl;
//		return;
//	}
//	cout << "False" << endl;
//}
//
//void call_listener() {
///*	while (true)
//	{
//		//case1();
//		//theOne8();
//		//theOne19();
//		one41();
//	}*/
//	//text1();
//	text2();
//}
//
//int main() {
//	setlocale(LC_ALL, "Russian");
//	call_listener();
//}