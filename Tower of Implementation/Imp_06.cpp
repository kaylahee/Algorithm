//#include <iostream>
//
//int board[19][19];
//
//bool isValid(int y, int x) {
//	if (y < 0 || y >= 19 || x < 0 || x >= 19) {
//		return false;
//	}
//	return true;
//}
//
//int check(int y, int x, int color) {
//	bool flag1 = true;
//	bool flag2 = true;
//	bool flag3 = true;
//	bool flag4 = true;
//
//	int cnt1 = 0;
//	int cnt2 = 0;
//	int cnt3 = 0;
//	int cnt4 = 0;
//
//	// 가로 확인
//	for (int i = x; i < 18; i++) {
//		if (color == board[y][i] && board[y][i] == board[y][i + 1]) {
//			cnt1++;
//		}
//		else {
//			break;
//		}
//	}
//	if (cnt1 == 4) {
//		flag1 = true;
//	}
//	else {
//		flag1 = false;
//	}
//
//	// 세로 확인
//	for (int i = y; i < 18; i++) {
//		if (color == board[i][x] && board[i][x] == board[i + 1][x]) {
//			cnt2++;
//		}
//		else {
//			break;
//		}
//	}
//
//	if (cnt2 == 4) {
//		flag2 = true;
//	}
//	else {
//		flag2 = false;
//	}
//
//	// 오른쪽 대각선 확인
//	int j = x;
//	for (int i = y; i < 18; i++) {
//		if (j < 18) {
//			if (color == board[i][j] && board[i][j] == board[i + 1][j + 1]) {
//				cnt3++;
//			}
//			else {
//				break;
//			}
//		}
//		j++;
//	}
//	if (cnt3 == 4) {
//		flag3 = true;
//	}
//	else {
//		flag3 = false;
//	}
//
//	// 왼쪽 대각선 확인
//	int k = x;
//	for (int i = y; i < 18; i++) {
//		if (k >= 0) {
//			if (color == board[i][k] && board[i][k] == board[i + 1][k - 1]) {
//				cnt4++;
//			}
//			else {
//				break;
//			}
//		}
//		k--;
//	}
//	if (cnt4 == 4) {
//		flag4 = true;
//	}
//	else {
//		flag4 = false;
//	}
//
//	/*std::cout << y << " " << x << "\n";
//	std::cout << cnt1 << " " << cnt2 << " " << cnt3 << " " << cnt4<< "\n";
//	std::cout << flag1 << " " << flag2 << " " << flag3 << " " << flag4 << "\n";
//	std::cout << "---------------------------------------------------\n";*/
//
//	if (cnt1 == 5 || cnt2 == 5 || cnt3 == 5 || cnt4 == 5) {
//		return 6;
//	}
//
//	if (flag1 || flag2 || flag3 || flag4) {
//		if (flag4) {
//			return 2;
//		}
//		return 1;
//	}
//	return 0;
//}
//
//int main_06() {
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			std::cin >> board[i][j];
//		}
//	}
//
//	for (int i = 0; i < 19; i++) {
//		for (int j = 0; j < 19; j++) {
//			if (board[i][j] == 0) {
//				continue;
//			}
//			// 0이 아닐 경우만 체크
//			int num = check(i, j, board[i][j]);
//			if (num == 1) {
//				std::cout << board[i][j] << "\n";
//				std::cout << i + 1 << " " << j + 1;
//				return 0;
//			}
//			else if (num == 2) {
//				std::cout << board[i][j] << "\n";
//				std::cout << i + 5 << " " << j - 3;
//				return 0;
//			}
//			else if (num == 6){
//				std::cout << 0;
//				return 0;
//			}
//		}
//	}
//
//	std::cout << 0;
//	return 0;
//}