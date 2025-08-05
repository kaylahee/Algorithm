#include <iostream>
#include <vector>
#include <algorithm>

struct Person {
	int height;
	int card_num;
};

bool compare(Person a, Person b) {
	return a.card_num > b.card_num;
}

int main() {
	int t;
	std::cin >> t;

	while (t--) {
		int n;
		std::cin >> n;

		std::vector<Person> p1(n);
		std::vector<int> heights(n);
		for (int i = 0; i < n; i++) {
			std::cin >> p1[i].height;
			heights[i] = p1[i].height;
		}

		for (int i = 0; i < n; i++) {
			std::cin >> p1[i].card_num;
		}

		std::sort(p1.begin(), p1.end(), compare);
		std::sort(heights.begin(), heights.end());

		bool isRight = true;
		for (int i = 0; i < n; i++) {
			if (p1[i].height != heights[i]) {
				isRight = false;
				break;
			}
		}

		if (isRight) {
			std::cout << "YES\n";
		}
		else {
			std::cout << "NO\n";
		}
	}

	return 0;
}