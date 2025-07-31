#include<iostream>
#include<string>

int main_04() {
	std::string s;
	std::cin >> s;

	int cnt[200] = { 0 };
	for (int i = 0; i < s.size(); i++) {
		cnt['a' - s[i]]++;
	}

	for (int i = 199; i >= 0; i--) {
		if (cnt[i] >= 1) {
			std::cout << char('a' - i);
		}
	}
	return 0;
}