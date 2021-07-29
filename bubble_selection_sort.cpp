#include <iostream>
#include <algorithm>

void selection_sort(int a[], int size) {

	for (int start_index = 0; start_index < size - 1; ++start_index) {

		int max_index = start_index;

		for (int current_index = start_index + 1; current_index < size; ++current_index) {

			if (a[current_index] > a[max_index]) {
				max_index = current_index;
			}

		}

		std::swap(a[start_index], a[max_index]);

	}

}

void bubble_sort(int arr[], int size) {

	for (int i = 0; i < size - 1; ++i) {

		bool sorted = true;

		for (int j = 0; j < size - 1 - i; ++j) {

			if (arr[j] > arr[j + 1]) {

				std::swap(arr[j], arr[j + 1]);
				sorted = false;

			}

		}

		if (sorted) {
			std::cout << "Early termination right after " << (i + 1) << " itteration";
			break;
		}

	}

}

void print_array(int a[], int size) {

	for (int i = 0; i < size; ++i) {
		std::cout << a[i] << " ";
	}
	std::cout << '\n';

}

int main() {

	int arr[] = { 7, 5, 6, 4, 9, 8, 2, 1, 3 };
	int size = sizeof(arr) / sizeof(arr[0]);

	print_array(arr, size);
	
	bubble_sort(arr, size);

	//print_array(arr, size);

	return 0;
}