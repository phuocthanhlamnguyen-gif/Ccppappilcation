#include <iostream>
#include <string>
#include <iomanip>
#include <algorithm> 
#include <cctype>
#include <cstdlib>
#include <cmath>

#define NUM2 0

int main(int argc, char *argv[]/*Command line argument*/) {
	//Named of variables
	float interest;
	int time;
	double num2 = NUM2;
	if (argc != 2) {
		std::cout << "Failed!" << std::endl;
		return 1;
	}
	//Check if the argv[1] is digits
	else if (argv[1][0] != '\0' && std::all_of(argv[1], argv[1] + std::string(argv[1]).length(), [](unsigned char c) { return std::isdigit(c); })) {
		double num = std::stod(argv[1]);
		std::cout << "What is the interest(In decimal): " << std::endl;
		std::cin >> interest;
		if (std::cin.fail() || interest < 0) {
			//Fail system 1
			std::cout << "Failed!" << std::endl;
			return 1;
		}
		else {
			std::cout << "What is the time in years: " << std::endl;
			std::cin >> time;

			//Fail system 2
			if (std::cin.fail() || interest < 0) {
				std::cout << "Failed!" << std::endl;
				return 1;
			}
			else
			{
				//For loop
				for (int i = 0; i < time; i++) {
					num = num * (1 + interest);
				}

				if (time == 1) {
					if (num >= 0) {                    
						//Output if time == 1
						std::cout << "The interest after " << time << " year is $" << std::setprecision(2) << std::fixed << num << std::endl;
						return 0;
					}
				}
				else {
					if (num >= 0) {
						//Output if time != 1 && num > 0
						std::cout << "The interest after " << time << " years is $" << std::setprecision(2) << std::fixed << num << std::endl;
						return 0;
					} 
				}
			}
		}
	}
	//It is when argv[1] is check but doesn't have the digits
	else {
		std::cout << "Failed!" << std::endl;
		return 1;
	}
}