// [BOJ_4179] 불!
// 미로에서의 지훈이의 위치와 불이 붙은 위치를 감안해서
// 불에 타기 전에 탈출할 수 있는지의 여부
// 얼마나 빨리 탈출할 수 있는지 결정

// 지훈이와 불은 매 분마다 한칸씩 수평 또는 수직으로 이동
// => 상 하 좌 우

// 불은 각 지점에서 4방향으로 확산
// 지훈이는 미로의 가장자리에 접한 공간에서 탈출할 수 있다.

// 지훈이와 불은 벽이 있는 공간 통과 X

#include <iostream>
#include <string>
#include <vector>
#include <queue>

int r, c;
char map[1001][1001];

int jy, jx;
std::vector<std::pair<int, int>> fire_pos;

int visited[1001][1001];
int fired[1001][1001];
int time_val[1001][1001];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
bool bfs(int sy, int sx) {
	std::queue<std::pair<int, int>> q;
	q.push({ sy, sx });
	visited[sy][sx] = 1;
	time_val[sy][sx] = 0;

	while (!q.empty()) {
		std::queue <std::pair<int, int>> new_fire_pos;
		for (std::pair<int, int> f : fire_pos) {
			int fy = f.first;
			int fx = f.second;

			for (int i = 0; i < 4; i++) {
				int nfy = fy + dy[i];
				int nfx = fx + dx[i];

				if (nfy < 0 || nfy >= r || nfx < 0 || nfx >= c) {
					continue;
				}

				if (visited[nfy][nfx]) {
					continue;
				}

				if (fired[nfy][nfx]) {
					continue;
				}

				if (map[nfy][nfx] == '#') {
					continue;
				}

				new_fire_pos.push({ nfy, nfx });
				fired[nfy][nfx] = 1;
			}
		}
		
		fire_pos.clear();
		while (!new_fire_pos.empty()) {
			int fy = new_fire_pos.front().first;
			int fx = new_fire_pos.front().second;
			new_fire_pos.pop();

			fire_pos.push_back({ fy, fx });
		}

		std::queue <std::pair<int, int>> new_J_pos;
		new_J_pos = q;
		while (!new_J_pos.empty()) {
			int cy = new_J_pos.front().first;
			int cx = new_J_pos.front().second;
			new_J_pos.pop();
			q.pop();

			for (int i = 0; i < 4; i++) {
				int ny = cy + dy[i];
				int nx = cx + dx[i];

				if (ny < 0 || ny >= r || nx < 0 || nx >= c) {
					std::cout << time_val[cy][cx] + 1 << "\n";
					return true;
				}

				if (visited[ny][nx]) {
					continue;
				}

				if (fired[ny][nx]) {
					continue;
				}

				if (map[ny][nx] == '#') {
					continue;
				}

				q.push({ ny, nx });
				visited[ny][nx] = 1;
				time_val[ny][nx] = time_val[cy][cx] + 1;
			}
		}
	}

	return false;
}

int main() {
	std::cin >> r >> c;
	for (int i = 0; i < r; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < c; j++) {
			map[i][j] = str[j];

			if (str[j] == 'F') {
				fire_pos.push_back({ i, j });
				fired[i][j] = 1;
			}
			else if (str[j] == 'J') {
				jy = i;
				jx = j;
			}
		}
	}

	if (!bfs(jy, jx)) {
		std::cout << "IMPOSSIBLE\n";
	}

	return 0;
}