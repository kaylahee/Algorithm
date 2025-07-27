#include <iostream>
#include <vector>

int main_14501() {
	int n;
	std::cin >> n;

	std::vector<int> arr_time(n + 1, 0);
	std::vector<int> arr_price(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> arr_time[i] >> arr_price[i];
	}

	for (int i = 1; i <= n; i++) {
		if (!(i + arr_time[i] >= n + 1)) {
			arr_price[i] = std::max(arr_price[i], arr_price[i] + arr_price[i + arr_time[i]]);
			i += arr_time[i];
		}
		else {
			i++;
		}
	}

	std::cout << arr_price[n - 1];
	return 0;
}