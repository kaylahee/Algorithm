#include <iostream>

int sum = 0;
void func(int num) {
	if (num == 1) {
		std::cout << sum;
		return;
	}
	sum++;

	// ¦����
	if (num % 2 == 0) {
		func(num / 2);
	}
	// Ȧ����
	else {
		func(num * 3 + 1);
	}
}

int main() {
	int n;
	std::cin >> n;
	func(n);
	return 0;
}