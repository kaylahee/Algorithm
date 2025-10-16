#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int range[3000];

int changeToint(std::string t, bool isEnd){
    std::string hour;
    for (int i = 0; i < 2; i++){
        hour += t[i];
    }
    
    std::string minute;
    for (int i = 3; i < 5; i++){
        minute += t[i];
    }
    
    int h = std::stoi(hour);
    int m = std::stoi(minute);
    
    if (isEnd){
        m += 10;
        if (m >= 60){
            m -= 60;
            h += 1;
            // if (h >= 24){
            //     h -= 24;
            // }
        }       
    }
    
    // std::cout << h << " " << m << "\n";
    return h * 60 + m;
}

int solution(vector<vector<string>> book_time) {
    // 시간 나열
    std::vector<std::pair<int, int>> Time_val;
    for (int i = 0; i < book_time.size(); i++){
        std::string st = book_time[i][0];
        std::string en = book_time[i][1];
        
        int st_t = changeToint(st, false);
        int en_t = changeToint(en, true);
        
        for (int j = st_t; j < en_t; j++){
            range[j]++;
        }
    }
    
    int maxCnt = 0;
    for (int i = 0; i < 1450; i++){
        std::cout << range[i] << " ";
        if (maxCnt < range[i]){
            maxCnt = range[i];
        }
    }
    
    int answer = maxCnt;
    
    return answer;
}
