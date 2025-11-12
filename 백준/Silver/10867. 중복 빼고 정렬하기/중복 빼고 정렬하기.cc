#include <iostream>
#include <set>
#include <algorithm>

int main() {
	int n;
	std::cin >> n;

	std::set<int> arr;
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		arr.insert(num);
	}

	for (int i : arr) {
		std::cout << i << " ";
	}

	return 0;
}