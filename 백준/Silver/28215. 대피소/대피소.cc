// 2차원 평면의 KOI 마을에 N개의 집이 있음
// i번째 집의 위치는 (Xi, Yi)이다.

// i번째 집과 j번째 집 사이의 거리는 
// dist_ij = abs(x_i - x_j) + abs(y_i - y_j);

// 주민들이 안전하게 대피할 수 있도록 k개의 집에 대피소 설치 예정
// 모든 주민의 안전을 고려해,
// 집에서 가장 가까운 대피소로 이동할 때 
// 가장 긴 거리가 최소가 되도록 설치할 k개의 집을 선택하고,
// 그때 대피소와 가장 멀리 떨어진 집과의 거리 구하려 한다.

// 1. k개의 집에 대피소 설치
// (조합 -> dfs)
// 2. k개의 집을 제외한 나머지 집에서 k개의 집 중 가장 가까운 집에서의 거리 구함
// (그냥 구현?)
// 3. 2번에서의 최댓값 구하고

// 4. 통틀어서 최솟값 구하기

#include <iostream>
#include <vector>
#include <algorithm>

int n, k;
std::vector<std::pair<int, int>> house;
std::vector<std::pair<int, int>> select_house;

int resMinDist = 21e8;

int selected[51];
int make_dist() {
	int maxDist = 0;
	for (int i = 0; i < house.size(); i++) {
		if (selected[i]) {
			continue;
		}

		int minDist = 21e8;

		int hy = house[i].first;
		int hx = house[i].second;

		//std::cout << "dist: \n";
		for (int j = 0; j < select_house.size(); j++) {
			int dy = select_house[j].first;
			int dx = select_house[j].second;

			int dist = abs(hy - dy) + abs(hx - dx);
			//std::cout << dist << " ";

			minDist = std::min(dist, minDist);
		}
		//std::cout << "\n";

		maxDist = std::max(minDist, maxDist);
	}

	return maxDist;
}

int path[51];
void find_comb(int lev, int st) {
	if (lev == k) {
		//std::cout << "comb: \n";
		for (int i = 0; i < k; i++) {
			//std::cout << path[i] << " ";
			selected[path[i]] = 1;
			select_house.push_back({ house[path[i]].first, house[path[i]].second });
		}
		//std::cout << "\n";

		resMinDist = std::min(make_dist(), resMinDist);

		select_house.clear();
		for (int i = 0; i < k; i++) {
			selected[path[i]] = 0;
		}
		return;
	}

	for (int i = st; i < house.size(); i++) {
		path[lev] = i;
		find_comb(lev + 1, i + 1);
		path[lev] = 0;
	}
}

int main() {
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int x, y;
		std::cin >> x >> y;

		house.push_back({ y, x });
	}

	find_comb(0, 0);

	std::cout << resMinDist << "\n";

	return 0;
}