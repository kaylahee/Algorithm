// 22:43~
// [BOJ_1197] 최소 스패닝 트리

#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>

int v, e;
std::vector<std::tuple<int, int, int>> edges;

int parent[100001];

int find_parent(int x) {
	if (x == parent[x]) {
		return x;
	}

	return parent[x] = find_parent(parent[x]);
}

void unite_parent(int a, int b) {
	a = find_parent(a);
	b = find_parent(b);

	if (a < b) {
		parent[b] = a;
	}
	else {
		parent[a] = b;
	}
}

int main() {
	std::cin >> v >> e;
	for (int i = 0; i < e; i++) {
		int a, b, c;
		std::cin >> a >> b >> c;

		edges.push_back({ c, a, b });
	}

	std::sort(edges.begin(), edges.end());

	for (int i = 1; i <= v; i++) {
		parent[i] = i;
	}

	int res = 0;
	int edgeCnt = 0;
	for (std::tuple<int, int, int> t : edges) {
		int a, b, c;
		std::tie(c, a, b) = t;

		if (find_parent(a) != find_parent(b)) {
			unite_parent(a, b);
			res += c;
			edgeCnt++;
		}

		if (edgeCnt == e) {
			break;
		}
	}

	std::cout << res << "\n";
	return 0;
}