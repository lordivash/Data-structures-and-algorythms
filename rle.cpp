#include <iostream>
#include <string>
#include <vector>

using namespace std;

string pack(char c, int count) {

	string s{ c };

	if (count == 1) {

		return s;

	}

	return s + to_string(count);

}

string rle(string line) {

	string encoded_line;

	if (line == "") {
		return "";
	}

	int previous_i = 0;

	for (int i = 1; i < line.length(); i++) {

		if (line[i] != line[previous_i]) {

			encoded_line += pack(line[previous_i], i - previous_i);
			previous_i = i;

		}

	}

	encoded_line += pack(line[previous_i], line.length() - previous_i);

	return encoded_line;
}

int main() {

	string str;
	cin >> str;

	string encoded_string = rle(str);

	cout << encoded_string;

	return 0;
}