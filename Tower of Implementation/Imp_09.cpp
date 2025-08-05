//#include <iostream>
//#include <stack>
//
//int board[8][8];
//
//// 8 ¹æÇâ
//int dy[8] = { -1, 1, 0, 0, -1, 1, -1, 1 };
//int dx[8] = { 0, 0, -1, 1, 1, 1, -1, -1 };
//
//struct Stone {
//	int y;
//	int x;
//	int color;
//};
//
//void print() {
//	for (int i = 7; i >= 0; i--) {
//		for (int j = 0; j <= 7; j++) {
//			if (board[i][j] == 1) {
//				std::cout << "@";
//			}
//			else if (board[i][j] == 2) {
//				std::cout << "O";
//			}
//			else {
//				std::cout << "_";
//			}
//		}
//		std::cout << "\n";
//	}
//}
//
//void findStone(int y, int x, int color) {
//	for (int i = 0; i < 8; i++) {
//		int diry = dy[i];
//		int dirx = dx[i];
//
//		std::stack<Stone> s;
//		s.push({ y, x, color });
//
//		while (1) {
//			int cy = s.top().y;
//			int cx = s.top().x;
//
//			int ny = cy + dirx;
//			int nx = cx + diry;
//
//			if (nx < 0 || nx >= 8 || ny < 0 || ny >= 8) {
//				break;
//			}
//			else {
//				s.push({ ny, nx, board[ny][nx] });
//			}
//
//			if (s.top().color != color) {
//				if (s.top().color == 0) {
//					break;
//				}
//			}
//			else if (s.top().color == color) {
//				while (!s.empty()) {
//					board[s.top().y][s.top().x] = color;
//					s.pop();
//				}
//
//				if (s.empty()) {
//					break;
//				}
//			}
//		}
//	}
//}
//
//int main_Imp_09() {
//	int n;
//	std::cin >> n;
//
//	for (int i = 0; i < n; i++) {
//		int x, y;
//		std::cin >> x >> y;
//
//		board[y][x] = i % 2 + 1;
//		findStone(y, x, board[y][x]);
//	}
//	print();
//	return 0;
//}