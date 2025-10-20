// 10:40~
// [BOJ_16139] 인간-컴퓨터 상호작용

// 문자열에서 특정 알파벳이 몇 번 나타나는지 알아봐서
// 자주 나타나는 알파벳이 중지나 검지 위치에 오는 알파벳인지 확인하면
// 실용적인지 확인 가능하다

// 특정 문자열 s, 특정 알파벳 a, 
// 문자열 구간 [l, r]

// s의 l번째 문자부터 r번째 문자 사이에 a가 몇 번 나타나는지 구하는

#include <iostream>
#include <string>

int alpha[200001][26];
int sum[200001][26];

int main() {
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(NULL);

	std::string s;
	std::cin >> s;

	for (int i = 0; i < s.size(); i++) {
		alpha[i][s[i] - 'a']++;
	}

	for (int i = 0; i < 26; i++) {
		for (int j = 1; j <= s.size(); j++) {
			sum[j][i] = alpha[j - 1][i] + sum[j - 1][i];
		}
	}

	int q;
	std::cin >> q;
	for (int i = 0; i < q; i++) {
		char c;
		std::cin >> c;
		int l, r;
		std::cin >> l >> r;

		/*int sum = 0;
		for (int i = l; i <= r; i++) {
			sum += alpha[i][c - 'a'];
		}*/

		std::cout << sum[r + 1][c - 'a'] - sum[l][c - 'a'] << "\n";
	}

	return 0;
}