#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> times = {
	"one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
	"eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen", "twenty"
};

int main_04() {
	int h, m;
	std::cin >> h >> m;

	if (m >= 1 && m < 30) {
		std::string str;
		if (m <= 20) {
			str = times[m - 1];
		}
		else {
			m -= 20;
			str = times[19] + " " + times[m - 1];
		}

		if (m == 1) {
			str += " minute";
		}
		else if (m == 15) {
			str = "quarter";
		}
		else {
			str += " minutes";
		}
		std::cout << str << " past " << times[h - 1];
	}
	else if (m == 30) {
		std::cout << "half past " << times[h - 1];
	}
	else if (m >= 31 && m <= 59) {
		std::string str;
		if (m < 40) {
			m = 59 - m;
			m -= 20;
			str = times[19] + " " + times[m];
		}
		else {
			str = times[59 - m];
		}
		if (m == 1) {
			str += " minute";
		}
		else if (m == 45) {
			str = "quarter";
		}
		else {
			str += " minutes";
		}
		std::cout << str << " to " << times[h];
	}
	else {
		std::cout << times[h - 1] << " o' clock";
	}
	return 0;
}