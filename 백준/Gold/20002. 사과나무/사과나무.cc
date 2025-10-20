// 09:07~
// [BOJ_20002] 사과나무

#include <iostream>
#include <algorithm>

int n;
int map[301][301];
int sum[301][301];

int main() {
	std::cin >> n;

	int maxSum = -21e8;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> map[i][j];
			maxSum = std::max(maxSum, map[i][j]);
		}
	}

	//std::cout << "origin: \n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			sum[i][j] = map[i - 1][j - 1] + sum[i - 1][j] + sum[i][j - 1] - sum[i - 1][j - 1];
			//std::cout << sum[i][j] << " ";
		}
		//std::cout << "\n";
	}

	for (int k = 1; k <= n; k++) {
		//std::cout << k << ": \n";
		for (int i = 1; i <= n; i++) {
			if (i - k < 0) {
				continue;
			}
			for (int j = 1; j <= n; j++) {
				if (j - k < 0) {
					continue;
				}
				int curSum = sum[i][j] - sum[i - k][j] - sum[i][j - k] + sum[i - k][j - k];
				//std::cout << curSum << " ";
				maxSum = std::max(maxSum, curSum);
			}
			//std::cout << "\n";
		}
		//std::cout << "\n";
	}
	std::cout << maxSum << "\n";

	return 0;
}