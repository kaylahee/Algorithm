#include <iostream>
#include <vector>
#include <queue>

struct City {
	int num;
	int cost;
};

struct compare {
	bool operator()(City a, City b) {
		return a.cost > b.cost;
	}
};

int n, m;
std::vector<City> citys[1001];
int st_city, en_city;

int dist[1001];
void init() {
	for (int i = 0; i < 1001; i++) {
		dist[i] = 21e8;
	}
}

void dijkstra(int st) {
	std::priority_queue<City, std::vector<City>, compare> pq;
	pq.push({st, 0});
	dist[st] = 0;

	while (!pq.empty()) {
		int cNum = pq.top().num;
		int cCost = pq.top().cost;
		pq.pop();

		if (dist[cNum] < cCost) {
			continue;
		}

		for (int i = 0; i < citys[cNum].size(); i++) {
			int nNum = citys[cNum][i].num;
			int nCost = citys[cNum][i].cost + cCost;

			if (dist[nNum] > nCost) {
				dist[nNum] = nCost;
				pq.push({ nNum, nCost });
			}
		}
	}
}

int main() {
	std::cin >> n;
	std::cin >> m;
	for (int i = 0; i < m; i++) {
		int st, en, cost;
		std::cin >> st >> en >> cost;

		citys[st].push_back({en, cost});
	}

	std::cin >> st_city >> en_city;

	init();
	dijkstra(st_city);
	std::cout << dist[en_city];

	return 0;
}