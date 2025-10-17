#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    std::vector<int> servers(players.size(), 0);
    for (int i = 0; i < players.size(); i++){
        if (players[i] >= m){
            if (players[i] / m <= servers[i]){
                continue;
            }
            
            std::cout << i << " ";
            int increase = players[i] / m - servers[i];
            answer += increase;
            std::cout << players[i] / m - servers[i] << "\n";
            
            for (int j = i; j < i + k; j++){
                if (j >= players.size()){
                    continue;
                }
                
                servers[j] += increase;
            }
        }
    }
    // std::cout << "\n";
    
    for (int i = 0; i < players.size(); i++){
        std::cout << servers[i] << " ";
    }
    
    return answer;
}