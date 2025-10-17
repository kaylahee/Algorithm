// 1부터 n까지의 서로 다른 정수 5개가 오름차순으로 정렬된 비밀 코드를 가지고 있다.
// 이 비밀 코드를 맞혀야 한다.

// m번 시도할 수 있다.
// 각 시도마다 서로 다른 5개의 정수를 입력하면, 시스템은 그 중 몇 개가 비밀 코드에 포함되어 있는지 알려준다.

// m 번의 시도 후, 비밀 코드로 가능한 정수 조합의 개수를 알고 싶다.

// dfs로 찾아내야 하나?

#include <iostream>
#include <string>
#include <vector> 
#include <algorithm>

using namespace std;

struct Ex{
    std::vector<int> q;
    int cnt;
};

bool compare (Ex a, Ex b){
    return a.cnt > b.cnt;
}

std::vector<Ex> Qq;

int path[5];
int res = 0;
void dfs(int n, int lev, int st, std::vector<std::vector<int>> q, std::vector<int> ans){
    if (lev == 5){      
        // for (int i = 0; i < 5; i++){
        //     std::cout << path[i] << " ";
        // }
        // std::cout << "\n";
        int correct = 0;
        for (int i = 0; i < q.size(); i++){
            int cnt = 0;
            for (int j = 0; j < q[i].size(); j++){
                for (int k = 0; k < 5; k++){
                    if (path[k] == q[i][j]){
                        cnt++;
                        break;
                    }
                }
            }
            
            if (cnt == ans[i]){
                correct++;
            }
        }
        
        if (correct == q.size()){
            res++;
        }
        
        return;
    }
    
    for (int i = st; i <= n; i++){
        path[lev] = i;
        dfs(n, lev + 1, i + 1, q, ans);
        path[lev] = 0;
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    // ans 순으로 q 정렬한다.
    // for (int i = 0; i < q.size(); i++){
    //     Qq.push_back({q[i], ans[i]});
    // }
    // std::sort(Qq.begin(), Qq.end(), compare);
    
    dfs(n, 0, 1, q, ans);
    
    int answer = res;
    return answer;
}