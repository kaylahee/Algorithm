#include <iostream>
#include <vector>
#include <set>

int main_08() {
	int h, w;
	std::cin >> h >> w;

	std::vector<std::vector<int>> apt(h, std::vector<int>(w));
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			std::cin >> apt[i][j];
		}
	}

	int bh, bw;
	std::cin >> bh >> bw;

	std::vector<int> blacklist(bh * bw);
	for (int i = 0; i < bh; i++) {
		for (int j = 0; j < bw; j++) {
			std::cin >> blacklist[i * bw + j];
		}
	}

	/*for (int i = 0; i < bh * bw; i++) {
		std::cout << blacklist[i] << " ";
	}
	std::cout << "\n";*/

	// 중복된 값 삭제
	std::set<int> blacklist_set(blacklist.begin(), blacklist.end());

	int cnt = 0;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			if (blacklist_set.count(apt[i][j])) {
				cnt++;
			}
		}
	}

	std::cout << cnt << "\n";
	std::cout << h * w - cnt;
	return 0;
}