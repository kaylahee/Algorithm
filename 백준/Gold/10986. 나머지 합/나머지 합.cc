// 11:40~
// [BOJ_10986] 나머지 합

// 수 N개가 주어진다.
// 연속된 부분 구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하라

#include <iostream>
#include <set>

int n, m;
long long arr[1000001];
long long sum[1000001];

long long calc_div[1000001] ;

int main() {
	std::cin >> n >> m;
	for (int i = 0; i < n; i++) {
		std::cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		sum[i] = arr[i - 1] + sum[i - 1];
		//std::cout << sum[i] << " ";

		calc_div[sum[i] % m]++;
	}
	//std::cout << "\n";

	/*for (int i = 1; i <= n; i++) {
		std::cout << sum[i] % m << " ";
	}
	std::cout << "\n";*/

	long long cnt = 0;
	cnt += calc_div[0];

	for (int i = 0; i < m; i++) {
		if (calc_div[i] > 1) {
			cnt += (calc_div[i] * (calc_div[i] - 1)) / 2;
		}
	}
	std::cout << cnt << "\n";

	return 0;
}