#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Artifact {
	int weight;
	int tax;
};

bool compareByWeight(Artifact const& a, Artifact const& b) {
	return a.weight > b.weight;
}

void BackRec10() {
	ifstream file("artifacts.txt");
	int N, Z;
	file >> N >> Z;

	vector<Artifact> artifacts(N);
	for (int i = 0; i < N; ++i) {
		file >> artifacts[i].weight;
	}
	for (int i = 0; i < N; ++i) {
		file >> artifacts[i].tax;
	}
	file.close();

	sort(artifacts.begin(), artifacts.end(), compareByWeight);

	int totalWeight = 0;
	int totalTax = 0;
	for (int i = 0; i < N; ++i) {
		if (totalWeight + artifacts[i].weight <= Z) {
			totalWeight += artifacts[i].weight;
			totalTax += artifacts[i].tax;
			cout << i + 1 << " ";
		}
	}
	cout << "\nTotal weight: " << totalWeight << "\nTotal tax: " << totalTax << endl;

}

void HomeDyn4() {
	ifstream inputFile("HomeDyn4input.txt");
	ofstream outputFile("HomeDyn4output.txt");

	int N;
	inputFile >> N;

	vector<vector<int>> discomfort(N, vector<int>(N));
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			inputFile >> discomfort[i][j];
		}
	}

	vector<vector<int>> dp(N, vector<int>(N, INT_MAX));
	dp[0][0] = discomfort[0][0];

	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i > 0) {
				dp[i][j] = min(dp[i][j], dp[i - 1][j] + discomfort[i][j]);
			}
			if (j > 0) {
				dp[i][j] = min(dp[i][j], dp[i][j - 1] + discomfort[i][j]);
			}
		}
	}

	outputFile << dp[N - 1][N - 1] << "\n";

	int i = N - 1, j = N - 1;
	while (i > 0 || j > 0) {
		if (i > 0 && (j == 0 || dp[i - 1][j] <= dp[i][j - 1])) {
			outputFile << "R";
			--i;
		}
		else {
			outputFile << "D";
			--j;
		}
	}
}
/*
const int MOD = 1e9 + 7;
const int MAXN = 20;
const int MAXK = 10;

vector<vector<vector<int>>> dp(MAXN + 1, vector<vector<int>>(4, vector<int>(MAXK)));

void fill_dp(int K, int N) {
	dp[0][0][0] = 1;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 4; ++j) {
			for (int k = 0; k < K; ++k) {
				dp[i][j][k] = dp[i - 1][j][k];
				if (j > 0) {
					dp[i][j][k] += dp[i - 1][j - 1][k];
				}
				if (k > 0) {
					dp[i][j][k] += dp[i - 1][j][k - 1];
				}
				dp[i][j][k] %= MOD;
			}
		}
	}
}

int count_numbers(int K, int N) {
	fill_dp(K, N);
	int ans = 0;
	for (int j = 0; j < 4; ++j) {
		for (int k = 0; k < K; ++k) {
			ans += dp[N][j][k];
		}
	}
	return ans;
}*/

bool valid(const string& str) {
	int count = 0;
	for (char c : str) {
		if (c == '0') {
			count++;
			if (count > 3) {
				return false;
			}
		}
		else {
			count = 0;
		}
	}
	return true;
}

double generateNumbers(int K, int N, const string& prefix) {
	double o = 0;
	if (prefix.length() == N && valid(prefix)) {
		o+=1;
		//cout << prefix << endl;
	}
	else if (prefix.length() < N) {
		for (int i = 0; i < K; ++i) {
			o+=generateNumbers(K, N, prefix + char('0' + i));
		}
	}
	return o;
}

//bool hasThreeZeros(const string& str) {
//	return find_if(str.begin(), str.end(), [](char c) { return c == '0'; }) != str.end();
//}
//
//double count_numbers(int K, int N) {
//	vector<string> arr = generateNumbers(K, N, "");
//	double count = 0;
//	for (int i = 0; i < arr.size(); i++) {
//		if (!hasThreeZeros(arr[i])) {
//			count += stod(arr[i]);
//		}
//	}
//	return count;
//}

double checkNumWithoutTZerros(int ss, int n) {
	if (n < 3) return (double) ss * n;
	double q = 0;
	for (double i = 1; i <= (n - 2); i++) { 
		q += i;
		cout << "i= " << i << " q= " << q << endl;
	}
	return (double) (ss * n) - q;
}

void HomeDyn15() {
	int K, N;
	cin >> K >> N;
	cout << checkNumWithoutTZerros(K, N);
}

int main() {
	setlocale(LC_ALL, "Russian");
	system("chcp 1251");
	//BackRec10();
	//HomeDyn4();
	HomeDyn15();
	return 0;
}