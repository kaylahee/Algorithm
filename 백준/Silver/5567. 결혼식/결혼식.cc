#include <iostream>
#include <vector>
#include <queue>

int n, m;
std::vector<int> friendship[501];

int visited[501];
int dist[501];
void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	dist[st] = 1;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < friendship[cur].size(); i++) {
			int nxt = friendship[cur][i];

			if (visited[nxt]) {
				continue;
			}

			q.push(nxt);
			visited[nxt] = 1;
			dist[nxt] = dist[cur] + 1;
		}
	}
}

int main() {
	std::cin >> n;
	std::cin >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;

		friendship[a].push_back(b);
		friendship[b].push_back(a);
	}

	bfs(1);

	int cnt = 0;
	for (int i = 2; i <= 500; i++) {
		if (visited[i] && dist[i] <= 3) {
			cnt++;
		}
	}
	std::cout << cnt << "\n";

	return 0;
}