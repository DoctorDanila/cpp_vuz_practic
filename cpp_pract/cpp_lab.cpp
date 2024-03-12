////8
//#include <iostream>
//
//using namespace std;
//
//void case1() {
//	int day_num;
//	cout << "Введите число от 1 до 7: ";cin >> day_num;
//	switch (day_num)
//	{
//	case 1:
//		cout << "Выбранный день недели: понедельник" << endl;
//		break;
//	case 2:
//		cout << "Выбранный день недели: вторник" << endl;
//		break;
//	case 3:
//		cout << "Выбранный день недели: среда" << endl;
//		break;
//	case 4:
//		cout << "Выбранный день недели: четверг" << endl;
//		break;
//	case 5:
//		cout << "Выбранный день недели: пятница" << endl;
//		break;
//	case 6:
//		cout << "Выбранный день недели: суббота" << endl;
//		break;
//	case 7:
//		cout << "Выбранный день недели: воскресение" << endl;
//		break;
//	default:
//		cout << "Я ничего не нашёл. Пожалуйста, попробуйте ввести число заново." << endl;
//		break;
//	}
//}
//
//void theOne8() {
//	float x, y;
//	cout << "Введите х,у координаты соответственно: "; cin >> x >> y;
//	
//	if ( (y <= pow((1.4*x),2)-1) && (y <= 5 && y >= 0) ) cout << "Принадлежит (True)" << endl;
//	else cout << "Не принадлежит (False)" << endl;
//}
//
//void theOne19() {
//	int op;
//	float L;
//	cout << "Введите длинну отрезка L: "; cin >> L;
//	cout << "Выберите единицу измерения для отрезка L (1 - дециметр, 2 - километр, 3 - метр, 4 - миллиметр, 5 - сантиметр): "; cin >> op;
//	switch (op)
//	{
//	case 1:
//		cout << L / 10 << "м" << endl;
//		break;
//	case 2:
//		cout << L * 1000 << "м" << endl;
//		break;
//	case 3:
//		cout << L << "м" << endl;
//		break;
//	case 4:
//		cout << L / 1000 << "м" << endl;
//		break;
//	case 5:
//		cout << L / 100 << "м" << endl;
//		break;
//	default:
//		cout << "Я не знаю такой команды. Пожалуйста, попробуйте ввести число заново." << endl;
//		break;
//	}
//}
//
///*
//
//Дано шестизначное натуральное число N. Определите, правда ли, что крайние цифры
//числа равны, а все средние различны между собой и не совпадают с крайними цифрами. 
//В качестве ответа выведите логическое значение
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
//	cout << "Ввести длины сторон треугольника: ";
//	cin >> a >> b;
//	cout << "Ввести угол между сторонами: ";
//	cin >> angle;
//	S = degrees(a, b, angle);
//	if (S <= 0) {
//		cout << "Treygolnik invalid\n";
//		return;
//	}
//	cout << "Sqare: " << S << endl;
//	//cout<<"Ответ "<<1/2*a*b*sin(angle) << endl;
//}
//
//void text2() {
//	int S;
//	float rasxod, tsena;
//	cout << "Расстояние до дачи в одну сторону (км)->"; cin >> S;
//	cout << "Расход бензина (л на 100 км) ->"; cin >> rasxod; rasxod /= 100;
//	cout << "Цена литра бензина (руб.) ->"; cin >> tsena;
//	cout << "Поездка на дачу обойдётся в " << (rasxod*(S*2))*tsena;
//}
//
//
//void one41() {
//	int num;
//	cout << "Введите 6-ти занчное число: "; cin >> num;
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