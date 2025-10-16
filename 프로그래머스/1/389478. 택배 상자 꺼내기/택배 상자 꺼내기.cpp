// [프로그래머스] 택배 상자 꺼내기

// 1~n의 번호가 있는 택배 상자가 창고에 있다.
// 택배 상자 정리

// 왼쪽 -> 오른쪽 (1번 상자부터 번호 순서대로 택배 상자 하나씩 놓는다.
// 가로로 w개 놓았다면
// 오른쪽 -> 왼쪽
// n개의 택배 상자를 모두 놓을 때까지 w개씩 상자를 쌓는다.

#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

int map[101][101];
int solution(int n, int w, int num) {
    int h = ceil((float)n / (float)w);
    int even = h % 2;
    int cnt = 1;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){            
            if (i % 2 == 0){
                map[i][j] = cnt++;       
            }
            else{
                map[i][w - j - 1] = cnt++;
            }
            
            if (cnt == n + 1){
                break;
            }
        }
    }
    
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            std::cout << map[i][j] << " ";
        }
        std::cout << "\n";
    }
    
    int LocY = 0;
    int LocX = 0;
    for (int i = 0; i < h; i++){
        for (int j = 0; j < w; j++){
            if (map[i][j] == num){
                LocY = i;
                LocX = j;
                break;
            }
        }
    }
    
    int Fcnt = 0;
    for (int i = LocY; i < h; i++){
        if (map[i][LocX] != 0){
            Fcnt++;
        }
    }
    
    std::cout << Fcnt << "\n";
    int answer = Fcnt;
    return answer;
}