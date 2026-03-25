// 21:36~
// [BOJ_1926] 그림

// 그림의 개수
// 넓이가 가장 넓은 것의 넓이

// 그림 = 1로 연결된 것을 한 그림
// 가로나 세로로 연결된 것은 연결이 된 것
// 대각선은 떨어진 그림

// => 상하좌우 방향으로 인접한 영역의 개수를 찾는 것

#include <iostream>
#include <queue>

int n, m;
int map[501][501];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[501][501];

int bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	int cnt = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		cnt++;
		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

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
		}
	}
	return cnt;
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
		}
	}

	int region_cnt = 0;
	int region = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				region_cnt++;
				region = std::max(region, bfs(i, j));
			}
		}
	}
	std::cout << region_cnt << "\n" << region << "\n";

	return 0;
}