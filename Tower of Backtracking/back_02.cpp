#include <iostream>

int sum = 0;
void func(int num) {
	if (num == 1) {
		std::cout << sum;
		return;
	}
	sum++;

	// Â¦¼ö¸é
	if (num % 2 == 0) {
		func(num / 2);
	}
	// È¦¼ö¸é
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