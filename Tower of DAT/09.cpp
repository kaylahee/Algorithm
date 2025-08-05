#include <iostream>
#include <string>
#include <vector>

struct Employee {
	int action;
	int id;
	std::string name;
};

int main() {
	int n;
	std::cin >> n;

	std::vector<int> id_cnt(10000, 0);
	std::vector<bool> id_register(10000, false);
	std::vector<std::string> names(10000);
	while (n--) {
		Employee e;
		std::cin >> e.action >> e.id;
		if (e.action == 1) {
			std::cin >> e.name;

			if (!id_register[e.id]) {
				std::cout << e.id << " OK\n";
				id_register[e.id] = true;
				names[e.id] = e.name;
			}
			else {
				std::cout << e.id << " ERROR\n";
			}
		}
		else {
			if (id_register[e.id]) {
				if (id_cnt[e.id] == 0) {
					std::cout << e.id << " " << names[e.id] << " ENTER\n";
					id_cnt[e.id]++;
				}
				else if (id_cnt[e.id] == 1) {
					std::cout << e.id << " " << names[e.id] << " EXIT\n";
					id_cnt[e.id] = 0;
				}
			}
			else {
				std::cout << e.id << " ERROR\n";
			}
		}




	}
	return 0;
}