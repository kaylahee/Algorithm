#include <iostream>

int sum = 0;
void func(int num) {
	if (num <= 0) {
		return;
	}
	sum += num % 10;
	func(num / 10);
}

int main() {
	long long n;
	std::cin >> n;

	func(n);
	std::cout << sum;
	return 0;
}