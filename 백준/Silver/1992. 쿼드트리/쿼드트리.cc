// 09:42~
// [BOJ_1992] 쿼드트리

// 흰점을 나타내는 0 / 검은 점을 나타내는 1
// 같은 숫자의 점들이 한 곳에 많이 몰려있으면,
// 쿼드 트리에서는 이를 압축하여 간단히 표현할 수 있다.

// 주어진 영상이 모두 0으로만 되어 있으면, 압축 결과는 0이 되고,
// 모두 1로만 되어 있으면, 압축 결과는 1이 된다.

// 만약, 0과 1이 섞여 있으면
// 전체를 한 번에 나타내지 못하고,
// 좌상단, 우상단, 좌하단, 우하단 이렇게 4개의 영상으로 나누어 압축하게 된다.
// 이 4개의 영역을 압축한 결과를 괄호 안에 묶어서 표현한다.

#include <iostream>
#include <string>

int n;
int map[65][65];

bool isSameColor(int y, int x, int k) {
	int color = map[y][x];
	for (int i = y; i < y + k; i++) {
		for (int j = x; j < x + k; j++) {
			if (color != map[i][j]) {
				return false;
			}
		}
	}
	return true;
}

void compress(int lev, int y, int x, int k) {
	if (isSameColor(y, x, k)) {
		std::cout << map[y][x];
		return;
	}

	std::cout << "(";
	compress(lev + 1, y, x, k / 2);
	compress(lev + 1, y, x + k / 2, k / 2);
	compress(lev + 1, y + k / 2, x, k / 2);
	compress(lev + 1, y + k / 2, x + k / 2, k / 2);
	std::cout << ")";
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;

		for (int j = 0; j < n; j++) {
			map[i][j] = s[j] - '0';
		}
	}

	compress(0, 0, 0, n);
	return 0;
}