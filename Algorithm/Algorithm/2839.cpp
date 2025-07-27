#include <iostream>

int main_2839() {
	int n;
	std::cin >> n;

	int cnt_5 = 0;
	int cnt_3 = 0;

	bool is3double = false;
	bool is5double = false;
	
	int min_sum = 9999;
	int tmp = n;
	for (int i = n / 5; i >= 0; i--) {
		tmp -= 5 * i;
		if (tmp % 3 == 0) {
			cnt_5 = i;
			cnt_3 = tmp / 3;
			tmp /= 3;
		}

		if (cnt_5 * 5 + cnt_3 * 3 == n) {
			if (min_sum > cnt_5 + cnt_3) {
				min_sum = cnt_5 + cnt_3;
			}
		}
		cnt_3 = 0; cnt_5 = 0;
		tmp = n;
	}

	if (min_sum == 9999) {
		if (n % 3 == 0) {
			min_sum = n / 3;
		}
		else {
			min_sum = -1;
		}
	}

	std::cout << min_sum;

	return 0;
}