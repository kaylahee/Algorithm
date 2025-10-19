// 23:14~23:17
// [BOJ_10810] 공 넣기

#include <iostream>
#include <vector>

int main() {
	int n, m;
	std::cin >> n >> m;

	std::vector<int> balls(n + 1, 0);
	for (int i = 0; i < m; i++) {
		int a, b, num;
		std::cin >> a >> b >> num;

		for (int j = a; j <= b; j++) {
			balls[j] = num;
		}
	}

	for (int i = 1; i <= n; i++) {
		std::cout << balls[i] << " ";
	}
	return 0;
}