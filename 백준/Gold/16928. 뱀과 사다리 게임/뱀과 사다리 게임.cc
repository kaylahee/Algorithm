// 10:32~10:52
// [BOJ_16928] 뱀과 사다리 게임

// 주사위 조작해 내가 원하는 수가 나오게 만들 수 있다면
// 최소 몇번만에 도착점에 도착할 수 있을까.

// 게임은 크기가 10*10이고,
// 총 100개의 칸으로 나누어져 있는 보드판에서 진행된다.

// 보드판에는 1부터 100까지 수가 하나씩 순서대로 적혀져 있다.

// 플레이어는 주사위를 굴려 나온 수만큼 이동해야 한다.
// 100번 칸 넘어간다면 이동 불가

// 사다리 -> 위로 올라감
// 뱀 -> 내려감

// 즉, 사다리 -> 원래 있던 칸의 번보보다 큼
// 뱀 -> 원래 있던 칸의 번호보다 작아짐

#include <iostream>
#include <queue>

int n, m;
int map[101];

int dist[101];
int visited[101];
void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	dist[st] = 0;

	while (!q.empty()) {
		int cNum = q.front();
		q.pop();

		for (int i = 1; i <= 6; i++) {
			int nNum = cNum + i;

			if (nNum > 100) {
				continue;
			}

			if (visited[nNum]) {
				continue;
			}

			if (map[nNum] != 0) {
				visited[nNum] = 1;
				nNum = map[nNum];
			}

			if (visited[nNum]) {
				continue;
			}

			q.push(nNum);
			visited[nNum] = 1;
			dist[nNum] = dist[cNum] + 1;
		}
	}
}

int main() {
	std::cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;

		map[x] = y;
	}

	for (int i = 0; i < m; i++) {
		int u, v;
		std::cin >> u >> v;

		map[u] = v;
	}

	bfs(1);
	std::cout << dist[100] << "\n";
}