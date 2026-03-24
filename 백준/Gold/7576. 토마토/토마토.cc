// 22:00 ~
// BOJ_7576 토마토
// 토마토 : 잘 익은 것 or 아직 익지 않은 것
// 하루 지나면 인접한 곳에 있는 익지 않은 토마토 -> 익게 됨
// 왼, 오, 앞, 뒤 4방향
// 다 익게 되는 최소 일수
// 1 : 익은 토마토
// 0 : 익지 않은 토마토
// -1: 토마토가 들어있지 않은 칸

#include <iostream>
#include <queue>
#include <vector>

int m, n;
int box[1001][1001];
std::queue<std::pair<int, int>> tomatos;

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[1001][1001];
int dist[1001][1001];

void bfs() {
	while (!tomatos.empty()) {
		int cy = tomatos.front().first;
		int cx = tomatos.front().second;
		tomatos.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m) {
				continue;
			}

			if (visited[ny][nx]) {
				continue;
			}

			// 토마토가 들어있지 않은 칸이라면
			if (box[ny][nx] == -1) {
				continue;
			}
			// 토마토가 들어있는 칸이라면
			if (box[ny][nx] == 1) {
				continue;
			}
			
			visited[ny][nx] = 1;
			if (dist[ny][nx] > 0) {
				dist[ny][nx] = std::min(dist[ny][nx], dist[cy][cx] + 1);
			}
			else {
				dist[ny][nx] = dist[cy][cx] + 1;
			}
			tomatos.push({ ny, nx });
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
		}
	}
}

int main() {
	std::cin >> m >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			std::cin >> box[i][j];

			if (box[i][j] == 1) {
				tomatos.push({ i, j });
				visited[i][j] = 1;
			}
		}
	}

	// 저장될 때부터 모든 토마토가 익어있는 상태이면 0을 출력
	if (tomatos.size() == m * n) {
		std::cout << 0 << "\n";
	}
	else {
		bfs();

		bool isAll = true;
		int day = -9999;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (box[i][j] == 0 && dist[i][j] == 0) {
					isAll = false;
					break;
				}
				else {
					day = std::max(day, dist[i][j]);
				}
			}
		}

		// 토마토가 모두 익지는 못하는 상황이면 -1을 출력
		if (!isAll) {
			std::cout << -1 << "\n";
		}
		else {
			std::cout << day << "\n";
		}
	}	

	return 0;
}