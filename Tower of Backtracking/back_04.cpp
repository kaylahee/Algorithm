#include <iostream>
#include <vector>
#include <algorithm>

int path1[100001];
int path2[100001];
int path3[100001];

int visited[100001];

void func(int lev, int n, int m, int start) {
	if (lev == n) {
		if (m == 1) {
			for (int i = 0; i < n; i++) {
				std::cout << path1[i] << " ";
			}
			std::cout << "\n";
		}

		if (m == 2) {
			for (int i = 0; i < n; i++) {
				std::cout << path2[i] << " ";
			}
			std::cout << "\n";
		}

		if (m == 3) {
			for (int i = 0; i < n; i++) {
				std::cout << path3[i] << " ";
			}
			std::cout << "\n";
		}
		return;
	}

	if (m == 1) {
		for (int i = 1; i <= 6; i++) {
			path1[lev] = i;
			func(lev + 1, n, m, 0);
			path1[lev] = 0;
		}
	}

	if (m == 2) {
		for (int i = start; i <= 6; i++) {
			path2[lev] = i;
			func(lev + 1, n, m, i);
			path2[lev] = 0;
		}
	}

	if (m == 3) {
		for (int i = 1; i <= 6; i++) {
			if (visited[i]) {
				continue;
			}
			visited[i] = 1;
			path3[lev] = i;
			func(lev + 1, n, m, 0);
			visited[i] = 0;
			path3[lev] = 0;
		}
	}
}

int main() {
	int n, m;
	std::cin >> n >> m;
	func(0, n, m, 1);
	return 0;
}