#include <iostream>
#include <queue>

struct Point {
	int y;
	int x;
	int cost;
};

struct compare {
	bool operator()(Point a, Point b) {
		return a.cost > b.cost;
	}
};

int n;
int map[126][126];

int dist[126][126];
int visited[126][126];
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

void init_dist() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			dist[i][j] = 21e8;
		}
	}
}

void dijkstra(int sy, int sx) {
	std::priority_queue<Point, std::vector<Point>, compare> pq;
	pq.push({ sy, sx, map[sy][sx] });
	dist[sy][sx] = map[sy][sx];

	while (!pq.empty()) {
		int cy = pq.top().y;
		int cx = pq.top().x;
		int cCost = pq.top().cost;
		pq.pop();

		if (dist[cy][cx] < cCost) {
			continue;
		}

		for (int i = 0; i < 4; i++) {
			int ny = cy + dy[i];
			int nx = cx + dx[i];
			int nCost = map[ny][nx] + cCost;

			if (dist[ny][nx] > nCost) {
				dist[ny][nx] = nCost;
				pq.push({ ny, nx, nCost });
			}
		}
	}
}

int main() {
	int t = 1;

	while (true) {
		std::cin >> n;
		if (n == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				std::cin >> map[i][j];
			}
		}

		init_dist();
		dijkstra(0, 0);
		std::cout << "Problem " << t << ": " << dist[n - 1][n - 1] << "\n";
		t++;
	}

	return 0;
}