#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main() {

	map <string, int> word_frequency;

	ifstream file("input.txt");

	string most_frequent_word = "";

	//Возможно следует предусмотреть случай пустой строки/файла
	file >> most_frequent_word;
	word_frequency[most_frequent_word] = 1;

	while (!file.eof()) {

		string word;
		file >> word;

		if (word != "") {

			if (word_frequency.find(word) == word_frequency.end()) {
				word_frequency[word] = 0;
			}

			word_frequency[word]++;

			if (word_frequency[word] > word_frequency[most_frequent_word]) {

				most_frequent_word = word;

			}
			else if (word_frequency[word] == word_frequency[most_frequent_word] && word < most_frequent_word) {

				most_frequent_word = word;

			}

		}
	}

	cout << most_frequent_word;

	return 0;
}