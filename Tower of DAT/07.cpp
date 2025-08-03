#include <iostream>
#include <vector>

int main_07() {
	int h, w;
	std::cin >> h >> w;

	std::vector<std::vector<int>> arr(h, std::vector<int>(w, 0));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			std::cin >> arr[i][j];
		}
	}

	std::vector<int> cnt(10000001, 0);
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			// 정시 출근 횟수
			cnt[arr[i][j]]++;
		}
	}

	// 정시 출근 횟수가 가장 많은 사람 선정
	int max = 0;
	// 정시 출근 사원 번호
	int max_num = 0;
	for (int i = 0; i < 10000001; i++) {
		if (max < cnt[i]) {
			max = cnt[i];
			max_num = i;
		}
	}

	std::cout << max_num;
	return 0;
}