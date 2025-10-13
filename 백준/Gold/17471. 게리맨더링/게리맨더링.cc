// 15:12~
// [BOJ_17471] 게리맨더링

// N개의 구역으로 나누어져 있다.
// 1번부터 N번까지 번호가 매겨져 있다.
// 구역을 두 개의 선거구로 나눠야 하고,
// 각 구역은 두 선거구 중 하나에 포함되어야 한다.

// 선거구는 구역을 적어도 하나 포함해야 하고, 
// 한 선거구에 포함되어 있는 구역은 모두 연결되어 있어야 한다.

// 만약, 4개의 구역이 있다 가정하자.
// {1} {2, 3, 4}
// {2} {1, 3, 4}
// {3} {1, 2, 4}
// {4} {1, 2, 3}
// {1, 2} {3, 4}
// {1, 3} {2, 4}
// .. 이런 식으로 두개의 부분 수열로 나누어준다.
// 그런 다음 이들이 서로 연결되어 있는지 파악한다.

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

int n;
int people[11];
std::vector<int> region[11];

int visited[11];
bool isConnected(std::vector<int>& arr) {
	for (int i = 1; i <= n; i++) {
		visited[i] = 0;
	}

	std::queue<int> q;
	q.push(arr[0]);
	visited[arr[0]] = 1;

	while (!q.empty()) {
		int cNum = q.front();
		q.pop();

		for (int i = 0; i < region[cNum].size(); i++) {
			if (visited[region[cNum][i]]) {
				continue;
			}

			for (int a : arr) {
				if (region[cNum][i] == a) {
					q.push(region[cNum][i]);
					visited[region[cNum][i]] = 1;
				}
			}

		}
	}

	/*std::cout << "visited: \n";
	for (int i = 1; i <= n; i++) {
		std::cout << visited[i] << " ";
	}
	std::cout << "\n";*/

	for (int a : arr) {
		if (!visited[a]) {
			return false;
		}
	}
	return true;
}

int minDiff = 21e8;
int included[11];
void divide_region(int lev) {
	if (lev == n) {
		std::vector<int> a, b;
		for (int i = 1; i <= n; i++) {
			if (included[i]) {
				a.push_back(i);
			}
			else {
				b.push_back(i);
			}
		}

		if (a.size() > 0 && b.size() > 0) {
			if (isConnected(a) && isConnected(b)) {
				int aSum = 0;
				for (int i = 0; i < a.size(); i++) {
					//std::cout << a[i] << " ";
					aSum += people[a[i]];
				}
				//std::cout << "/";

				int bSum = 0;
				for (int i = 0; i < b.size(); i++) {
					//std::cout << b[i] << " ";
					bSum += people[b[i]];
				}

				//std::cout << abs(aSum - bSum) << "\n";
				minDiff = std::min(minDiff, abs(aSum - bSum));
			}
		}

		return;
	}

	included[lev] = 1;
	divide_region(lev + 1);

	included[lev] = 0;
	divide_region(lev + 1);
}

int main() {
	std::cin >> n;
	for (int i = 1; i <= n; i++) {
		std::cin >> people[i];
	}

	for (int i = 1; i <= n; i++) {
		int a;
		std::cin >> a;

		for (int j = 0; j < a; j++) {
			int b;
			std::cin >> b;
		
			region[i].push_back(b);
			region[b].push_back(i);
		}
	}

	divide_region(0);

	if (minDiff == 21e8) {
		std::cout << -1 << "\n";
	}
	else {
		std::cout << minDiff << "\n";
	}
	
	return 0;
}