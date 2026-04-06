// 23:06~23:15
// [BOJ_1697] 숨바꼭질

// 수빈이는 현재 점 n
// 동생은 점 k
// 수빈이는 걷거나 순간이동 가능

// 수민이의 위치 x
// 걷는다 : x-1 / x+1
// 순간이동 : 2*x

#include <iostream>
#include <queue>

int n, k;
int visited[200001];
int time_val[200001];

int val[3] = { -1, 1, 2 };

void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	visited[st] = 1;
	time_val[st] = 0;

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		if (cur == k) {
			break;
		}

		for (int i = 2; i >= 0; i--) {
			int nxt = cur + val[i];
			if (i == 2) {
				nxt = cur * val[i];
			}

			if (nxt < 0 || nxt >= 200000) {
				continue;
			}

			if (visited[nxt]) {
				continue;
			}

			q.push(nxt);
			visited[nxt] = 1;
			time_val[nxt] = time_val[cur] + 1;
		}
	}
}

int main() {
	std::cin >> n >> k;

	bfs(n);

	std::cout << time_val[k] << "\n";

	return 0;
}