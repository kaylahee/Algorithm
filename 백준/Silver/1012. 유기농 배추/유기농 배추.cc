// 22:45
// [BOJ_1012] 유기농 배추

// 지렁이 : 인접한 배추로 상하좌우 4방향 이동
// 0 : 배추 심어져 있지 않은 땅
// 1 : 배추가 심어져 있는 땅

// 테스트 케이스 t
// m(1 <= m <= 50)
// n(1 <= n <= 50)
// 배추 위치 개수 k

#include <iostream>
#include <queue>

int m, n;
int k;

int map[51][51];
std::queue<std::pair<int, int>> q;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[51][51];

int region = 1;
void bfs(int sy, int sx) {
	q.push({ sy, sx });
	visited[sy][sx] = 1;

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
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		std::cin >> m >> n >> k;
		init();
		for (int i = 0; i < k; i++) {
			int x, y;
			std::cin >> x >> y;
			map[y][x] = 1;
		}

		int region_cnt = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (!visited[i][j] && map[i][j] == 1) {
					bfs(i, j);
					region_cnt++;
				}
				//std::cout << map[i][j] << " ";
			}
			//std::cout << "\n";
		}
		std::cout << region_cnt << "\n";
	}

	return 0;
}