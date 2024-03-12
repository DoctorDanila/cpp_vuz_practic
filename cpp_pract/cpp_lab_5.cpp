#include <iostream>
#include <vector>
#include <string>

using namespace std;

double recur3_0(double n) {
	if (n == 1) return 1;
	return n * recur3_0(n - 1);
}

double recur3_1(int n) {
	if ((n / 10) < 1) return n;
	return (n % 10) * recur3_1(n/10);
}

double recur13(double x, int n) {
	if (n-1 == 0) return x;
	if ((n - 1) % 2 != 0) return -pow(2, n - 1) * pow(x, n) + recur13(x, n - 1);
	if ((n - 1) % 2 == 0) return pow(2, n - 1) * pow(x, n) + recur13(x, n - 1);
}

void minMax23_0(int n, vector<int>data) {
	if (n <= 3) return;
	int a = 0,
		b = 0,
		c = 0;
	for (int i = 0; i < data.size(); i++)
		if (data[i] > a || data[i] > b || data[i] > c)
			if (a <= b || a <= c)
				a = data[i];
			else
				if (b <= c)
					b = data[i];
				else
					c = data[i];
	int mi = min(a, b), mx = max(a, b), sr;
	mi = min(mi, c);
	mx = max(mx, c);
	sr = (a + b + c) - mi - mx;
	cout << mx << " " << sr << " " << mi << "\n";
}

int& min__(int *a, int *b, int *c) {
	int q = min(*a, *b);
	q = min(q, *c);
	if (*a == q) return *a;
	if (*b == q) return *b;
	if (*c == q) return *c;
}

void minMax23_1(int n, vector<int>data) {
	if (n <= 3) return;
	int a = 0, 
		b = 0,
		c = 0;
	for (int i = 0; i < data.size(); i++) {
		if (data[i] > a || data[i] > b || data[i] > c) {
			min__(&a, &b, &c) = data[i];
		}
	}
	int mi = min(a,b), mx=max(a,b), sr;
	mi = min(mi, c);
	mx = max(mx, c);
	sr = (a + b + c) - mi - mx;
	cout << mx << " " << sr << " " << mi << "\n";
}

void minMax23_2() {
	int a = 0,
		b = 0,
		c = 0,
		n, q;
	cout << "n:"; cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "q:"; cin >> q;
		if (q > a || q > b || q > c) {
			c = b;
			b = a;
			a = q;
		}
	}
	cout << a << " " << b << " " << c << "\n";
}

//void call_listener() {
//	double r3_0, r3_1, r13x, r13n;
//	int n; vector<int> data;
//	/*cout << "r3_0:"; cin >> r3_0;
//	cout << recur3_0(r3_0) << endl;*/
//	/*cout << "r3_1:"; cin >> r3_1;
//	cout << recur3_1(r3_1) << endl;*/
//	/*cout << "r13x:"; cin >> r13x;
//	cout << "r13n:"; cin >> r13n;
//	cout << recur13(r13x,r13n) << endl;	*/
//	/*cout << "n:"; cin >> n;
//	cout << "input num or put \"r\" for input random nums\n";
//	for (int i = 0; i < n; i++)
//	{
//		string q;
//		cin >> q;
//		if (q == "r") {
//			for (int j = i; j < n; j++)
//			{
//				data.push_back(rand());
//			}
//			break;
//		}
//		data.push_back(stoi(q));
//	}
//	for (int i = 0; i < data.size(); i++)
//	{
//		cout << data[i] << " ";
//	}cout << endl;
//	minMax23_0(n, data);
//	minMax23_1(n, data);*/
//	minMax23_2();
//}
//
//int main() {
//	srand((unsigned int)time(NULL));
//	call_listener();
//	return 0;
//}