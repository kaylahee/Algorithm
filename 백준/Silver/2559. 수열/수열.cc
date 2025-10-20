// 10:26~
// [BOJ_2559] 수열

// 연속적인 며칠 동안의 온도의 합이 가장 큰 값

#include <iostream>
#include <algorithm>

int n, k;
int arr[100001];
int sum[100001];

int main() {
	std::cin >> n >> k;

	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = arr[i - 1] + sum[i - 1];
	}

	int maxSum = -21e8;
	for (int i = 1; i <= n; i++) {
		if (i - k < 0) {
			continue;
		}
		int curSum = sum[i] - sum[i - k];
		maxSum = std::max(maxSum, curSum);
	}
	std::cout << maxSum << "\n";

	return 0;
}