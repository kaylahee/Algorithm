#include <iostream>
#include <string>
#include <algorithm>

int n, m;
int map[51][51];

int findSquare(int sy, int sx) {
	int wide = 1;
	for (int j = sx + 1; j < m; j++) {
		if (sy + j - sx >= n) {
			continue;
		}

		if (map[sy][sx] == map[sy][j]) {
			if (map[sy][sx] == map[sy + j - sx][sx] && map[sy][sx] == map[sy + j - sx][j]) {
				wide = std::max(wide, (j - sx + 1) * (j - sx + 1));
			}
		}
	}

	return wide;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}

	int maxWidth = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			maxWidth = std::max(maxWidth, findSquare(i, j));
		}
	}
	std::cout << maxWidth << "\n";

	return 0;
}