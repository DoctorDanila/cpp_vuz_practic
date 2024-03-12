#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;

//proc_1
/*
ќписать функцию Quarter(x, y) целого типа, определ€ющую номер координатной четверти, 
в которой находитс€ точка с ненулевыми вещественными координатами (x, y). — помощью

этой функции найти номера координатных четвертей дл€ трех точек с данными ненулевыми координатами.
*/
int Quarter(double x, double y) {
    if (x != 0 && y != 0)
    {
        if (x > 0 && y > 0)
        {
            return 1;
        }
        if (x < 0 && y > 0)
        {
            return 2;
        }
        if (x < 0 && y < 0)
        {
            return 3;
        }
        if (x > 0 && y < 0)
        {
            return 4;
        }
    }
    else 
        cout << "Ќаходитс€ на сис. координат" << endl;
    return 0;
}

void proc23() {
    cout << Quarter(3.57, 2.8) << " четверть плоскости." << endl;
    cout << Quarter(-13.57, 8.2) << " четверть плоскости." << endl;
    cout << Quarter(-120.5, -4.4) << " четверть плоскости." << endl;
    cout << Quarter(3.57, -12.28) << " четверть плоскости." << endl;
    cout << Quarter(0, -12.28) << " четверть плоскости." << endl;
}

int AddRightDigit(int D, int K) {
    return (K * 10) + D;
}

void proc8() {
    int K = 879, D1 = 8, D2 = 3;
    cout << "K=" << K << " D1=" << D1 << " D2=" << D2 << endl;
    cout << K << endl;
    K = AddRightDigit(D1, K);
    cout << K << endl;
    K = AddRightDigit(D2, K);
    cout << K << endl;
}

double factorial(double i)
{
	if (i == 0) return 1;
	else return i * factorial(i - 1);
}


double Sin1(double x, double e) {
	long double answ = 0;
	bool toggle = false;
	for (int i = 0; i < e; i++)
	{
		if (toggle) answ -= pow(x, (2 * i + 1)) / factorial(2 * i + 1);
		if (!toggle) answ += pow(x, (2 * i + 1)) / factorial(2 * i + 1);
		toggle = !toggle;
	}
    return answ;
}

void proc41() {
    double x, e;
    cout << "eps - целое число)\n";
    cout << "x:"; cin >> x;
    cout << "e:"; cin >> e;
    cout << "Ёталонное значение: " << sin(x) << endl;
    cout << Sin1(x, e) << endl;
    cout << "e:"; cin >> e;
    cout << Sin1(x, e) << endl;
    cout << "e:"; cin >> e;
    cout << Sin1(x, e) << endl;
    cout << "e:"; cin >> e;
    cout << Sin1(x, e) << endl;
    cout << "e:"; cin >> e;
    cout << Sin1(x, e) << endl;
    cout << "e:"; cin >> e;
    cout << Sin1(x, e) << endl;
}

double segmentLen(double x1, double y1, double x2, double y2) {
    return sqrt(pow(x2-x1,2)+pow(y2-y1,2));
}

void TheTri2() {
    vector<vector<double>> segments;
    ifstream fin("b.otr");
    if (!fin) return;
    string buf;
    getline(fin, buf);
    int numSegs = stoi(buf);
    for (int i = 0; i < numSegs && !fin.eof(); i++)
    {
        vector<double> segment;
        getline(fin, buf, ' ');
        segment.push_back(stod(buf));
        getline(fin, buf, ' ');
        segment.push_back(stod(buf));
        segments.push_back(segment);
        segment.clear();
        getline(fin, buf, ' ');
        segment.push_back(stod(buf));
        getline(fin, buf, ' ');
        segment.push_back(stod(buf));
        segments.push_back(segment);
    }
    double maxLen = -1;
    for (int i = 1; i < segments.size(); i++)
    {
        double tmp = segmentLen(segments[i-1][0], segments[i - 1][1], segments[i][0], segments[i][1]);
        if (tmp > maxLen) maxLen = tmp;
    }
    cout << "maxLen: " << maxLen << endl;
}

bool check_polindrom(string word)
{
    int len = word.length();
    for (int i = 0; i < len / 2; ++i)
    {
        if (word[i] != word[len - i - 1])
        {
            return false;
        }
    }
    return true;
}

void TheTri11() {
    int a, b;
    bool q = false;
    cout << "a:"; cin >> a;
    cout << "b:"; cin >> b;
    for (int i = a; i <= b; i++) {
        if (check_polindrom(to_string(i))) {
            cout << i << endl;
            q = true;
        }
    }
    if (!q) cout << "No solution" << endl;
}

string ten_base(int x, int base) {
    char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
    if (base > (sizeof(digits) / sizeof(digits[0]))) return to_string(x);
    string res = "";
    while (x > 0) {
        res = digits[x % base] + res;
        x /= base;
    }
    return res;
}

void TheTri14() {
    int x, base;
    cout << "x:"; cin >> x;
    cout << "base:"; cin >> base;
    cout << ten_base(x,base);
}

//void call_listener() {
//    /*cout << "proc23\n";
//    proc23();
//    cout << "proc8\n";
//    proc8();*/
//    cout << "proc41\n";
//    proc41();
//    cout << "TheTri2\n";
//    TheTri2();
//    cout << "TheTri11\n";
//    TheTri11();
//    cout << "TheTri14\n";
//    TheTri14();
//}
//
//int main() {
//    setlocale(LC_ALL, "Russian");
//	call_listener();
//	return 0;
//}