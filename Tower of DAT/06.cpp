//#include <iostream>
//#include <vector>
//
//void type1(int n) {
//	std::vector<int> arr(n, 0);
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i];
//	}
//
//	int cnt[10] = { 0 };
//	for (int i = 1; i <= 9; i++) {
//		for (int j = 0; j < n; j++) {
//			if (arr[j] == i) {
//				cnt[i]++;
//			}
//		}
//	}
//
//	for (int i = 1; i <= 9; i++) {
//		std::cout << i << ":" << cnt[i] << "개\n";
//	}
//}
//
//bool type2(int n) {
//	std::vector<int> arr(n, 0);
//	for (int i = 0; i < n; i++) {
//		std::cin >> arr[i];
//	}
//
//	int cnt[1001] = { 0 };
//	for (int i = 0; i < n; i++) {
//		cnt[arr[i]]++;
//	}
//
//	bool flag = false;
//	for (int i = 0; i < 1001; i++) {
//		if (cnt[i] >= 2) {
//			flag = true;
//		}
//	}
//
//	return flag;
//}
//
//int main_06() {
//	int t;
//	std::cin >> t;
//
//	int n;
//	std::cin >> n;
//
//	//type1
//	if (t == 1) {
//		type1(n);
//	}
//
//	//type2
//	if (t == 2) {
//		if (type2(n)) {
//			std::cout << "중복발견";
//		}
//		else {
//			std::cout << "중복없음";
//		}
//	}
//
//	return 0;
//}