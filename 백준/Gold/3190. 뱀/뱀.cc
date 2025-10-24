// 09:14~09:41 22:49~
// [BOJ_3190] 뱀

// 사과 먹으면 뱀 길이 늘어남
// 뱀이 이리저리 기어다니다가 벽 또는 자기자신의 몸과 부딪히면 게임 끝

// 게임은 n*n 정사각 보드 위에서 진행됨
// 몇몇 칸에는 사과가 놓여져 있음

// 보드의 상하좌우 끝에 벽이 있다.
// 게임이 시작할 때 뱀은 맨위 맨좌측에 위치한다.
// => 좌상단에 위치
// 뱀의 길이는 1
// 뱀은 처음에 오른쪽을 향한다.

// 뱀의 이동은 다음과 같다.
// 1. 뱀은 몸길이를 늘려 머리를 다음칸에 위치시킨다.
// 2. 벽이나 자기 자신의 몸과 부딪히면 게임 끝
// 3. 이동칸에 사과가 있다? 그 칸에 있던 사과 X 꼬리는 움직이지 않음
// => 즉, 길이 늘어남

// 4. 이동한 칸에 사과 없음? 몸길이 줄여, 꼬리가 위치한 칸을 비워준다.
// => 즉, 길이 그대로

// 사과의 위치와 뱀의 이동 경로가 주어진다.
// 이 게임은 몇 초만에 끝나는가.

// *1-index

#include <iostream>
#include <vector>
#include <algorithm>

int n, k;
int map[101][101];
int apple[101][101];
int move_map[101][101];


int l;
char trans[10001];

std::vector<std::pair<int, int>> tail;
std::vector<std::pair<int, std::pair<int, int>>> find_min;

bool compare(std::pair<int, std::pair<int, int>> a, std::pair<int, std::pair<int, int>> b) {
	return a.first > b.first;
}

void print_map() {
	std::cout << "map: \n";
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			std::cout << map[i][j] << " ";
		}
		std::cout << "\n";
	}
}

int t = 0;
// 상 우 하 좌
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void solve() {
    std::vector<std::pair<int, int>> snake_body; // deque 대신 vector 사용
    snake_body.push_back({ 1, 1 }); // 시작 위치
    map[1][1] = 2; // 맵에 뱀 표시 (2 사용)

    int dir = 1; // 0:상, 1:우, 2:하, 3:좌
    t = 0; // 전역 변수 t 사용 (또는 solve 함수 내 지역 변수)

    while (true) {
        t++; // 시간 증가

        // 1. 다음 머리 위치 계산
        int hy = snake_body.back().first;
        int hx = snake_body.back().second;
        int ny = hy + dy[dir];
        int nx = hx + dx[dir];

        // 2. 충돌 검사
        if (ny <= 0 || ny > n || nx <= 0 || nx > n || map[ny][nx] == 2) {
            break; // 게임 종료
        }

        // 3. 사과 확인 및 이동 처리
        if (apple[ny][nx] == 1) { // 사과 있음
            apple[ny][nx] = 0; // 사과 먹기
            map[ny][nx] = 2;   // 뱀 몸통으로 변경
            snake_body.push_back({ ny, nx }); // 머리만 추가 (길이 증가)
        }
        else { // 사과 없음
            map[ny][nx] = 2;   // 뱀 몸통으로 변경
            snake_body.push_back({ ny, nx }); // 머리 추가

            // 꼬리 제거 (Vector 방식)
            std::pair<int, int> tail_pos = snake_body[0]; // 맨 앞(꼬리) 좌표 확인
            map[tail_pos.first][tail_pos.second] = 0;   // 맵에서 꼬리 지우기
            snake_body.erase(snake_body.begin());       // 벡터 맨 앞 원소 제거 (비효율적)
        }

        // 4. 방향 전환 (시간 t 이후)
        if (trans[t] == 'L') {
            dir = (dir + 3) % 4;
        }
        else if (trans[t] == 'D') {
            dir = (dir + 1) % 4;
        }
        // print_map(); // 디버깅용 출력 (선택 사항)
    }
}

int main() {
	std::cin >> n;
	map[1][1] = 2; // 뱀 위치

	std::cin >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		std::cin >> r >> c;

		apple[r][c] = 1;
	}

	std::cin >> l;
	for (int i = 0; i < l; i++) {
		int x;
		char c;
		std::cin >> x >> c;

		trans[x] = c;
	}

	//print_map();

	solve();

	std::cout << t << "\n";

	return 0;
}