// 23:34~
// [프로그래머스] 유연근무제

// 출근 희망 시각에 늦지 않고 출근한 직원들에게 상품을 주는 이베트
// 일주일 동안 자신이 설정한 출근 희망 시각 + 10분까지 출근해야 함
// 토요일, 일요일의 출근 시각은 이벤트에 영향 X
// 시 * 100 + 분

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int cnt = 0;
    for (int people = 0; people < timelogs.size(); people++){
        int m = schedules[people] % 100;
        int h = (schedules[people] - m) / 100;
        m += 10;
        
        if (m >= 60){
            m -= 60;
            h += 1;
            if (h == 24){
                h = 0;
            }
        }
        int st = h * 100 + m;
        
        bool flag = true;
        int day = 0;
        for (int i = startday; i < 7 + startday; i++){        
            int day_idx = (i - 1) % 7;
            // 주말에는 이벤트 X
            if (day_idx == 5 || day_idx == 6){
                day++;
                continue;
            }
            
            if (timelogs[people][day] > st){
                flag = false;
            }
            day++;
        }   
        if (flag){
            cnt++;
        }
    }    
    return cnt;
}