#include <iostream>
#include <string>

int main_11720() {
	int n;
	std::cin >> n;

	std::string num;
	std::cin >> num;
	
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += int(num[i] - 48);
	}
	std::cout << sum;

	return 0;
}