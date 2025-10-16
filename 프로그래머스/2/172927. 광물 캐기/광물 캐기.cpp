// 다이아몬드 곡괭이
// 철 곡괭이
// 돌 곡괭이

// 곡괭이로 광물을 캘 때 피로도 소모됨
// 곡괭이는 종류에 상관없이 광물 5개 캔 후 더 이상 사용 불가

// 최소한의 피로도 : BFS

// 사용할 수 있는 곡괭이 중 아무거나 하나 선택해 광물을 캔다.
// 한 번 사용하기 시작한 곡괭이는 사용할 수 없을 때까지 사용한다.
// 광물은 주어진 순서대로만 캘 수 있다.
// 광산에 있는 모든 광물을 캐거나 더 사용할 곡괭이가 없을 때까지 광물을 캔다.

// minerals 배열에 5개의 광물의 종류를 살핀다.
    // 다이아몬드가 많을 경우, 다이아몬드 곡괭이  
        // 만약 다이아몬드 곡괭이가 없다면 철 곡괭이
        // 만약 철 곡괭이가 없다면 돌 곡괭이
    // 철이 많을 경우, 철 곡괭이
        // 만약 철 곡괭이가 없다면 돌 곡괭이
    // 돌이 많을 겨우, 돌 곡괭이
    // 만약, 개수가 다 같을 경우
        // 남아있는 곡괭이 중 가장 좋은 것

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

struct Mine{
    int rockType = 0;
    int cnt = 0;
};

struct Bundle {
    int diamond_cnt;
    int iron_cnt;
    int stone_cnt;
};

bool compare(Mine a, Mine b){
    if (a.cnt == b.cnt){
        return a.rockType < b.rockType;
    }
    return a.cnt > b.cnt;
}

bool compare_bundles(const Bundle& a, const Bundle& b) {
    // 1순위: 다이아 개수가 많은 묶음이 앞으로
    if (a.diamond_cnt != b.diamond_cnt) {
        return a.diamond_cnt > b.diamond_cnt;
    }
    // 2순위: 철 개수가 많은 묶음이 앞으로
    if (a.iron_cnt != b.iron_cnt) {
        return a.iron_cnt > b.iron_cnt;
    }
    // 3순위: 돌 개수가 많은 묶음이 앞으로
    return a.stone_cnt > b.stone_cnt;
}

using namespace std;

int solution(vector<int> picks, vector<string> minerals) {
    int energy = 0;
    std::vector<Bundle> all_bundles;
    
    int total_picks = picks[0] + picks[1] + picks[2];
    for (int i = 0; i < minerals.size(); i+=5){
        if (all_bundles.size() == total_picks) {
            break;
        }
        
        int dCnt = 0;
        int iCnt = 0;
        int sCnt = 0;
        for (int j = i; j < i + 5; j++){
            if (j > minerals.size() - 1){
                break;
            }
            
            // std::cout << j << " ";
            if (minerals[j] == "diamond"){
                dCnt++;
            }
            else if (minerals[j] == "iron"){
                iCnt++;
            }
            else{
                sCnt++;   
            }
        }
        
        all_bundles.push_back({dCnt, iCnt, sCnt});
        std::sort(all_bundles.begin(), all_bundles.end(), compare_bundles);
        
//         std::vector<Mine> mines;
//         mines.push_back({0, dCnt});
//         mines.push_back({1, iCnt});
//         mines.push_back({2, sCnt});
        
//         std::sort(mines.begin(), mines.end(), compare);
    }
    
    for (Bundle bundle : all_bundles) {
        int pick_type = -1; // 0:다이아, 1:철, 2:돌

        // 사용할 수 있는 가장 좋은 곡괭이를 찾는다.
        if (picks[0] > 0) {
            pick_type = 0;
            picks[0]--;
        } 
        else if (picks[1] > 0) {
            pick_type = 1;
            picks[1]--;
        } 
        else if (picks[2] > 0) {
            pick_type = 2;
            picks[2]--;
        } 
        else { // 곡괭이가 더 이상 없으면 종료
            break;
        }

        // 선택된 곡괭이로 현재 묶음을 캘 때의 피로도 계산
        if (pick_type == 0) { // 다이아 곡괭이
            energy += bundle.diamond_cnt * 1 + bundle.iron_cnt * 1 + bundle.stone_cnt * 1;
        } 
        else if (pick_type == 1) { // 철 곡괭이
            energy += bundle.diamond_cnt * 5 + bundle.iron_cnt * 1 + bundle.stone_cnt * 1;
        } 
        else if (pick_type == 2) { // 돌 곡괭이
            energy += bundle.diamond_cnt * 25 + bundle.iron_cnt * 5 + bundle.stone_cnt * 1;
        }
    }
    
    int answer = energy;
    return answer;
}