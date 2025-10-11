// 18:43~
// [BOJ_2309] 일곱 난쟁이

// 일과 마치고 돌아온 난쟁이가 7명 아닌 9명
// 9명 난쟁이 모두 자신이 난쟁이라 주장
// 일곱 난쟁이의 키의 합이 100

// 9명 난쟁이 주어졌을 때 7명 찾아라

#include <iostream>
#include <vector>
#include <algorithm>

std::vector<int> arr(9, 0);
std::vector<int> path(7, 0);
std::vector<int> res(7, 0);
void dfs(int lev, int st, int sum) {
	if (sum > 100) {
		return;
	}

	if (lev == 7) {
		if (sum == 100) {
			res = path;
		}
		return;
	}

	for (int i = st; i < 9; i++) {
		path[lev] = arr[i];
		dfs(lev + 1, i + 1, sum + arr[i]);
		path[lev] = 0;
	}
}

int main() {
	for (int i = 0; i < 9; i++) {
		std::cin >> arr[i];
	}

	dfs(0, 0, 0);

	std::sort(res.begin(), res.end());
	for (int i = 0; i < 7; i++) {
		std::cout << res[i] << "\n";
	}
}