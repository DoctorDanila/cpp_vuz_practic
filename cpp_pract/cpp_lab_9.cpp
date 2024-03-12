#include <iostream>
#include <vector>
#include <regex>
#include <sstream>
#include <string>
#include <map>
#include <bitset>

using namespace std;

//vector<string> split(const string& s, const char* delim)
//{
//	std::string::size_type size = s.length();
//	char* const buffer = new char[size + 1];
//	std::vector<std::string> res;
//
//	strcpy(buffer, s.c_str());
//
//	char* p = strtok(buffer, delim);
//	while (p)
//	{
//		res.push_back(std::string(p));
//		p = strtok(NULL, delim);
//	}
//	delete[]buffer;
//
//	return res;
//}

//std::vector<std::string> split(const std::string& src, const std::string& delim)
//{
//	std::vector<std::string> dest;
//	std::string::size_type i = src.find_first_not_of(delim);
//	while (i != std::string::npos)
//	{
//		const std::string::size_type j = src.find_first_of(delim, i);
//		if (j == std::string::npos)
//		{
//			dest.push_back(src.substr(i));
//			return dest;
//		}
//
//		const std::string::size_type n = j - i;
//		dest.push_back(src.substr(i, n));
//		i = src.find_first_not_of(delim, i + n);
//	}
//
//	return dest;
//}


string replaceItem(string arr, int x, char newItem = '.') {
	arr[x] = newItem;
	return arr;
}

void String48() {
	string input;
	cout << "¬ведите строку, слова раздел€ть пробелами, все буквы заглавные, знаки препинани€ не ставьте, чтобы не запутатьс€)\n"; 
	//while ((s = std::getline(std::cin, input)) != " ")
	//

	regex regex_space(" ");
	//std::istringstream iss(input);
	//std::vector<std::string> text{ std::istream_iterator<std::string>(iss), std::istream_iterator<std::string>() };

	getline(cin, input);
	vector<string> text(
		sregex_token_iterator(input.begin(), input.end(), regex_space, -1),
		sregex_token_iterator()
	);

	char tar;
	for (int i = 0; i < text.size(); i++)
	{
		tar = text[i][0];
		for (int j = 1; j < text[i].size(); j++)
		{
			if (text[i][j] == tar) {
				text[i] = replaceItem(text[i], j);
			}
		}
	}
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << " ";
	cout << endl;
}

void str20() {
	string input;
	cout << "¬ведите строку (string)\n"; 
	getline(cin, input);
	regex regex_space(" ");
	vector<string> text(
		sregex_token_iterator(input.begin(), input.end(), regex_space, -1),
		sregex_token_iterator()
	);
	for (int i = 0; i < text.size(); i++)
		for (int j = 0; j < text[i].size(); j++)
			text[i][j] = toupper(text[i][j]);
			//putchar(toupper(text[i][j]));
	for (int i = 0; i < text.size(); i++)
		cout << text[i] << " ";
	cout << endl;
}

void str43() {
	string input;
	cout << "¬ведите строку (string)\n";
	getline(cin, input);

	map<char, int> table; // pair key->value
	for (int i = 0; i < input.size(); i++) {
		if (table.count(input[i])) {
			table[input[i]] += 1;
		}
		else {
			table[input[i]] = 1;
		}
	}
	int maxk = INT_MIN;
	char el;
	for (const auto& element : table)
	{
		if (element.second > maxk) {
			maxk = element.second;
			el = element.first;
		}
	}
	cout << el << " был встреччен " << maxk << endl;
}

string conv(char* s, int thss, int toss)
{
	long rez = strtol(s, NULL, thss);
	char digits[] = { '0','1','2','3','4','5','6','7','8','9' };
	if (toss > (sizeof(digits) / sizeof(digits[0]))) return to_string(rez);
	string res = "";
	while (rez > 0) {
		res = digits[rez % toss] + res;
		rez /= toss;
	}
	return res;
}

void str33() {
	char* input = new char[100];
	cin >> input;
	for (int i = 0; i < sizeof(input)/sizeof(input[0]); i++)
		input[i] = tolower(input[i]);
	cout << conv(input, 12, 4);
}

//int main() {
//	setlocale(LC_ALL, "Russian");
//	system("chcp 1251");
//	//String48();
//	//str20();
//	//str43();
//	str33();
//	return 0;
//}