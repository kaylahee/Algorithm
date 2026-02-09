// [BOJ_13913] 숨바꼭질 4
// 수빈이는 점 n에 있고, 동생은 점 k에 있다.
// 수빈이는 걷거나 순간이동이 가능하다.
// 수빈이의 위치가 x일때
	// 걷는다면 x-1, x+1
	// 순간이동 x*2
// 수빈이와 동생의 위치가 주어졌을 때
// 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지

// BFS + 경로찾기

#include <iostream>
#include <queue>
#include <stack>

int n, k;

int visited[200001];
int dist[200001];

int path[200001];
int val[3] = { 2, -1, 1 };

void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	dist[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			return;
		}

		for (int i = 0; i < 3; i++) {
			if (i >= 1) {
				if (cur + val[i] < 0 || cur + val[i] >= 200001) {
					continue;
				}

				if (visited[cur + val[i]]) {
					continue;
				}
				
				q.push(cur + val[i]);
				visited[cur + val[i]] = 1;
				dist[cur + val[i]] = dist[cur] + 1;
				path[cur + val[i]] = cur;
			}
			else {
				if (cur * val[i] < 0 || cur * val[i] >= 200001) {
					continue;
				}

				if (visited[cur * val[i]]) {
					continue;
				}

				q.push(cur * val[i]);
				visited[cur * val[i]] = 1;
				dist[cur * val[i]] = dist[cur] + 1;
				path[cur * val[i]] = cur;
			}
		}
	}
}

int main() {
	std::cin >> n >> k;
	bfs(n);

	std::cout << dist[k];
	std::cout << "\n";

	int cur = k;
	
	std::queue<int> ex;
	while (ex.size() - 1 != dist[k]) {
		ex.push(cur);
		cur = path[cur];
	}

	std::stack<int> s;
	while (!ex.empty()) {
		int f = ex.front();
		ex.pop();
		s.push(f);
	}

	while (!s.empty()) {
		std::cout << s.top() << " ";
		s.pop();
	}
	return 0;
}