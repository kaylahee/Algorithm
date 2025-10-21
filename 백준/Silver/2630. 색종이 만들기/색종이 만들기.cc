// 09:20~
// [BOJ_2630] 색종이 만들기

// 여러개의 정사각형칸들로 이루어진 정사각형 모양의 종이
// 각 정사각형들은 하얀색으로 칠해져 있거나 파란색으로 칠해져 있음

// 주어진 종이를 일정한 규칙에 따라 잘라서 다양한 크기를 가진
// 정사각형 모양의 하얀색 또는 파란색 색종이를 만들려고 한다.

// 전체 종이의 크기가 n*n이라면 종이를 자르는 규칙은 다음과 같다
// 전체 종이가 모두 같은색으로 칠해져 있지 않으면
// 가로와 세로로 중간 부분을 잘라서 
// 똑같은 크기의 4개의 n/2*n/2 색종이로 나눈다.

// 나누어진 종이 각각에 대해서도 앞에서와 마찬가지로 
// 모두 같은 색으로 칠해져 있지 않으면 같은 방법으로
// 똑같은 크기의 4개의 색종이로 나눈다.

#include <iostream>

int n;
int map[300][300];

// 전체가 같은 색인지 판별
bool isSameColor(int ry, int rx, int k) {
	int color = map[ry][rx];
	for (int i = ry; i < ry + k; i++) {
		for (int j = rx; j < rx + k; j++) {
			if (map[i][j] != color) {
				return false;
			}
		}
	}
	return true;
}

int blueCnt = 0;
int whiteCnt = 0;
void cutting(int n, int y, int x, int k) {
	if (isSameColor(y, x, k)) {
		if (map[y][x] == 1) {
			blueCnt++;
		}
		else {
			whiteCnt++;
		}
		return;
	}

	cutting(n, y, x, k / 2);
	cutting(n, y, x + k / 2, k / 2);
	cutting(n, y + k / 2, x, k / 2);
	cutting(n, y + k / 2, x + k / 2, k / 2);
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
		}
	}

	cutting(n, 0, 0, n);

	std::cout << whiteCnt << "\n" << blueCnt << "\n";
	return 0;
}