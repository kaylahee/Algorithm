// A회사의 물류창고에는 알파벳 대문자로 종류를 구분하는 컨테이너가 
// 세로로 n줄, 가로로 m줄
// 총 n*m 개 놓여 있다.

// 특정 종류 컨테이너의 출고 요청이 들어올 때마다
// 지게차로 창고에서 접근이 가능한 해당 종류의 컨테이너 모두 꺼낸다.
// 접근이 가능한 컨테이너란 4면 중 적어도 1면이 창고 외부와 연결된 컨테이너

// 창고 외부와 연결되지 않은 컨테이너도 꺼낼 수 있도록 하는 크레인이 있음

// 알파벳 하나로만 출고 요청이 들어온다 ? 지게차 사용
// BB처럼 같은 알파벳 두번 반복 -> 크레인 사용

// 1. 지게차 사용 함수 (목표 주변에 0이 있는지 확인)
// 2. 크레인 사용 함수
// 3. 갱신 함수

#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int binary[51][51];

int newMap[51][51];
int newnewMap[51][51];
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

int visited[51][51];
bool bfs(int sy, int sx, std::vector<std::string> map){    
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[0].size(); j++){
            visited[i][j] = 0;
        }
    }
    
    std::queue<std::pair<int, int>> q;
    q.push({sy, sx});
    visited[sy][sx] = 1;
    // std::cout << "start: " << sy << " " << sx << "\n";
    while (!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
        
        for (int i = 0; i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];
            
            if (ny < 0 || ny >= map.size() || nx < 0 || nx >= map[0].size()){
                continue;
            }
            
            if (visited[ny][nx]){
                continue;
            }
            
            if (map[ny][nx] != '0'){
                continue;
            }
            
            // std::cout << "nxt: " << ny << " " << nx << "\n";
            q.push({ny, nx});
            visited[ny][nx] = 1;
        }
    }
    
    for (int i = 0; i < map.size(); i++){
        for (int j = 0; j < map[0].size(); j++){
            if (visited[i][j] && binary[i][j]){
                return true;
            }
        }
    }
    return false;
}

void jigaeCar(char goal, std::vector<std::string>& storage){
    // 잡을 수 있는 문자 newMap에 저장
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            if (storage[i][j] == goal){
                for (int d = 0; d < 4; d++){
                    int ny = i + dy[d];
                    int nx = j + dx[d];
                    
                    if (ny < 0 || ny >= storage.size() || nx < 0 || nx >= storage[i].size()){
                        newMap[i][j] = 1;
                        break;
                    }
                    
                    if (bfs(i, j, storage)){
                        newMap[i][j] = 1;    
                        break;
                    }
                }
            }
        }
    }
    
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            if (newMap[i][j] == 1){
                storage[i][j] = '0';
            }
            newMap[i][j] = 0;
        }
    }
}

void krain(char goal, std::vector<std::string>& storage){
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            if (storage[i][j] == goal){
                newMap[i][j] = 1;
            }
        }
    }
    
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            if (newMap[i][j] == 1){
                storage[i][j] = '0';
                newMap[i][j] = 0;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    
    for (int i = 0; i < storage.size(); i++){
        if (i != 0 && i != storage.size() - 1){
            continue;
        }
        
        for (int j = 0; j < storage[i].size(); j++){            
            binary[i][j] = 1;    
        }
    }
    
    for (int i = 0; i < storage.size(); i++){        
        for (int j = 0; j < storage[i].size(); j++){            
            if (j != 0 && j != storage[i].size() - 1){
                continue;
            }
            
            binary[i][j] = 1;            
        }
    }
    
    for (int i = 0; i < requests.size(); i++){
        if (requests[i].size() == 1){
            jigaeCar(requests[i][0], storage);
        }
        else{
            krain(requests[i][0], storage);
        }
    }
    
    int answer = 0;
    for (int i = 0; i < storage.size(); i++){
        for (int j = 0; j < storage[i].size(); j++){
            // std::cout << storage[i][j] << " ";
            if (storage[i][j] != '0'){
                answer++;           
            }
        }
        // std::cout << "\n";
    }    
    return answer;
}