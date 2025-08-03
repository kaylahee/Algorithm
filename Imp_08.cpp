#include <iostream>

int map[6][6];
int startx;

void paint_leftUp(int y, int x, int num);
void paint_rightUp(int y, int x, int num);
void paint_leftDown(int y, int x, int num);
void paint_rightDown(int y, int x, int num);

void print() {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 6; j++) {
			if (map[i][j] == 0) {
				std::cout << "_";
			}
			else {
				std::cout << map[i][j];
			}
		}
		std::cout << "\n";
	}
}

void paint_leftUp(int y, int x, int num) {
	int j = x;

	for (int i = y; i >= 0; i--) {
		if (map[i][j] == 0) {
			map[i][j] = num;
		}
		else {
			if (map[i][j] > num) {
				map[i][j] = num;
			}
		}
		num++;

		if (i == 0 && j == 0) {
			paint_rightDown(i + 1, j + 1, num);
			break;
		}
		else if (i == 0) {
			paint_leftDown(i + 1, j - 1, num);
			break;
		}
		else if (j == 0) {
			paint_rightUp(i - 1, j + 1, num);
			break;
		}
		j--;
	}
}

void paint_rightUp(int y, int x, int num) {
	int j = x;
	for (int i = y; i >= 0; i--) {
		if (map[i][j] == 0) {
			map[i][j] = num;
		}
		else {
			if (map[i][j] > num) {
				map[i][j] = num;
			}
		}
		num++;

		if (i == 0 && j == 5) {
			paint_leftDown(i + 1, j - 1, num);
			break;
		}
		else if (i == 0) {
			paint_rightDown(i + 1, j + 1, num);
			break;
		}
		else if (j == 5) {
			paint_leftUp(i - 1, j - 1, num);
			break;
		}
		j++;
	}
}


void paint_rightDown(int y, int x, int num) {
	int j = x;
	for (int i = y; i < 6; i++) {
		if (map[i][j] == 0) {
			map[i][j] = num;
		}
		else {
			if (map[i][j] > num) {
				map[i][j] = num;
			}
		}
		num++;

		if (i == 5 && j == 5) {
			if (startx == j) {
				return;
			}
			paint_leftUp(i - 1, j - 1, num);
			break;
		}
		else if (i == 5) {
			if (startx == j) {
				return;
			}
			paint_rightUp(i - 1, j + 1, num);
			break;
		}
		else if (j == 5) {
			paint_leftDown(i + 1, j - 1, num);
			break;
		}
		j++;
	}
}

void paint_leftDown(int y, int x, int num) {
	int j = x;
	for (int i = y; i < 6; i++) {
		if (map[i][j] == 0) {
			map[i][j] = num;
		}
		else {
			if (map[i][j] > num) {
				map[i][j] = num;
			}
		}
		num++;

		if (i == 5 && j == 0) {
			if (startx == j) {
				return;
			}
			paint_rightUp(i - 1, j + 1, num);
			break;
		}
		else if (i == 5) {
			if (startx == j) {
				return;
			}
			paint_leftUp(i - 1, j - 1, num);
			break;
		}
		else if (j == 0) {
			paint_rightDown(i + 1, j + 1, num);
			break;
		}

		j--;
	}
}

int main_Imp_08() {
	int t;
	std::cin >> t;

	for (int i = 0; i < t; i++) {
		int x;
		char dir;
		std::cin >> x >> dir;

		if (dir == 'R') {
			startx = x;

			paint_rightUp(5, x, 1);
		}
		else {
			startx = x;
			paint_leftUp(5, x, 1);
		}
	}

	print();


	return 0;
}