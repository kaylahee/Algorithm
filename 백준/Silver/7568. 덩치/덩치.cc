// 13:35~
// [BOJ_7568] 덩치

#include <iostream>
#include <vector>
#include <algorithm>

struct Dungchi {
	int kg;
	int cm;
};

int main() {
	int n;
	std::cin >> n;

	std::vector<Dungchi> arr;
	for (int i = 0; i < n; i++) {
		int kg, cm;
		std::cin >> kg >> cm;

		arr.push_back({ kg, cm });
	}
	
	for (int i = 0; i < n; i++) {
		int cnt = 1;
		for (int j = 0; j < n; j++) {
			if (arr[i].kg < arr[j].kg && arr[i].cm < arr[j].cm) {
				cnt++;
			}
		}
		std::cout << cnt << " ";
	}

	return 0;
}