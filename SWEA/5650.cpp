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
//// ���� ������
//int reverse(int cur_dir) {
//	// �� -> ��
//	if (cur_dir == 0) {
//		cur_dir = 1;
//	}
//	// �� -> ��
//	else if (cur_dir == 1) {
//		cur_dir = 0;
//	}
//	// �� -> ��
//	else if (cur_dir == 2) {
//		cur_dir = 3;
//	}
//	// �� -> ��
//	else if (cur_dir == 3) {
//		cur_dir = 2;
//	}
//
//	return cur_dir;
//}
//
//// �ﰢ�� ������ ���
//int meetTriangle(int num, int cur_dir) {
//	// 1�� �ﰢ�� ������ ���
//	if (num == 1) {
//		// �� -> ��
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// �� -> ��
//		else if (cur_dir == 1) {
//			cur_dir = 3;
//		}
//		// �� -> ��
//		else if (cur_dir == 2) {
//			cur_dir = 0;
//		}
//		// �� -> ��
//		else if (cur_dir == 3) {
//			cur_dir = 2;
//		}
//	}
//	// 2�� �ﰢ�� ������ ���
//	else if (num == 2) {
//		// �� -> ��
//		if (cur_dir == 0) {
//			cur_dir = 3;
//		}
//		// �� -> ��
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// �� -> ��
//		else if (cur_dir == 2) {
//			cur_dir = 1;
//		}
//		// �� -> ��
//		else if (cur_dir == 3) {
//			cur_dir = 2;
//		}
//	}
//	// 3�� �ﰢ�� ������ ���
//	else if (num == 3) {
//		// �� -> ��
//		if (cur_dir == 0) {
//			cur_dir = 2;
//		}
//		// �� -> ��
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// �� -> ��
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// �� -> ��
//		else if (cur_dir == 3) {
//			cur_dir = 1;
//		}
//	}
//	// 4�� �ﰢ�� ������ ���
//	else if (num == 4) {
//		// �� -> ��
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// �� -> ��
//		else if (cur_dir == 1) {
//			cur_dir = 2;
//		}
//		// �� -> ��
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// �� -> ��
//		else if (cur_dir == 3) {
//			cur_dir = 0;
//		}
//	}
//	else if (num == 5) {
//		// �� -> ��
//		if (cur_dir == 0) {
//			cur_dir = 1;
//		}
//		// �� -> ��
//		else if (cur_dir == 1) {
//			cur_dir = 0;
//		}
//		// �� -> ��
//		else if (cur_dir == 2) {
//			cur_dir = 3;
//		}
//		// �� -> ��
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
//		// ��ǥ�� ���� ���
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
//			// �ﰢ�� Ȥ�� ��ϰ� �ε���
//			else if (val >= 1 && val <= 5) {
//				// ���� �ٲ��ֱ�
//				dir = meetTriangle(val, dir);
//				// ���� ���ϱ�
//				sum++;
//			}
//			// ��Ȧ
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
//		// ���� ��ġ�� ���ƿ� ��� / ��Ȧ�� ��� �� ����
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