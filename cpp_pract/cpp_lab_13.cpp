#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

int main() {
    ifstream inputFile("bin-input.bin", ios::binary);
    ofstream positiveFile("bin-positive.bin", ios::binary);
    ofstream negativeFile("bin-negative.bin", ios::binary);

    vector<int> positiveNumbers;
    vector<int> negativeNumbers;

    int number;
    while (inputFile.read(reinterpret_cast<char*>(&number), sizeof(int))) {
        if (number > 0) {
            positiveNumbers.push_back(number);
        }
        else if (number < 0) {
            negativeNumbers.push_back(number);
        }
    }

    reverse(positiveNumbers.begin(), positiveNumbers.end());
    for (int num : positiveNumbers) {
        positiveFile.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    reverse(negativeNumbers.begin(), negativeNumbers.end());
    for (int num : negativeNumbers) {
        negativeFile.write(reinterpret_cast<const char*>(&num), sizeof(int));
    }

    inputFile.close();
    positiveFile.close();
    negativeFile.close();

    return  0;
}
