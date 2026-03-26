// 22:27~
// [BOJ_2583] 영역 구하기

// k개의 직사각형을 그릴 때
// 이들 k개의 직사각형의 내부를 제외한 나머지 부분이 몇개의 분리된 영역으로 나누어짐
// 칠한 직사각형을 1로 놓고
// 나머지를 0이라고 한다면, 0의 영역의 넓이를 구하면 될듯

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

int m, n, k;
int map[101][101];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[101][101];

int bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;

	int width = 0;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		width++;
		for (int d = 0; d < 4; d++) {
			int ny = cy + dy[d];
			int nx = cx + dx[d];

			if (ny < 0 || ny >= m || nx < 0 || nx >= n) {
				continue;
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
	return width;
}

int main() {
	std::cin >> m >> n >> k;
	for (int i = 0; i < k; i++) {
		int ld_x, ld_y, ru_x, ru_y;
		std::cin >> ld_x >> ld_y >> ru_x >> ru_y;

		for (int col = ld_y; col < ru_y; col++) {
			for (int row = ld_x; row < ru_x; row++) {
				map[col][row] = 1;
			}
		}
	}

	int region_cnt = 0;
	std::vector<int> regions;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 0) {
				region_cnt++;
				regions.push_back(bfs(i, j));
			}
			//std::cout << map[i][j] << " ";
		}
		//std::cout << "\n";
	}
	std::sort(regions.begin(), regions.end());

	std::cout << region_cnt << "\n";
	for (int i : regions) {
		std::cout << i << " ";
	}
	return 0;
}