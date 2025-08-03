//#include <iostream>
//#include <vector>
//#include <string>
//
//int n, m;
//std::vector<std::string> first_status;
//
//bool isValid(int y, int x) {
//	if (y < 0 || y >= n || x < 0 || x >= m) {
//		return false;
//	}
//	return true;
//}
//
//void print() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			std::cout << first_status[i][j];
//		}
//		std::cout << "\n";
//	}
//}
//
//void bomb(int y, int x, int k) {
//	for (int i = y; i <= y + k; i++) {
//		if (isValid(i, x) && first_status[i][x] != '@') {
//			if (first_status[i][x] == '#') {
//				break;
//			}
//			first_status[i][x] = '%';
//		}
//	}
//
//	for (int i = y; i >= y - k; i--) {
//		if (isValid(i, x) && first_status[i][x] != '@') {
//			if (first_status[i][x] == '#') {
//				break;
//			}
//			first_status[i][x] = '%';
//		}
//	}
//
//	for (int i = x; i <= x + k; i++) {
//		if (isValid(y, i) && first_status[y][i] != '@') {
//			if (first_status[y][i] == '#') {
//				break;
//			}
//			first_status[y][i] = '%';
//		}
//	}
//
//	for (int i = x; i >= x - k; i--) {
//		if (isValid(y, i) && first_status[y][i] != '@') {
//			if (first_status[y][i] == '#') {
//				break;
//			}
//			first_status[y][i] = '%';
//		}
//	}
//}
//
//int main_imp_05() {
//	// ����, ���� ũ�� �Է�
//	std::cin >> n >> m;
//	// ȭ�� �Է�
//	int k;
//	std::cin >> k;
//
//	// �ʱ� ���� �� ���� �Է�
//	for (int i = 0; i < n; i++) {
//		std::string a;
//		std::cin >> a;
//		first_status.push_back(a);
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			// ��ź�̶��
//			if (first_status[i][j] == '@') {
//				bomb(i, j, k);
//				first_status[i][j] = '%';
//			}
//		}
//	}
//
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < m; j++) {
//			std::cout << first_status[i][j];
//		}
//		std::cout << "\n";
//	}
//
//	return 0;
//}