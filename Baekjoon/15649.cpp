#include <iostream>
#include <vector>

int main_15649() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> arr;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}

	int cnt = 1;
	int tmp = n;
	for (int i = 1; i <= m; i++) {
		cnt *= tmp--;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i != j) {
				std::cout << arr[i] << " " << arr[j] << "\n";
			}
		}
	}

	for (auto a : arr) {
		for (int i = 0; i < arr.size(); i++) {
			if (a != arr[i]) {
				
			}
		}
	}

	std::cout << cnt;

	return 0;
}