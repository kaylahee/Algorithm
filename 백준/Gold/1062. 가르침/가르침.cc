// 21:50~
// [BOJ_1062] 가르침

// 되도록 많은 단어 읽을 수 있도록
// K개의 글자 가르칠 시간 밖에 없음
// K개의 글자로만 이루어진 단어만을 읽을 수 있다.

// 어떤 K개의 글자를 가르쳐야 학생들이 읽을 수 있는 단어의 개수가 최대가 되는지
// 남극언어의 모든 언어는
// "anta"~"tica"
// 남극 단어는 N개밖에 없다고 가정
// 학생들이 읽을 수 있는 단어의 최댓값은?

// antic <- 이거는 포함이 되어야 한다.
// k - 5 개의 글자를 선정해야한다.
// 그렇다면 저 anta와 tica를 제외한 단어를 살펴보자

// 예를 들어
// antarctica / antahellotica / antacartica
// 이렇게 있다.

// anta 와 tica를 제외한 것을 보면
// rc / hello / car 
// a, n, t, i, c 를 제외한 알파벳을 보자
// r / hell / r 이 되겠다.

// 만약, k가 6이라면 antic을 제외한 1개의 글자만 고를 수 있고,
// 그럴 경우 r을 선택하면 2개의 단어를 읽을 수 있다.

// 1. a, n, t, i, c 는 고정
// 2. n개의 단어에서 a, n, t, i, c 를 제외한 알파벳을 구한다.
// 3. k - 5개의 글자를 배울 수 있다.
	// 즉, 각 단어별로 2번에서 제외한 글자가 가장 적은 것부터 나열
	// 그 글자를 배우고, 남은 알파벳의 개수가 가장 적은 것부터 다시 나열
	// 그렇게 반복해서 남은 알파벳의 개수가 없으면 그 단어는 읽을 수 있는 것

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
	// 1. 입력
	std::cin >> n >> k;
	for (int i = 0; i < n; i++) {
		std::string str;
		std::cin >> str;

		words.push_back(str);
	}

	// 2. a, n, t, i, c 를 제외한 알파벳을 구한다.
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