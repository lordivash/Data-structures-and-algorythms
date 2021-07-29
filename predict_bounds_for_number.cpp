#include <iostream>
#include <string>
#include <iomanip>

int main() {

	double lower_bound = 30, higher_bound = 4000;

	int n;
	std::cin >> n;

	double previous_frequency;
	std::cin >> previous_frequency;

	for (int i = 0; i < n - 1; ++i) {

		double frequency;
		std::cin >> frequency;

		std::string position;
		std::cin >> position;

		if (position == "closer") {

			if (previous_frequency < frequency) {
				lower_bound = std::max((previous_frequency + frequency) / 2, lower_bound);
			}
			else {
				higher_bound = std::min((previous_frequency + frequency) / 2, higher_bound);
			}

		}
		else if (position == "further") {

			if (previous_frequency < frequency) {
				higher_bound = std::min((previous_frequency + frequency) / 2, higher_bound);
			}
			else {
				lower_bound = std::max((previous_frequency + frequency) / 2, lower_bound);
			}

		}

		previous_frequency = frequency;

	}

	std::cout << std::setprecision(10) << lower_bound << " " << higher_bound;

	return 0;
}