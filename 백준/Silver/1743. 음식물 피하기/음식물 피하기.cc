#include <iostream>
#include <queue>
#include <algorithm>

int n, m;
int k;

int map[101][101];

int visited[101][101];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	int cnt = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			if (visited[ny][nx]) {
				continue;
			}

			if (map[ny][nx] == 0) {
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			cnt++;
		}
	}
	return cnt;
}

int main() {
	std::cin >> n >> m;
	std::cin >> k;

	for (int i = 0; i < k; i++) {
		int r, c;
		std::cin >> r >> c;

		map[r - 1][c - 1] = 1;
	}

	int maxWidth = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1) {
				// std::cout << bfs(i, j) << "\n";
				maxWidth = std::max(maxWidth, bfs(i, j));
			}
		}
	}
	std::cout << maxWidth << "\n";

	return 0;
}