// 09:34~
// [BOJ_11660] 구간 합 구하기 5

#include <iostream>

int arr[1025][1025];
int sum[1025][1025];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	int n, m;
	std::cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cin >> arr[i][j];
		}
	}

	sum[0][0] = 0;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i][j - 1] + arr[i][j];
			}
		}
		else {
			for (int j = 1; j <= n; j++) {
				sum[i][j] = sum[i][j - 1] + arr[i][j];
			}

			for (int j = 1; j <= n; j++) {
				sum[i][j] += sum[i - 1][j];
			}
		}
	}

	for (int i = 0; i < m; i++) {
		int a1, b1, a2, b2;
		std::cin >> a1 >> b1 >> a2 >> b2;

		std::cout << sum[a2][b2] - sum[a2][b1 - 1] - sum[a1 - 1][b2] + sum[a1 - 1][b1 - 1] << "\n";
	}

	return 0;
}