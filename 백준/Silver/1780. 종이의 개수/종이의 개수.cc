// 10:10~
// [BOJ_1780] 종이의 개수

// n*n 크기의 행렬로 표현되는 종이가 있다
// 종이의 각 칸에는 -1, 0, 1 중 하나가 저장되어 있다.

// 종이가 모두 같은 수 -> 그 종이 그대로 상ㅇ
// 종이 9개로 자른다. 

#include <iostream>

int n;
int map[2200][2200];

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

int minusCnt = 0;
int zeroCnt = 0;
int plusCnt = 0;
void countingCnt(int y, int x, int k) {
	if (isSameColor(y, x, k)) {
		int color = map[y][x];

		if (color == -1) {
			minusCnt++;
		}
		else if (color == 0) {
			zeroCnt++;
		}
		else {
			plusCnt++;
		}
		return;
	}

	countingCnt(y, x, k / 3);
	countingCnt(y + k / 3, x, k / 3);
	countingCnt(y + 2 * (k / 3), x, k / 3);
	countingCnt(y, x + k / 3, k / 3);
	countingCnt(y, x + 2 * (k / 3), k / 3);
	countingCnt(y + k / 3, x + k / 3, k / 3);
	countingCnt(y + k / 3, x + 2 * (k / 3), k / 3);
	countingCnt(y + 2 * (k / 3), x + k / 3, k / 3);
	countingCnt(y + 2 * (k / 3), x + 2 * (k / 3), k / 3);
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
		}
	}

	countingCnt(0, 0, n);
	std::cout << minusCnt << "\n" << zeroCnt << "\n" << plusCnt << "\n";
	return 0;
}