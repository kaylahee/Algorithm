#include <iostream>
#include <vector>
#include <queue>

int main_2606() {
	int cnt_com;
	std::cin >> cnt_com;
	
	int couple;
	std::cin >> couple;

	std::vector<std::vector<int>> network(cnt_com + 1);
	for (int i = 0; i < couple; i++) {
		int com, net;
		std::cin >> com >> net;
		network[com].push_back(net);
		network[net].push_back(com);
	}

	std::vector<bool> visited(cnt_com + 1, false);
	std::queue<int> q;
	
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int cur_com = q.front();
		q.pop();

		for (int i = 0; i < network[cur_com].size(); i++) {
			int next_com = network[cur_com][i];
			
			if (!visited[next_com]) {
				q.push(next_com);
				visited[next_com] = true;
			}
		}
	}
	
	int cnt = 0;
	for (int i = 1; i <= cnt_com; i++) {
		if (visited[i]) {
			cnt++;
		}
	}
	std::cout << cnt - 1;
	
	return 0;
}