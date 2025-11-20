// [BOJ_13549] 숨바꼭질 3

// 수빈이는 현재 점 N에 있고,
// 동생은 점 K에 있다.

// 수빈이는 걷거나 순간이동할 수 있다.

// 만약, 수빈이의 위치가 X일 때,
// 걷는다면 1초 후 X - 1 혹은 X + 1로 이동
// 순간이동을 한다면, 2 * X의 위치로 이동

// 몇 초 후 ?

#include <iostream>
#include <queue>
#include <algorithm>

int n, k;

int sec[200001];
int visited[200001];
int opt[2] = { -1, 1 };

int minTime = 21e8;
void init() {
	for (int i = 0; i < 200000; i++) {
		sec[i] = 21e8;
	}
}

void bfs(int st) {
	std::queue<int> q;
	q.push(st);
	sec[st] = 0;
	visited[st] = 1;

	while (!q.empty()) {
		int cPos = q.front();
		q.pop();

		if (cPos == k) {
			std::cout << sec[cPos] << "\n";
			return;
		}

		if (!(cPos * 2 < 0 || cPos * 2 > 100000)) {
			if (sec[cPos * 2] > sec[cPos]) {
				sec[cPos * 2] = sec[cPos];
				q.push(cPos * 2);
			}
		}

		if (!(cPos + 1 < 0 || cPos + 1 > 100000)) {
			if (sec[cPos + 1] > sec[cPos]) {
				sec[cPos + 1] = sec[cPos] + 1;
				q.push(cPos + 1);
			}
		}

		if (!(cPos - 1 < 0 || cPos - 1 > 100000) && !visited[cPos - 1]) {
			if (sec[cPos - 1] > sec[cPos]) {
				sec[cPos - 1] = sec[cPos] + 1;
				q.push(cPos - 1);
			}
		}
	}
}

int main() {
	std::cin >> n >> k;

	init();
	bfs(n);

	return 0;
}