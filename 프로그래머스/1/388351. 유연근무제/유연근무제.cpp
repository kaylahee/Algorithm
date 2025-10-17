// 출근 희망 시각 + 10분까지 어플로 출근해야 함
// 토요일, 일요일 출근 시각은 이벤트에 영향 끼치지 않음
// 모든 시각은 시에 100을 곱하고 분을 더한 정수로 표현됨

// 상품 받을 직원은 몇명?

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    for (int i = 0; i < schedules.size(); i++){
        int goal_t = schedules[i] + 10;
        
        int h = goal_t / 100;
        int m = goal_t % 100;
        if (m >= 60){
            m -= 60;
            
            h += 1;
            if (h == 24){
                h -= 24;
            }
        }
        
        goal_t = h * 100 + m;
        // std::cout << goal_t << " ";
        
        int cnt = 0;
        int day = 0;
        for (int j = 0 + startday; j < 7 + startday; j++){
            day++;
            if (j % 7 == 6 || j % 7 == 0){
                continue;
            }
            
            std::cout << j % 7 << " " << goal_t << " " << timelogs[i][day] << "\n";
            if (goal_t < timelogs[i][day - 1]){
                continue;
            }
            
            cnt++;
        }
        
        if (cnt == 5){
            answer++;
        }
    }
    return answer;
}