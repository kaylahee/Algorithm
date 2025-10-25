#include <iostream>
#include <vector>
#include <queue>

int n, m, k, x;
std::vector<int> road[300001];

int dist[300001];
int visited[300001];
void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	dist[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < road[cur].size(); i++) {
			int nxt = road[cur][i];

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
	std::cin >> n >> m >> k >> x;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;

		road[a].push_back(b);
	}

	bfs(x);

	bool flag = false;
	for (int i = 1; i <= n; i++) {
		if (dist[i] == k) {
			std::cout << i << "\n";
			flag = true;
		}
	}

	if (!flag) {
		std::cout << -1 << "\n";
	}

	return 0;
}