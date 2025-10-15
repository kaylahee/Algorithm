// 23:06~
// [BOJ_2563] 색종이

// 가로 세로의 크기 각각 100 정사각형 모양의 흰색 도화지
// 이 도화지 위에 가로, 세로 크기가 각각 10인 정사각형 모양의 검은색 종이를

// 색종이 수 * 100 - 겹친 곳 넓이

#include <iostream>

int map[101][101];

int main() {
	int n;
	std::cin >> n;

	while (n--) {
		int x, y;
		std::cin >> x >> y;

		for (int i = 10 + y; i > y; i--) {
			for (int j = x; j < 10 + x; j++) {
				map[i][j]++;
			}
		}
	}

	int res = 100 * 100;
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] == 0) {
				res--;
			}
		}
	}

	std::cout << res << "\n";
	return 0;
}