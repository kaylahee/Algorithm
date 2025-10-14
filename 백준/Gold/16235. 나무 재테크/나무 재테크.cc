// 15:46~17:37
// [BOJ_16235] 나무 재테크

// r: 가장 위에서부터 떨어진 칸의 개수
// c: 가장 왼쪽으로부터 떨어진 칸의 개수

// 1-index

// 가장 처음에 양분은 모든 칸에 5만큼 들어있음
// 작은 묘목을 구매해 어느정도 키운 후 팔아서 수익을 얻는 재테크
// m개의 나무 구매 -> 땅에 심음

// 봄
// 나무가 자신의 나이만큼 양분을 먹고 나이가 + 1
// 각각의 나무는 나무가 있는 칸에 있는 양분만 먹을 수 있다.

// 하나의 칸에 여러 개의 나무가 있다면
// 나이가 어린 나무부터 양분을 먹는다.

// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 즉시 죽는다.

// 여름
// 봄에 죽은 나무가 양분으로 변하게 된다.
// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
// 소수점 아래는 버림

// 가을
// 나무 번식
// 번식하는 나무는 나이가 5의 배수
// 인접한 8개의 칸에 나이가 1인 나무가 생김

// 겨울
// 땅에 양분 추가
// 각 칸에 추가되는 양분의 양은 A[r][c]

#include <iostream>
#include <vector>
#include <algorithm>

struct Tree {
	int age;
	bool isDead = false;
};

int n, m, k;
int ground[11][11];
int A[11][11];
std::vector<Tree> tree_map[11][11];

bool compare(Tree a, Tree b) {
	return a.age < b.age;
}

// 나무가 자신의 나이만큼 양분을 먹고 나이가 + 1
// 각각의 나무는 나무가 있는 칸에 있는 양분만 먹을 수 있다.
void spring() {
	// 하나의 칸에 여러 개의 나무가 있다면
	// 나이가 어린 나무부터 양분을 먹는다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree_map[i][j].size() > 0) {
				std::sort(tree_map[i][j].begin(), tree_map[i][j].end(), compare);

				for (Tree &t : tree_map[i][j]) {
					if (ground[i][j] >= t.age) {
						ground[i][j] -= t.age;
						t.age += 1;
					}
					else {
						t.isDead = true;
					}
				}
			}
		}
	}
}

void summer() {
	// 봄에 죽은 나무가 양분으로 변하게 된다.
	// 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree_map[i][j].size() > 0) {
				for (Tree &t : tree_map[i][j]) {
					if (t.isDead) {
						ground[i][j] += t.age / 2;
					}
				}

				tree_map[i][j].erase(
					std::remove_if(tree_map[i][j].begin(), tree_map[i][j].end(), [](Tree&t) {
						return t.isDead == true;
					}),
					tree_map[i][j].end()
				);
			}
		}
	}
}

// 나무 번식
int dy[8] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dx[8] = { -1, 0, 1, -1, 1, -1, 0, 1 };
void autumn() {
	std::vector<std::vector<int>> newTree(n + 1, std::vector<int>(n + 1, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (tree_map[i][j].size() > 0) {
				for (Tree &t : tree_map[i][j]) {
					if (t.age % 5 == 0) {
						for (int d = 0; d < 8; d++) {
							int ny = i + dy[d];
							int nx = j + dx[d];

							if (ny < 0 || ny >= n || nx < 0 || nx >= n) {
								continue;
							}

							// 인접한 8개의 칸에 나이가 1인 나무가 생김
							tree_map[ny][nx].push_back({ 1 });
						}
					}
				}
			}
		}
	}
}

// 땅에 양분 추가
// 각 칸에 추가되는 양분의 양은 A[r][c]
void winter() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ground[i][j] += A[i][j];
		}
	}
}

void init() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			ground[i][j] = 5;
		}
	}
}

int main() {
	std::cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cin >> A[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y, z;
		std::cin >> y >> x >> z;

		tree_map[y - 1][x - 1].push_back({ z });
	}

	init();
	while (k--) {
		// 봄
		spring();
		// 여름
		summer();
		// 가을
		autumn();
		// 겨울
		winter();
	}

	int treeCnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			treeCnt += tree_map[i][j].size();
		}
	}
	std::cout << treeCnt << "\n";
	
	return 0;
}