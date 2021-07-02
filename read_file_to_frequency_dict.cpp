#include <iostream>
#include <string>
#include <map>
#include <fstream>

using namespace std;

int main() {

	map <string, int> word_frequency;

	ifstream file("input.txt");

	while (!file.eof()) {

		string word;
		file >> word;

		if (word != "") {

			if (word_frequency.find(word) == word_frequency.end()) {
				word_frequency[word] = 0;
			}

			cout << word_frequency[word]++ << " ";
		}

	}

	return 0;
}