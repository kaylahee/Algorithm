#include <iostream>
#include <algorithm>

int main() {
	int x, y;
	std::cin >> x >> y;

	int w, h;
	std::cin >> w >> h;

	int resW = std::min(abs(x - 0), abs(x - w));
	int resH = std::min(abs(y - 0), abs(y - h));

	int res = std::min(resW, resH);
	std::cout << res << "\n";

	return 0;
}