// [BOJ_9205] 맥주 마시면서 걸어가기
// 맥주를 마시면서 걷는다.
// 출발 : 상근이네 집
// 맥주 한 박스 들고 출발

// 맥주 한 박스 : 맥주 20개
// 목 마르면 안됨 => 50미터에 한병씩 마신다.
// 즉, 50미터 가려면 그 직전에 맥주 한병 마셔야 한다.

// 맥주를 더 구매할 수도 있다.
// 미리 인터넷으로 조사해보니 편의점 있다.
// 편의점 들릴 경우 빈 병은 버리고, 새 맥주 병 살 수 있다.
// 박스에 들어있는 맥주는 최대 20병

// 편의점 나선 직후에도 50미터를 가기 전에 맥주 한병 마셔야 한다.

// 두 거리 좌표 사이의 거리 : x 좌표의 차 + y 좌표의 차
// 상근이네 집과 페스티벌 집과의 거리 > 20 * 50
// abs(lock.x - home.x) + abs(lock.y - home.y)
// 상근이네 집과 편의점 사이의 거리 < 20 * 50 있는지 보고
// 있으면 그 편의점에서부터 페스티벌까지의 거리도 봐야함

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <cmath>

struct Loc {
	int x;
	int y;

	bool operator==(const Loc& other) const {
		return y == other.y && x == other.x;
	}
};

// 편의점 개수
int n;
// 상근이네 집
Loc home;
// 편의점
std::vector<Loc> store;
// 락페스티벌 좌표
Loc lock;

bool compare(Loc a, Loc b) {
	int diff_xA = abs(a.x - lock.x);
	int diff_yA = abs(a.y - lock.y);
	int distA = diff_xA + diff_yA;

	int diff_xB = abs(b.x - lock.x);
	int diff_yB = abs(b.y - lock.y);
	int distB = diff_xB + diff_yB;

	return distA < distB;
}

int beerCnt = 20;
std::string res;

void bfs(Loc st) {
	std::queue<Loc> q;
	q.push(st);

	while (!q.empty()) {
		int curY = q.front().y;
		int curX = q.front().x;
		q.pop();

		int rdist = abs(lock.x - curX) + abs(lock.y - curY);
		if (rdist <= 1000) {
			res = "happy";
			return;
		}

		for (Loc s : store) {
			int dist = abs(s.x - curX) + abs(s.y - curY);
			if (dist <= 1000) {
				q.push(s);
				store.erase(std::remove(store.begin(), store.end(), s), store.end());
			}
		}
	}
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		res = "sad";
		store.clear();

		std::cin >> n;
		std::cin >> home.x >> home.y;
		for (int i = 0; i < n; i++) {
			int x, y;
			std::cin >> x >> y;
			store.push_back({ x, y });
		}
		std::cin >> lock.x >> lock.y;

		bfs(home);

		std::cout << res << "\n";
	}

	return 0;
}