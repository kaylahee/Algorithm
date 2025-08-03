//#include <iostream>
//#include <algorithm>
//#include <vector>
//
//int dx[4] = { 0, 0, -1, 1 };
//int dy[4] = { -1, 1, 0, 0 };
//
//int n;
//int map[101][101];
//
//std::vector<std::pair<int, int>> warmhole[11];
//
//// ¹æÇâ µÚÁý±â
//int reverse(int cur_dir) {
//	// »ó -> ÇÏ
//	if (cur_dir == 0) {
//		cur_dir = 1;
//	}
//	// ÇÏ -> »ó
//	else if (cur_dir == 1) {
//		cur_dir = 0;
//	}
//	// ÁÂ -> ¿ì
//	else if (cur_dir == 2) {
//		cur_dir = 3;
//	}
//	// ¿ì -> ÁÂ
//	else if (cur_dir == 3) {
//		cur_dir = 2;
//	}
//
//	return cur_dir;
//}
//
//// »ï°¢Çü ¸¸³µÀ» °æ¿ì
//int meetTriangle(int num, int cur_dir) {
//	// 1¹ø »ï°¢Çü ¸¸³µÀ» °æ¿ì
//	if (num == 1) {
//		// »ó -> ÇÏ
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// ÇÏ -> ¿ì
//		else if (cur_dir == 1) {
//			cur_dir = 3;
//		}
//		// ÁÂ -> »ó
//		else if (cur_dir == 2) {
//			cur_dir = 0;
//		}
//		// ¿ì -> ÁÂ
//		else if (cur_dir == 3) {
//			cur_dir = 2;
//		}
//	}
//	// 2¹ø »ï°¢Çü ¸¸³µÀ» °æ¿ì
//	else if (num == 2) {
//		// »ó -> ¿ì
//		if (cur_dir == 0) {
//			cur_dir = 3;
//		}
//		// ÇÏ -> »ó
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// ÁÂ -> ÇÏ
//		else if (cur_dir == 2) {
//			cur_dir = 1;
//		}
//		// ¿ì -> ÁÂ
//		else if (cur_dir == 3) {
//			cur_dir = 2;
//		}
//	}
//	// 3¹ø »ï°¢Çü ¸¸³µÀ» °æ¿ì
//	else if (num == 3) {
//		// »ó -> ÁÂ
//		if (cur_dir == 0) {
//			cur_dir = 2;
//		}
//		// ÇÏ -> »ó
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// ÁÂ -> ¿ì
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// ¿ì -> ÇÏ
//		else if (cur_dir == 3) {
//			cur_dir = 1;
//		}
//	}
//	// 4¹ø »ï°¢Çü ¸¸³µÀ» °æ¿ì
//	else if (num == 4) {
//		// »ó -> ÇÏ
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// ÇÏ -> ÁÂ
//		else if (cur_dir == 1) {
//			cur_dir = 2;
//		}
//		// ÁÂ -> ¿ì
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// ¿ì -> »ó
//		else if (cur_dir == 3) {
//			cur_dir = 0;
//		}
//	}
//	else if (num == 5) {
//		// »ó -> ÇÏ
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// ÇÏ -> »ó
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// ÁÂ -> ¿ì
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// ¿ì -> ÁÂ
//		else if (cur_dir == 3) {
//			cur_dir = 2;
//		}
//	}
//
//	return cur_dir;
//}
//
//int game(int cy, int cx, int dir) {
//	int startX = cx;
//	int startY = cy;
//
//	cx += dx[dir];
//	cy += dy[dir];
//
//	int sum = 0;
//	while (true) {
//		// ÁÂÇ¥°¡ º®ÀÏ °æ¿ì
//		if (cx < 0 || cx >= n || cy < 0 || cy >= n) {
//			dir = reverse(dir);
//			cy += dy[dir];
//			cx += dx[dir];
//			sum++;
//		}
//
//		int val = map[cy][cx];
//
//		if (val != 0) {
//			if (val == -1) {
//				break;
//			}
//			// »ï°¢Çü È¤Àº ºí·Ï°ú ºÎµúÈû
//			else if (val >= 1 && val <= 5) {
//				// ¹æÇâ ¹Ù²ãÁÖ±â
//				dir = meetTriangle(val, dir);
//				// Á¡¼ö ´õÇÏ±â
//				sum++;
//			}
//			// ¿úÈ¦
//			else if (val >= 6 && val <= 10) {
//				if (warmhole[val][0].first == cy && warmhole[val][0].second == cx) {
//					cy = warmhole[val][1].first;
//					cx = warmhole[val][1].second;
//				}
//				else {
//					cy = warmhole[val][0].first;
//					cx = warmhole[val][0].second;
//				}
//			}
//		}
//		// ½ÃÀÛ À§Ä¡·Î µ¹¾Æ¿Â °æ¿ì / ºí·¢È¦ÀÏ °æ¿ì º¼ ¸ØÃã
//		if (startX == cx && startY == cy) {
//			break;
//		}
//
//		cx += dx[dir];
//		cy += dy[dir];
//	}
//
//	return sum;
//}
//
//int main_5650() {
//	//freopen("input.txt", "r", stdin);
//
//	int t;
//	std::cin >> t;
//
//	for (int tc = 1; tc <= t; tc++) {
//		std::cin >> n;
//
//		for (int i = 6; i <= 10; i++) {
//			warmhole[i].clear();
//		}
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				std::cin >> map[i][j];
//
//				if (map[i][j] >= 6) {
//					warmhole[map[i][j]].push_back({i, j});
//				}
//			}
//		}
//
//		int k = 0;
//		int max_score = 0;
//		for (int i = 0; i < n; i++) {
//			for (int j = 0; j < n; j++) {
//				if (map[i][j] != 0) {
//					continue;
//				}
//
//				for (int k = 0; k < 4; k++) {
//					max_score = std::max(max_score, game(i, j, k));
//				}
//
//			}
//		}
//
//		std::cout << "#" << tc << " " << max_score << "\n";
//	}
//
//	return 0;
//}