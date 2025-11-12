#include <iostream>
#include <cmath>

int main() {
	int a, b;
	std::cin >> a >> b;

	int sum = 0;
	int num = 0;
	for (int i = floor(sqrt(b)); i >= ceil(sqrt(a)); i--) {
		sum += i * i;
		num = i * i;

		//std::cout << i << "\n";
	}

	if (sum == 0) {
		std::cout << -1 << "\n";
	}
	else {
		std::cout << sum << "\n";
		std::cout << num << "\n";
	}

	return 0;
}