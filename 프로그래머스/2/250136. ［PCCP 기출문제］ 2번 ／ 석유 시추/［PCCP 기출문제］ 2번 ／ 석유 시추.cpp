// 세로길이가 n, 가로길이가 m인 격자 모양의 땅 속에서 석유 발견
// 석유는 여러 덩어리로 나누어 묻혀있음
// 시추관을 수직으로 단 하나만 뚫을 수 있음
// 가장 많은 석유를 뽑을 수 있는 시추관 위치
// 시추관은 열 하나 관통하는 형태
// 열과 열 사이에 시추관 뚫을 수 X

// bfs로 그룹 나누고, 그룹에 있는 석유 수도 알아낼 것

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>

struct Group{
    int num = 0;
    int cnt = 0;
};

using namespace std;

int map[501][501];
int nGroup = 1;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
int visited[501][501];
int bfs(int y, int x, int n, int m, std::vector<std::vector<int>> &land){
    std::queue<std::pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 1;
    
    int cnt = 1;
    while (!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        map[cy][cx] = nGroup;
        
        for (int d = 0; d < 4; d++){
            int ny = cy + dy[d];
            int nx = cx + dx[d];
            
            if (ny < 0 || ny >= n || nx < 0 || nx >= m){
                continue;
            }
            
            if (visited[ny][nx]){
                continue;
            }
            
            if (land[ny][nx] == 0){
                continue;
            }
            
            q.push({ny, nx});
            visited[ny][nx] = 1;
            cnt++;
        }
    }
    return cnt;
}

int solution(vector<vector<int>> land) {
    
    std::vector<int> groups(250000);
    for (int i = 0; i < land.size(); i++){
        for (int j = 0; j < land[i].size(); j++){
            if (!visited[i][j] && land[i][j] == 1){
                groups[nGroup] = (bfs(i, j, land.size(), land[i].size(), land));
                nGroup++;
            }
        }
    }
    
    int maxCnt = 0;
    for (int i = 0; i < land[0].size(); i++){
        std::set<int> g;
        for (int j = 0; j < land.size(); j++){
            if (map[j][i] != 0){
                g.insert(map[j][i]);
            }
        }
        
        int sum = 0;
        for (int j : g){
            sum += groups[j];
        }
        
        maxCnt = std::max(maxCnt, sum);
    }
    
    int answer = maxCnt;
    return answer;
}