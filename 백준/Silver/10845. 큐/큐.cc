// 17:30~17:38
// [BOJ_10845] 큐

// 정수를 저장하는 큐를 구현한 다음, 입력으로 주어지는 명령 처리

#include <iostream>
#include <string>
#include <queue>

int main() {
	int n;
	std::cin >> n;
	
	std::queue<int> q;
	while (n--) {
		std::string order;
		std::cin >> order;

		if (order == "push") {
			int x;
			std::cin >> x;
			q.push(x);
		}
		else if (order == "pop") {
			if (!q.empty()) {
				std::cout << q.front() << "\n";
				q.pop();
			}
			else {
				std::cout << -1 << "\n";
			}
		}
		else if (order == "size") {
			std::cout << q.size() << "\n";
		}
		else if (order == "empty") {
			if (q.empty()) {
				std::cout << 1 << "\n";
			}
			else {
				std::cout << 0 << "\n";
			}
		}
		else if (order == "front") {
			if (!q.empty()) {
				std::cout << q.front() << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
		else if (order == "back") {
			if (!q.empty()) {
				std::cout << q.back() << "\n";
			}
			else {
				std::cout << -1 << "\n";
			}
		}
	}
	return 0;
}