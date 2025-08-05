#include <iostream>
#include <vector>
#include <algorithm>

// ���� ���� N
int n;
std::vector<std::vector<int>> region;

// �̵����� ���� ������ ����
std::vector<std::vector<int>> cnt;

// �̻��� ���� ����
struct Micro
{
	int id;
	int pos_y;
	int pos_x;
	int cnt;
	int dir;
};

// ���� ���� (�����¿�)
int dy[4] = { -1, 1, 0, 0 };
int dx[4] = { 0, 0, -1, 1 };

// �Լ� ����
void move(Micro *m);
int changePos(int dir);

// ��� �Լ�
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			std::cout << region[i][j] << " ";
		}
		std::cout << "\n";
	}
}

// �̻��� �����̴� �Լ�
void move(Micro *m) {
	int ny = m->pos_y + dy[(m->dir) - 1];
	int nx = m->pos_x + dx[(m->dir) - 1];

	// ���� ������ ���
	if (region[ny][nx] == -1) {
		m->cnt /= 2;
		m->dir = changePos(m->dir);
	}
	else {
		cnt[ny][nx]++;
	}

 	if (region[m->pos_y][m->pos_x] != -1) {
		region[m->pos_y][m->pos_x] = 0;
	}

	if (region[ny][nx] != -1) {
		region[ny][nx] = m->id;
	}
	m->pos_y = ny;
	m->pos_x = nx;
}

// �̻��� ��ġ ���� �Լ�
int changePos(int dir) {
	switch (dir) {
	case 1:
		return 2;
	case 2:
		return 1;
	case 3:
		return 4;
	case 4:
		return 3;
	}
	return dir;
}

void add(std::vector<Micro> &groups) {
	std::vector<std::pair<int, int>> together;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// �� �� �̻��� ���� Ž��
			if (cnt[i][j] > 1) {
				// �� �� �̻��� ������ ��ġ�� �ִ� �� 
				together.push_back({ i, j });
			}
		}
	}

	// �� �� �̻��� ������ ��ġ�� �ִ� ���� �̻��� Ž��
	for (std::pair<int, int> p : together) {
		std::vector<Micro> m;
		for (int i = 0; i < groups.size(); i++) {
			if (p.first == groups[i].pos_y && p.second == groups[i].pos_x) {
				m.push_back(groups[i]);
			}
		}

		// �� �� �̻��� ������ ���� ���
		Micro new_micro = { 0, 0, 0, 0, 0 };
		int max_cnt = 0;
		for (int i = 0; i < m.size(); i++) {
			new_micro.cnt += m[i].cnt;

			// ������ ���� ������ �̵�����
			if (max_cnt < m[i].cnt) {
				max_cnt = m[i].cnt;
				new_micro.id = m[i].id;
				new_micro.dir = m[i].dir;
				new_micro.pos_x = m[i].pos_x;
				new_micro.pos_y = m[i].pos_y;
			}
		}
		
		std::vector<Micro> new_groups;
		new_groups.push_back(new_micro);
		for (int i = 0; i < groups.size(); i++) {
			if (!(p.first == groups[i].pos_y && p.second == groups[i].pos_x)) {
				new_groups.push_back(groups[i]);
			}
		}
		groups.clear();
		groups = new_groups;
	}
}

int main() {
	int testcase;
	std::cin >> testcase;

	for (int tc = 1; tc <= testcase; tc++) {
		// �ݸ� �ð� M, �̻��� ������ ���� K
		int m, k;
		std::cin >> n >> m >> k;

		region.resize(n, std::vector<int>(n, 0));
		cnt.resize(n, std::vector<int>(n, 0));

		// �̻��� ������ ������ŭ �Է� ����
		std::vector<Micro> groups(k);
		for (int i = 0; i < k; i++) {
			groups[i].id = i;
			std::cin >> groups[i].pos_y >> groups[i].pos_x >> groups[i].cnt >> groups[i].dir;

			// ������ ��ġ ����
			region[groups[i].pos_y][groups[i].pos_x] = groups[i].id;
		}

		// ���� ���� ǥ�� (Ư�� ��ǰ���� ĥ�����ִ� ����)
		for (int i = 0; i < n; i++) {
			region[0][i] = -1;
			region[n - 1][i] = -1;
			region[i][0] = -1;
			region[i][n - 1] = -1;
		}

		// �ݸ� �ð� ���� ������
		for (int t = 0; t < m; t++) {
			for (int i = 0; i < groups.size(); i++) {
				if (groups[i].cnt > 0) {
					move(&groups[i]);
				}
			}
			// �� �� �̻��� ������ ���� ���
			add(groups);
			cnt.clear();
			cnt.resize(n, std::vector<int>(n, 0));
		}

		int res = 0;
		for (int i = 0; i < groups.size(); i++) {
			res += groups[i].cnt;
		}
		std::cout << "#" << tc << " " << res << "\n";

		region.clear();
		cnt.clear();
	}

	return 0;
}