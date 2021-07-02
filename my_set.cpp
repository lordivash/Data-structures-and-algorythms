#include <iostream>
#include <vector>

using namespace std;

class Set {

public:

	Set(int n) {

		elements = vector <vector<int>>(n, vector <int>());
		set_rows = n;
		size = 0;

	}

	void insert(int x) {

		if (!find(x)) {

			elements[x % set_rows].push_back(x);
			size++;

			if (size > set_rows) {
				rebuild_hash_table();
			}

		}

	}

	bool find(int x) {

		for (int element : elements[x % set_rows]) {

			if (element == x) {
				return true;
			}

		}

		return false;

	}

	void remove(int x) {

		int row_size = elements[x % set_rows].size();

		for (int i = 0; i < row_size; i++) {

			if (elements[x % set_rows][i] == x) {

				elements[x % set_rows][i] = elements[x % set_rows][row_size - 1];
				elements[x % set_rows].pop_back();
				size--;

			}

		}

	}

	void show_set() {

		for (vector <int> row : elements) {

			cout << "row: ";

			for (int element : row) {
				cout << element << " ";
			}

			cout << endl;

		}

	}

private:

	vector <vector <int>> elements;
	int set_rows;
	int size;

	void rebuild_hash_table() {

		int new_rows = 2 * set_rows;
		vector <vector <int>> new_elements(new_rows, vector <int>());
		//Set new_set(2 * set_rows);

		for (vector <int> row : elements) {

			for (int element : row) {

				new_elements[element % new_rows].push_back(element);
				//new_set.insert(element)

			}

		}

		set_rows = new_rows;
		elements = new_elements;
		//*this = new_set;

	}

};

int main() {

	Set my_set(10);

	my_set.insert(1);
	my_set.insert(42);
	my_set.insert(23);
	my_set.insert(14);
	my_set.insert(75);
	my_set.insert(46);
	my_set.insert(87);
	my_set.insert(98);
	my_set.insert(29);
	my_set.insert(10);

	my_set.show_set();

	cout << "After hash table rebuild:" << endl;

	my_set.insert(225);

	my_set.show_set();

	cout << my_set.find(14) << endl;

	my_set.remove(14);

	cout << my_set.find(14) << endl;

	return 0;
}