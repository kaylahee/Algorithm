//#include <iostream>
//#include <vector>
//#include <queue>
//
//int n;
//int map[10][10] = { 0 };
//
//int dy[4] = { -1, 1, 0, 0 };
//int dx[4] = { 0, 0, -1, 1 };
//
//struct Square {
//	int color;
//	int y1;
//	int x1;
//	int y2;
//	int x2;
//};
//
//void print() {
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n; j++) {
//			std::cout << map[i][j] << " ";
//		}
//		std::cout << "\n";
//	}
//}
//
//void color(Square sq) {
//	int y_dif = abs(sq.y1 - sq.y2);
//	int x_dif = abs(sq.x1 - sq.x2);
//
//	int sy = sq.y1 > sq.y2 ? sq.y2 : sq.y1;
//	int sx = sq.x1 > sq.x2 ? sq.x2 : sq.x1;
//	for (int i = sy; i <= sy + y_dif; i++) {
//		for (int j = sx; j <= sx + x_dif; j++) {
//			if (map[i][j] <= sq.color) {
//				map[i][j] = sq.color;
//			}
//		}
//	}
//}
//
//int findSquare(int y, int x, int l, int color) {
//	/*std::cout << "original l : " << l << "\n";*/
//	int cnt = 0;
//	for (int i = y; i < y + l; i++) {
//		for (int j = x; j < x + l; j++) {
//			if (color != map[i][j]) {
//				return cnt;
//			}
//			else {
//				/*std::cout << l << "\n";
//				std::cout << i << " " << j << "\n";*/
//				cnt++;
//			}
//		}
//	}
//	return cnt;
//}
//
//int main_Imp_07() {
//	std::cin >> n;
//
//	int q;
//	std::cin >> q;
//
//	std::vector<Square> arr(q);
//	for (int i = 0; i < q; i++) {
//		Square sq;
//		std::cin >> sq.color >> sq.y1 >> sq.x1 >> sq.y2 >> sq.x2;
//		arr[i] = sq;
//	}
//
//	for (int i = 0; i < q; i++) {
//		color(arr[i]);
//		/*print();
//		std::cout << "\n";*/
//	}
//
//	int max = 0;
//	for (int i = 0; i < q; i++) {
//		Square sq = arr[i];
//		int y_dif = abs(sq.y1 - sq.y2);
//		int x_dif = abs(sq.x1 - sq.x2);
//		int l = y_dif > x_dif ? x_dif : y_dif;
//
//		int sy = sq.y1 > sq.y2 ? sq.y2 : sq.y1;
//		int sx = sq.x1 > sq.x2 ? sq.x2 : sq.x1;
//
//		for (int tmp = l + 1; tmp >= 1; tmp--) {
//			for (int j = sy; j < sy + l + 1; j++) {
//				for (int k = sx; k < sx + l + 1; k++) {
//					// 각 좌표마다 정사각형 찾기
//					int res = findSquare(j, k, tmp, arr[i].color);
//					if (res != 0) {
//						/*std::cout << arr[i].color << "\n---------------\n";*/
//						max = std::max(max, res);
//					}
//				}
//			}
//		}
//		/*std::cout << "\n";*/
//	}
//	std::cout << max;
//	return 0;
//}