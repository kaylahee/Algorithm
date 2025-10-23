// 21:46~21:48 22:44~22:46

#include <iostream>
#include <string>
#include <deque>

int n;
std::deque<int> dq;

int main() {
	std::cin >> n;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;

		if (str == "push_front") {
			int x;
			std::cin >> x;

			dq.push_front(x);
		}
		else if (str == "push_back") {
			int x;
			std::cin >> x;

			dq.push_back(x);
		}
		else if (str == "pop_front") {
			if (!dq.empty()) {
				int num = dq.front();
				dq.pop_front();

				std::cout << num << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
		else if (str == "pop_back") {
			if (!dq.empty()) {
				int num = dq.back();
				dq.pop_back();

				std::cout << num << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
		else if (str == "size") {
			std::cout << dq.size() << "\n";
		}
		else if (str == "empty") {
			if (!dq.empty()) {
				std::cout << 0 << "\n";
			}
			else {
				std::cout << 1 << "\n";
			}
		}
		else if (str == "front") {
			if (!dq.empty()) {
				std::cout << dq.front() << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
		else if (str == "back") {
			if (!dq.empty()) {
				std::cout << dq.back() << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
	}
	return 0;
}