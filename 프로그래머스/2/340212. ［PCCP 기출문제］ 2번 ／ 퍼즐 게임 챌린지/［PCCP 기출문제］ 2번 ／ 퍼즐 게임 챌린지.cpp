// n개의 퍼즐을 제한 시간 내에 풀어야 하는 퍼즐 게임을 하고 있다.
// 각 퍼즐은 난이도와 소요 시간이 정해져 있다.
// 당신의 숙련도에 따라 퍼즐을 풀 때 틀리는 횟수가 바뀌게 된다.

// 현재 퍼즐의 난이도 : diff
// 현재 퍼즐의 소요 시간 : time_cur
// 이전 퍼즐의 소요 시간 : time_prev
// 숙련도 : level

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> diffs, vector<int> times, long long limit) {
    int size = diffs.size();
    int level = 1;
    
    int st = 1;
    int en = 100000;    
    
    int cnt = 0;
    while (st <= en){
        int mid = (st + en) / 2;
        
        long long alltime = 0;
        for (int i = 0; i < size; i++){
            int diff_cur = diffs[i];
            int time_cur = times[i];

            int time_prev = 0;
            if (i >= 1){
                time_prev = times[i - 1];
            }

            long long solve_time = 0;       
            if (diff_cur <= mid){
                // 퍼즐 틀리지 않고, time_cur만큼의 시간을 사용해 해결한다.
                solve_time = time_cur;
            }
            else{
                // 시간 : 틀린 횟수 * (time_cur + time_prev) + time_cur
                solve_time = ((diff_cur - mid) * (time_cur + time_prev)) + time_cur;
            
            }
            alltime += solve_time;
            
            if (alltime > limit){
                break;    
            }
        }    
        
        if (alltime <= limit){
            en = mid - 1;
            level = mid;
        }
        else{
            st = mid + 1;         
        }
        
    }
    
    int answer = level;
    return answer;
}