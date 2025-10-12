// 16:42~16:46
// [BOJ_25494] 단순한 문제

// 세 양의 정수 a, b, c가 주어질 때
// 정수 쌍의 개수를 구하라

#include <iostream>

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int a, b, c;
		std::cin >> a >> b >> c;

		int cnt = 0;
		for (int x = 1; x <= a; x++) {
			for (int y = 1; y <= b; y++) {
				for (int z = 1; z <= c; z++) {
					if ((x % y) == (y % z) && (x % y) == (z % x)) {
						cnt++;
					}
				}
			}
		}

		std::cout << cnt << "\n";
	}
	return 0;
}