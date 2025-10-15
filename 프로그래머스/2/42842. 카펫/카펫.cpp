// 노란색과 갈색으로 색칠된 격자의 개수 기억
// 전체 카펫의 크기 기억 X

// 갈색 격자의 수 : brown
// 노란색 격자의 수 : yellow

// 가로 길이 >= 세로 길이
// 가로 길이 : w / 세로 길이 : h

// brown + yellow = w * h
// brown_w - 2 = yellow_w
// brown_h - 2 = yellow_h

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    for (int i = 1; i <= yellow; i++){
        if (yellow % i == 0){
            if (i <= yellow / i){
                // std::cout << i << " " << yellow / i << "\n";       
                int w = i + 2;
                int h = yellow / i + 2;
                
                if (w * h == brown + yellow){
                    answer.push_back(h);
                    answer.push_back(w);
                    break;
                }
            }
        }
    }
    return answer;
}