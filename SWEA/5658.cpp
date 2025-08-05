#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cmath>

int main() {
	int tc;
	std::cin >> tc;

	for (int t = 1; t <= tc; t++) {
		int n, k;
		std::cin >> n >> k;

		std::string s;
		std::cin >> s;
		std::string tmp_string = s;

		std::vector<std::string> store;
		store.push_back(s);
		for (int i = 1; i < n / 4; i++) {
			for (int j = 0; j < n; j++) {
				s[(j + i) % n] = tmp_string[j];
			}
			store.push_back(s);
		}

		std::vector<std::string> smalls;
		for (int i = 0; i < store.size(); i++) {
			std::string small;
			//std::cout << store[i] << "\n";
			for (int j = 0; j < store[i].size() + 1; j++) {
				if (j != 0 && j % (n / 4) == 0) {
					if (small != "") {
						//std::cout << small << " ";
						smalls.push_back(small);
					}
					small = "";
				}
				small += store[i][j];
			}
			//std::cout << "\n";
		}

		std::set<std::string> small_list(smalls.begin(), smalls.end());
		smalls.clear();
		for (std::string i : small_list) {
			//std::cout << i << "\n";
			smalls.push_back(i);
		}

		//std::cout << (int)'0' - 48 << "\n";

		std::vector<int> nums;
		for (int i = 0; i < smalls.size(); i++) {
			//std::cout << smalls[i] << "\n";
			long long sum = 0;
			for (int j = 0; j < n / 4; j++) {
				int num = 0;
				if (!(smalls[i][j] >= '0' && smalls[i][j] <= '9')) {
					sum += ((int)smalls[i][j] - 64 + 9) * pow(16, n / 4 - 1 - j);
				}
				else {
					sum += ((int)smalls[i][j] - 48) * pow(16, n / 4 - 1 - j);
				}
			}
			//std::cout << sum << "\n";
			nums.push_back(sum);
		}

		std::sort(nums.begin(), nums.end(), std::greater<int>());

		std::cout << "#" << t << " " << nums[k - 1] << "\n";
	}

	return 0;
}