// 16:32~
// [BOJ_2589] 보물섬

// 각 칸은 육지나 바다로 표시되어 있다.
// 이동은 상하좌우로 이웃한 육지로만 가능하며,
// 한 칸 이동하는데 한 시간이 걸린다.

// 보물은 서로 간에 최단 거리로 이동하는 데 있어
// 가장 긴 시간이 걸리는 육지 두 곳에 나뉘어 묻혀있다.

// 육지를 나타내는 두 곳 사이를 최단 거리로 이동하려면
// 같은 곳을 두 번 이상 지나가거나, 멀리 돌아가서는 안된다.

#include <iostream>
#include <string>
#include <queue>

int n, m;
char map[51][51];

int visited[51][51];
int dist[51][51];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

int maxDist = 0;
void bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	dist[sy][sx] = 0;

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

			if (map[ny][nx] == 'W') {
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = 1;
			dist[ny][nx] = dist[cy][cx] + 1;
		}
	}

	// std::cout << "dist\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			// std::cout << dist[i][j] << " ";
			if (maxDist < dist[i][j]) {
				maxDist = dist[i][j];
			}
		}
		// std::cout << "\n";
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			dist[i][j] = 0;
		}
	}
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < m; j++) {
			map[i][j] = str[j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'W') {
				continue;
			}

			init();
			bfs(i, j);
		}
	}

	std::cout << maxDist << "\n";

	return 0;
}