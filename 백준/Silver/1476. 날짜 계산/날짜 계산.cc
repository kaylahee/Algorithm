// 19:02~
// [BOJ_1476] 날짜 계산

// 수 3개를 이용해 연도 나타냄
// 각각의 수는 지구, 태양, 달을 나타냄

// 지구 나타내는 수 E
// 태양 나타내는 수 S
// 달을 나타내는 수 M

// 1년 => 1 1 1
// 1년 증가 => 2 2 2
// 범위 넘어가면 1로 됨

#include <iostream>

int main() {
	int e, s, m;
	std::cin >> e >> s >> m;

	// n -> e s m
	// n + 1 -> e + 1 s + 1 m + 1
	// n + ? -> (e + ?)%15 (s + ?)%28 (m + ?)%19
	// res = n + ?

	int year = 1;
	int E = 1;
	int S = 1;
	int M = 1;
	while (true) {
		E = (year) % 15;
		S = (year) % 28;
		M = (year) % 19;

		if (E == e % 15 && S == s % 28 && M == m % 19) {
			std::cout << year << "\n";
			break;
		}

		year++;
	}

	return 0;
}