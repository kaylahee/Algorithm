#include <iostream>
#include <vector>
#include <algorithm>

int main_02() {
	int n;
	std::cin >> n;

	std::vector<int> c_prices(n, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> c_prices[i];
	}

	std::sort(c_prices.begin(), c_prices.end(), std::greater<int>());

	long long max_total = 0;
	int max_fixprice = 0;
	for (int i = 0; i < n; i++) {
		long long price = c_prices[i];
		long long sell_count = i + 1;

		long long total = price * sell_count;

		if (max_total <= total) {
			max_total = total;
			max_fixprice = price;
		}
	}

	std::cout << max_total << " " << max_fixprice;
	
	return 0;
}