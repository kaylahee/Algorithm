#include <iostream>
#include <vector>
#include <algorithm>

struct Data {
	int a;
	int b;
};

int n;
std::vector<int> arrA;
std::vector<int> arrB;
std::vector<Data> arr;

int s(std::vector<Data> arr) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i].a * arr[i].b;
	}
	return sum;
}

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		arrA.push_back(num);
	}
	for (int i = 0; i < n; i++) {
		int num;
		std::cin >> num;
		arrB.push_back(num);
	}

	std::sort(arrA.begin(), arrA.end());
	std::sort(arrB.begin(), arrB.end(), std::greater<int>());
	for (int i = 0; i < n; i++) {
		arr.push_back({ arrA[i], arrB[i] });
	}

	std::cout << s(arr) << "\n";

	return 0;
}