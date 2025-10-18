#include <iostream>
#include <queue>

int n, m;
int map[301][301];
int tmp[301][301];

int visited[301][301];

int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cout << tmp[i][j] << " ";
		}
		std::cout << "\n";
	}
	std::cout << "\n";
}

int visited2[301][301];
void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			visited2[i][j] = 0;
			map[i][j] = tmp[i][j];
		}
	}
}

// 덩어리 확인하기 위한 함수
void checkTwoSpace(int st_y, int st_x) {
	std::queue<std::pair<int, int>> q;
	q.push({ st_y, st_x });
	visited2[st_y][st_x] = 1;

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

			if (map[ny][nx] == 0) {
				continue;
			}

			if (visited2[ny][nx]) {
				continue;
			}

			q.push({ ny, nx });
			map[ny][nx] = 0;
			visited2[ny][nx] = 1;
		}
	}
}

// 1년 후 덩어리 확인 함수
int check() {
	init();
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] != 0) {
				checkTwoSpace(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

// 빙하 녹이는 함수
void bfs(int st_y, int st_x) {
	std::queue<std::pair<int, int>> q;
	q.push({ st_y, st_x });
	visited[st_y][st_x] = 1;

	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		int sea_cnt = 0;
		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			if (visited[ny][nx]) {
				continue;
			}

			// 주변 칸이 바다라면
			if (tmp[ny][nx] == 0) {
				sea_cnt++;
				continue;
			}

			q.push({ ny, nx });
			visited[ny][nx] = 1;
		}
		if (tmp[cy][cx] > 0) {
			tmp[cy][cx] -= sea_cnt;

			if (tmp[cy][cx] < 0) {
				tmp[cy][cx] = 0;
			}
		}
	}
}

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> map[i][j];
			tmp[i][j] = map[i][j];
		}
	}

	int year = 0;

	bool flag = false;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] > 0) {
				bfs(i, j);
				year++;
				if (check() >= 2) {
					flag = true;
					break;
				}
				init();
			}
		}
		if (flag) {
			break;
		}
	}

	if (flag) {
		std::cout << year;
	}
	else {
		std::cout << 0;
	}

	return 0;
}