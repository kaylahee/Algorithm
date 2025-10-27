#include <iostream>
#include <cmath>

int sumPart(int num) {
	int sum = 0;
	int tmp = num;

	int cnt = 0;
	while (tmp > 0) {
		tmp /= 10;
		cnt++;
	}

	tmp = num;
	while (cnt--) {
		sum += tmp / (int)pow(10, cnt);
		tmp -= tmp / (int)pow(10, cnt) * (int)pow(10, cnt);
	}

	return sum + num;
}

int nums[10001];

int main() {
	int i = 1;
	while (true) {
		if (i >= 10000) {
			break;
		}

		nums[sumPart(i)] = 1;
		i++;
	}

	for (int i = 1; i < 10000; i++) {
		if (nums[i]) {
			continue;
		}

		std::cout << i << "\n";
	}
	return 0;
}