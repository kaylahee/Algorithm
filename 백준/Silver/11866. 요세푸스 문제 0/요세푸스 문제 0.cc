#include <iostream>
#include <queue>

int main() {
	int n, k;
	std::cin >> n >> k;

	std::queue<int> q;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}

	std::vector<int> v;
	int cnt = 0;
	while (!q.empty()) {
		for (int i = 0; i < k - 1; i++) {
			int num = q.front();
			q.push(num);
			q.pop();
		}
		v.push_back(q.front());
		q.pop();
	}

	std::cout << "<";
	for (int i = 0; i < v.size() - 1; i++) {
		std::cout << v[i] << ", ";
	}
	std::cout << v[v.size() - 1];
	std::cout << ">";

	return 0;
}