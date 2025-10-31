// [BOJ_1049] 기타줄

// 기타에서 N개의 줄이 끊어짐
// 따라서 새로운 줄을 사거나 교체해야 함
// 강토는 되도록이면 돈을 적게 쓰려고 함
// 6줄 패키지를 살 수도 있고, 1개 또는 그 이상의 줄을 낱개로 살 수도 있음

// 끊어진 기타줄의 개수 N과 기타줄 브랜드 M개가 주잊ㅁ
// 각각의 브랜드에서 파는 기타줄 6개가 들어있는 패키지의 가격
// 낱개로 살 때의 가격이 주어질 때

// 적어도 N개를 사기 위해 필요한 돈의 수를 최소로 하는 프로그램
#include <iostream>
#include <vector>
#include <algorithm>

struct Line {
	int package_price;
	int one_price;
};

int n, m;

int main() {
	std::cin >> n >> m;

	int min_package = 21e8;
	int min_one = 21e8;
	std::vector<Line> gitar;
	for (int i = 0; i < m; i++) {
		int a, b;
		std::cin >> a >> b;

		gitar.push_back({ a, b });
		min_package = std::min(a, min_package);
		min_one = std::min(b, min_one);
	}

	int res_price = std::min(min_one * n, std::min(min_package * (n / 6) + min_one * (n % 6), min_package * (n / 6 + 1)));
	std::cout << res_price << "\n";

	return 0;
}