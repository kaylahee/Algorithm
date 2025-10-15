// 09:14~
// [BOJ_11659] 구간 합 구하기 4

// 수 N개가 주어졌을 때, i번째 수부터 j번째 수까지 합을 구하는 프로그램

#include <iostream>

int arr[100001];
int sum[100001];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		std::cin >> arr[i];
	}

	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + arr[i];
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;
		std::cout << sum[b] - sum[a - 1] << "\n";
	}

	return 0;
}