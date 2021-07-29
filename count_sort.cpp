#include <iostream>
#include <vector>

using namespace std;

int min_element(vector <int>& sequence) {

	int min = sequence[0];

	for (int i = 1; i < sequence.size(); i++) {

		if (sequence[i] < min) {
			min = sequence[i];
		}

	}

	return min;

}

int max_element(vector <int>& sequence) {

	int max = sequence[0];

	for (int i = 1; i < sequence.size(); i++) {

		if (sequence[i] > max) {
			max = sequence[i];
		}

	}

	return max;

}

//Complexity O(n + k) where k - number of possible elements (max - min + 1)
void count_sort(vector <int>& sequence) {

	int min = min_element(sequence);
	int max = max_element(sequence);

	int count_of_elements = max - min + 1;

	vector <int> counters(count_of_elements, 0);

	int sequence_size = sequence.size();

	for (int i = 0; i < sequence_size; i++) {

		counters[sequence[i] - min]++;

	}

	int current_position = 0;

	for (int i = 0; i < count_of_elements; i++) {

		for (int j = 0; j < counters[i]; j++) {

			sequence[current_position] = min + i;
			current_position++;

		}

	}

}

int main() {

	int n;
	cin >> n;

	vector <int> arr(n);

	for (int i = 0; i < n; i++) {

		cin >> arr[i];

	}

	count_sort(arr);

	for (int element : arr) {
		cout << element << " ";
	}

	return 0;
}