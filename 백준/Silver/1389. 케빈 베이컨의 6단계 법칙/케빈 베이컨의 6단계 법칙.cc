#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n, m;
std::vector<int> user[101];

int visited[101];
int dist[101];

void init() {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
		dist[i] = 0;
	}
}

void bfs(int st) {
	init();

	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	dist[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i < user[cur].size(); i++) {
			int nxt = user[cur][i];

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
	std::cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;

		user[a].push_back(b);
		user[b].push_back(a);
	}

	int minSum = 21e8;
	std::vector<int> student;
	for (int i = 1; i <= n; i++) {
		bfs(i);

		int sum = 0;
		for (int j = 1; j <= n; j++) {
			sum += dist[j];
		}
		if (sum < minSum) {
			minSum = sum;
		}
	
		student.push_back(sum);
	}

	for (int i = 0; i < student.size(); i++) {
		if (minSum == student[i]) {
			std::cout << i + 1 << "\n";
			break;
		}
	}

	return 0;
}