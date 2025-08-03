#include <iostream>
#include <vector>

// 가로 확인
bool checkRow(int y, int x, std::vector<std::vector<int>> arr) {
	for (int i = 0; i < 5; i++) {
		if (arr[y][i] != 1) {
			return false;
		}
	}
	return true;
}

// 세로 확인
bool checkCol(int y, int x, std::vector<std::vector<int>> arr) {
	for (int i = 0; i < 5; i++) {
		if (arr[i][x] != 1) {
			return false;
		}
	}
	return true;
}

// 대각선 확인
bool checkDia1(std::vector<std::vector<int>> arr) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (i == j) {
				if (arr[i][j] != 1) {
					return false;
				}
			}
		}
	}
	return true;
}

bool checkDia2(std::vector<std::vector<int>> arr) {
	for (int i = 0; i < 5; i++) {
		for (int j = 4; j >= 0; j--) {
			if (i + j == 4) {
				if (arr[i][j] != 1) {
					return false;
				}
			}
		}
	}
	return true;
}

int main_imp_03() {
	// 빙고판
	std::vector<std::vector<int>> num_matrix(5, std::vector<int>(5, 0));
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			std::cin >> num_matrix[i][j];
		}
	}

	// 체크하는 배열
	std::vector<std::vector<int>> isChecked(5, std::vector<int>(5, 0));

	// 엠씨가 불러준 숫자 배열
	std::vector<int> mc_nums(25, 0);
	for (int i = 0; i < 25; i++) {
		std::cin >> mc_nums[i];
	}

	int bingo = 0;
	for (int k = 0; k < 25; k++) {
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (mc_nums[k] == num_matrix[i][j]) {
					isChecked[i][j] = 1;
					if (i == j) {
						if (checkDia1(isChecked)) {
							bingo++;
						}
					}
					if (i + j == 4) {
						if (checkDia2(isChecked)) {
							bingo++;
						}
					}

					if (checkRow(i, j, isChecked) || checkCol(i, j, isChecked)) {
						bingo++;
					}

					if (bingo == 3) {
						std::cout << mc_nums[k] << "\n";
						return 0;
					}
				}
			}
		}
	}

	return 0;
}