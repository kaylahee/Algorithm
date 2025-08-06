#include <iostream>

int n;

int path[100001];

int cnt = 0;
void func(int lev) {
	int sum = 0;
	for (int i = 0; i < lev; i++) {
		sum += path[i];
	}
	if (sum == n) {
		cnt++;
	}

	if (lev == n) {
		return;
	}

	for (int i = 1; i <= 3; i++) {
		path[lev] = i;
		func(lev + 1);
		path[lev] = 0;
	}
}

int main() {
	std::cin >> n;
	func(0);
	std::cout << cnt;
	return 0;
}