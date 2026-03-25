// 21:46~
// [BOJ_2178] 미로 탐색

// 1: 이동할 수 있는 칸
// 0: 이동할 수 없는 칸

// (1, 1)에서 출발 -> (n, m)의 위치로 지나야 하는 최소 칸 수

// 한 칸에서 다른 칸으로 이동할 때 서로 인접한 칸만 이동 가능

#include <iostream>
#include <string>
#include <queue>

int n, m;
int map[101][101];

void print_map() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[101][101];
int dist[101][101];

void bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	dist[sy][sx] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

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
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;

		for (int j = 0; j < m; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	std::cout << dist[n - 1][m - 1] << "\n";
	return 0;
}