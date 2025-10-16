// 무인도에 갇힌 사람들을 구출하려 한다.
// 구명보트 작아서 한번에 최대 2명씩 밖에 탈 수 없다.
// 무게 제한도 있다.

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    std::sort(people.begin(), people.end());
    
    int left = 0;
    int right = people.size() - 1;
    
    int cnt = 0;
    while (left <= right){
        if (people[left] + people[right] <= limit){
            left++;
            right--;
        }
        else{
            right--;
        }
        
        cnt++;
    }
    
    int answer = cnt;
    return answer;
}