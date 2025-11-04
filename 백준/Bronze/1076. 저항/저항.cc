#include <iostream>
#include <string>
#include <vector>
#include <cmath>

struct Register {
	std::string color;
	int val;
	int mul;
};
std::vector<Register> reg;

int main() {
	reg.push_back({ "black", 0, 1 });
	reg.push_back({ "brown", 1, 10 });
	reg.push_back({ "red", 2, 100 });
	reg.push_back({ "orange", 3, 1000 });
	reg.push_back({ "yellow", 4, 10000 });
	reg.push_back({ "green", 5, 100000 });
	reg.push_back({ "blue", 6, 1000000 });
	reg.push_back({ "violet", 7, 10000000 });
	reg.push_back({ "grey", 8, 100000000 });
	reg.push_back({ "white", 9, 1000000000 });

	long long int num = 0;
	for (int i = 0; i < 3; i++) {
		std::string str;
		std::cin >> str;

		for (Register r : reg) {
			if (str == r.color) {
				if (i == 2) {
					num *= r.mul;
					break;
				}

				num += r.val * pow(10, 1 - i);
			}
		}
	}
	std::cout << num << "\n";
	return 0;
}