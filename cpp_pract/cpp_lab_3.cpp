#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

void TextFile8() {
    ifstream fin("d.txt");
    if (!fin) {
        return;
    }
    string buf;
    double X;
    double minX = 64000;
    double maxX = -1;
    while (!fin.eof()) {
        getline(fin, buf);
        X = stod(buf);
        if (X > maxX) maxX = X;
        if (X < minX) minX = X;
        cout << X << endl;
    }
    cout << "minX: " << minX << " maxX: " << maxX << endl;
}

void TextFile9() {
    int N, a, b;
    vector<int> answs;
    cout << "input a,b:"; cin >> a >> b;
    cout << "input N:"; cin >> N;
    for (int i = a; i <= b; i++) {
        int tmp = i;
        while (tmp != 0) {
            if (tmp % 10 == N) {
                answs.push_back(i);
            }
            tmp /= 10;
        }
    }
    ofstream fout("a.txt");
    if (!fout) {
        return;
    }
    for (int i = 0; i < answs.size(); i++) {
        fout << answs[i] << endl;
    }
}

//double fib(double n)
//{
//    if (n <= 1)
//        return n;
//    return fib(n - 1) + fib(n - 2);
//}

//void TextFile4() {
//    int N;
//    vector<double> fibs;
//    cout << "input N:"; cin >> N;
//    for (int i = 1; i < N * 2; i += 2) {
//        fibs.push_back(fib(i));
//    }
//    ofstream fout("d_1.txt");
//    if (!fout) {
//        return;
//    }
//    for (int i = 0; i < fibs.size(); i++) {
//        fout << fibs[i] << endl;
//    }
//}


/*
ƒан текстовый файл с именем c.txt, в первой строке которого записано един-
ственное число N, а во второй строке последовательность из N целых чисел, разделенных

пробелами. ќпределить количество цифр в самом "длинном" числе. ќб€зательно использо-
вать логическую переменную и Ќ≈ использовать оператор ветвлени€ в теле цикла. ћассивы

использовать запрещаетс€, а файл дл€ чтени€ открывать только один раз.
*/
//int Count(int a)
//{
//    int count = 0;
//    do {
//        count++;
//        a /= 10;
//    } while (a);
//    return count;
//}
//
//void TextFile18() {
//    ifstream fin("c.txt");
//    if (!fin) {
//        return;
//    }
//    string buf;
//    getline(fin, buf);
//    int N = stoi(buf);
//    int bigest = 0;
//    while (getline(fin, buf)) {
//        std::stringstream ss(buf);
//        while (getline(ss, buf, ' ')) {
//            bool is_bigest = Count(stoi(buf)) > bigest;
//            bigest = is_bigest ? Count(stoi(buf)) : bigest;
//        }
//    }
//    cout << bigest << endl;
//}

//void call_listener() {
//    cout << "TextFile8\n";
//    TextFile8();
//    cout << "TextFile9\n";
//    TextFile9();
//    cout << "TextFile4\n";
//    TextFile4();
//    cout << "TextFile18\n";
//    TextFile18();
//}
//
//int main() {
//	srand((unsigned int)time(NULL));
//	setlocale(LC_ALL, "Russian");
//	call_listener();
//	return 0;
//}