// 22:50~23:00
// [BOJ_2667] 단지번호붙이기

// 1 : 집이 있는 곳
// 0 : 집이 없는 곳

// 연결된 집의 모임 : 단지
// 단지에 번호를 붙이려 함

// 상하좌우 연결
// 단지수 출력, 집의 수 출력

// BFS 

#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>

int n;
int map[26][26];

int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };
int visited[26][26];
int bfs(int y, int x) {
	std::queue<std::pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = 1;

	int cnt = 1;
	while (!q.empty()) {
		int cy = q.front().first;
		int cx = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
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
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;
		for (int j = 0; j < n; j++) {
			map[i][j] = str[j] - '0';
		}
	}

	int cnt = 0;
	std::vector<int> house;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && map[i][j] == 1) {
				house.push_back(bfs(i, j));
				cnt++;
			}
		}
	}

	std::cout << cnt << "\n";

	std::sort(house.begin(), house.end());
	for (int h : house) {
		std::cout << h << "\n";
	}

	return 0;
}