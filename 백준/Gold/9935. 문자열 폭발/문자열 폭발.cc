// [BOJ_9935] 문자열 폭발

// 상근이는 문자열에 폭발 문자열 심어 놓음
// 폭발 문자열 폭발하면 그 문자는 문자열에서 사라짐
// 남은 문자열은 합쳐지게 된다.

// 1. 문자열이 폭발 문자열을 포함하고 있는 경우에
//    모든 문자열 폭발
//    남은 문자열을 순서대로 이어 붙여 새로운 문자열을 만든다.

// 2. 새로 생긴 문자열에 폭발 문자열이 포함되어 있을 수도 있다.
// 3. 폭발은 폭발 문자열이 문자열에 없을 때까지 계속된다.

// 어떤 문자열이 남는가
// 남아있는 문자가 없으면 FRULA 출력

#include <iostream>
#include <string>
#include <stack>

int main() {
	std::string str;
	std::cin >> str;

	std::string bomb_str;
	std::cin >> bomb_str;

	std::stack<char> st;
	int idx = 0;
	int cnt = 0;
	std::string res;
	for (char c : str) {
		res += c;

		if (res.size() >= bomb_str.size()) {
			if (res.substr(res.size() - bomb_str.size()) == bomb_str) {
				res.resize(res.size() - bomb_str.size());
			}
		}
	}

	if (res.size() == 0) {
		std::cout << "FRULA\n";
	}
	else {
		std::cout << res << "\n";
	}

	return 0;
}