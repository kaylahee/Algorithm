#include <iostream>
#include <vector>

bool find(int num){
    std::vector<int> arr;
    while (num > 0){
        arr.push_back(num % 10);
        num /= 10;
    }
    
    int diff = arr[1] - arr[0];
    for (int i = 1; i < arr.size() - 1; i++){
        if (arr[i + 1] - arr[i] != diff){
            return false;
        }
    }
    return true;
}

int main()
{
    int n;
    std::cin >> n;
    
    int cnt = 0;
    if (n < 100){
        cnt = n;
    }
    else{
        cnt = 99;
        
        for (int i = 100; i <= n; i++){
            if (find(i)){
                // std::cout << i << "\n";
                cnt++;
            }
        }
    }
    
    std::cout << cnt << "\n";

    return 0;
}