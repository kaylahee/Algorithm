// 16:46~
// [BOJ_32710] 구구단표

#include <iostream>

int main() {
	int n;
	std::cin >> n;

	int exit = 0;
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			if (i == n || j == n || i * j == n) {
				exit = 1;
			}
		}
	}

	std::cout << exit << "\n";
	return 0;
}