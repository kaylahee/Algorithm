// A나라가 B나라를 침공했다. (A -> B)
// B나라의 대부분의 전략 자원은 아이기스 군사 기지에 집중
// A나라는 B나라의 아이기스 군사 기지에 융단 폭격

// A나라의 공격에 대항하여 아이기스 군사 기지에서는 무수히 쏟아지는 폭격 미사일들을 요격하려고 한다.
// 백발백중을 자랑하는 요격 시스템이 있다. 
// 운용 비용 상당하다 -> 미사일 최소 => BFS?

// A나라와 B나라가 싸우고 있는 이 세계는 2차원 공간으로 이루어져 있다.
// A나라가 발사한 폭격 미사일은 x축에 평행한 직선 형태의 모양이며
// 개구간을 나타내는 정수 쌍 (s, e) 형태로 표현된다.

// B나라는 특정 x좌표에서 y축에 수평이 되도록 미사일을 발사하며, 발사된 미사일은 해당 x좌표에 걸쳐 있는
// 모든 폭격 미사일을 관통하여 한 번에 요격 가능하다.

// 단, 개구간 (s, e)로 표현되는 폭격 미사일은 s와 e에서 발사하는 요격 미사일로는 요격할 수 없다.
// 요격 미사일은 실수인 x좌표에서도 발사 가능하다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(std::vector<int> a, std::vector<int> b){
    return a[1] < b[1];
}

int solution(vector<vector<int>> targets) {     
    int answer = 0;
    
    std::sort(targets.begin(), targets.end(), compare);
    
    int missile_end = -1;
    for (int i = 0; i < targets.size(); i++){
        int s = targets[i][0];
        int e = targets[i][1];
        
        if (s >= missile_end){
            answer++;
            missile_end = e;
        }
    }
    
    return answer;
}