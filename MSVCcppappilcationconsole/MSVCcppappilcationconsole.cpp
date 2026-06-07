#include <iostream>
#include <string>
#include <iomanip>

int main(int argc, char *argv[]) {
	float interest;
	int time;

	if (argc != 2) {
		std::cout << "Failed!" << std::endl;
		return 1;
	}

	float num = std::stof(argv[1]);

	std::cout << "What is the interest(In decimal): " << std::endl;
	std::cin >> interest;
	std::cout << "What is the time in years: " << std::endl;
	std::cin >> time;

	for (int i = 0; i < time; i++) {
		num = num * (1 + interest);
	}

	std::cout << "The interest after " << time << " year is $" << std::setprecision(2) << std::fixed << num << std::endl;

	return 0;

}