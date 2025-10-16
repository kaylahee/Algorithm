// 시작 위치에서 출발 -> 목표 위치에 정확하게 멈추기 위해 최소 몇 번의 이동이 필요한가.
// 말의 이동은 상하좌우 중 한 방향으로 
// 게임판의 장애물이나 게임판 가장자리까지 부딪힐 때까지 미끄러져 움직이는 것을 한번의 이동으로 정의

// 즉, 장애물이나 가장자리에 부딪힐 때까지 이동해야 한다.

// 상 하 좌 우 중 한 방향 이동 가능
// 네 방향 중에 벽, 장애물이 있는지 판단해야 한다.
// 만약, 장애물이 상 좌 에 있다면 우나 하로 가야 한다.

// bfs 활용해서 문제를 해결

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

// 시작 위치, 도착 위치
int sy, sx, ey, ex;

int dist[101][101];
int visited[101][101];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
void bfs(int sy, int sx, std::vector<std::string>& board){
    std::queue<std::pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    dist[sy][sx] = 0;
    
    while (!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int ny = cy;
            int nx = cx;
            
            while (true){
                int nxt_y = ny + dy[i];
                int nxt_x = nx + dx[i];
                
                if (nxt_y < 0 || nxt_y >= board.size() || nxt_x < 0 || nxt_x >= board[0].size()){
                    break;
                }
                
                if (board[nxt_y][nxt_x] == 'D'){
                    break;
                }
                
                ny = nxt_y;
                nx = nxt_x;
            }
            
            if (visited[ny][nx]){
                continue;
            }
            
            q.push({ny, nx});
            visited[ny][nx] = 1;
            dist[ny][nx] = dist[cy][cx] + 1;
        }
    }
    
}

int solution(vector<string> board) {
    int answer = 0;
    for (int i = 0; i < board.size(); i++){
        for (int j =0; j < board[i].size(); j++){
            if (board[i][j] == 'R'){
                sy = i;
                sx = j;
            }
            else if (board[i][j] == 'G'){
                ey = i;
                ex = j;
            }
        }
    }
    
    // std::cout << "end: " << ey << " " << ex << "\n";
    bfs(sy, sx, board);
    
    if (dist[ey][ex] == 0){
        // std::cout << -1 << "\n";
        answer = -1;
    }
    else{
        // std::cout << dist[ey][ex] << "\n";
        answer = dist[ey][ex];
    }
    
    
    return answer;
}
