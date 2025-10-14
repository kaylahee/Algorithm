// 21:50~23:41
// [BOJ_1062] 가르침

// 1. a, n, t, i, c를 제외한 나머지 알파벳 중에 모든 단어에 들어가 있는 알파벳을 구한다.
// 2. 그 구한 알파벳 중에 k - 5개를 중복 없는 조합으로 선택한다.
// 3. 중복 없는 조합을 선택한 후
// 4. 그 조합이 words_remove_alpha 배열에 있는지 확인한다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int n, k;
std::vector<std::string> words;
std::vector<std::string> words_remove_antic;

int alpha[27];
std::vector<char> should_learn_alpha;
std::vector<char> alpha_comb;

int maxCnt = 0;

void dfs(int lev, int st) {
	if (lev == k - 5) {
		int cnt = 0;
		for (int i = 0; i < words_remove_antic.size(); i++) {
			int complete = 0;
			for (int j = 0; j < alpha_comb.size(); j++) {
				if (words_remove_antic[i].find(alpha_comb[j]) != std::string::npos) {
					complete++;
				}
			}

			if (complete == words_remove_antic[i].size()) {
				cnt++;
			}
		}

		maxCnt = std::max(cnt, maxCnt);
		return;
	}

	for (int i = st; i < should_learn_alpha.size(); i++) {
		alpha_comb.push_back(should_learn_alpha[i]);
		dfs(lev + 1, i + 1);
		alpha_comb.pop_back();
	}
}

int main() {
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;

		words.push_back(str);
	}

	for (int i = 0; i < n; i++) {
		std::string str = "";
		for (int j = 0; j < words[i].size(); j++) {
			if (words[i][j] == 'a' || words[i][j] == 'n' || words[i][j] == 't'
				|| words[i][j] == 'i' || words[i][j] == 'c') {
				continue;
			}

			if (str.find(words[i][j]) != std::string::npos) {
				continue;
			}
			str += words[i][j];
		}
		words_remove_antic.push_back(str);
	}
    
	int shouldCnt = 0;
	for (int i = 0; i < words_remove_antic.size(); i++) {
		for (int j = 0; j < words_remove_antic[i].size(); j++) {
			if (alpha[words_remove_antic[i][j] - 'a']) {
				continue;
			}

			should_learn_alpha.push_back(words_remove_antic[i][j]);
			alpha[words_remove_antic[i][j] - 'a'] = 1;
			shouldCnt++;
		}
	}

	if (k - 5 - shouldCnt >= 0) {
		maxCnt = words.size();
	}
	else {
		dfs(0, 0);
	}
	std::cout << maxCnt << "\n";

	return 0;
}