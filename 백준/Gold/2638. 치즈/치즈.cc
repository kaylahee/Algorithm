// 23:56~12:18
// [BOJ_2638] 치즈

#include <iostream>
#include <vector>
#include <queue>
	
int n, m;
int map[101][101];
int will_melt[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[101][101];

void print_map() {
	std::cout << "map: \n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

bool checkAir(int y, int x) {
	init();

	std::queue<std::pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				return true;
			}

			if (visited[ny][nx]) {
				continue;
			}

			if (map[ny][nx] == 1) {
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
	}

	return false;
}

bool check4Dir(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];

		if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
			cnt++;
			continue;
		}

		if (map[ny][nx] == 0 && checkAir(ny, nx)) {
			cnt++;
		}
	}

	if (cnt >= 2) {
		return true;
	}
	return false;
}

int main() {
	std::cin >> n >> m;

	int total_cheese = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];

			if (map[i][j] == 1) {
				total_cheese++;
			}
		}
	}

	int t = 0;
	while (total_cheese != 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (map[i][j] == 1) {
					if (check4Dir(i, j)) {
						will_melt[i][j] = 1;
					}
				}
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (will_melt[i][j] == 1) {
					map[i][j] = 0;
					will_melt[i][j] = 0;
					total_cheese--;
				}
			}
		}

		//print_map();

		t++;
	}
	std::cout << t << "\n";

	return 0;
}