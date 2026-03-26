// 22:55~23:04
// [BOJ_7562] 나이트의 이동

// 나이트가 이동할 수 있는
// 보통의 문제처럼 4방향이 아님

// 8방향

// 방향만 다르게 해주면 나머지는 동일

#include <iostream>
#include <queue>

int l;
int map[301][301];
int sy, sx, ey, ex;

int dy[8] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dx[8] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int dist[301][301];
int visited[301][301];

void bfs() {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	dist[sy][sx] = 0;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		if (cy == ey && cx == ex) {
			return;
		}

		for (int i = 0; i < 8; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= l || nx < 0 || nx >= l) {
				continue;
			}
			if (visited[ny][nx]) {
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}
}

void init() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			dist[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		std::cin >> l;
		std::cin >> sy >> sx >> ey >> ex;

		bfs();
		std::cout << dist[ey][ex] << "\n";

		init();
	}

	return 0;
}