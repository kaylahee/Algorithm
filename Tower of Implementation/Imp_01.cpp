#include <iostream>
#include <vector>

int main_imp_01() {
	int n;
	std::cin >> n;

	std::vector<int> arr(n + 1, 0);
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	std::vector<int> dif(n, 0);
	int max = 0;
	int max_idx_s = 0;
	int max_idx_e = 0;
	for (int i = 0; i < n - 1; i++) {
		if (arr[i] < arr[i + 1]) {
			dif[i + 1] = arr[i + 1] - arr[i];

			if (max < dif[i + 1]) {
				max = dif[i + 1];
				max_idx_s = i + 1;
				max_idx_e = i + 2;
			}
		}
	}

	if (max_idx_s == 0 && max_idx_e == 0) {
		std::cout << 0;
	}
	else {
		std::cout << max_idx_s << " " << max_idx_e;
	}

	return 0;
}