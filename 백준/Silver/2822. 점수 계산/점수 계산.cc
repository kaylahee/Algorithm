#include <iostream>
#include <vector>
#include <algorithm>

bool compare(std::pair<int, int> a, std::pair<int, int> b) {
	return a.second > b.second;
}

int main() {
	std::vector<std::pair<int, int>> scores;
	for (int i = 0; i < 8; i++) {
		int score;
		std::cin >> score;
		scores.push_back({ i, score });
	}
	std::sort(scores.begin(), scores.end(), compare);
	
	int sum = 0;
	std::vector<int> arr;
	for (int i = 0; i < 5; i++) {
		sum += scores[i].second;
		arr.push_back(scores[i].first + 1);
	}

	std::cout << sum << "\n";
	std::sort(arr.begin(), arr.end());
	for (int i = 0; i < 5; i++) {
		std::cout << arr[i] << " ";
	}

	return 0;
}